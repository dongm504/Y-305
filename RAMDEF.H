/*
 * vim:syntax=elan
 */

;IO口定义
;--------------------------------------------------------------
;按键相关口

IO_Led_B      ==  PORT6.0   ;Led灯1
   ; IO_Led_A      ==  PORT6.4   ;Led灯1
IO_Led_A      ==  PORT5.4   ;Led灯2
    ;IO_Led_B      ==  PORT6.5   ;Led灯2

;Key1          ==  PORT5.0
Key1          ==  PORT5.1

Test_VIN      ==  PORT5.3
Com_VIN       ==  PORT6.1
IO_Txd        ==  PORT5.0 
;通用寄存器分配
;------------------------------------------------------------
Key_Indx          ==      0x10      
Key_Indx_Have               ==     Key_Indx.0 
Key_Indx_Down               ==     Key_Indx.1
Chargeing                   ==     Key_Indx.2
Key_DC_Chargen              ==     Key_Indx.3
Low_Volage                  ==     Key_Indx.4
Idle_Release                ==     Key_Indx.5
Speed_100mS                 ==     Key_Indx.6
;============================================================
TimerFlag          ==     0x11
TxEn                        ==      TimerFlag.0 
TimerFlag_100mS             ==      TimerFlag.1
TimerFlag_5mS               ==      TimerFlag.2
Err_Heat                    ==      TimerFlag.3
Err_Motor                   ==      TimerFlag.4
Err_Vol                     ==      TimerFlag.5
TimerFlag_2S                ==      TimerFlag.6
TimerFlag_100mSLED          ==      TimerFlag.7
;------------------------------------------------------------
KEY_Buffer	      ==	  0x12   ;
;------------------------------------------------------------
KEY_Buffer_COMP	  ==	  0x13   ;
;------------------------------------------------------------
KEY_CONT          ==      0x14   ;
;------------------------------------------------------------
Count100mSec      ==      0x15  
;------------------------------------------------------------
Rwk01             ==      0x16
Rwk02             ==      0x17
Rwk03             ==      0x18
Rwk04             ==      0x19

Rwk_Temperture01  ==      0x1A
Rwk_Temperture02  ==      0x1B

Count_R           ==      0x1C
COUNTER	          ==      0x1D


Mode_Count        ==      0x1E
Mode_Pwm_Speed1       ==   Mode_Count.1 
Mode_Pwm_Speed2       ==   Mode_Count.0
;------------------------------------------------------------
Count5mSec        ==      0x1F
Count2Sec         ==      0x20
;------------------------------------------------------------


Sr_buf	          ==      0x21	
Acc_buf	          ==      0x22
WW02              ==      0x23                                       
WW03              ==      0x24

Charge_Timer1     ==      0x25
Charge_Timer2     ==      0x26
Charge_Timer3     ==      0x27
Charge_Timer4     ==      0x28
Charge_Timer5     ==      0x29
Charge_Timer6     ==      0x2A
Charge_Timer7     ==      0x2B
Charge_Timer8     ==      0x2C
Charge_Timer9     ==      0x2D

AD_Count_R        ==      0x2E
Key_Delay         ==      0x2F

Speed_Timer       ==      0x30
Count500mSec      ==      0x31
;--------------------------------------------------
TxStatus	==	0x32	;传送状态寄存器
TxDly		==	0x33	;传送延时计数器
TxData		==	0x34	;传送数据寄存器
CountTxBit	==	0x35	;传送位计数器
Tx_Ptr		==	0x36	;传送指针
TxBuf1		      ==	0x37
TxBuf2		      ==	0x38
TxBuf3		      ==	0x39
;帧处理相关寄存器
PackageStatus	  ==	0x3A
AD_Vol_Buf1       ==	0x3B
AD_Vol_Buf10      ==	0x3C


