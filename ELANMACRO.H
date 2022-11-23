/*
 * vim:syntax=elan
 */

;��¡���ָ��궨��

;*********************************
;���������ݸ�IOC�Ĵ���
IOW		MACRO	REG1,@NUM
		MOV	A,@NUM
		IOW	REG1
		ENDM
;*********************************

;*********************************
;�Ĵ���REG2ֵ���ݸ�REG1
MOV		MACRO	REG1,REG2
		MOV	A,REG2
		MOV	REG1,A
		ENDM
;*********************************

;*********************************
;�Ĵ���REG3REG4ֵ���ݸ�REG1REG2
FMOV		MACRO	REG1,REG2,REG3,REG4
		MOV	A,REG3
		MOV	REG1,A
		MOV	A,REG4
		MOV	REG2,A
		ENDM
;*********************************

;*********************************
;���������ݸ��Ĵ���REG1
MOV		MACRO	REG1,@NUM
		MOV	A,@NUM
		MOV	REG1,A
		ENDM
;*********************************

;*********************************
;���������ݸ��Ĵ���REG2REG1
FMOV		MACRO	REG2,REG1,@NUMH,@NUML
		MOV	A,@NUMH
		MOV	REG2,A
		MOV	A,@NUML
		MOV	REG1,A
		ENDM
;*********************************

;*********************************
;��λԪ���ƣ���REG2�ж�ӦLITERAL��=1��λ���Ƶ�REG1����Ӧ��λ��
MOVNB		MACRO	REG1,REG2,@LITERAL
		MOV	A,REG2
		XOR	A,REG1
		AND	A,@LITERAL
		XOR	REG1,A
		ENDM
;*********************************

;*********************************
;��λԪ���ƣ���NUM�ж�ӦLITERAL��=1��λ���Ƶ�REG1����Ӧ��λ��
MOVNB		MACRO	REG1,@NUM,@LITERAL
		MOV	A,@NUM
		XOR	A,REG1
		AND	A,@LITERAL
		XOR	REG1,A
		ENDM
;*********************************

;*********************************
;�Ĵ���REG2��REG1��ֵ������REG1��
OR		MACRO	REG1,REG2
		MOV	A,REG2
		OR	REG1,A
		ENDM
;*********************************

;*********************************
;�Ĵ���NUM��REG1��ֵ������REG1��
OR		MACRO	REG1,@NUM
		MOV	A,@NUM
		OR	REG1,A
		ENDM
;*********************************

;*********************************
;�Ĵ���NUM��REG1���ֵ������REG1��
XOR		MACRO	REG1,@NUM
		MOV	A,@NUM
		XOR	REG1,A
		ENDM
;*********************************

;*********************************
;�Ĵ���REG2��REG1�룬ֵ������REG1��
AND		MACRO	REG1,REG2
		MOV	A,REG2
		AND	REG1,A
		ENDM
;*********************************

;*********************************
;��������Ĵ���REG1�룬ֵ���ڼĴ�����
AND		MACRO	REG1,@NUM
		MOV	A,@NUM
		AND	REG1,A
		ENDM
;*********************************

;*********************************
;�Ĵ���REG2��REG1��ӣ�ֵ����REG1��
ADD		MACRO	REG1,REG2
		MOV	A,REG2
		ADD	REG1,A
		ENDM
;*********************************

;*********************************
;��������Ĵ���REG1��ӣ�ֵ����REG1��
ADD		MACRO	REG1,@NUM
		MOV	A,@NUM
		ADD	REG1,A
		ENDM
;*********************************

;*********************************
;�Ĵ���REG2��REG1���(����λ��־)��ֵ����REG1��
ADDC	MACRO	REG1,REG2
		MOV	A,REG2
		JBC	STATUS,C
		JZA	REG2
		ADD	REG1,A
		ENDM
;*********************************

;�Ĵ���REG1��������(����λ��־)��ֵ����REG1��
ADDC	MACRO	REG1,@NUM
		MOV	A,@NUM
		JBC	STATUS,C
		JZ	REG1
		ADD	REG1,A
		ENDM

;*********************************
;*********************************
;�Ĵ���REG1��ȥREG2��ֵ����REG1��
SUB		MACRO	REG1,REG2
		MOV	A,REG2
		SUB	REG1,A
		ENDM
