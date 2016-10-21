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


//prevent double include
#ifndef DSMR_DEFINED_6546te54365476576575
#define DSMR_DEFINED_6546te54365476576575



BYTE DSM_DeterminBitCount(void);
BOOL DSM_process_Data(void);
void DSM_CheckForReciver(void);

#endif