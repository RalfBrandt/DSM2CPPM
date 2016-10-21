/*
*PPM.C
*A 16 Bit PWM module  is used to gennerate the PPM train
*The PWM actually gennerates an inverted CPPM __|_|_|_|_|_|_|_|_|___|_|_|_|_|_|_|_|_|___|_
*this has the advantage that the pulse width can stay constant, only the periode has to be changed
*on everey compare match interrupt the periode value for the next chanel is loaded
*the last chanal value has an extra large value and is used to gennerate the sync gap
*the fist ppm train after power up is wrong so dynamic reconfiguration is used to disconect the PWM from the output PIN
*this mecanism is also used the start / stop the PPM output loading a 1 to ppm_Run will output one pulse train
*between the last pulse and the sync pulse an IO interrupt on rising edge is enabled , in the interrupt rotine 
*of this ppm_Run is cleared and the PWM is disdonected from the PIN, the PWM will stay in state PPM_PULSE_COUNT+1
* and wait that the main program will set ppm_Run again, that will start the next cycle
*/

#include <m8c.h>        // part specific constants and macros
#include "PSoCAPI.h"    // PSoC API definitions for all User Modules
#include "ppm.h"


volatile WORD ppm_Data[PPM_PULSE_COUNT];	//the pulse len valune for the chanales
volatile BYTE ppm_Nr=0;//the chanal counter
volatile BOOL ppm_Run=0;//start one pulse train

//initialize PPM output
void ppm_Init(void )
{
	
int n;
	//Init PPM_DATA array
	for (n=0;n<PPM_PULSE_COUNT;n++)
	{	//set to center
		ppm_Data[n]=(PPM_OUT_MIN_LEN+PPM_OUT_MAX_LEN)/2;
	}
	//enable glogal interrupts
	M8C_EnableGInt; 
	//enable compare match interrupt of the PWM
	PWM16_1_EnableInt();
	//enable GPOI Interrupts
	//we need that to trigger on falling egde of "compare true"
	M8C_EnableIntMask(INT_MSK0, INT_MSK0_GPIO);
	//pulse widht is actually the small gap between the PPM pulses
	PWM16_1_WritePulseWidth(PPM_OUT_PULSE_GAP_LEN_US);
	//disable IRQ on Port Pin, we do nt need iot jet
	Port_0_4_IntEn_ADDR&=~(1<<4); 
	//disconnect the PIN from the PWM and  set the pin to High
	RDI0LT0|=0x3;
	//init pulse counter, will loop thru the canales
	ppm_Nr=0;		
	//set a initial pulse len, just to have somthing in ther will be change in the interrupt service
	PWM16_1_WritePeriod(PPM_OUT_SYNC_PULSE_LEN);
	//start the PWM Module
	PWM16_1_Start();
}//END OFF ppm_Init



/*inerrupt service routine for the PWM module
*will be called on compare match
*-load pulse len of the next PPM pulse
*- increase pulse counter
*-after the last pulse (before the sync pulse is outputed enable GPOI interrupt on rising egde
*-when done wait for ppm_Run to go on again, stay in a small loop for that time
*/
#pragma interrupt_handler PWM16_1_CMP_ISR
void PWM16_1_CMP_ISR(void )
{
	//if we are done wait for start (ppm_Run==1)
	if (ppm_Nr==PPM_PULSE_COUNT+1)
	{
		if (ppm_Run)
		{ //continue with next Block of pulses
			RDI0LT0&=~0x3;	//reconect i/O PIN to PWM
			ppm_Nr=1;//reset counter
			PWM16_1_WritePeriod(ppm_Data[0]);//load pulse len of first chanal
		}
		else//continue waiting
			PWM16_1_WritePeriod(PPM_OUT_PULSE_GAP_LEN_US+10); //continue waiting
	}
	//load pulse len of next chanal
	else 
	{	//check if that is the last chanal is done
		if(ppm_Nr==PPM_PULSE_COUNT)
		{
			ppm_Nr++;
			PWM16_1_WritePeriod(PPM_OUT_SYNC_PULSE_LEN); 
			Port_0_4_IntEn_ADDR|=(1<<4);	//enable pin irq
		}
		else 
		{
			PWM16_1_WritePeriod(ppm_Data[ppm_Nr++]); 
		}
	}
}//END OFF PWM16_1_CMP_ISR

//called on a GPIO interrupt
#pragma interrupt_handler PPM_GPIO_ISR
void PPM_GPIO_ISR(void )
{
	if (PRT0DR&(1<<4)) //Check if PPM output pin went high
	{ //we are done 
	PRT0DR^=(1<<2);
		ppm_Run=0;		//signal that we are done
		Port_0_4_IntEn_ADDR&=~(1<<4);	//disable pin irq
		RDI0LT0|=0x3;	//disconect IO pin from PWM and set to High
	}
	
}
