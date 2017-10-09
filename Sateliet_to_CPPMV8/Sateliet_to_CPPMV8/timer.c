/* this module implements the systimer
* the systic will be incremented once per ms
*also the timer is used to gennerate the bind pulses for the sttelite
*for that the hardware is reconfigured so that to serial input pin is connected to the timer output instead
*/
#include <m8c.h>        // part specific constants and macros
#include "PSoCAPI.h"    // PSoC API definitions for all User Modules
#include "timer.h"
#include "serial.h"

WORD systic=0;   //will be incremented once per ms
BYTE BindCount=0;  //used to gnnerate the 120us bind pulses


//initialize system timer
void TimerInit(void )
{
	//enable interrupt
	M8C_EnableGInt; 
	Counter8_1_EnableInt();  
	//ser periode to one per ms
	Counter8_1_WritePeriod(125); //one TC per ms
	Counter8_1_WriteCompareValue(0);
	//start it
	Counter8_1_Start();
}

//connect the timer output to the I/O pin
void TimerConnectToPin(void)
{
	//switch pin connection to counter8_1 compare out
	PRT0DM0|=(1<<5);
	//change driver Mode to Output
	PRT0DM1&=~(1<<5);
	//set number of bind pulses to gennerate
}

//gennerate the bind pulses for the satelite reciver
void Timer_GennerateBindPulses(BYTE Pulese)
{
	TimerConnectToPin();
	BindCount=Pulese+1;
	while (BindCount); //wait till done
	//waite a bite more
	TimerWait_ms(100);
	SerialConnectToPin();
}

//a delay
void TimerWait_ms(BYTE ms)
{
WORD time;
	time = TMR_GET_SYSTIC();
	while (TMR_GET_TIME_DELTA(time)<ms);
}

void TMR8_1_Interrupt(void )
{
	//the bind pulses are gennerated by the timer
	if (BindCount)
	{
		Counter8_1_WriteCompareValue(15); //120us
		Counter8_1_WritePeriod(30); //240 us
		BindCount--;
		if(!BindCount)
		{ //back to normal operation 
			Counter8_1_WriteCompareValue(0);
			Counter8_1_WritePeriod(250);
		}
	}
	else 
	{
		systic++;
		
	}
}