;*********************************

;*********************************
;�Ĵ���REG1��ȥ��������ֵ����REG1��
SUB		MACRO	REG1,@NUM
		MOV	A,@NUM
		SUB	REG1,A
		ENDM
;*********************************

;*********************************
;�Ĵ���REG1��ȥREG2(����λ��־)��ֵ����REG1��
SUBC		MACRO	REG1,REG2
		MOV	A,REG2
		JBS	STATUS,C
		JZA	REG2
		SUB	REG1,A
		ENDM
;*********************************

;*********************************
;ĳλ����0����ת����Ӧ�ĵ�ַADR
CJBC		MACRO	REG,BIT,ADR
		JBS	REG,BIT
		JMP	ADR
		ENDM
;*********************************

;*********************************
;ĳλ����1����ת����Ӧ�ĵ�ַADR
CJBS		MACRO	REG,BIT,ADR
		JBC	REG,BIT
		JMP	ADR
		ENDM
;*********************************

;*********************************
;ĳλ����0����ת����Ӧ�ĵ�ַADR
CJBC		MACRO	REGBIT,ADR
		JBS	REGBIT
		JMP	ADR
		ENDM
;*********************************

;*********************************
;ĳλ����1����ת����Ӧ�ĵ�ַADR
CJBS		MACRO	REGBIT,ADR
		JBC	REGBIT
		JMP	ADR
		ENDM
;*********************************

;*********************************
;��REG1>=REG2������ת��ADR
CJGE		MACRO	REG1,REG2,ADR
		MOV	A,REG2
		SUB	A,REG1
		JBC	STATUS,C
		JMP	ADR
		ENDM
;*********************************

;*********************************
;��REG1>=NUM������ת��ADR
CJGE		MACRO	REG1,@NUM,ADR
		MOV	A,@NUM
		SUB	A,REG1
		JBC	STATUS,C
		JMP	ADR
		ENDM
;*********************************

;*********************************
;��REG1>REG2������ת��ADR
CJG		MACRO	REG1,REG2,ADR
		MOV	A,REG1
		SUB	A,REG2
		JBS	STATUS,C
		JMP	ADR
		ENDM
;*********************************


;*********************************
;��REG1>NUM������ת��ADR
CJG		MACRO	REG1,@NUM,ADR
		MOV	A,REG1
		SUB	A,@NUM
		JBS	STATUS,C
		JMP	ADR
		ENDM
;*********************************
;*********************************
;��REG2REG1>@NUMHNUML������ת��ADR
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
;��REG1<=REG2������ת��ADR
CJLE		MACRO	REG1,REG2,ADR
		MOV	A,REG1
		SUB	A,REG2
		JBC	STATUS,C
		JMP	ADR
		ENDM
;*********************************

;*********************************
;��REG1<=NUM������ת��ADR
CJLE		MACRO	REG1,@NUM,ADR
		MOV	A,REG1
		SUB	A,@NUM
		JBC	STATUS,C
		JMP	ADR
		ENDM
;*********************************

;*********************************
;��REG1<REG2������ת��ADR
CJL		MACRO	REG1,REG2,ADR
		MOV	A,REG2
		SUB	A,REG1
		JBS	STATUS,C
		JMP	ADR
		ENDM
;*********************************

;*********************************
;��REG1<NUM������ת��ADR
CJL		MACRO	REG1,@NUM,ADR
		MOV	A,@NUM
		SUB	A,REG1
		JBS	STATUS,C
		JMP	ADR
		ENDM
;*********************************

;*********************************
;��REG2REG1<@NUMHNUML������ת��ADR
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
;��REG2REG1<REG4REG3������ת��ADR
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
;��REG4REG3REG2REG1<REG8REG7REG6REG5������ת��ADR
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
;��REG=0ʱ������ת��ADR
CJZ		MACRO	REG,ADR
		MOV	REG,REG
		JBC	STATUS,Z
		JMP	ADR
		ENDM
;*********************************

;*********************************
;��REG2REG1=0ʱ������ת��ADR
CJZ		MACRO	REG2,REG1,ADR
		MOV	A,REG1
		OR	A,REG2
		JBC	STATUS,Z
		JMP	ADR
		ENDM
;*********************************

