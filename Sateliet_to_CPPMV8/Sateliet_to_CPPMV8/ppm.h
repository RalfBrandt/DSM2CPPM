/*
*PPM.h
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

//prevent double include
#ifndef PPM_DEFINE_6546te54365476576575
#define PPM_DEFINE_6546te54365476576575

//definitions
#define PPM_OUT_PULSES_PER_100US 200U //the speed the PWM counter is running 200 counts per 0.1ms > 2000 counts per ms
#define PPM_OUT_PULSE_GAP_LEN_US ((4U*PPM_OUT_PULSES_PER_100US)) //150us the lengh of the gap between pulses
#define PPM_OUT_SYNC_PULSE_LEN (30U*PPM_OUT_PULSES_PER_100US)		//3ms the lenght of the sync pulse
#define PPM_OUT_MIN_LEN (10U*PPM_OUT_PULSES_PER_100US-24)	//1ms minimum pulse len  (24=(2048-2000)/2)
#define PPM_OUT_MAX_LEN (20U*PPM_OUT_PULSES_PER_100US+24)	 //2ms maximum pulse len
#define PPM_OUT_CENTER_LEN ((PPM_OUT_MIN_LEN+PPM_OUT_MAX_LEN)/2) //1,5ms center pulse len


#define PPM_PULSE_COUNT 8 //number of chanales to output

#define PPM_START_ONE_PPM_TRAIN() {ppm_Run=1;}
#define PPM_IS_PPM_DONE() (ppm_Run==0)

//data
extern volatile WORD ppm_Data[PPM_PULSE_COUNT];	//the pulse len valune for the chanales
extern volatile BOOL ppm_Run; 					//start one pulse train

//prototypes
void ppm_Init(void );

#endif //PPM_DEFINE_6546te54365476576575