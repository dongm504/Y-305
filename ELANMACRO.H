/*
 * vim:syntax=elan
 */

;义隆相关指令宏定义

;*********************************
;立即数传递给IOC寄存器
IOW		MACRO	REG1,@NUM
		MOV	A,@NUM
		IOW	REG1
		ENDM
;*********************************

;*********************************
;寄存器REG2值传递给REG1
MOV		MACRO	REG1,REG2
		MOV	A,REG2
		MOV	REG1,A
		ENDM
;*********************************

;*********************************
;寄存器REG3REG4值传递给REG1REG2
FMOV		MACRO	REG1,REG2,REG3,REG4
		MOV	A,REG3
		MOV	REG1,A
		MOV	A,REG4
		MOV	REG2,A
		ENDM
;*********************************

;*********************************
;立即数传递给寄存器REG1
MOV		MACRO	REG1,@NUM
		MOV	A,@NUM
		MOV	REG1,A
		ENDM
;*********************************

;*********************************
;立即数传递给寄存器REG2REG1
FMOV		MACRO	REG2,REG1,@NUMH,@NUML
		MOV	A,@NUMH
		MOV	REG2,A
		MOV	A,@NUML
		MOV	REG1,A
		ENDM
;*********************************

;*********************************
;多位元复制，将REG2中对应LITERAL中=1的位复制到REG1中相应的位置
MOVNB		MACRO	REG1,REG2,@LITERAL
		MOV	A,REG2
		XOR	A,REG1
		AND	A,@LITERAL
		XOR	REG1,A
		ENDM
;*********************************

;*********************************
;多位元复制，将NUM中对应LITERAL中=1的位复制到REG1中相应的位置
MOVNB		MACRO	REG1,@NUM,@LITERAL
		MOV	A,@NUM
		XOR	A,REG1
		AND	A,@LITERAL
		XOR	REG1,A
		ENDM
;*********************************

;*********************************
;寄存器REG2与REG1或，值保存在REG1中
OR		MACRO	REG1,REG2
		MOV	A,REG2
		OR	REG1,A
		ENDM
;*********************************

;*********************************
;寄存器NUM与REG1或，值保存在REG1中
OR		MACRO	REG1,@NUM
		MOV	A,@NUM
		OR	REG1,A
		ENDM
;*********************************

;*********************************
;寄存器NUM与REG1异或，值保存在REG1中
XOR		MACRO	REG1,@NUM
		MOV	A,@NUM
		XOR	REG1,A
		ENDM
;*********************************

;*********************************
;寄存器REG2与REG1与，值保存在REG1中
AND		MACRO	REG1,REG2
		MOV	A,REG2
		AND	REG1,A
		ENDM
;*********************************

;*********************************
;立即数与寄存器REG1与，值存在寄存器中
AND		MACRO	REG1,@NUM
		MOV	A,@NUM
		AND	REG1,A
		ENDM
;*********************************

;*********************************
;寄存器REG2与REG1相加，值存在REG1中
ADD		MACRO	REG1,REG2
		MOV	A,REG2
		ADD	REG1,A
		ENDM
;*********************************

;*********************************
;立即数与寄存器REG1相加，值存在REG1中
ADD		MACRO	REG1,@NUM
		MOV	A,@NUM
		ADD	REG1,A
		ENDM
;*********************************

;*********************************
;寄存器REG2与REG1相加(带进位标志)，值存在REG1中
ADDC	MACRO	REG1,REG2
		MOV	A,REG2
		JBC	STATUS,C
		JZA	REG2
		ADD	REG1,A
		ENDM
;*********************************

;寄存器REG1与立即数(带进位标志)，值存在REG1中
ADDC	MACRO	REG1,@NUM
		MOV	A,@NUM
		JBC	STATUS,C
		JZ	REG1
		ADD	REG1,A
		ENDM

;*********************************
;*********************************
;寄存器REG1减去REG2，值存在REG1中
SUB		MACRO	REG1,REG2
		MOV	A,REG2
		SUB	REG1,A
		ENDM
;*********************************

;*********************************
;寄存器REG1减去立即数，值存在REG1中
SUB		MACRO	REG1,@NUM
		MOV	A,@NUM
		SUB	REG1,A
		ENDM
;*********************************

;*********************************
;寄存器REG1减去REG2(带进位标志)，值存在REG1中
SUBC		MACRO	REG1,REG2
		MOV	A,REG2
		JBS	STATUS,C
		JZA	REG2
		SUB	REG1,A
		ENDM
