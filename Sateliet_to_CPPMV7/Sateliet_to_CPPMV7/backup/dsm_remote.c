/*this module does contain the code to extract the data from
*the serial stream from the sattelite reciver
* the first byte ist a lost frame counter
* the second byte is a transmitter capability byte
* 0x1 DSM2 less that 8 chanal 1024 Bit 
* 0x2 DSM2 8 or more chanal 1024 Bit
* 0x11/0x12 like 0x1/0x2 but 2048 Bit
*next is the chanal data, one chanal per WORD
*BITS: the lowes 10/11 bit is the chanal value, right above (4 Bit) is the chanal Number
* xxCCCCVVVVVVVVVV (10 bit) or xCCCCVVVVVVVVVVV (11Bit)
*/
#include <m8c.h>        // part specific constants and macros
#include "PSoCAPI.h"    // PSoC API definitions for all User Modules
#include "DSM_Remote.h"
#include "ppm.h"
#include "serial.h"
#include "timer.h"
#include "GlobalParams.h"

BOOL BindMode=0;

//determin if we got 10 or 11 Bit data
//first check the transmiter capability  byte
//else tryout
BYTE DSM_DeterminBitCount(void)
{
	//check capability byte first
	if (ser_databuf[1]!=0)
	{
		if ((ser_databuf[1]&0xF)<=3)
		{
			if (ser_databuf[1]&0x10)
				return 11;
			else 
				return 10;
		}
	}
	//else tryout
	{
		BYTE min=0xff;
		BYTE max=0;
		BYTE chanal;
		BYTE n;
		//try 10 Bits
		for (n=0;n<7;n++)
		{
			chanal=(ser_databuf[n*2+2]>>2)&0xF;
			if (chanal && chanal<min)
				min=chanal;
			if(ser_databuf[n*2+2]!=0xFF  && chanal>max)
				max=chanal;
		}		
		if (min==1 &&  max && max <7)
			return 10;
		else 
			return 11;
	}
}

//Extract chanal data from serial data
BOOL DSM_process_Data(void)
{

static BYTE bits;	
	if (!bits) //check if we have 10 or 11 Bit data
		bits=DSM_DeterminBitCount();
	if (bits)
	{
	BYTE n;
	//static to sace stack space		
	static BYTE chanal; 
	static WORD value;	
		//loop thru the words 
		for (n=0;n<7;n++)
		{	//extract chanal number
			if (bits==10)
				chanal=(ser_databuf[n*2+2]>>2)&0xF;
			else 
				chanal=(ser_databuf[n*2+2]>>3)&0xF;
			//check if chanal numer is in range
			if (chanal<PPM_PULSE_COUNT && ser_databuf[n*2+2]!=0xFF)
				//extract chanal value
			{
				if (bits==10)
					value=(((WORD)ser_databuf[n*2+2]<<8)+ser_databuf[n*2+3])&0x3FF;
				else
				{
					value=(((WORD)ser_databuf[n*2+2]<<8)+ser_databuf[n*2+3])&0x7FF;
				}
				//PPM has resulution of 2000/1ms so 10 Bit datta (0 to 1024) needs to be multipleid by 2
				//best would be a linear scale like "Value=PPM_MIN + (value*(PPM_MAX-PPM_MIN))/(1<<Bits)" but that takes to mutch time.
				if (bits==10)
					ppm_Data[chanal]=PPM_OUT_MIN_LEN+ value*2;
				else 
					ppm_Data[chanal]=PPM_OUT_MIN_LEN+ value;
				//limit to MIN / MAX
				if (PPM_OUT_MAX_LEN<ppm_Data[chanal])
					ppm_Data[chanal]=PPM_OUT_MAX_LEN;
				if (PPM_OUT_MIN_LEN>ppm_Data[chanal])
					ppm_Data[chanal]=PPM_OUT_MIN_LEN;
			}
		}
		return 1;
	}
	return 0;
}

//check if reciver is connected 
//if we power up without reciver is connected then wait for reciver connected an enter bind mode
void DSM_CheckForReciver(void)
{
	//wait for a High on the input from the satelite reciver
	//also check if there is a jumper between P1_1 and P1_0

	PRT0DR&=~(1<<5); //clear input
	
	//set P1_1 to output
	PRT1DM0|=2;
	PRT1DM1&=~2;
	PRT1DM2&=~2;
	//set P1_0 to High Z
	PRT1DM0&=~1;
	PRT1DM1|=1;
	PRT1DM2&=~1;
	
	//check for bind jumper
	{
		BYTE delay=0;
		BYTE matchCnt=0;
		for (delay=0;delay<10;delay++)
		{
			//toggle P1_1
			PRT0DR^=2;
			TimerWait_ms(1);
			delay++;
			if ((PRT0DR&2)>>1==(PRT0DR&1)) //check if signal comes back in on P1_0
				matchCnt++;
			if (matchCnt>6)
				BindMode=1;
		}
	}

	//set P1_X back to startup value
	PRT1DM0=PORT_1_DRIVE_0;
	PRT1DM1=PORT_1_DRIVE_1;
	PRT1DM2=PORT_1_DRIVE_2;
	
	//Wait for reciver
	{
		BYTE delay=0;
		while (!(PRT0DR&(1<<5)))  //wait for the satelite
		{
			TimerWait_ms(1);
			delay++;
			//if we powered up without a connected reciver enter Bind mode
			//and wait for the reciver to connect
			if (!BindMode && delay>10)
			{
				BindMode=1;
			}
		}
	}
	if (BindMode)
	{
		TimerWait_ms(80);		
		Timer_GennerateBindPulses(5);
	}

	//found high signal on pin ->normal startup	

}