/******************************************************************************
*  Generated by PSoC Designer 5.4.2946
******************************************************************************/
//=============================================================================
//  FILENAME:   GlobalParams.h
//  DATE:       28 October 2004
//
//  DESCRIPTION:
//  Constants describing many of the global parameter settings.
//  This file contains defines to support register initialization
//  for the CY8C21123
//
//  Copyright (c) Cypress Semiconductor 2014. All Rights Reserved.
//
// NOTES:
// Do not modify this file. It is generated by PSoC Designer each time the
// generate application function is run. The values of the parameters in this
// file can be modified by changing the values of the global parameters in the
// device editor.
//=============================================================================
//

#define CPU_CLOCK              0x2     //CPU clock value
#define CPU_CLOCK_MASK         0x7     //CPU clock mask
#define CPU_CLOCK_JUST         0x2     //CPU clock value justified
#define SLEEP_TIMER            0x0     //Sleep Timer value
#define SLEEP_TIMER_MASK       0x18    //Sleep Timer mask
#define SLEEP_TIMER_JUST       0x0     //Sleep Timer value justified
#define SWITCH_MODE_PUMP       0x1     //Switch Mode Pump value
#define SWITCH_MODE_PUMP_MASK  0x80    //Switch Mode Pump mask
#define SWITCH_MODE_PUMP_JUST  0x80    //Switch Mode Pump value justified
#define TRIP_VOLTAGE           0x2     //Trip Voltage
#define POWER_SETTING          0x10    //Power Setting 
#define WATCHDOG_ENABLE        0x0     //Watchdog Enable 1 = Enable
#define CLOCK_DIV_VC1          0xb     // VC1 clock divider 
#define CLOCK_DIV_VC1_MASK     0xf0    // VC1 clock divider mask
#define CLOCK_DIV_VC1_JUST     0xb0    // jVC1 clock divider ustified
#define CLOCK_DIV_VC2          0xf     // VC2 clock divider 
#define CLOCK_DIV_VC2_MASK     0xf     // VC2 clock divider mask
#define CLOCK_DIV_VC2_JUST     0xf     // VC2 clock divider justified
#define CLOCK_INPUT_VC3        0x0     // VC3 clock source
#define CLOCK_INPUT_VC3_MASK   0x3     // VC3 clock source mask
#define CLOCK_INPUT_VC3_JUST   0x0     // VC3 clock source justified
#define CLOCK_DIV_VC3          0x19    // VC3 clock divider
#define CLOCK_DIV_VC3_MASK     0xff    // VC3 clock divider mask
#define CLOCK_DIV_VC3_JUST     0x19    // VC3 clock divider justified
#define SYSCLK_SOURCE          0x0     // SysClk Source setting
#define SYSCLK_SOURCE_MASK     0x4     // SysClk Source setting mask
#define SYSCLK_SOURCE_JUST     0x0     // SysClk Source setting justified
#define SYSCLK_2_DISABLE       0x0     // SysClk*2 Disable setting
#define SYSCLK_2_DISABLE_MASK  0x1     // SysClk*2 Disable setting mask
#define SYSCLK_2_DISABLE_JUST  0x0     // SysClk*2 Disable setting justified
//
// register initial values
//
#define ANALOG_IO_CONTROL      0x0     //Analog IO Control register (ABF_CR)
#define PORT_0_GLOBAL_SELECT   0x30    //Port 0 global select register (PRT0GS)
#define PORT_0_DRIVE_0         0x14    //Port 0 drive mode 0 register (PRT0DM0)
#define PORT_0_DRIVE_1         0x28    //Port 0 drive mode 1 register (PRT0DM1)
#define PORT_0_DRIVE_2         0x8     //Port 0 drive mode 1 register (PRT0DM2)
#define PORT_0_INTENABLE       0x10    //Port 0 interrupt enable register (PRT0IE)
#define PORT_0_INTCTRL_0       0x0     //Port 0 interrupt control 0 register (PRT0IC0)
#define PORT_0_INTCTRL_1       0x10    //Port 0 interrupt control 1 register (PRT0IC1)
#define PORT_1_GLOBAL_SELECT   0x0     //Port 1 global select register (PRT1GS)
#define PORT_1_DRIVE_0         0x3     //Port 1 drive mode 0 register (PRT1DM0)
#define PORT_1_DRIVE_1         0x1     //Port 1 drive mode 1 register (PRT1DM1)
#define PORT_1_DRIVE_2         0x0     //Port 1 drive mode 2 register (PRT1DM2)
#define PORT_1_INTENABLE       0x0     //Port 1 interrupt enable register (PRT1IE)
#define PORT_1_INTCTRL_0       0x0     //Port 1 interrupt control 0 register (PRT1IC0)
#define PORT_1_INTCTRL_1       0x0     //Port 1 interrupt control 1 register (PRT1IC1)
