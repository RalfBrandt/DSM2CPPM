/* this module implements the systimer
* the systic will be incremented once per ms
*also the timer is used to gennerate the bind pulses for the sttelite
*for that the hardware is reconfigured so that to serial input pin is connected to the timer output instead
*/

//prevent double include
#ifndef TIMER_DEFINED_6546te54365476576575
#define TIMER_DEFINED_6546te54365476576575

//defines
#define TMR_GET_SYSTIC() (systic)
#define TMR_GET_TIME_DELTA(lasttime) (TMR_GET_SYSTIC()-lasttime)


//variables
extern WORD systic;
extern BYTE BindCount;


//prototypes
void TimerInit(void ); //initialize the timer
void Timer_GennerateBindPulses(BYTE Pulese); //gennerate the bind pulses for the satelite reciver
void TimerConnectToPin(void); //connect the timer output to the I/O pin
void TimerWait_ms(BYTE ms); //wait for x ms

#endif