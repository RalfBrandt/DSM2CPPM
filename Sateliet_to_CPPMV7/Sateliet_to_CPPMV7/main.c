//----------------------------------------------------------------------------
// C main line
//----------------------------------------------------------------------------

#include <m8c.h>        // part specific constants and macros
#include "PSoCAPI.h"    // PSoC API definitions for all User Modules
#include "ppm.h"
#include "serial.h"
#include "timer.h"
#include "DSM_Remote.h"



void main(void)
{
BOOL new_data=0;
	//activate systick counter
	TimerInit();
	DSM_CheckForReciver();	
	SerialRX_Init();
	ppm_Init();
	while (1)
	{
		if (SerialReadData())
		{
			new_data|=DSM_process_Data();
			SER_RESET();
		}
		if (PPM_IS_PPM_DONE())
		{
			if (new_data)
			{
				new_data=0;	
				PPM_START_ONE_PPM_TRAIN();
			}
		}
	}
}