;*********************************

;*********************************
;某位等于0则跳转到相应的地址ADR
CJBC		MACRO	REG,BIT,ADR
		JBS	REG,BIT
		JMP	ADR
		ENDM
;*********************************

;*********************************
;某位等于1则跳转到相应的地址ADR
CJBS		MACRO	REG,BIT,ADR
		JBC	REG,BIT
		JMP	ADR
		ENDM
;*********************************

;*********************************
;某位等于0则跳转到相应的地址ADR
CJBC		MACRO	REGBIT,ADR
		JBS	REGBIT
		JMP	ADR
		ENDM
;*********************************

;*********************************
;某位等于1则跳转到相应的地址ADR
CJBS		MACRO	REGBIT,ADR
		JBC	REGBIT
		JMP	ADR
		ENDM
;*********************************

;*********************************
;当REG1>=REG2，则跳转到ADR
CJGE		MACRO	REG1,REG2,ADR
		MOV	A,REG2
		SUB	A,REG1
		JBC	STATUS,C
		JMP	ADR
		ENDM
;*********************************

;*********************************
;当REG1>=NUM，则跳转到ADR
CJGE		MACRO	REG1,@NUM,ADR
		MOV	A,@NUM
		SUB	A,REG1
		JBC	STATUS,C
		JMP	ADR
		ENDM
;*********************************

;*********************************
;当REG1>REG2，则跳转到ADR
CJG		MACRO	REG1,REG2,ADR
		MOV	A,REG1
		SUB	A,REG2
		JBS	STATUS,C
		JMP	ADR
		ENDM
;*********************************


;*********************************
;当REG1>NUM，则跳转到ADR
CJG		MACRO	REG1,@NUM,ADR
		MOV	A,REG1
		SUB	A,@NUM
		JBS	STATUS,C
		JMP	ADR
		ENDM
;*********************************
;*********************************
;当REG2REG1>@NUMHNUML，则跳转到ADR
CJG		MACRO	REG2,REG1,@NUMH,@NUML,ADR
		MOV	A,@NUMH
		SUB	A,REG2

		JBC	STATUS,Z
	    JMP $+4
		
        JBC	STATUS,C
		JMP	ADR	
		JMP $+5 
								
		MOV	A,@NUML
		SUB	A,REG1
		JBC	STATUS,C
		JMP	ADR	
	
		ENDM
;*********************************
;*********************************
;当REG1<=REG2，则跳转到ADR
CJLE		MACRO	REG1,REG2,ADR
		MOV	A,REG1
		SUB	A,REG2
		JBC	STATUS,C
		JMP	ADR
		ENDM
;*********************************

;*********************************
;当REG1<=NUM，则跳转到ADR
CJLE		MACRO	REG1,@NUM,ADR
		MOV	A,REG1
		SUB	A,@NUM
		JBC	STATUS,C
		JMP	ADR
		ENDM
;*********************************

;*********************************
;当REG1<REG2，则跳转到ADR
CJL		MACRO	REG1,REG2,ADR
		MOV	A,REG2
		SUB	A,REG1
		JBS	STATUS,C
		JMP	ADR
		ENDM
;*********************************

;*********************************
;当REG1<NUM，则跳转到ADR
CJL		MACRO	REG1,@NUM,ADR
		MOV	A,@NUM
		SUB	A,REG1
		JBS	STATUS,C
		JMP	ADR
		ENDM
;*********************************

;*********************************
;当REG2REG1<@NUMHNUML，则跳转到ADR
CJL		MACRO	REG2,REG1,@NUMH,@NUML,ADR
		MOV	A,@NUMH
		SUB	A,REG2
		JBS	STATUS,C
		JMP	ADR
		JBS	STATUS,Z
		JMP	$+5
		MOV	A,@NUML
		SUB	A,REG1
		JBS	STATUS,C
		JMP	ADR
		ENDM
;*********************************

;*********************************
;当REG2REG1<REG4REG3，则跳转到ADR
CJL		MACRO	REG2,REG1,REG4,REG3,ADR
		MOV	A,REG3
		SUB	A,REG1
		MOV	A,REG4
		JBS	STATUS,C
		JZA	REG4
		SUB	A,REG2
		JBS	STATUS,C
		JMP	ADR
		ENDM
;*********************************