;*********************************
;��REG3REG2REG1=0ʱ������ת��ADR
CJZ		MACRO	REG3,REG2,REG1,ADR
		MOV	A,REG1
		OR	A,REG2
		OR	A,REG3
		JBC	STATUS,Z
		JMP	ADR
		ENDM
;*********************************

;*********************************
;��REG4REG3REG2REG1=0ʱ������ת��ADR
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
;��REG!=0ʱ������ת��ADR
CJNZ		MACRO	REG,ADR
		MOV	REG,REG
		JBS	STATUS,Z
		JMP	ADR
		ENDM
;*********************************

;*********************************
;��REG2REG1!=0ʱ������ת��ADR
CJNZ		MACRO	REG2,REG1,ADR
		MOV	A,REG1
		OR	A,REG2
		JBS	STATUS,Z
		JMP	ADR
		ENDM
;*********************************

;*********************************
;��REG3REG2REG1!=0ʱ������ת��ADR
CJNZ		MACRO	REG3,REG2,REG1,ADR
		MOV	A,REG1
		OR	A,REG2
		OR	A,REG3
		JBS	STATUS,Z
		JMP	ADR
		ENDM
;*********************************

;*********************************
;��REG4REG3REG2REG1!=0ʱ������ת��ADR
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
;��REG1=REG2������ת��ADR
CJE		MACRO	REG1,REG2,ADR
		MOV	A,REG2
		SUB	A,REG1
		JBC	STATUS,Z
		JMP	ADR
		ENDM
;*********************************

;*********************************
;��REG2REG1=REG4REG3������ת��ADR
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
;��REG1=NUM������ת��ADR
CJE		MACRO	REG1,@NUM,ADR
		MOV	A,@NUM
		SUB	A,REG1
		JBC	STATUS,Z
		JMP	ADR
		ENDM
;*********************************

;*********************************
;��REG2REG1=@NUMHNUML������ת��ADR
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
;��REG1!=REG2������ת��ADR
CJNE		MACRO	REG1,REG2,ADR
		MOV	A,REG2
		SUB	A,REG1
		JBS	STATUS,Z
		JMP	ADR
		ENDM
;*********************************

;*********************************
;��REG2REG1!=REG4REG3������ת��ADR
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
;��REG1!=NUM������ת��ADR
CJNE		MACRO	REG1,@NUM,ADR
		MOV	A,@NUM
		SUB	A,REG1
		JBS	STATUS,Z
		JMP	ADR
		ENDM
;*********************************

;*********************************
;��REG2REG1!=@NUMHNUML������ת��ADR
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
;��REG1<NUM������ת��ADR1
;��REG1>NUM������ת��ADR2
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
;��REG1<REG2������ת��ADR1
;��REG1>REG2������ת��ADR2
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
;��REG1=REG2������ת��ADR1
;��REG1<REG2������ת��ADR2
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
;��REG1=NUM������ת��ADR1
;��REG1<NUM������ת��ADR2
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
;��(REG1&LITERAL)=0������תADR
CNBJZ		MACRO	REG1,@LITERAL,ADR
		MOV	A,REG1
		AND	A,@LITERAL
		JBC	STATUS,Z
		JMP	ADR
		ENDM
;*********************************

;*********************************
;��(REG1&LITERAL)!=0������תADR
CNBJNZ		MACRO	REG1,@LITERAL,ADR
		MOV	A,REG1
		AND	A,@LITERAL
		JBS	STATUS,Z
		JMP	ADR
		ENDM
;*********************************

;*********************************
;��(REG1&LITERAL)>NUM������תADR
CNBJG		MACRO	REG1,@NUM,@LITERAL,ADR
		MOV	A,REG1
		AND	A,@LITERAL
		SUB	A,@NUM
		JBS	STATUS,C
		JMP	ADR
		ENDM
;*********************************

;*********************************
;��(REG1&LITERAL)<=NUM������תADR
CNBJLE		MACRO	REG1,@NUM,@LITERAL,ADR
		MOV	A,REG1
		AND	A,@LITERAL
		SUB	A,@NUM
		JBC	STATUS,C
		JMP	ADR
		ENDM
;*********************************

