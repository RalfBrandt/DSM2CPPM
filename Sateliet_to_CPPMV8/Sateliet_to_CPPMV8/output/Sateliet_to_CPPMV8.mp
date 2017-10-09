Project:      output/Sateliet_to_CPPMV8
Build Number: 0
Date:         Sun Jul 30 23:26:04 2017
Compiler:     ICCM8C
Version:      7.05.00


Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                           idata   0150   0009 =      9. bytes (rel,con,rom,lit)

       Addr  Global Symbol
      -----  --------------------------------
       0150  __idata_start
       0159  __idata_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                     psoc_config   0159   00F1 =    241. bytes (rel,con,rom,code)

       Addr  Global Symbol
      -----  --------------------------------
       0159  LoadConfigTBL_pdproject2
       0240  _LoadConfigInit
       0240  LoadConfigInit
       0244  _LoadConfig_pdproject2
       0244  LoadConfig_pdproject2
       024A  __psoc_config_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                     UserModules   024A   009B =    155. bytes (rel,con,rom,code)

       Addr  Global Symbol
      -----  --------------------------------
       024A  _RX8_1_ISR
       024E  _RX8_1_EnableInt
       024E  RX8_1_EnableInt
       0252  _RX8_1_DisableInt
       0252  RX8_1_Start
       0252  _RX8_1_Start
       0257  RX8_1_cGetChar
       0257  _RX8_1_bReadRxData
       0257  _bRX8_1_ReadRxData
       0257  _RX8_1_Stop
       0257  _bRX8_1_ReadRxStatus
       0257  _RX8_1_bReadRxStatus
       0257  bRX8_1_ReadRxStatus
       0257  bRX8_1_ReadRxData
       0257  _RX8_1_cGetChar
       025F  _PWM16_1_ISR
       025F  _RX8_1_iReadChar
       025F  _RX8_1_cReadChar
       0263  PWM16_1_EnableInt
       0263  _PWM16_1_EnableInt
       0267  _PWM16_1_Start
       0267  PWM16_1_Start
       0267  _PWM16_1_DisableInt
       026B  _PWM16_1_WritePeriod
       026B  _PWM16_1_Stop
       026B  PWM16_1_WritePeriod
       0271  PWM16_1_WritePulseWidth
       0271  _PWM16_1_WritePulseWidth
       0277  wPWM16_1_ReadCounter
       0277  _PWM16_1_wReadCounter
       0277  _wPWM16_1_ReadCounter
       0277  _wPWM16_1_ReadPulseWidth
       0277  _PWM16_1_wReadPulseWidth
       0277  wPWM16_1_ReadPulseWidth
       0277  _Counter8_1_ISR
       02D7  Counter8_1_EnableInt
       02D7  _Counter8_1_EnableInt
       02DB  _Counter8_1_Start
       02DB  Counter8_1_Start
       02DB  _Counter8_1_DisableInt
       02DF  Counter8_1_WritePeriod
       02DF  _Counter8_1_WritePeriod
       02DF  _Counter8_1_Stop
       02E2  Counter8_1_WriteCompareValue
       02E2  _Counter8_1_WriteCompareValue
       02E5  _bCounter8_1_ReadCounter
       02E5  _Counter8_1_bReadCounter
       02E5  _bCounter8_1_ReadCompareValue
       02E5  __UserModules_end
       02E5  bCounter8_1_ReadCounter
       02E5  _Counter8_1_bReadCompareValue
       02E5  bCounter8_1_ReadCompareValue

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                            text   02E5   047F =   1151. bytes (rel,con,rom,code)

       Addr  Global Symbol
      -----  --------------------------------
       02E5  __text_start
       02E5  _DSM_DeterminBitCount
       033F  _DSM_process_Data
       0438  _DSM_CheckForReciver
       0463  _main
       04A1  _ppm_Init
       04F7  _PWM16_1_CMP_ISR
       059E  _PPM_GPIO_ISR
       05BC  _SerialRX_Init
       05F9  _SerialReadData
       0617  _SerialConnectToPin
       0622  _ser_Tic
       0633  _RX8_1_Interrupt
       069E  _TimerInit
       06B3  _TimerConnectToPin
       06BE  _Timer_GennerateBindPulses
       06D9  _TimerWait_ms
       0706  _TMR8_1_Interrupt
       0732  PSoC_GPIO_ISR
       0736  <created procedures>
       0764  __text_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                            data   0000   0009 =      9. bytes (rel,con,ram)

       Addr  Global Symbol
      -----  --------------------------------
       0000  __data_start
       0000  _BindMode
       0001  _ppm_Nr
       0002  _ppm_Run
       0003  _ser_idx
       0004  _ser_status
       0005  _ser_to
       0006  _systic
       0008  _BindCount
       0009  __data_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
               virtual_registers   0009   000F =     15. bytes (rel,con,ram)

       Addr  Global Symbol
      -----  --------------------------------
       0009  __rZ
       000A  __rY
       000B  __rX
       000C  __r11
       000D  __r10
       000E  __r9
       000F  __r8
       0010  __r7
       0011  __r6
       0012  __r5
       0013  __r4
       0014  __r3
       0015  __r2
       0016  __r1
       0017  __r0
       0018  __virtual_registers_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                             bss   0018   0025 =     37. bytes (rel,con,ram)

       Addr  Global Symbol
      -----  --------------------------------
       0018  __bss_start
       001C  _ppm_Data
       002D  _ser_databuf
       003D  __ramareas_end
       003D  __bss_end

Area                               Start  End    Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                             TOP   0000   00CE =    206. bytes (abs,ovr,rom,code)

       Addr  Global Symbol
      -----  --------------------------------
       0068  __Start
       00CB  _bGetPowerSetting
       00CB  bGetPowerSetting

Files Linked      [ module(s) ]

./obj/boot.o	[ boot.asm ]
obj/dsm_remote.o	[ dsm_remote.c ]
obj/main.o	[ main.c ]
obj/ppm.o	[ ppm.c ]
obj/serial.o	[ serial.c ]
obj/timer.o	[ timer.c ]
<library>	[ rx8_1int.asm, rx8_1.asm, pwm16_1int.asm, pwm16_1.asm, psocgpioint.asm, psocconfigtbl.asm, psocconfig.asm ]
[ counter8_1int.asm, counter8_1.asm, rZ.asm, rY.asm, rX.asm, r11.asm, r10.asm, r9.asm, r8.asm, r7.asm ]
[ r6.asm, r5.asm, r4.asm, r3.asm, r2.asm, r1.asm, r0.asm ]

Area Definitions

-blit:0x150.0xfff
-bdata:0.0xff
-rwh:SSCParmBlk:0xf7.0xff