;*********************************
;当REG4REG3REG2REG1<REG8REG7REG6REG5，则跳转到ADR
CJL		MACRO	REG4,REG3,REG2,REG1,REG8,REG7,REG6,REG5,ADR
		MOV	A,REG5
		SUB	A,REG1
		MOV	A,REG6
		JBS	STATUS,C
		JZA	REG6
		SUB	A,REG2
		MOV	A,REG7
		JBS	STATUS,C
		JZA	REG7
		SUB	A,REG3
		MOV	A,REG8
		JBS	STATUS,C
		JZA	REG8
		SUB	A,REG4
		JBS	STATUS,C
		JMP	ADR
		ENDM
;*********************************

;*********************************
;当REG=0时，则跳转到ADR
CJZ		MACRO	REG,ADR
		MOV	REG,REG
		JBC	STATUS,Z
		JMP	ADR
		ENDM
;*********************************

;*********************************
;当REG2REG1=0时，则跳转到ADR
CJZ		MACRO	REG2,REG1,ADR
		MOV	A,REG1
		OR	A,REG2
		JBC	STATUS,Z
		JMP	ADR
		ENDM
;*********************************

;*********************************
;当REG3REG2REG1=0时，则跳转到ADR
CJZ		MACRO	REG3,REG2,REG1,ADR
		MOV	A,REG1
		OR	A,REG2
		OR	A,REG3
		JBC	STATUS,Z
		JMP	ADR
		ENDM
;*********************************

;*********************************
;当REG4REG3REG2REG1=0时，则跳转到ADR
CJZ		MACRO	REG4,REG3,REG2,REG1,ADR
		MOV	A,REG1
		OR	A,REG2
		OR	A,REG3
		OR	A,REG4
		JBC	STATUS,Z
		JMP	ADR
		ENDM
;*********************************

;*********************************
;当REG!=0时，则跳转到ADR
CJNZ		MACRO	REG,ADR
		MOV	REG,REG
		JBS	STATUS,Z
		JMP	ADR
		ENDM
;*********************************

;*********************************
;当REG2REG1!=0时，则跳转到ADR
CJNZ		MACRO	REG2,REG1,ADR
		MOV	A,REG1
		OR	A,REG2
		JBS	STATUS,Z
		JMP	ADR
		ENDM
;*********************************

;*********************************
;当REG3REG2REG1!=0时，则跳转到ADR
CJNZ		MACRO	REG3,REG2,REG1,ADR
		MOV	A,REG1
		OR	A,REG2
		OR	A,REG3
		JBS	STATUS,Z
		JMP	ADR
		ENDM
;*********************************

;*********************************
;当REG4REG3REG2REG1!=0时，则跳转到ADR
CJNZ		MACRO	REG4,REG3,REG2,REG1,ADR
		MOV	A,REG1
		OR	A,REG2
		OR	A,REG3
		OR	A,REG4
		JBS	STATUS,Z
		JMP	ADR
		ENDM
;*********************************

;*********************************
;当REG1=REG2，则跳转到ADR
CJE		MACRO	REG1,REG2,ADR
		MOV	A,REG2
		SUB	A,REG1
		JBC	STATUS,Z
		JMP	ADR
		ENDM
;*********************************

;*********************************
;当REG2REG1=REG4REG3，则跳转到ADR
CJE		MACRO	REG2,REG1,REG4,REG3,ADR
		MOV	A,REG4
		SUB	A,REG2
		JBS	STATUS,Z
		JMP	$+5
		MOV	A,REG3
		SUB	A,REG1
		JBC	STATUA,Z
		JMP	ADR
		ENDM
;*********************************

;*********************************
;当REG1=NUM，则跳转到ADR
CJE		MACRO	REG1,@NUM,ADR
		MOV	A,@NUM
		SUB	A,REG1
		JBC	STATUS,Z
		JMP	ADR
		ENDM
;*********************************

;*********************************
;当REG2REG1=@NUMHNUML，则跳转到ADR
CJE		MACRO	REG2,REG1,@NUMH,@NUML,ADR
		MOV	A,@NUMH
		SUB	A,REG2
		JBS	STATUS,Z
		JMP	$+5
		MOV	A,@NUML
		SUB	A,REG1
		JBC	STATUA,Z
		JMP	ADR
		ENDM
;*********************************

;*********************************
;当REG1!=REG2，则跳转到ADR
CJNE		MACRO	REG1,REG2,ADR
		MOV	A,REG2
		SUB	A,REG1
		JBS	STATUS,Z
		JMP	ADR
		ENDM