;*********************************
;��(REG1&LITERAL)=NUM������תADR
CNBJE		MACRO	REG1,@NUM,@LITERAL,ADR
		MOV	A,REG1
		AND	A,@LITERAL
		SUB	A,@NUM
		JBC	STATUS,Z
		JMP	ADR
		ENDM
;*********************************

;*********************************
;��(REG1&LITERAL)!=NUM������תADR
CNBJNE		MACRO	REG1,@NUM,@LITERAL,ADR
		MOV	A,REG1
		AND	A,@LITERAL
		SUB	A,@NUM
		JBS	STATUS,Z
		JMP	ADR
		ENDM
;*********************************

;*********************************
;��LITE1 =< REG <= LITE2ʱ����ת��ADR
CJIN		MACRO	REG,@LITE1,@LITE2,ADR
		MOV	A,REG
		ADD	A,@255-LITE2
		ADD	A,@LITE2-LITE1+1
		JBC	STATUS,C
		JMP	ADR
		ENDM
;*********************************

;*********************************
;��REG > LITE2��REG < LITE1ʱ����ת��ADR
CJOUT		MACRO	REG,@LITE1,@LITE2,ADR
		MOV	A,REG
		ADD	A,@255-LITE2
		ADD	A,@LITE2-LITE1+1
		JBS	STATUS,C
		JMP	ADR
		ENDM
;*********************************

;*********************************
;�Ĵ�����1�󣬲�����0����תADR
DJNZ		MACRO	REG,ADR
		DJZ	REG
		JMP	ADR
		ENDM
;*********************************

;*********************************
;����λ
ALLRLC		MACRO	REG1,REG2
		RLC	REG2
		RLC	REG1
		ENDM
;*********************************

;*********************************
;����λ
ALLRLC		MACRO	REG1,REG2,REG3
		RLC	REG3
		RLC	REG2
		RLC	REG1
		ENDM
;*********************************

;*********************************
;����λ
ALLRLC		MACRO	REG1,REG2,REG3,REG4
		RLC	REG4
		RLC	REG3
		RLC	REG2
		RLC	REG1
		ENDM
;*********************************

;*********************************
;����λ
ALLRRC		MACRO	REG1,REG2
		RRC	REG1
		RRC	REG2
		ENDM
;*********************************

;*********************************
;����λ
ALLRRC		MACRO	REG1,REG2,REG3
		RRC	REG1
		RRC	REG2
		RRC	REG3
		ENDM
;*********************************

;*********************************
;����λ
ALLRRC		MACRO	REG1,REG2,REG3,REG4
		RRC	REG1
		RRC	REG2
		RRC	REG3
		RRC	REG4
		ENDM
;*********************************

;*********************************
;��ռĴ���
ALLCLR		MACRO	REG1,REG2
		CLR	REG1
		CLR	REG2
		ENDM
;*********************************

;*********************************
;��ռĴ���
ALLCLR		MACRO	REG1,REG2,REG3
		CLR	REG1
		CLR	REG2
		CLR	REG3
		ENDM
;*********************************

;*********************************
;��ռĴ���
ALLCLR		MACRO	REG1,REG2,REG3,REG4
		CLR	REG1
		CLR	REG2
		CLR	REG3
		CLR	REG4
		ENDM
;*********************************

;*********************************
;BCD���1
BCDINC		MACRO	REG
		MOV	A,@1
		ADD	A,REG
		DAA
		MOV	REG,A
		ENDM
;*********************************

;*********************************
;BCD���1
BCDDEC		MACRO	REG
		MOV	A,@0x99
		ADD	A,REG
		DAA
		MOV	REG,A
		ENDM
;*********************************

;*********************************
;BCD��ӷ�
BCDADD		MACRO	REG,@NUM
		MOV	A,@NUM
		ADD	A,REG
		DAA
		MOV	REG,A
		ENDM
;*********************************

;*********************************
;BCD��ӷ�
BCDSUB		MACRO	REG,@NUM
		MOV	A,@0x9A-NUM
		ADD	A,REG
		DAA
		MOV	REG,A
		ENDM
;*********************************

;*********************************
;�Ĵ���λȡ��
COM		MACRO	REG,NUM
			XOR	REG,@(0x01<<NUM)
		ENDM
;*********************************

;*********************************
;����Ĵ���ҳ��ѡ��
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
;ioc�Ĵ���ҳ��ѡ��
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