;*********************************

;*********************************
;当REG2REG1!=REG4REG3，则跳转到ADR
CJNE		MACRO	REG2,REG1,REG4,REG3,ADR
		MOV	A,REG4
		SUB	A,REG2
		JBS	STATUS,Z
		JMP	ADR
		MOV	A,REG3
		SUB	A,REG1
		JBS	STATUS,Z
		JMP	ADR
		ENDM
;*********************************

;*********************************
;当REG1!=NUM，则跳转到ADR
CJNE		MACRO	REG1,@NUM,ADR
		MOV	A,@NUM
		SUB	A,REG1
		JBS	STATUS,Z
		JMP	ADR
		ENDM
;*********************************

;*********************************
;当REG2REG1!=@NUMHNUML，则跳转到ADR
CJNE		MACRO	REG2,REG1,@NUMH,@NUML,ADR
		MOV	A,@NUMH
		SUB	A,REG2
		JBS	STATUS,Z
		JMP	ADR
		MOV	A,@NUML
		SUB	A,REG1
		JBS	STATUS,Z
		JMP	ADR
		ENDM
;*********************************

;*********************************
;当REG1<NUM，则跳转到ADR1
;当REG1>NUM，则跳转到ADR2
CJLJG		MACRO	REG1,@NUM,ADR1,ADR2
		MOV	A,@NUM
		SUB	A,REG1
		JBS	STATUS,C
		JMP	ADR1
		JBS	STATUS,Z
		JMP	ADR2
		ENDM
;*********************************

;*********************************
;当REG1<REG2，则跳转到ADR1
;当REG1>REG2，则跳转到ADR2
CJLJG		MACRO	REG1,REG2,ADR1,ADR2
		MOV	A,REG2
		SUB	A,REG1
		JBS	STATUS,C
		JMP	ADR1
		JBS	STATUS,Z
		JMP	ADR2
		ENDM
;*********************************

;*********************************
;当REG1=REG2，则跳转到ADR1
;当REG1<REG2，则跳转到ADR2
CJEJL		MACRO	REG1,REG2,ADR1,ADR2
		MOV	A,REG2
		SUB	A,REG1
		JBC	STATUS,Z
		JMP	ADR1
		JBS	STATUS,C
		JMP	ADR2
		ENDM
;*********************************

;*********************************
;当REG1=NUM，则跳转到ADR1
;当REG1<NUM，则跳转到ADR2
CJEJL		MACRO	REG1,@NUM,ADR1,ADR2
		MOV	A,@NUM
		SUB	A,REG1
		JBC	STATUS,Z
		JMP	ADR1
		JBS	STATUS,C
		JMP	ADR2
		ENDM
;*********************************

;*********************************
;当(REG1&LITERAL)=0，则跳转ADR
CNBJZ		MACRO	REG1,@LITERAL,ADR
		MOV	A,REG1
		AND	A,@LITERAL
		JBC	STATUS,Z
		JMP	ADR
		ENDM
;*********************************

;*********************************
;当(REG1&LITERAL)!=0，则跳转ADR
CNBJNZ		MACRO	REG1,@LITERAL,ADR
		MOV	A,REG1
		AND	A,@LITERAL
		JBS	STATUS,Z
		JMP	ADR
		ENDM
;*********************************

;*********************************
;当(REG1&LITERAL)>NUM，则跳转ADR
CNBJG		MACRO	REG1,@NUM,@LITERAL,ADR
		MOV	A,REG1
		AND	A,@LITERAL
		SUB	A,@NUM
		JBS	STATUS,C
		JMP	ADR
		ENDM
;*********************************

;*********************************
;当(REG1&LITERAL)<=NUM，则跳转ADR
CNBJLE		MACRO	REG1,@NUM,@LITERAL,ADR
		MOV	A,REG1
		AND	A,@LITERAL
		SUB	A,@NUM
		JBC	STATUS,C
		JMP	ADR
		ENDM
;*********************************

;*********************************
;当(REG1&LITERAL)=NUM，则跳转ADR
CNBJE		MACRO	REG1,@NUM,@LITERAL,ADR
		MOV	A,REG1
		AND	A,@LITERAL
		SUB	A,@NUM
		JBC	STATUS,Z
		JMP	ADR
		ENDM
;*********************************

;*********************************
;当(REG1&LITERAL)!=NUM，则跳转ADR
CNBJNE		MACRO	REG1,@NUM,@LITERAL,ADR
		MOV	A,REG1
		AND	A,@LITERAL
		SUB	A,@NUM
		JBS	STATUS,Z
		JMP	ADR
		ENDM
;*********************************

;*********************************
;当LITE1 =< REG <= LITE2时，跳转到ADR
CJIN		MACRO	REG,@LITE1,@LITE2,ADR
		MOV	A,REG
		ADD	A,@255-LITE2
		ADD	A,@LITE2-LITE1+1
		JBC	STATUS,C
		JMP	ADR
		ENDM
;*********************************

;*********************************
;当REG > LITE2且REG < LITE1时，跳转到ADR
CJOUT		MACRO	REG,@LITE1,@LITE2,ADR
		MOV	A,REG
		ADD	A,@255-LITE2
		ADD	A,@LITE2-LITE1+1
		JBS	STATUS,C
		JMP	ADR
		ENDM
;*********************************

;*********************************
;寄存器减1后，不等于0则跳转ADR
DJNZ		MACRO	REG,ADR
		DJZ	REG
		JMP	ADR
		ENDM
;*********************************

;*********************************
;左移位
ALLRLC		MACRO	REG1,REG2
		RLC	REG2
		RLC	REG1
		ENDM
;*********************************

;*********************************
;左移位
ALLRLC		MACRO	REG1,REG2,REG3
		RLC	REG3
		RLC	REG2
		RLC	REG1
		ENDM
;*********************************

;*********************************
;左移位
ALLRLC		MACRO	REG1,REG2,REG3,REG4
		RLC	REG4
		RLC	REG3
		RLC	REG2
		RLC	REG1
		ENDM
;*********************************

;*********************************
;右移位
ALLRRC		MACRO	REG1,REG2
		RRC	REG1
		RRC	REG2
		ENDM
;*********************************

;*********************************
;右移位
ALLRRC		MACRO	REG1,REG2,REG3
		RRC	REG1
		RRC	REG2
		RRC	REG3
		ENDM
;*********************************

;*********************************
;右移位
ALLRRC		MACRO	REG1,REG2,REG3,REG4
		RRC	REG1
		RRC	REG2
		RRC	REG3
		RRC	REG4
		ENDM
;*********************************

;*********************************
;清空寄存器
ALLCLR		MACRO	REG1,REG2
		CLR	REG1
		CLR	REG2
		ENDM
;*********************************

;*********************************
;清空寄存器
ALLCLR		MACRO	REG1,REG2,REG3
		CLR	REG1
		CLR	REG2
		CLR	REG3
		ENDM
;*********************************

;*********************************
;清空寄存器
ALLCLR		MACRO	REG1,REG2,REG3,REG4
		CLR	REG1
		CLR	REG2
		CLR	REG3
		CLR	REG4
		ENDM
;*********************************

;*********************************
;BCD码加1
BCDINC		MACRO	REG
		MOV	A,@1
		ADD	A,REG
		DAA
		MOV	REG,A
		ENDM
;*********************************

;*********************************
;BCD码减1
BCDDEC		MACRO	REG
		MOV	A,@0x99
		ADD	A,REG
		DAA
		MOV	REG,A
		ENDM
;*********************************

;*********************************
;BCD码加法
BCDADD		MACRO	REG,@NUM
		MOV	A,@NUM
		ADD	A,REG
		DAA
		MOV	REG,A
		ENDM
;*********************************

;*********************************
;BCD码加法
BCDSUB		MACRO	REG,@NUM
		MOV	A,@0x9A-NUM
		ADD	A,REG
		DAA
		MOV	REG,A
		ENDM
;*********************************

;*********************************
;寄存器位取反
COM		MACRO	REG,NUM
			XOR	REG,@(0x01<<NUM)
		ENDM
;*********************************

;*********************************
;特殊寄存器页面选择
RPAGE	MACRO	num
		IF	num == 0
		      BC	FSR,7
		elseif	num == 1
		      BS	FSR,7
		ELSE
		      message "Warning: num of rpage is not exit"
		ENDIF
		ENDM
;*********************************

;*********************************
;ioc寄存器页面选择
IPAGE	MACRO	num
		IF	num == 0
		      BC	STATUS,IOCS
		elseif	num == 1
		      BS	STATUS,IOCS
		ELSE
		      message "Warning: num of iocpage is not exit"
		ENDIF
		ENDM
;*********************************
