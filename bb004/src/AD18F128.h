//*************************************************************************************
//#Project  :AD18F128
//#Version  :v1
//#DATE     :20221107
//-------------------------change list-------------------------------------------------
//===============================================================================
//--Version.----------------Content---------------------------------------------Who---
//============================================================
//|-0-| ...

#ifndef	__AD18F128_H
#define	__AD18F128_H

#define _XTAL_FREQ 16000000
#pragma intrinsic(_delay)
extern __nonreentrant void _delay(unsigned long);
#define __delay_us(x) _delay((unsigned long)((x)*(_XTAL_FREQ/4000000.0)))
#define __delay_ms(x) _delay((unsigned long)((x)*(_XTAL_FREQ/4000.0)))
//配置SLEEP -------------------------------------------------------------
#define SLEEP_PWIDLE()      CLKCFG1&=0X3F;CLKCFG2=0X00;SMCR = 0X01; SLEEP();NOP()
#define SLEEP_PWSAVE()      SMCR = 0X03; SLEEP();NOP()
#define SLEEP_DEEPPWSAVE()  SMCR = 0X05; SLEEP();NOP()
#define SLEEP_PWOFF()       SMCR = 0X07; SLEEP();NOP()
//-----------------------------MAP_DEFINE-------------------------------
//IO映射相关宏定义
#define IO_A 0
#define IO_B 1
#define IO_C 2
#define IO_D 3

#define PIN0 0
#define PIN1 1
#define PIN2 2
#define PIN3 3
#define PIN4 4
#define PIN5 5

#define MAP_PA0 ((IO_A<<3)|PIN0)
#define MAP_PA1 ((IO_A<<3)|PIN1)
#define MAP_PA2 ((IO_A<<3)|PIN2)
#define MAP_PA3 ((IO_A<<3)|PIN3)
#define MAP_PA4 ((IO_A<<3)|PIN4)
#define MAP_PA5 ((IO_A<<3)|PIN5)

#define MAP_PB0 (IO_B<<3)|PIN0
#define MAP_PB1 (IO_B<<3)|PIN1
#define MAP_PB2 (IO_B<<3)|PIN2
#define MAP_PB3 (IO_B<<3)|PIN3
#define MAP_PB4 (IO_B<<3)|PIN4
#define MAP_PB5 (IO_B<<3)|PIN5

#define MAP_PC0 (IO_C<<3)|PIN0
#define MAP_PC1 (IO_C<<3)|PIN1
#define MAP_PC2 (IO_C<<3)|PIN2
#define MAP_PC3 (IO_C<<3)|PIN3
#define MAP_PC4 (IO_C<<3)|PIN4
#define MAP_PC5 (IO_C<<3)|PIN5

#define MAP_PD0 (IO_D<<3)|PIN0
#define MAP_PD1 (IO_D<<3)|PIN1
#define MAP_PD2 (IO_D<<3)|PIN2
#define MAP_PD3 (IO_D<<3)|PIN3


//-----------------------------------CONCFG------------------------------
/*
__CONFIG(1,_FINTOSC_DIV1_1L     & _LVREN_ON_1L       & _LVT20V_1L                                                                                              );
__CONFIG(2,_FLASH_CP7_OFF_2L    & _FLASH_CP6_OFF_2L  & _FLASH_CP5_OFF_2L  & _FLASH_CP4_OFF_2L   & _FLASH_CP3_OFF_2L & _FLASH_CP2_OFF_2L  & _FLASH_CP1_OFF_2L  &_FLASH_CP0_OFF_2L
            &_CRYLEN_OFF_2L     & _CRYHEN_OFF_2L     & _IDIS_OFF_2L       & _CKSUM_OFF_2L      & _CBP_OFF_2L     & _RESETE_OFF_2L & _RSEL_LOW_2L & _STV_ON_2L  );
__CONFIG(3,_PSUT_1_3L           & _FCPU_4T_3L        & _WDTEN_OFF_3L      & _TWDT_000_3L                                                                       );
__CONFIG(4,_OSCM_HIRC_16M_4L    & _DBG_OFF_4L        & _ENVDDL_OFF_4L     & _BBP_OFF_4L       & _FCMEN_OFF_4L     & _IESO_OFF_4L      & _MAPEN_ON_4L                               );
*/


//STACK Register Define;
static volatile  unsigned char 				 TOSU				@0XFFF;
static volatile  unsigned char 				 TOSH				@0XFFE;
static volatile  unsigned char 				 TOSL				@0XFFD;
static volatile  unsigned char  			 STKPTR				@0XFFC;

//PC Register Define;
static volatile  unsigned char  			 PCLATU				@0XFFB;
static volatile  unsigned char  			 PCLATH				@0XFFA;
static volatile  unsigned char  			 PCL				@0XFF9;

//TBLPTR Register Define;
static volatile  unsigned char   			 TBLPTRU			@0XFF8;
static volatile  unsigned char   			 TBLPTRH			@0XFF7;
static volatile  unsigned char   			 TBLPTRL			@0XFF6;
static volatile  unsigned char 				 TABLAT				@0XFF5;

static volatile  unsigned char 				 PRODH				@0XFF4;
static volatile  unsigned char 				 PRODL				@0XFF3;

static volatile  unsigned char 				 INTCON				@0XFF2;
static volatile  unsigned char 				 PCON   			@0XFF1;

//arrye one;
static volatile  unsigned char 				 INDF				@0XFEF;
static volatile  unsigned char 				 POSTINC0           @0XFEE;
static volatile  unsigned char 				 POSTDEC0           @0XFED;
static volatile  unsigned char 				 PREINC0            @0XFEC;
static volatile  unsigned char 				 PLUSW0				@0XFEB;
static volatile  unsigned char 				 FSR0H				@0XFEA;
static volatile  unsigned char 				 FSR0L				@0XFE9;
static volatile  unsigned char 				 WREG				@0XFE8;

//arrye second;
static volatile  unsigned char 				 INDF1              @0XFE7;
static volatile  unsigned char 				 POSTINC1           @0XFE6;
static volatile  unsigned char 				 POSTDEC1           @0XFE5;
static volatile  unsigned char 				 PREINC1            @0XFE4;
static volatile  unsigned char 				 PLUSW1				@0XFE3;
static volatile  unsigned char 				 FSR1H				@0XFE2;
static volatile  unsigned char 				 FSR1L				@0XFE1;
static volatile  unsigned char 				 BSR                @0XFE0;

//arrye third;
static volatile  unsigned char 				 INDF2				@0XFDF;
static volatile  unsigned char 				 POSTINC2           @0XFDE;
static volatile  unsigned char				 POSTDEC2           @0XFDD;
static volatile  unsigned char				 PREINC2            @0XFDC;
static volatile  unsigned char 				 PLUSW2				@0XFDB;
static volatile  unsigned char 				 FSR2H				@0XFDA;
static volatile  unsigned char				 FSR2L				@0XFD9;
static volatile  unsigned char               STATUS				@0XFD8;
//------------------------------TMR0-----------------------------------------
static volatile  unsigned char 				 T0CON				@0XFD7;
static volatile  unsigned char 				 PR0				@0XFD6;
static volatile  unsigned char 				 TMR0				@0XFD5;
static volatile  unsigned char 				 PWM0DUTY			@0XFD4;
static volatile  unsigned char 				 PWM0CON	    	@0XFD3;
static volatile  unsigned char 				 RCON 				@0XFD2;
//-----------------------------TMR1----------------------------------------------
static volatile  unsigned char               TMR1H				@0XFD1;
static volatile  unsigned char 				 TMR1L				@0XFD0;
static volatile  unsigned char 				 T1CON0				@0XFCF;
static volatile  unsigned char 				 T1CON1 			@0XFCE;
//-----------------------------TMR2----------------------------------------------
static volatile  unsigned char 				 TMR2L				@0XFCD;
static volatile  unsigned char 				 TMR2H				@0XFCC;
static volatile  unsigned char  			 PR2L				@0XFCB;
static volatile  unsigned char  			 PR2H				@0XFCA;
static volatile  unsigned char  			 T2CON  		   	@0XFC9;
//-----------------------------CCP----------------------------------------------
static volatile  unsigned char  			 CCPR1H 	   		@0XFC8;
static volatile  unsigned char  			 CCPR1L 			@0XFC7;
static volatile  unsigned char  			 CCPR1LH			@0XFC6;
static volatile  unsigned char               PMS			    @0XFC5;
static volatile  unsigned char  			 PXC			    @0XFC4;
static volatile  unsigned char  			 DTC			    @0XFC3;
static volatile  unsigned char  			 POLS			    @0XFC2;
static volatile  unsigned char    			 PME			    @0XFC1;


static volatile  unsigned char    			 CCPCON			    @0XFBF;
static volatile  unsigned char    			 PWM1CON0			@0XFBE;
static volatile  unsigned char    			 PWM1CON1			@0XFBD;
//-----------------------------TMR3------------------------------------------
static volatile  unsigned char  			 T3CON			    @0XFBC;
static volatile  unsigned char 				 TMR3H              @0XFBB;
static volatile  unsigned char 				 TMR3L              @0XFBA;
static volatile  unsigned char  			 PR3H               @0XFB9;
static volatile  unsigned char  			 PR3L               @0XFB8;


//-----------------------------------PWM--------------------------------------
static volatile  unsigned char  			 PWM5H              @0XFB7;
static volatile  unsigned char				 PWM5L              @0XFB6;
static volatile  unsigned char				 PWM4H              @0XFB5;
static volatile  unsigned char				 PWM4L              @0XFB4;
static volatile  unsigned char				 PWM3H              @0XFB3;
static volatile  unsigned char				 PWM3L              @0XFB2;
static volatile  unsigned char				 PWM2H              @0XFB1;
static volatile  unsigned char				 PWM2L              @0XFB0;

static volatile  unsigned char				 PWM2CON0           @0XFAF;
static volatile  unsigned char				 PWM2CON1           @0XFAE;
static volatile  unsigned char 				 PWM2CON2           @0XFAD;
static volatile  unsigned char  			 PWM2CON3           @0XFAC;
//-----------------------------------ADC--------------------------------------
static volatile  unsigned char  			 ADCMP0H            @0XFAB;
static volatile  unsigned char  			 ADCMP1H			@0XFAA;
static volatile  unsigned char   			 ADCMP01L		   	@0XFA9;
static volatile  unsigned char				 ADRESH		   	    @0XFA8;
static volatile  unsigned char				 ADRESL		   	    @0XFA7;
static volatile  unsigned char  			 ADCON0		   	    @0XFA6;
static volatile  unsigned char  			 ADCON1		   	    @0XFA5;

//-----------------------------------INT--------------------------------------
static volatile  unsigned char  			 IPR1		   	    @0XFA3;
static volatile  unsigned char               PIR1		   	    @0XFA2;
static volatile  unsigned char  			 PIE1		   	    @0XFA1;

static volatile  unsigned char  			 IPR2		   	    @0XFA0;
static volatile  unsigned char  			 PIR2		   	    @0XF9F;
static volatile  unsigned char  			 PIE2				@0XF9E;

static volatile  unsigned char               IPR3		   	    @0XF9D;
static volatile  unsigned char  			 PIR3				@0XF9C;
static volatile  unsigned char               PIE3		    	@0XF9B;



//----------------------------------GPIO----------------------------------

static volatile  unsigned char  			 SMTC		   	    @0XF9A;
static volatile  unsigned char  			 SMTB		   	    @0XF99;
static volatile  unsigned char				 SMTA		   	    @0XF98;

static volatile  unsigned char				 PDOD				@0XF97;
static volatile  unsigned char				 PCOD				@0XF96;
static volatile  unsigned char				 PBOD				@0XF95;
static volatile  unsigned char				 PAOD		   	    @0XF94;

static volatile  unsigned char				 TRISD				@0XF93;
static volatile  unsigned char				 TRISC				@0XF92;
static volatile  unsigned char				 TRISB				@0XF91;
static volatile  unsigned char				 TRISA				@0XF90;

static volatile  unsigned char				 PDPD		   	    @0XF8F;
static volatile  unsigned char				 PCPD		   	    @0XF8E;
static volatile  unsigned char				 PBPD				@0XF8D;
static volatile  unsigned char				 PAPD				@0XF8C;

static volatile  unsigned char				 PIND		   	    @0XF8B;
static volatile  unsigned char				 PINC		   	    @0XF8A;
static volatile  unsigned char				 PINB				@0XF89;
static volatile  unsigned char				 PINA		   	    @0XF88;

static volatile  unsigned char				 PDPU		   	    @0XF87;
static volatile  unsigned char				 PCPU		   	    @0XF86;
static volatile  unsigned char				 PBPU		   	    @0XF85;
static volatile  unsigned char				 PAPU				@0XF84;

static volatile  unsigned char				 PORTD		   	    @0XF83;
static volatile  unsigned char				 PORTC		   	    @0XF82;
static volatile  unsigned char				 PORTB		   	    @0XF81;
static volatile  unsigned char				 PORTA				@0XF80;

//----------------------------OP&CMP---------------------------------------
static volatile  unsigned char  			 CMP2CON0		   	@0XF7F;
static volatile  unsigned char  			 CMP2CON1		   	@0XF7E;
static volatile  unsigned char  			 CMPCON1		   	@0XF7D;
static volatile  unsigned char  			 OP1CON0		   	@0XF7C;
static volatile  unsigned char  			 OP1CON1		   	@0XF7B;
static volatile  unsigned char  			 OP1CON2		   	@0XF7A;
static volatile  unsigned char  			 OP1CON3		   	@0XF79;
static volatile  unsigned char  			 CMP0CON		   	@0XF78;
static volatile  unsigned char				 CMP1CON		   	@0XF77;
static volatile  unsigned char				 CMPCON				@0XF76;

//----------------------------DAC---------------------------------------
static volatile  unsigned char				 DACCON		   	    @0XF75;
static volatile  unsigned char				 DAC0CON			@0XF74;
static volatile  unsigned char				 DAC1CON			@0XF73;

static volatile  unsigned char				 FVRCON				@0XF72;
//-----------------------------LCD---------------------------------------
static volatile  unsigned char				 LCDCON0			@0XF71;
static volatile  unsigned char				 LCDCON1			@0XF70;
static volatile  unsigned char				 LCDCON2			@0XF6F;
static volatile  unsigned char				 LCDCON3		   	@0XF6E;

static volatile  unsigned char				 BUCON				@0XF6D;

static volatile  unsigned char				 IAPTRIG			@0XF6C;
static volatile  unsigned char				 IAPCTRL		   	@0XF6B;
static volatile  unsigned char				 IAPADDRH			@0XF6A;
static volatile  unsigned char				 IAPADDRL		   	@0XF69;
static volatile  unsigned char				 IAPDATH		   	@0XF68;
static volatile  unsigned char				 IAPDATL		   	@0XF67;
static volatile  unsigned char				 IAPWAIT		   	@0XF66;

static volatile  unsigned char				 SMCR		   	    @0XF65;
static volatile  unsigned char				 OSCCON 			@0XF64;
static volatile  unsigned char				 CLKCFG1			@0XF63;
static volatile  unsigned char				 CLKCFG2		   	@0XF62;
static volatile  unsigned char				 SIGCON 			@0XF61;

static volatile  unsigned char				 PAINTMASK			@0XF60;
static volatile  unsigned char				 PBINTMASK			@0XF5F;
static volatile  unsigned char				 PCINTMASK		   	@0XF5E;
static volatile  unsigned char				 PDINTMASK		   	@0XF5D;


static volatile  unsigned char				 EEDAT				@0XF5C;
static volatile  unsigned char				 EEADR		   	    @0XF5B;
static volatile  unsigned char				 EECON1		   	    @0XF5A;
static volatile  unsigned char				 EECON2		   	    @0XF59;

static volatile  unsigned char				 WDTCON		   	    @0XF58;
static volatile  unsigned char				 OP1CON4		   	@0XF56;
static volatile  unsigned char				 CURCON		   	    @0XF55;

static volatile  unsigned char				 ANASEL0		   	@0XF54;
static volatile  unsigned char				 ANASEL1		   	@0XF53;
static volatile  unsigned char				 ANASEL2		   	@0XF52;

static volatile  unsigned char				 SPBRG		   	    @0XF51;
static volatile  unsigned char				 RCREG		   	    @0XF50;
static volatile  unsigned char				 TXREG		   	    @0XF4F;
static volatile  unsigned char				 TXSTA		   	    @0XF4E;
static volatile  unsigned char				 RCSTA		   	    @0XF4D;
static volatile  unsigned char				 UARTCON		   	@0XF4C;

static volatile  unsigned char				 I2CACKDLY		   	@0XF4B;
static volatile  unsigned char				 I2CTX		   	    @0XF4A;
static volatile  unsigned char				 I2CRC		   	    @0XF49;
static volatile  unsigned char				 I2CADDR0		   	@0XF48;
static volatile  unsigned char				 I2CADDR1		   	@0XF47;
static volatile  unsigned char				 I2CADDMASK		   	@0XF46;
static volatile  unsigned char				 I2CSTAT		   	@0XF45;
static volatile  unsigned char				 I2CCON0		   	@0XF44;
static volatile  unsigned char				 I2CCON1		   	@0XF43;
static volatile  unsigned char				 I2CIE		   	    @0XF42;
static volatile  unsigned char				 I2CIF		   	    @0XF41;
static volatile  unsigned char				 I2CIP		   	    @0XF40;



static volatile  unsigned char				 TX0_MAP		   	@0XF3D;
static volatile  unsigned char				 RX0_MAP		   	@0XF3C;
static volatile  unsigned char				 SDA_MAP		   	@0XF3B;
static volatile  unsigned char				 SCL_MAP		   	@0XF3A;
static volatile  unsigned char				 PWM10_MAP		   	@0XF39;
static volatile  unsigned char				 PWM11_MAP		   	@0XF38;
static volatile  unsigned char				 PWM12_MAP		   	@0XF37;
static volatile  unsigned char				 PWM13_MAP		   	@0XF36;
static volatile  unsigned char				 PWM14_MAP		   	@0XF35;
static volatile  unsigned char				 PWM15_MAP		   	@0XF34;

static volatile  unsigned char				 CMP0CON2		   	@0XF33;
static volatile  unsigned char				 CMP1CON2		   	@0XF32;
static volatile  unsigned char				 CMP2CON2		   	@0XF31;


static volatile  unsigned char				 FVRCON1		   	@0XF30;
static volatile  unsigned char				 CRC32CON		   	@0XF2F;
static volatile  unsigned char				 CRC32IN		   	@0XF2E;
static volatile  unsigned char				 CRC32R0		   	@0XF2D;
static volatile  unsigned char				 CRC32R1		   	@0XF2C;
static volatile  unsigned char				 CRC32R2		   	@0XF2B;
static volatile  unsigned char				 CRC32R3		   	@0XF2A;
static volatile  unsigned char				 BMCRST		   	    @0XF29;
static volatile  unsigned char				 PDRCT		   	    @0XF28;
static volatile  unsigned char				 BMCRL		   	    @0XF27;
static volatile  unsigned char				 BMCRH		   	    @0XF26;
static volatile  unsigned char				 BMCR5T4		   	@0XF25;
static volatile  unsigned char				 PDTCT		   	    @0XF24;
static volatile  unsigned char				 BMCT4T5		   	@0XF23;
static volatile  unsigned char				 BMCTL		   	    @0XF22;
static volatile  unsigned char				 BMCTH		   	    @0XF21;
static volatile  unsigned char				 MCT0		   	    @0XF20;
static volatile  unsigned char				 MCPR0		   	    @0XF1F;
static volatile  unsigned char				 MCTCON		   	    @0XF1E;
static volatile  unsigned char				 CCRPCON0		   	@0XF1D;
static volatile  unsigned char				 CCRPCON1		   	@0XF1C;
static volatile  unsigned char				 BMCTX		   	    @0XF1B;

static volatile  unsigned char               IPR4		   	    @0XF1A;
static volatile  unsigned char  			 PIR4				@0XF19;
static volatile  unsigned char               PIE4		        @0XF18;

static volatile  unsigned char				 ADRESH1			@0XF17;
static volatile  unsigned char				 ADRESL1			@0XF16;
static volatile  unsigned char				 ADRESH2			@0XF15;
static volatile  unsigned char				 ADRESL2			@0XF14;
static volatile  unsigned char				 ADCON3			    @0XF13;
static volatile  unsigned char				 ADCON4			    @0XF12;
static volatile  unsigned char				 CMPDLY			    @0XF11;
static volatile  unsigned char				 CMPCON2			@0XF10;
static volatile  unsigned char				 CMPCON3			@0XF0F;
static volatile  unsigned char				 SMTD			    @0XF0E;
static volatile  unsigned char				 ANASEL3			@0XF0D;



//--------------------------------------------------------------------------
/* Definitions for STKPTR register */
static volatile  bit	STKFUL				           @ ((unsigned)&STKPTR*8)+7;
static volatile  bit	STKUNF			               @ ((unsigned)&STKPTR*8)+6;
static volatile  bit	SP4 			               @ ((unsigned)&STKPTR*8)+4;
static volatile  bit	SP3 			               @ ((unsigned)&STKPTR*8)+3;
static volatile  bit	SP2 			               @ ((unsigned)&STKPTR*8)+2;
static volatile  bit	SP1 			               @ ((unsigned)&STKPTR*8)+1;
static volatile  bit	SP0 			               @ ((unsigned)&STKPTR*8)+0;

/* Definitions for STATUS register */
static volatile  bit	N     			               @ ((unsigned)&STATUS*8)+5;
static volatile  bit	OV			                   @ ((unsigned)&STATUS*8)+4;
static volatile  bit	Z   			               @ ((unsigned)&STATUS*8)+3;
static volatile  bit	DC			                   @ ((unsigned)&STATUS*8)+1;
static volatile  bit	C   			               @ ((unsigned)&STATUS*8)+0;
/* Definitions for INTCON register */
static volatile   bit	PEIE			               @ ((unsigned)&INTCON*8)+6;
static volatile   bit	GIEL			               @ ((unsigned)&INTCON*8)+6;
static volatile   bit	GIE  			               @ ((unsigned)&INTCON*8)+7;
static volatile   bit	GIEH   			               @ ((unsigned)&INTCON*8)+7;
/* Definitions for RCON register */
static volatile  bit	IRFEN			               @ ((unsigned)&RCON*8)+7;
static volatile  bit	EMCEN			               @ ((unsigned)&RCON*8)+6;
static volatile  bit	RSTF1			               @ ((unsigned)&RCON*8)+5;
static volatile  bit	RSTF0			               @ ((unsigned)&RCON*8)+4;
static volatile  bit	TO			                   @ ((unsigned)&RCON*8)+3;
static volatile  bit	PD			                   @ ((unsigned)&RCON*8)+2;
static volatile  bit	POR			                   @ ((unsigned)&RCON*8)+1;
static volatile  bit	BOR			                   @ ((unsigned)&RCON*8)+0;

//-----------------------------------TIMER0-----------------------------------
/* Definitions for T0CON register */
static volatile  bit	T0OUT		                   @ ((unsigned)&T0CON*8)+7;
static volatile  bit	T0CS1		                   @ ((unsigned)&T0CON*8)+6;
static volatile  bit	T0CS0		                   @ ((unsigned)&T0CON*8)+5;
static volatile  bit	T0SE     	                   @ ((unsigned)&T0CON*8)+4;
static volatile  bit	PSA		                       @ ((unsigned)&T0CON*8)+3;
static volatile  bit	PS2		                       @ ((unsigned)&T0CON*8)+2;
static volatile  bit	PS1		                       @ ((unsigned)&T0CON*8)+1;
static volatile  bit	PS0		                       @ ((unsigned)&T0CON*8)+0;

/* Definitions for PWM0CON register */
static volatile  bit	POLS_03    	                   @ ((unsigned)&PWM0CON*8)+7;
static volatile  bit	POLS_02    	                   @ ((unsigned)&PWM0CON*8)+6;
static volatile  bit	POLS_01    	                   @ ((unsigned)&PWM0CON*8)+5;
static volatile  bit	POLS_00    	                   @ ((unsigned)&PWM0CON*8)+4;
static volatile  bit	PWM03EN		                   @ ((unsigned)&PWM0CON*8)+3;
static volatile  bit	PWM02EN		                   @ ((unsigned)&PWM0CON*8)+2;
static volatile  bit	PWM01EN		                   @ ((unsigned)&PWM0CON*8)+1;
static volatile  bit	PWM00EN		                   @ ((unsigned)&PWM0CON*8)+0;

/* Definitions for T1CON0 register */
static volatile  bit	T1CK1		                   @ ((unsigned)&T1CON0*8)+7;
static volatile  bit	T1CK0		                   @ ((unsigned)&T1CON0*8)+6;
static volatile  bit	T1CKPS1		                   @ ((unsigned)&T1CON0*8)+5;
static volatile  bit	T1CKPS0    	                   @ ((unsigned)&T1CON0*8)+4;
static volatile  bit	T1SE		                   @ ((unsigned)&T1CON0*8)+3;
static volatile  bit	T1SYNC		                   @ ((unsigned)&T1CON0*8)+2;
static volatile  bit	TMR1CS0		                   @ ((unsigned)&T1CON0*8)+1;
static volatile  bit	TMR1ON		                   @ ((unsigned)&T1CON0*8)+0;
/* Definitions for T1CON1 register */
static volatile  bit	INT2EDGE	                   @ ((unsigned)&T1CON1*8)+7;
static volatile  bit	INT1EDGE	                   @ ((unsigned)&T1CON1*8)+6;
static volatile  bit	INT0EDGE		               @ ((unsigned)&T1CON1*8)+5;
static volatile  bit	T1EDGE    	                   @ ((unsigned)&T1CON1*8)+4;
static volatile  bit	T1CH1		                   @ ((unsigned)&T1CON1*8)+3;
static volatile  bit	T1CH0		                   @ ((unsigned)&T1CON1*8)+2;
static volatile  bit	T1M1		                   @ ((unsigned)&T1CON1*8)+1;
static volatile  bit	T1M0		                   @ ((unsigned)&T1CON1*8)+0;
/* Definitions for T2CON register */
static volatile  bit	PWM2CAEN 	                   @ ((unsigned)&T2CON*8)+7;
static volatile  bit	T2OUTPS3	                   @ ((unsigned)&T2CON*8)+6;
static volatile  bit	T2OUTPS2	                   @ ((unsigned)&T2CON*8)+5;
static volatile  bit	T2OUTPS1	                   @ ((unsigned)&T2CON*8)+4;
static volatile  bit	T2OUTPS0	                   @ ((unsigned)&T2CON*8)+3;
static volatile  bit	TMR2ON		                   @ ((unsigned)&T2CON*8)+2;
static volatile  bit	T2CKPS1		                   @ ((unsigned)&T2CON*8)+1;
static volatile  bit	T2CKPS0		                   @ ((unsigned)&T2CON*8)+0;
/* Definitions for PMS register */
static volatile bit    DMISTK2                         @ ((unsigned)&PMS*8)+7;
static volatile bit    PWMH                            @ ((unsigned)&PMS*8)+6;
static volatile bit    PMS21                           @ ((unsigned)&PMS*8)+5;
static volatile bit    PMS20                           @ ((unsigned)&PMS*8)+4;
static volatile bit    PMS11                           @ ((unsigned)&PMS*8)+3;
static volatile bit    PMS10                           @ ((unsigned)&PMS*8)+2;
static volatile bit    PMS01                           @ ((unsigned)&PMS*8)+1;
static volatile bit    PMS00                           @ ((unsigned)&PMS*8)+0;
/* Definitions for PXC register */
static volatile bit    T3PWMEN                         @ ((unsigned)&PXC*8)+7;
static volatile bit    PWM14SEL                        @ ((unsigned)&PXC*8)+6;
static volatile bit    PXC21                           @ ((unsigned)&PXC*8)+5;
static volatile bit    PXC20                           @ ((unsigned)&PXC*8)+4;
static volatile bit    PXC11                           @ ((unsigned)&PXC*8)+3;
static volatile bit    PXC10                           @ ((unsigned)&PXC*8)+2;
static volatile bit    PXC01                           @ ((unsigned)&PXC*8)+1;
static volatile bit    PXC00                           @ ((unsigned)&PXC*8)+0;
/* Definitions for DTC register */
static volatile bit    DTCKS1                          @ ((unsigned)&DTC*8)+7;
static volatile bit    DTCKS0                          @ ((unsigned)&DTC*8)+6;
static volatile bit    DTEN                            @ ((unsigned)&DTC*8)+5;
static volatile bit    DTD4                            @ ((unsigned)&DTC*8)+4;
static volatile bit    DTD3                            @ ((unsigned)&DTC*8)+3;
static volatile bit    DTD2                            @ ((unsigned)&DTC*8)+2;
static volatile bit    DTD1                            @ ((unsigned)&DTC*8)+1;
static volatile bit    DTD0                            @ ((unsigned)&DTC*8)+0;
/* Definitions for POLS register */
static volatile bit    T3PWMMODE                       @ ((unsigned)&POLS*8)+7;
static volatile bit    PT2MODE                         @ ((unsigned)&POLS*8)+6;
static volatile bit    POLS15                          @ ((unsigned)&POLS*8)+5;
static volatile bit    POLS14                          @ ((unsigned)&POLS*8)+4;
static volatile bit    POLS13                          @ ((unsigned)&POLS*8)+3;
static volatile bit    POLS12                          @ ((unsigned)&POLS*8)+2;
static volatile bit    POLS11                          @ ((unsigned)&POLS*8)+1;
static volatile bit    POLS10                          @ ((unsigned)&POLS*8)+0;
/* Definitions for PME register */
static volatile bit    PT1MODE                         @ ((unsigned)&PME*8)+7;
static volatile bit    PT0MODE                         @ ((unsigned)&PME*8)+6;
static volatile bit    PWM15EN                         @ ((unsigned)&PME*8)+5;
static volatile bit    PWM14EN                         @ ((unsigned)&PME*8)+4;
static volatile bit    PWM13EN                         @ ((unsigned)&PME*8)+3;
static volatile bit    PWM12EN                         @ ((unsigned)&PME*8)+2;
static volatile bit    PWM11EN                         @ ((unsigned)&PME*8)+1;
static volatile bit    PWM10EN                         @ ((unsigned)&PME*8)+0;

//------------------------------------------------CCP---------------------------
/* Definitions for CCPCON register */
static volatile  bit	CCP1CH3		                   @ ((unsigned)&CCPCON*8)+7;
static volatile  bit	CCP1CH2		                   @ ((unsigned)&CCPCON*8)+6;
static volatile  bit	CCP1CH1		                   @ ((unsigned)&CCPCON*8)+5;
static volatile  bit	CCP1CH0		                   @ ((unsigned)&CCPCON*8)+4;
static volatile  bit	CCP1M3		                   @ ((unsigned)&CCPCON*8)+3;
static volatile  bit	CCP1M2		                   @ ((unsigned)&CCPCON*8)+2;
static volatile  bit	CCP1M1		                   @ ((unsigned)&CCPCON*8)+1;
static volatile  bit	CCP1M0		                   @ ((unsigned)&CCPCON*8)+0;
/* Definitions for PWM1CON0 register */
static volatile bit     PWMADPOS1                      @ ((unsigned)&PWM1CON0*8)+7;
static volatile bit     CMPFLT                         @ ((unsigned)&PWM1CON0*8)+6;
static volatile bit     ASTART                         @ ((unsigned)&PWM1CON0*8)+5;
static volatile bit     ACLOSE                         @ ((unsigned)&PWM1CON0*8)+4;
static volatile bit     OPFLT                          @ ((unsigned)&PWM1CON0*8)+3;
static volatile bit     IOFLT                          @ ((unsigned)&PWM1CON0*8)+2;
static volatile bit     PWMADPOS0                      @ ((unsigned)&PWM1CON0*8)+1;
static volatile bit     PWM10ADEN                      @ ((unsigned)&PWM1CON0*8)+0;
/* Definitions for T3CON register */
static volatile  bit	PWM3CAEN 	                   @ ((unsigned)&T3CON*8)+7;
static volatile  bit	T3OUTPS3	                   @ ((unsigned)&T3CON*8)+6;
static volatile  bit	T3OUTPS2	                   @ ((unsigned)&T3CON*8)+5;
static volatile  bit	T3OUTPS1	                   @ ((unsigned)&T3CON*8)+4;
static volatile  bit	T3OUTPS0	                   @ ((unsigned)&T3CON*8)+3;
static volatile  bit	TMR3ON		                   @ ((unsigned)&T3CON*8)+2;
static volatile  bit	T3CKPS1		                   @ ((unsigned)&T3CON*8)+1;
static volatile  bit	T3CKPS0		                   @ ((unsigned)&T3CON*8)+0;

/* Definitions for PWM2CON0 register */
static volatile bit     PWM5OEN                        @ ((unsigned)&PWM2CON0*8)+7;
static volatile bit     PWM4OEN                        @ ((unsigned)&PWM2CON0*8)+6;
static volatile bit     PWM3OEN                        @ ((unsigned)&PWM2CON0*8)+5;
static volatile bit     PWM2OEN                        @ ((unsigned)&PWM2CON0*8)+4;
static volatile bit     PWM5EN                         @ ((unsigned)&PWM2CON0*8)+3;
static volatile bit     PWM4EN                         @ ((unsigned)&PWM2CON0*8)+2;
static volatile bit     PWM3EN                         @ ((unsigned)&PWM2CON0*8)+1;
static volatile bit     PWM2EN                         @ ((unsigned)&PWM2CON0*8)+0;
/* Definitions for PWM2CON1 register */
static volatile bit     POLS5                          @ ((unsigned)&PWM2CON1*8)+3;
static volatile bit     POLS4                          @ ((unsigned)&PWM2CON1*8)+2;
static volatile bit     POLS3                          @ ((unsigned)&PWM2CON1*8)+1;
static volatile bit     POLS2                          @ ((unsigned)&PWM2CON1*8)+0;
/* Definitions for PWM2CON3 register */
static volatile bit     P5CS1                          @ ((unsigned)&PWM2CON3*8)+7;
static volatile bit     P5CS0                          @ ((unsigned)&PWM2CON3*8)+6;
static volatile bit     P4CS1                          @ ((unsigned)&PWM2CON3*8)+5;
static volatile bit     P4CS0                          @ ((unsigned)&PWM2CON3*8)+4;
static volatile bit     P3CS1                          @ ((unsigned)&PWM2CON3*8)+3;
static volatile bit     P3CS0                          @ ((unsigned)&PWM2CON3*8)+2;
static volatile bit     P2CS1                          @ ((unsigned)&PWM2CON3*8)+1;
static volatile bit     P2CS0                          @ ((unsigned)&PWM2CON3*8)+0;

/* Definitions for ADCON0 register */
static volatile bit     ADFM                           @ ((unsigned)&ADCON0*8)+7;
static volatile bit     ADCMPMODE                      @ ((unsigned)&ADCON0*8)+6;
static volatile bit     CHS3                           @ ((unsigned)&ADCON0*8)+5;
static volatile bit     CHS2                           @ ((unsigned)&ADCON0*8)+4;
static volatile bit     CHS1                           @ ((unsigned)&ADCON0*8)+3;
static volatile bit     CHS0                           @ ((unsigned)&ADCON0*8)+2;
static volatile bit     DONG                           @ ((unsigned)&ADCON0*8)+1;
static volatile bit     GO                             @ ((unsigned)&ADCON0*8)+1;
static volatile bit     ADON                           @ ((unsigned)&ADCON0*8)+0;
/* Definitions for ADCON1 register */
static volatile bit     ADVREF                         @ ((unsigned)&ADCON1*8)+7;
static volatile bit     ADCSP                          @ ((unsigned)&ADCON1*8)+6;
static volatile bit     ACQT2                          @ ((unsigned)&ADCON1*8)+5;
static volatile bit     ACQT1                          @ ((unsigned)&ADCON1*8)+4;
static volatile bit     ACQT0                          @ ((unsigned)&ADCON1*8)+3;
static volatile bit     ADCS2                          @ ((unsigned)&ADCON1*8)+2;
static volatile bit     ADCS1                          @ ((unsigned)&ADCON1*8)+1;
static volatile bit     ADCS0                          @ ((unsigned)&ADCON1*8)+0;

/* Definitions for ADCON3 register */
static volatile bit     AD1CH3                         @ ((unsigned)&ADCON3*8)+7;
static volatile bit     AD1CH2                         @ ((unsigned)&ADCON3*8)+6;
static volatile bit     AD1CH1                         @ ((unsigned)&ADCON3*8)+5;
static volatile bit     AD1CH0                         @ ((unsigned)&ADCON3*8)+4;
static volatile bit     ADCRPT1                        @ ((unsigned)&ADCON3*8)+3;
static volatile bit     ADCRPT0                        @ ((unsigned)&ADCON3*8)+2;
static volatile bit     AD2EN                          @ ((unsigned)&ADCON3*8)+1;
static volatile bit     AD1EN                          @ ((unsigned)&ADCON3*8)+0;

/* Definitions for ADCON4 register */
static volatile bit     AD2CH3                         @ ((unsigned)&ADCON4*8)+7;
static volatile bit     AD2CH2                         @ ((unsigned)&ADCON4*8)+6;
static volatile bit     AD2CH1                         @ ((unsigned)&ADCON4*8)+5;
static volatile bit     AD2CH0                         @ ((unsigned)&ADCON4*8)+4;
static volatile bit     ADPWMMODE1                     @ ((unsigned)&ADCON4*8)+3;
static volatile bit     ADPWMMODE0                     @ ((unsigned)&ADCON4*8)+2;
static volatile bit     ADPWMSEL1                      @ ((unsigned)&ADCON4*8)+1;
static volatile bit     ADPWMSEL0                      @ ((unsigned)&ADCON4*8)+0;

/* Definitions for PCON register */
static volatile bit     IPEN                           @ ((unsigned)&PCON*8)+7;
static volatile bit     PB0ST                          @ ((unsigned)&PCON*8)+6;
static volatile bit     LVDM1                          @ ((unsigned)&PCON*8)+5;
static volatile bit     LVDM0                          @ ((unsigned)&PCON*8)+4;
static volatile bit     LVT3                           @ ((unsigned)&PCON*8)+3;
static volatile bit     LVT2                           @ ((unsigned)&PCON*8)+2;
static volatile bit     LVT1                           @ ((unsigned)&PCON*8)+1;
static volatile bit     LVT0                           @ ((unsigned)&PCON*8)+0;
//-------------------------------------interrupt----------------------------------------
/* Definitions for IPR1 register */
static volatile  bit	PDIP		                   @ ((unsigned)&IPR1*8)+7;
static volatile  bit	RCIP		                   @ ((unsigned)&IPR1*8)+6;
static volatile  bit	TXIP		                   @ ((unsigned)&IPR1*8)+5;
static volatile  bit	CCPIP		                   @ ((unsigned)&IPR1*8)+4;
static volatile  bit	TMR3IP		                   @ ((unsigned)&IPR1*8)+3;
static volatile  bit	TMR2IP		                   @ ((unsigned)&IPR1*8)+2;
static volatile  bit	TMR1IP		                   @ ((unsigned)&IPR1*8)+1;
static volatile  bit	TMR0IP		                   @ ((unsigned)&IPR1*8)+0;

/* Definitions for PIR1 register */
static volatile  bit	PDIF		                   @ ((unsigned)&PIR1*8)+7;
static volatile  bit	RCIF		                   @ ((unsigned)&PIR1*8)+6;
static volatile  bit	TXIF		                   @ ((unsigned)&PIR1*8)+5;
static volatile  bit	CCPIF		                   @ ((unsigned)&PIR1*8)+4;
static volatile  bit	TMR3IF		                   @ ((unsigned)&PIR1*8)+3;
static volatile  bit	TMR2IF		                   @ ((unsigned)&PIR1*8)+2;
static volatile  bit	TMR1IF		                   @ ((unsigned)&PIR1*8)+1;
static volatile  bit	TMR0IF		                   @ ((unsigned)&PIR1*8)+0;

/* Definitions for PIE1 register */
static volatile  bit	PDIE		                   @ ((unsigned)&PIE1*8)+7;
static volatile  bit	RCIE		                   @ ((unsigned)&PIE1*8)+6;
static volatile  bit	TXIE		                   @ ((unsigned)&PIE1*8)+5;
static volatile  bit	CCPIE		                   @ ((unsigned)&PIE1*8)+4;
static volatile  bit	TMR3IE		                   @ ((unsigned)&PIE1*8)+3;
static volatile  bit	TMR2IE		                   @ ((unsigned)&PIE1*8)+2;
static volatile  bit	TMR1IE		                   @ ((unsigned)&PIE1*8)+1;
static volatile  bit	TMR0IE		                   @ ((unsigned)&PIE1*8)+0;

/* Definitions for IPR2 register */
static volatile  bit	PCIP		                   @ ((unsigned)&IPR2*8)+7;
static volatile  bit	PBIP		                   @ ((unsigned)&IPR2*8)+6;
static volatile  bit	PAIP		                   @ ((unsigned)&IPR2*8)+5;
static volatile  bit	INT2IP		                   @ ((unsigned)&IPR2*8)+4;
static volatile  bit	INT1IP		                   @ ((unsigned)&IPR2*8)+3;
static volatile  bit	INT0IP		                   @ ((unsigned)&IPR2*8)+2;
static volatile  bit	CMP1IP		                   @ ((unsigned)&IPR2*8)+1;
static volatile  bit	CMP0IP		                   @ ((unsigned)&IPR2*8)+0;
/* Definitions for PIR2 register */
static volatile  bit	PCIF		                   @ ((unsigned)&PIR2*8)+7;
static volatile  bit	PBIF		                   @ ((unsigned)&PIR2*8)+6;
static volatile  bit	PAIF		                   @ ((unsigned)&PIR2*8)+5;
static volatile  bit	INT2IF		                   @ ((unsigned)&PIR2*8)+4;
static volatile  bit	INT1IF		                   @ ((unsigned)&PIR2*8)+3;
static volatile  bit	INT0IF		                   @ ((unsigned)&PIR2*8)+2;
static volatile  bit	CMP1IF		                   @ ((unsigned)&PIR2*8)+1;
static volatile  bit	CMP0IF		                   @ ((unsigned)&PIR2*8)+0;
/* Definitions for PIE2 register */
static volatile  bit	PCIE		                   @ ((unsigned)&PIE2*8)+7;
static volatile  bit	PBIE		                   @ ((unsigned)&PIE2*8)+6;
static volatile  bit	PAIE		                   @ ((unsigned)&PIE2*8)+5;
static volatile  bit	INT2IE		                   @ ((unsigned)&PIE2*8)+4;
static volatile  bit	INT1IE		                   @ ((unsigned)&PIE2*8)+3;
static volatile  bit	INT0IE		                   @ ((unsigned)&PIE2*8)+2;
static volatile  bit	CMP1IE		                   @ ((unsigned)&PIE2*8)+1;
static volatile  bit	CMP0IE		                   @ ((unsigned)&PIE2*8)+0;

/* Definitions for IPR3 register */
static volatile  bit	ADCMP1IP		               @ ((unsigned)&IPR3*8)+7;
static volatile  bit	ADCMP0IP		               @ ((unsigned)&IPR3*8)+6;
static volatile  bit	ADIP		                   @ ((unsigned)&IPR3*8)+5;
static volatile  bit	OP1IP		                   @ ((unsigned)&IPR3*8)+4;
static volatile  bit	CMP2IP		                   @ ((unsigned)&IPR3*8)+3;
static volatile  bit	EEIP		                   @ ((unsigned)&IPR3*8)+2;
static volatile  bit	OSFIP		                   @ ((unsigned)&IPR3*8)+1;
static volatile  bit	LVDIP		                   @ ((unsigned)&IPR3*8)+0;
/* Definitions for PIR3 register */
static volatile  bit	ADCMP1IF		               @ ((unsigned)&PIR3*8)+7;
static volatile  bit	ADCMP0IF		               @ ((unsigned)&PIR3*8)+6;
static volatile  bit	ADIF		                   @ ((unsigned)&PIR3*8)+5;
static volatile  bit	OP1IF		                   @ ((unsigned)&PIR3*8)+4;
static volatile  bit	CMP2IF		                   @ ((unsigned)&PIR3*8)+3;
static volatile  bit	EEIF		                   @ ((unsigned)&PIR3*8)+2;
static volatile  bit	OSFIF		                   @ ((unsigned)&PIR3*8)+1;
static volatile  bit	LVDIF		                   @ ((unsigned)&PIR3*8)+0;

/* Definitions for PIE3 register */
static volatile  bit	ADCMP1IE		               @ ((unsigned)&PIE3*8)+7;
static volatile  bit	ADCMP0IE		               @ ((unsigned)&PIE3*8)+6;
static volatile  bit	ADIE		                   @ ((unsigned)&PIE3*8)+5;
static volatile  bit	OP1IE		                   @ ((unsigned)&PIE3*8)+4;
static volatile  bit	CMP2IE		                   @ ((unsigned)&PIE3*8)+3;
static volatile  bit	EEIE		                   @ ((unsigned)&PIE3*8)+2;
static volatile  bit	OSFIE		                   @ ((unsigned)&PIE3*8)+1;
static volatile  bit	LVDIE		                   @ ((unsigned)&PIE3*8)+0;


/* Definitions for IPR4 register */
static volatile  bit	ADBIP		                   @ ((unsigned)&IPR4*8)+2;
static volatile  bit	PDRCIP		                   @ ((unsigned)&IPR4*8)+1;
static volatile  bit	PDTXIP		                   @ ((unsigned)&IPR4*8)+0;
/* Definitions for PIR4 register */
static volatile  bit	ADBIF		                   @ ((unsigned)&PIR4*8)+2;
static volatile  bit	PDRCIF		                   @ ((unsigned)&PIR4*8)+1;
static volatile  bit	PDTXIF		                   @ ((unsigned)&PIR4*8)+0;

/* Definitions for PIE4 register */
static volatile  bit	ADBIE		                   @ ((unsigned)&PIE4*8)+2;
static volatile  bit	PDRCIE		                   @ ((unsigned)&PIE4*8)+1;
static volatile  bit	PDTXIE		                   @ ((unsigned)&PIE4*8)+0;
//--------------------------------------------------------------SMT--------------------------
/* Definitions for SMTA register */
static volatile  bit	PA5SMT		                   @ ((unsigned)&SMTA*8)+5;
static volatile  bit	PA4SMT		                   @ ((unsigned)&SMTA*8)+4;
static volatile  bit	PA3SMT		                   @ ((unsigned)&SMTA*8)+3;
static volatile  bit	PA2SMT		                   @ ((unsigned)&SMTA*8)+2;
static volatile  bit	PA1SMT		                   @ ((unsigned)&SMTA*8)+1;
static volatile  bit	PA0SMT		                   @ ((unsigned)&SMTA*8)+0;
/* Definitions for SMTB register */
static volatile  bit	PB5SMT		                   @ ((unsigned)&SMTB*8)+5;
static volatile  bit	PB4SMT		                   @ ((unsigned)&SMTB*8)+4;
static volatile  bit	PB3SMT		                   @ ((unsigned)&SMTB*8)+3;
static volatile  bit	PB2SMT		                   @ ((unsigned)&SMTB*8)+2;
static volatile  bit	PB1SMT		                   @ ((unsigned)&SMTB*8)+1;
static volatile  bit	PB0SMT		                   @ ((unsigned)&SMTB*8)+0;
/* Definitions for SMTC register */
static volatile  bit	PC5SMT		                   @ ((unsigned)&SMTC*8)+5;
static volatile  bit	PC4SMT		                   @ ((unsigned)&SMTC*8)+4;
static volatile  bit	PC3SMT		                   @ ((unsigned)&SMTC*8)+3;
static volatile  bit	PC2SMT		                   @ ((unsigned)&SMTC*8)+2;
static volatile  bit	PC1SMT		                   @ ((unsigned)&SMTC*8)+1;
static volatile  bit	PC0SMT		                   @ ((unsigned)&SMTC*8)+0;
/* Definitions for SMTD register */
static volatile  bit	PD3SMT		                   @ ((unsigned)&SMTD*8)+3;
static volatile  bit	PD2SMT		                   @ ((unsigned)&SMTD*8)+2;
static volatile  bit	PD1SMT		                   @ ((unsigned)&SMTD*8)+1;
static volatile  bit	PD0SMT		                   @ ((unsigned)&SMTD*8)+0;
/* Definitions for PDOD register */
static volatile  bit	PD3OD		                   @ ((unsigned)&PDOD*8)+3;
static volatile  bit	PD2OD		                   @ ((unsigned)&PDOD*8)+2;
static volatile  bit	PD1OD		                   @ ((unsigned)&PDOD*8)+1;
static volatile  bit	PD0OD		                   @ ((unsigned)&PDOD*8)+0;

/* Definitions for PCOD register */
static volatile  bit	PC5OD		                   @ ((unsigned)&PCOD*8)+5;
static volatile  bit	PC4OD		                   @ ((unsigned)&PCOD*8)+4;
static volatile  bit	PC3OD		                   @ ((unsigned)&PCOD*8)+3;
static volatile  bit	PC2OD		                   @ ((unsigned)&PCOD*8)+2;
static volatile  bit	PC1OD		                   @ ((unsigned)&PCOD*8)+1;
static volatile  bit	PC0OD		                   @ ((unsigned)&PCOD*8)+0;

/* Definitions for PBOD register */
static volatile  bit	PB5OD		                   @ ((unsigned)&PBOD*8)+5;
static volatile  bit	PB4OD		                   @ ((unsigned)&PBOD*8)+4;
static volatile  bit	PB3OD		                   @ ((unsigned)&PBOD*8)+3;
static volatile  bit	PB2OD		                   @ ((unsigned)&PBOD*8)+2;
static volatile  bit	PB1OD		                   @ ((unsigned)&PBOD*8)+1;
static volatile  bit	PB0OD		                   @ ((unsigned)&PBOD*8)+0;
/* Definitions for PAOD register */
static volatile  bit	PA5OD		                   @ ((unsigned)&PAOD*8)+5;
static volatile  bit	PA4OD		                   @ ((unsigned)&PAOD*8)+4;
static volatile  bit	PA3OD		                   @ ((unsigned)&PAOD*8)+3;
static volatile  bit	PA2OD		                   @ ((unsigned)&PAOD*8)+2;
static volatile  bit	PA1OD		                   @ ((unsigned)&PAOD*8)+1;
static volatile  bit	PA0OD		                   @ ((unsigned)&PAOD*8)+0;

 /* Definitions for TRISA register */
static volatile  bit	TRISA5		                   @ ((unsigned)&TRISA*8)+5;
static volatile  bit	TRISA4		                   @ ((unsigned)&TRISA*8)+4;
static volatile  bit	TRISA3		                   @ ((unsigned)&TRISA*8)+3;
static volatile  bit	TRISA2		                   @ ((unsigned)&TRISA*8)+2;
static volatile  bit	TRISA1		                   @ ((unsigned)&TRISA*8)+1;
static volatile  bit	TRISA0		                   @ ((unsigned)&TRISA*8)+0;

/* Definitions for TRISB register */
static volatile  bit	TRISB5		                   @ ((unsigned)&TRISB*8)+5;
static volatile  bit	TRISB4		                   @ ((unsigned)&TRISB*8)+4;
static volatile  bit	TRISB3		                   @ ((unsigned)&TRISB*8)+3;
static volatile  bit	TRISB2		                   @ ((unsigned)&TRISB*8)+2;
static volatile  bit	TRISB1		                   @ ((unsigned)&TRISB*8)+1;
static volatile  bit	TRISB0		                   @ ((unsigned)&TRISB*8)+0;
/* Definitions for TRISC register */
static volatile  bit	TRISC5		                   @ ((unsigned)&TRISC*8)+5;
static volatile  bit	TRISC4		                   @ ((unsigned)&TRISC*8)+4;
static volatile  bit	TRISC3		                   @ ((unsigned)&TRISC*8)+3;
static volatile  bit	TRISC2		                   @ ((unsigned)&TRISC*8)+2;
static volatile  bit	TRISC1		                   @ ((unsigned)&TRISC*8)+1;
static volatile  bit	TRISC0		                   @ ((unsigned)&TRISC*8)+0;
/* Definitions for TRISD register */
static volatile  bit	TRISD3		                   @ ((unsigned)&TRISD*8)+3;
static volatile  bit	TRISD2		                   @ ((unsigned)&TRISD*8)+2;
static volatile  bit	TRISD1		                   @ ((unsigned)&TRISD*8)+1;
static volatile  bit	TRISD0		                   @ ((unsigned)&TRISD*8)+0;

/* Definitions for PDPD register */
static volatile  bit	PD3PD		                   @ ((unsigned)&PDPD*8)+3;
static volatile  bit	PD2PD		                   @ ((unsigned)&PDPD*8)+2;
static volatile  bit	PD1PD		                   @ ((unsigned)&PDPD*8)+1;
static volatile  bit	PD0PD		                   @ ((unsigned)&PDPD*8)+0;
/* Definitions for PCPD register */
static volatile  bit	PC5PD		                   @ ((unsigned)&PCPD*8)+5;
static volatile  bit	PC4PD		                   @ ((unsigned)&PCPD*8)+4;
static volatile  bit	PC3PD		                   @ ((unsigned)&PCPD*8)+3;
static volatile  bit	PC2PD		                   @ ((unsigned)&PCPD*8)+2;
static volatile  bit	PC1PD		                   @ ((unsigned)&PCPD*8)+1;
static volatile  bit	PC0PD		                   @ ((unsigned)&PCPD*8)+0;
/* Definitions for PBPD register */
static volatile  bit	PB5PD		                   @ ((unsigned)&PBPD*8)+5;
static volatile  bit	PB4PD		                   @ ((unsigned)&PBPD*8)+4;
static volatile  bit	PB3PD		                   @ ((unsigned)&PBPD*8)+3;
static volatile  bit	PB2PD		                   @ ((unsigned)&PBPD*8)+2;
static volatile  bit	PB1PD		                   @ ((unsigned)&PBPD*8)+1;
static volatile  bit	PB0PD		                   @ ((unsigned)&PBPD*8)+0;
/* Definitions for PAPD register */
static volatile  bit	PA5PD		                   @ ((unsigned)&PAPD*8)+5;
static volatile  bit	PA4PD		                   @ ((unsigned)&PAPD*8)+4;
static volatile  bit	PA3PD		                   @ ((unsigned)&PAPD*8)+3;
static volatile  bit	PA2PD		                   @ ((unsigned)&PAPD*8)+2;
static volatile  bit	PA1PD		                   @ ((unsigned)&PAPD*8)+1;
static volatile  bit	PA0PD		                   @ ((unsigned)&PAPD*8)+0;

/* Definitions for PIND register */
static volatile  bit	PIND3		                   @ ((unsigned)&PIND*8)+3;
static volatile  bit	PIND2		                   @ ((unsigned)&PIND*8)+2;
static volatile  bit	PIND1		                   @ ((unsigned)&PIND*8)+1;
static volatile  bit	PIND0		                   @ ((unsigned)&PIND*8)+0;
/* Definitions for PINC register */
static volatile  bit	PINC5		                   @ ((unsigned)&PINC*8)+5;
static volatile  bit	PINC4		                   @ ((unsigned)&PINC*8)+4;
static volatile  bit	PINC3		                   @ ((unsigned)&PINC*8)+3;
static volatile  bit	PINC2		                   @ ((unsigned)&PINC*8)+2;
static volatile  bit	PINC1		                   @ ((unsigned)&PINC*8)+1;
static volatile  bit	PINC0		                   @ ((unsigned)&PINC*8)+0;
/* Definitions for PINB register */
static volatile  bit	PINB5		                   @ ((unsigned)&PINB*8)+5;
static volatile  bit	PINB4		                   @ ((unsigned)&PINB*8)+4;
static volatile  bit	PINB3		                   @ ((unsigned)&PINB*8)+3;
static volatile  bit	PINB2		                   @ ((unsigned)&PINB*8)+2;
static volatile  bit	PINB1		                   @ ((unsigned)&PINB*8)+1;
static volatile  bit	PINB0		                   @ ((unsigned)&PINB*8)+0;
/* Definitions for PINA register */
static volatile  bit	PINA5		                   @ ((unsigned)&PINA*8)+5;
static volatile  bit	PINA4		                   @ ((unsigned)&PINA*8)+4;
static volatile  bit	PINA3		                   @ ((unsigned)&PINA*8)+3;
static volatile  bit	PINA2		                   @ ((unsigned)&PINA*8)+2;
static volatile  bit	PINA1		                   @ ((unsigned)&PINA*8)+1;
static volatile  bit	PINA0		                   @ ((unsigned)&PINA*8)+0;
/* Definitions for PDPU register */
static volatile  bit	PD3PU		                   @ ((unsigned)&PDPU*8)+3;
static volatile  bit	PD2PU		                   @ ((unsigned)&PDPU*8)+2;
static volatile  bit	PD1PU		                   @ ((unsigned)&PDPU*8)+1;
static volatile  bit	PD0PU		                   @ ((unsigned)&PDPU*8)+0;
/* Definitions for PCPU register */
static volatile  bit	PC5PU		                   @ ((unsigned)&PCPU*8)+5;
static volatile  bit	PC4PU		                   @ ((unsigned)&PCPU*8)+4;
static volatile  bit	PC3PU		                   @ ((unsigned)&PCPU*8)+3;
static volatile  bit	PC2PU		                   @ ((unsigned)&PCPU*8)+2;
static volatile  bit	PC1PU		                   @ ((unsigned)&PCPU*8)+1;
static volatile  bit	PC0PU		                   @ ((unsigned)&PCPU*8)+0;
/* Definitions for PBPU register */
static volatile  bit	PB5PU		                   @ ((unsigned)&PBPU*8)+5;
static volatile  bit	PB4PU		                   @ ((unsigned)&PBPU*8)+4;
static volatile  bit	PB3PU		                   @ ((unsigned)&PBPU*8)+3;
static volatile  bit	PB2PU		                   @ ((unsigned)&PBPU*8)+2;
static volatile  bit	PB1PU		                   @ ((unsigned)&PBPU*8)+1;
static volatile  bit	PB0PU		                   @ ((unsigned)&PBPU*8)+0;
/* Definitions for PAPU register */
static volatile  bit	PA5PU		                   @ ((unsigned)&PAPU*8)+5;
static volatile  bit	PA4PU		                   @ ((unsigned)&PAPU*8)+4;
static volatile  bit	PA3PU		                   @ ((unsigned)&PAPU*8)+3;
static volatile  bit	PA2PU		                   @ ((unsigned)&PAPU*8)+2;
static volatile  bit	PA1PU		                   @ ((unsigned)&PAPU*8)+1;
static volatile  bit	PA0PU		                   @ ((unsigned)&PAPU*8)+0;
/* Definitions for PORTD register */
static volatile  bit	PD3		                       @ ((unsigned)&PORTD*8)+3;
static volatile  bit	PD2		                       @ ((unsigned)&PORTD*8)+2;
static volatile  bit	PD1		                       @ ((unsigned)&PORTD*8)+1;
static volatile  bit	PD0		                       @ ((unsigned)&PORTD*8)+0;
/* Definitions for PORTC register */
static volatile  bit	PC5		                       @ ((unsigned)&PORTC*8)+5;
static volatile  bit	PC4		                       @ ((unsigned)&PORTC*8)+4;
static volatile  bit	PC3		                       @ ((unsigned)&PORTC*8)+3;
static volatile  bit	PC2		                       @ ((unsigned)&PORTC*8)+2;
static volatile  bit	PC1		                       @ ((unsigned)&PORTC*8)+1;
static volatile  bit	PC0		                       @ ((unsigned)&PORTC*8)+0;
/* Definitions for PORTB register */
static volatile  bit	PB5		                       @ ((unsigned)&PORTB*8)+5;
static volatile  bit	PB4		                       @ ((unsigned)&PORTB*8)+4;
static volatile  bit	PB3		                       @ ((unsigned)&PORTB*8)+3;
static volatile  bit	PB2		                       @ ((unsigned)&PORTB*8)+2;
static volatile  bit	PB1		                       @ ((unsigned)&PORTB*8)+1;
static volatile  bit	PB0		                       @ ((unsigned)&PORTB*8)+0;
/* Definitions for PORTC register */
static volatile  bit	PA5		                       @ ((unsigned)&PORTA*8)+5;
static volatile  bit	PA4		                       @ ((unsigned)&PORTA*8)+4;
static volatile  bit	PA3		                       @ ((unsigned)&PORTA*8)+3;
static volatile  bit	PA2		                       @ ((unsigned)&PORTA*8)+2;
static volatile  bit	PA1		                       @ ((unsigned)&PORTA*8)+1;
static volatile  bit	PA0		                       @ ((unsigned)&PORTA*8)+0;
/* Definitions for CURCON register */
static volatile  bit	PDCUR		                   @ ((unsigned)&CURCON*8)+3;
static volatile  bit	PCCUR		                   @ ((unsigned)&CURCON*8)+2;
static volatile  bit	PBCUR		                   @ ((unsigned)&CURCON*8)+1;
static volatile  bit	PACUR		                   @ ((unsigned)&CURCON*8)+0;

//--------------------------------------OP1--------------------------------------------
static volatile  bit	OP1ON		                   @ ((unsigned)&OP1CON0*8)+7;
static volatile  bit	EX1		                       @ ((unsigned)&OP1CON0*8)+6;
static volatile  bit	A1NS1		                   @ ((unsigned)&OP1CON0*8)+5;
static volatile  bit	PCH12		                   @ ((unsigned)&OP1CON0*8)+4;
static volatile  bit	PCH11		                   @ ((unsigned)&OP1CON0*8)+3;
static volatile  bit	PCH10		                   @ ((unsigned)&OP1CON0*8)+2;
static volatile  bit	NCH11		                   @ ((unsigned)&OP1CON0*8)+1;
static volatile  bit	NCH10		                   @ ((unsigned)&OP1CON0*8)+0;
//--------------------------------------OP1-------------------------------------------
static volatile  bit	OP1OUT		                   @ ((unsigned)&OP1CON1*8)+7;
static volatile  bit	OUT1EN1		                   @ ((unsigned)&OP1CON1*8)+6;
static volatile  bit	AN_AVSS1	                   @ ((unsigned)&OP1CON1*8)+5;
static volatile  bit	A1O2N1		                   @ ((unsigned)&OP1CON1*8)+4;
static volatile  bit	PGAEN1		                   @ ((unsigned)&OP1CON1*8)+3;
static volatile  bit	OP1POS		                   @ ((unsigned)&OP1CON1*8)+2;
static volatile  bit	CMPMODE1		               @ ((unsigned)&OP1CON1*8)+1;
static volatile  bit	OUT0EN1		                   @ ((unsigned)&OP1CON1*8)+0;
//--------------------------------------OP1-------------------------------------------
static volatile  bit	FILTER14	                   @ ((unsigned)&OP1CON2*8)+7;
static volatile  bit	FILTER13	                   @ ((unsigned)&OP1CON2*8)+6;
static volatile  bit	FILTER12	                   @ ((unsigned)&OP1CON2*8)+5;
static volatile  bit	FILTER11	                   @ ((unsigned)&OP1CON2*8)+4;
static volatile  bit	FILTER10	                   @ ((unsigned)&OP1CON2*8)+3;
static volatile  bit	OP1A2DEN                       @ ((unsigned)&OP1CON2*8)+2;
static volatile  bit	OP1PGA1 		               @ ((unsigned)&OP1CON2*8)+1;
static volatile  bit	OP1PGA0		                   @ ((unsigned)&OP1CON2*8)+0;
//--------------------------------------OP1 ------------------------------------------
static volatile  bit	OP1CSEL3		               @ ((unsigned)&OP1CON3*8)+7;
static volatile  bit	OP1CSEL2		               @ ((unsigned)&OP1CON3*8)+6;
static volatile  bit	OP1CSEL1		               @ ((unsigned)&OP1CON3*8)+5;
static volatile  bit	OP1CSEL0		               @ ((unsigned)&OP1CON3*8)+4;
static volatile  bit	OP1_HYS_EN		               @ ((unsigned)&OP1CON3*8)+3;
static volatile  bit	A1NS1B    		               @ ((unsigned)&OP1CON3*8)+2;
static volatile  bit	PGAENB  		               @ ((unsigned)&OP1CON3*8)+1;
static volatile  bit	OP1PGA2		                   @ ((unsigned)&OP1CON3*8)+0;
//--------------------------------------OP1-------------------------------------------
static volatile  bit	OP1_SW1 	                   @ ((unsigned)&OP1CON4*8)+7;
static volatile  bit	OP1_OFFSETEN                   @ ((unsigned)&OP1CON4*8)+6;
static volatile  bit	OP1_OFFSET5                    @ ((unsigned)&OP1CON4*8)+5;
static volatile  bit	OP1_OFFSET4                    @ ((unsigned)&OP1CON4*8)+4;
static volatile  bit	OP1_OFFSET3                    @ ((unsigned)&OP1CON4*8)+3;
static volatile  bit	OP1_OFFSET2                    @ ((unsigned)&OP1CON4*8)+2;
static volatile  bit	OP1_OFFSET1                    @ ((unsigned)&OP1CON4*8)+1;
static volatile  bit	OP1_OFFSET0     	           @ ((unsigned)&OP1CON4*8)+0;
//--------------------------------------CMP0--------------------------------------------
static volatile  bit	CMP0EN		                   @ ((unsigned)&CMP0CON*8)+7;
static volatile  bit	CMP0OUT		                   @ ((unsigned)&CMP0CON*8)+6;
static volatile  bit	CMP0POS		                   @ ((unsigned)&CMP0CON*8)+5;
static volatile  bit	CMP0PCH2		               @ ((unsigned)&CMP0CON*8)+4;
static volatile  bit	CMP0PCH1		               @ ((unsigned)&CMP0CON*8)+3;
static volatile  bit	CMP0PCH0		               @ ((unsigned)&CMP0CON*8)+2;
static volatile  bit	CMP0NCH1                       @ ((unsigned)&CMP0CON*8)+1;
static volatile  bit	CMP0NCH0		               @ ((unsigned)&CMP0CON*8)+0;
//--------------------------------------CMP1-------------------------------------------
static volatile  bit	CMP1EN		                   @ ((unsigned)&CMP1CON*8)+7;
static volatile  bit	CMP1OUT		                   @ ((unsigned)&CMP1CON*8)+6;
static volatile  bit	CMP1POS		                   @ ((unsigned)&CMP1CON*8)+5;
static volatile  bit	CMP1PCH2		               @ ((unsigned)&CMP1CON*8)+4;
static volatile  bit	CMP1PCH1		               @ ((unsigned)&CMP1CON*8)+3;
static volatile  bit	CMP1PCH0		               @ ((unsigned)&CMP1CON*8)+2;
static volatile  bit	CMP1NCH1		               @ ((unsigned)&CMP1CON*8)+1;
static volatile  bit	CMP1NCH0		               @ ((unsigned)&CMP1CON*8)+0;
//--------------------------------------CMP2-------------------------------------------
static volatile  bit	CMP2EN		                   @ ((unsigned)&CMP2CON0*8)+7;
static volatile  bit	CMP2OUT		                   @ ((unsigned)&CMP2CON0*8)+6;
static volatile  bit	CMP2POS		                   @ ((unsigned)&CMP2CON0*8)+5;
static volatile  bit	C2OUT1EN		               @ ((unsigned)&CMP2CON0*8)+4;
static volatile  bit	C2OUT0EN		               @ ((unsigned)&CMP2CON0*8)+3;
static volatile  bit	CMP2PCH2		               @ ((unsigned)&CMP2CON0*8)+2;
static volatile  bit	CMP2PCH1		               @ ((unsigned)&CMP2CON0*8)+1;
static volatile  bit	CMP2PCH0		               @ ((unsigned)&CMP2CON0*8)+0;
//--------------------------------------CMP2-------------------------------------------
static volatile  bit	CMP2HYSN_VOL1                  @ ((unsigned)&CMP2CON1*8)+7;
static volatile  bit	CMP2HYSN_VOL0	               @ ((unsigned)&CMP2CON1*8)+6;
static volatile  bit	CMP2HYSP_VOL1		           @ ((unsigned)&CMP2CON1*8)+5;
static volatile  bit	CMP2HYSP_VOL0		           @ ((unsigned)&CMP2CON1*8)+4;
static volatile  bit	CMP2NCH2		               @ ((unsigned)&CMP2CON1*8)+2;
static volatile  bit	CMP2NCH1		               @ ((unsigned)&CMP2CON1*8)+1;
static volatile  bit	CMP2NCH0		               @ ((unsigned)&CMP2CON1*8)+0;
//--------------------------------------CMP1&CMP0-------------------------------------------
static volatile  bit	CMP1HYSN_VOL1                  @ ((unsigned)&CMPCON1*8)+7;
static volatile  bit	CMP1HYSN_VOL0                  @ ((unsigned)&CMPCON1*8)+6;
static volatile  bit	CMP1HYSP_VOL1	               @ ((unsigned)&CMPCON1*8)+5;
static volatile  bit	CMP1HYSP_VOL0		           @ ((unsigned)&CMPCON1*8)+4;
static volatile  bit	CMP0HYSN_VOL1		           @ ((unsigned)&CMPCON1*8)+3;
static volatile  bit	CMP0HYSN_VOL0		           @ ((unsigned)&CMPCON1*8)+2;
static volatile  bit	CMP0HYSP_VOL1		           @ ((unsigned)&CMPCON1*8)+1;
static volatile  bit	CMP0HYSP_VOL0		           @ ((unsigned)&CMPCON1*8)+0;

//--------------------------------------CMP-------------------------------------------
static volatile  bit    CMPFILTER3                     @ ((unsigned)&CMPCON*8)+7;
static volatile  bit    CMPFILTER2                     @ ((unsigned)&CMPCON*8)+6;
static volatile  bit    CMPFILTER1                     @ ((unsigned)&CMPCON*8)+5;
static volatile  bit    CMPFILTER0                     @ ((unsigned)&CMPCON*8)+4;
static volatile  bit	C1OUT1EN                       @ ((unsigned)&CMPCON*8)+3;
static volatile  bit	C1OUT0EN                       @ ((unsigned)&CMPCON*8)+2;
static volatile  bit	C0OUT1EN    	               @ ((unsigned)&CMPCON*8)+1;
static volatile  bit	C0OUT0EN                       @ ((unsigned)&CMPCON*8)+0;

/* Definitions for CMP0CON2register */
static volatile  bit	CMP0_OFFSETEN		           @ ((unsigned)&CMP0CON2*8)+4;
static volatile  bit	CMP0_TRIM3                     @ ((unsigned)&CMP0CON2*8)+3;
static volatile  bit	CMP0_TRIM2	                   @ ((unsigned)&CMP0CON2*8)+2;
static volatile  bit	CMP0_TRIM1                     @ ((unsigned)&CMP0CON2*8)+1;
static volatile  bit	CMP0_TRIM0	                   @ ((unsigned)&CMP0CON2*8)+0;

/* Definitions for CMP1CON2register */
static volatile  bit	CMP1_OFFSETEN		           @ ((unsigned)&CMP1CON2*8)+4;
static volatile  bit	CMP1_TRIM3                     @ ((unsigned)&CMP1CON2*8)+3;
static volatile  bit	CMP1_TRIM2	                   @ ((unsigned)&CMP1CON2*8)+2;
static volatile  bit	CMP1_TRIM1                     @ ((unsigned)&CMP1CON2*8)+1;
static volatile  bit	CMP1_TRIM0	                   @ ((unsigned)&CMP1CON2*8)+0;

/* Definitions for CMP2CON2register */
static volatile  bit	CMP2_OFFSETEN		           @ ((unsigned)&CMP2CON2*8)+4;
static volatile  bit	CMP2_TRIM3                     @ ((unsigned)&CMP2CON2*8)+3;
static volatile  bit	CMP2_TRIM2	                   @ ((unsigned)&CMP2CON2*8)+2;
static volatile  bit	CMP2_TRIM1                     @ ((unsigned)&CMP2CON2*8)+1;
static volatile  bit	CMP2_TRIM0	                   @ ((unsigned)&CMP2CON2*8)+0;

/* Definitions for CMPCON2register */
static volatile  bit	CMP1LV   		               @ ((unsigned)&CMPCON2*8)+6;
static volatile  bit	CMP1M1   		               @ ((unsigned)&CMPCON2*8)+5;
static volatile  bit	CMP1M0                         @ ((unsigned)&CMPCON2*8)+4;
static volatile  bit	CMP0LV   	                   @ ((unsigned)&CMPCON2*8)+2;
static volatile  bit	CMP0M1                         @ ((unsigned)&CMPCON2*8)+1;
static volatile  bit	CMP0M0	                       @ ((unsigned)&CMPCON2*8)+0;

/* Definitions for CMPCON3register */
static volatile  bit	CMP2LV   	                   @ ((unsigned)&CMPCON3*8)+2;
static volatile  bit	CMP2M1                         @ ((unsigned)&CMPCON3*8)+1;
static volatile  bit	CMP2M0	                       @ ((unsigned)&CMPCON3*8)+0;

//--------------------------------------DAC-------------------------------------------
static volatile  bit	LVDST			               @ ((unsigned)&DACCON*8)+4;
static volatile  bit	DAC1VREF1                      @ ((unsigned)&DACCON*8)+3;
static volatile  bit	DAC1VREF0                      @ ((unsigned)&DACCON*8)+2;
static volatile  bit	DAC0VREF1    	               @ ((unsigned)&DACCON*8)+1;
static volatile  bit	DAC0VREF0                      @ ((unsigned)&DACCON*8)+0;

static volatile  bit	DAC0EN                         @ ((unsigned)&DAC0CON*8)+6;
static volatile  bit	DAC1EN                         @ ((unsigned)&DAC1CON*8)+6;
//-----------------------------------------FVR----------------------------------
/* Definitions for FVRCON register */
static volatile  bit	FVROUTEN	                   @ ((unsigned)&FVRCON*8)+7;
static volatile  bit	FVRPGA 	                       @ ((unsigned)&FVRCON*8)+6;
static volatile  bit	FVREN		                   @ ((unsigned)&FVRCON*8)+5;
static volatile  bit	FVR_SEL2	                   @ ((unsigned)&FVRCON*8)+2;
static volatile  bit	FVR_SEL1                       @ ((unsigned)&FVRCON*8)+1;
static volatile  bit	FVR_SEL0	                   @ ((unsigned)&FVRCON*8)+0;

/* Definitions for FVRCON1 register */
static volatile  bit	FVR_A2D_OUT 	               @ ((unsigned)&FVRCON1*8)+7;
static volatile  bit	FVRPGA1 	                   @ ((unsigned)&FVRCON1*8)+6;
static volatile  bit	FVR_OFFSET_EN		           @ ((unsigned)&FVRCON1*8)+5;
static volatile  bit	FVR_TRIM4	                   @ ((unsigned)&FVRCON1*8)+4;
static volatile  bit	FVR_TRIM3                      @ ((unsigned)&FVRCON1*8)+3;
static volatile  bit	FVR_TRIM2	                   @ ((unsigned)&FVRCON1*8)+2;
static volatile  bit	FVR_TRIM1                      @ ((unsigned)&FVRCON1*8)+1;
static volatile  bit	FVR_TRIM0	                   @ ((unsigned)&FVRCON1*8)+0;



//--------------------------------------LCD------------------------------------------
static volatile  bit	LCDEN                          @ ((unsigned)&LCDCON0*8)+7;
/* Definitions for LCDCON1 register */
static volatile  bit	COM7EN  	                   @ ((unsigned)&LCDCON1*8)+7;
static volatile  bit	COM6EN                         @ ((unsigned)&LCDCON1*8)+6;
static volatile  bit	COM5EN  	                   @ ((unsigned)&LCDCON1*8)+5;
static volatile  bit	COM4EN  	                   @ ((unsigned)&LCDCON1*8)+4;
static volatile  bit	COM3EN                         @ ((unsigned)&LCDCON1*8)+3;
static volatile  bit	COM2EN  	                   @ ((unsigned)&LCDCON1*8)+2;
static volatile  bit	COM1EN                         @ ((unsigned)&LCDCON1*8)+1;
static volatile  bit	COM0EN  	                   @ ((unsigned)&LCDCON1*8)+0;

/* Definitions for LCDCON2 register */
static volatile  bit	LCDCSEL1  	                   @ ((unsigned)&LCDCON2*8)+7;
static volatile  bit	LCDCSEL0                       @ ((unsigned)&LCDCON2*8)+6;

static volatile  bit	COM9EN                         @ ((unsigned)&LCDCON2*8)+1;
static volatile  bit	COM8EN  	                   @ ((unsigned)&LCDCON2*8)+0;

/* Definitions for LCDCON3 register */
static volatile  bit	COM17EN  	                   @ ((unsigned)&LCDCON3*8)+7;
static volatile  bit	COM16EN                        @ ((unsigned)&LCDCON3*8)+6;
static volatile  bit	COM15EN  	                   @ ((unsigned)&LCDCON3*8)+5;
static volatile  bit	COM14EN  	                   @ ((unsigned)&LCDCON3*8)+4;
static volatile  bit	COM13EN                        @ ((unsigned)&LCDCON3*8)+3;
static volatile  bit	COM12EN  	                   @ ((unsigned)&LCDCON3*8)+2;
static volatile  bit	COM11EN                        @ ((unsigned)&LCDCON3*8)+1;
static volatile  bit	COM10EN  	                   @ ((unsigned)&LCDCON3*8)+0;

/* Definitions for BUCON register */
static volatile  bit	BUOUTEN  	                   @ ((unsigned)&BUCON*8)+5;
static volatile  bit	BUEN                           @ ((unsigned)&BUCON*8)+4;
static volatile  bit	BUSEL3  	                   @ ((unsigned)&BUCON*8)+3;
static volatile  bit	BUSEL2  	                   @ ((unsigned)&BUCON*8)+2;
static volatile  bit	BUSEL1                         @ ((unsigned)&BUCON*8)+1;
static volatile  bit	BUSEL0  	                   @ ((unsigned)&BUCON*8)+0;

/* Definitions for IAPCTRL  register */
static volatile  bit	ERR                            @ ((unsigned)&IAPCTRL*8)+3;
static volatile  bit	LOCK    	                   @ ((unsigned)&IAPCTRL*8)+2;
static volatile  bit	ER                             @ ((unsigned)&IAPCTRL*8)+1;
static volatile  bit	PG  	                       @ ((unsigned)&IAPCTRL*8)+0;
/* Definitions for SMCR  register */
static volatile  bit	SM2    	                       @ ((unsigned)&SMCR*8)+3;
static volatile  bit	SM1    	                       @ ((unsigned)&SMCR*8)+2;
static volatile  bit	SM0                            @ ((unsigned)&SMCR*8)+1;
static volatile  bit	SE  	                       @ ((unsigned)&SMCR*8)+0;
/* Definitions for OSCCON register */
static volatile  bit	FINTOSC2                       @ ((unsigned)&OSCCON*8)+6;
static volatile  bit	FINTOSC1    	               @ ((unsigned)&OSCCON*8)+5;
static volatile  bit	FINTOSC0    	               @ ((unsigned)&OSCCON*8)+4;
static volatile  bit	LIRC2MEN                       @ ((unsigned)&OSCCON*8)+3;
static volatile  bit	CCPHYEN                        @ ((unsigned)&OSCCON*8)+0;

/* Definitions for CLKCFG1 register */
static volatile  bit    OPCLKEN                        @ ((unsigned)&CLKCFG1*8)+7;
static volatile  bit    UARTCLKEN                      @ ((unsigned)&CLKCFG1*8)+6;
static volatile  bit    CKOE1                          @ ((unsigned)&CLKCFG1*8)+5;
static volatile  bit    CKOE0                          @ ((unsigned)&CLKCFG1*8)+4;
static volatile  bit    OSCF1                          @ ((unsigned)&CLKCFG1*8)+3;
static volatile  bit    OSCF0                          @ ((unsigned)&CLKCFG1*8)+2;
static volatile  bit    OSCM1                          @ ((unsigned)&CLKCFG1*8)+1;
static volatile  bit    OSCM0                          @ ((unsigned)&CLKCFG1*8)+0;
/* Definitions for CLKCFG2 register */
static volatile  bit    CMPCLKEN                       @ ((unsigned)&CLKCFG2*8)+7;
static volatile  bit    DACCLKEN                       @ ((unsigned)&CLKCFG2*8)+6;
static volatile  bit    ADCCLKEN                       @ ((unsigned)&CLKCFG2*8)+5;
static volatile  bit    CCPCLKEN                       @ ((unsigned)&CLKCFG2*8)+4;
static volatile  bit    T3CLKEN                        @ ((unsigned)&CLKCFG2*8)+3;
static volatile  bit    T2CLKEN                        @ ((unsigned)&CLKCFG2*8)+2;
static volatile  bit    T1CLKEN                        @ ((unsigned)&CLKCFG2*8)+1;
static volatile  bit    T0CLKEN                        @ ((unsigned)&CLKCFG2*8)+0;
/* Definitions for SIGCON  register */
static volatile  bit    PLL                            @ ((unsigned)&SIGCON*8)+7;
static volatile  bit    LXTL_SEEDUP                    @ ((unsigned)&SIGCON*8)+6;
static volatile  bit    ENVDDL                         @ ((unsigned)&SIGCON*8)+5;
static volatile  bit    PWM1_EN                        @ ((unsigned)&SIGCON*8)+4;
static volatile  bit    I2CCLKEN                       @ ((unsigned)&SIGCON*8)+3;
static volatile  bit    ICE_TMREN                      @ ((unsigned)&SIGCON*8)+2;
static volatile  bit    UART_MUX                       @ ((unsigned)&SIGCON*8)+1;
static volatile  bit    SIGS                           @ ((unsigned)&SIGCON*8)+0;
/* Definitions for PAINTMASK register */
static volatile  bit	PA5MSK		                   @ ((unsigned)&PAINTMASK*8)+5;
static volatile  bit	PA4MSK		                   @ ((unsigned)&PAINTMASK*8)+4;
static volatile  bit	PA3MSK		                   @ ((unsigned)&PAINTMASK*8)+3;
static volatile  bit	PA2MSK		                   @ ((unsigned)&PAINTMASK*8)+2;
static volatile  bit	PA1MSK		                   @ ((unsigned)&PAINTMASK*8)+1;
static volatile  bit	PA0MSK		                   @ ((unsigned)&PAINTMASK*8)+0;
/* Definitions for PBINTMASK register */
static volatile  bit	PB5MSK		                   @ ((unsigned)&PBINTMASK*8)+5;
static volatile  bit	PB4MSK		                   @ ((unsigned)&PBINTMASK*8)+4;
static volatile  bit	PB3MSK		                   @ ((unsigned)&PBINTMASK*8)+3;
static volatile  bit	PB2MSK		                   @ ((unsigned)&PBINTMASK*8)+2;
static volatile  bit	PB1MSK		                   @ ((unsigned)&PBINTMASK*8)+1;
static volatile  bit	PB0MSK		                   @ ((unsigned)&PBINTMASK*8)+0;
/* Definitions for PCINTMASK register */
static volatile  bit	PC5MSK		                   @ ((unsigned)&PCINTMASK*8)+5;
static volatile  bit	PC4MSK		                   @ ((unsigned)&PCINTMASK*8)+4;
static volatile  bit	PC3MSK		                   @ ((unsigned)&PCINTMASK*8)+3;
static volatile  bit	PC2MSK		                   @ ((unsigned)&PCINTMASK*8)+2;
static volatile  bit	PC1MSK		                   @ ((unsigned)&PCINTMASK*8)+1;
static volatile  bit	PC0MSK		                   @ ((unsigned)&PCINTMASK*8)+0;
/* Definitions for PDINTMASK register */
static volatile  bit	PD3MSK		                   @ ((unsigned)&PDINTMASK*8)+3;
static volatile  bit	PD2MSK		                   @ ((unsigned)&PDINTMASK*8)+2;
static volatile  bit	PD1MSK		                   @ ((unsigned)&PDINTMASK*8)+1;
static volatile  bit	PD0MSK		                   @ ((unsigned)&PDINTMASK*8)+0;
/* Definitions for EECON1 register */
static volatile  bit	ER16EN 		                   @ ((unsigned)&EECON1*8)+6;
static volatile  bit	ERBEN 		                   @ ((unsigned)&EECON1*8)+5;
static volatile  bit	WRBEN		                   @ ((unsigned)&EECON1*8)+4;
static volatile  bit	WERR 		                   @ ((unsigned)&EECON1*8)+3;
static volatile  bit	WREN		                   @ ((unsigned)&EECON1*8)+2;
static volatile  bit	WR  	   	                   @ ((unsigned)&EECON1*8)+1;
static volatile  bit	RD		                       @ ((unsigned)&EECON1*8)+0;

/* Definitions for ANASEL0 register */
static volatile  bit	PA5AEN		                   @ ((unsigned)&ANASEL0*8)+5;
static volatile  bit	PA4AEN		                   @ ((unsigned)&ANASEL0*8)+4;
static volatile  bit	PA3AEN		                   @ ((unsigned)&ANASEL0*8)+3;
static volatile  bit	PA2AEN		                   @ ((unsigned)&ANASEL0*8)+2;
static volatile  bit	PA1AEN		                   @ ((unsigned)&ANASEL0*8)+1;
static volatile  bit	PA0AEN		                   @ ((unsigned)&ANASEL0*8)+0;
/* Definitions for ANASEL1 register */
static volatile  bit	PB5AEN		                   @ ((unsigned)&ANASEL1*8)+5;
static volatile  bit	PB4AEN		                   @ ((unsigned)&ANASEL1*8)+4;
static volatile  bit	PB3AEN		                   @ ((unsigned)&ANASEL1*8)+3;
static volatile  bit	PB2AEN		                   @ ((unsigned)&ANASEL1*8)+2;
static volatile  bit	PB1AEN		                   @ ((unsigned)&ANASEL1*8)+1;
static volatile  bit	PB0AEN		                   @ ((unsigned)&ANASEL1*8)+0;
/* Definitions for ANASEL2 register */
static volatile  bit	PC5AEN		                   @ ((unsigned)&ANASEL2*8)+5;
static volatile  bit	PC4AEN		                   @ ((unsigned)&ANASEL2*8)+4;
static volatile  bit	PC3AEN		                   @ ((unsigned)&ANASEL2*8)+3;
static volatile  bit	PC2AEN		                   @ ((unsigned)&ANASEL2*8)+2;
static volatile  bit	PC1AEN		                   @ ((unsigned)&ANASEL2*8)+1;
static volatile  bit	PC0AEN		                   @ ((unsigned)&ANASEL2*8)+0;
/* Definitions for ANASEL3 register */
static volatile  bit	PD3AEN		                   @ ((unsigned)&ANASEL3*8)+3;
static volatile  bit	PD2AEN		                   @ ((unsigned)&ANASEL3*8)+2;
static volatile  bit	PD1AEN		                   @ ((unsigned)&ANASEL3*8)+1;
static volatile  bit	PD0AEN		                   @ ((unsigned)&ANASEL3*8)+0;
/* Definitions for TXSTA register */
static volatile  bit	CSRC			               @ ((unsigned)&TXSTA*8)+7;
static volatile  bit	TX9		   		               @ ((unsigned)&TXSTA*8)+6;
static volatile  bit	TXEN			               @ ((unsigned)&TXSTA*8)+5;
static volatile  bit	SYNC			               @ ((unsigned)&TXSTA*8)+4;
static volatile  bit	TX_PARTY		               @ ((unsigned)&TXSTA*8)+3;
static volatile  bit	BRGH			               @ ((unsigned)&TXSTA*8)+2;
static volatile  bit	TMRT			               @ ((unsigned)&TXSTA*8)+1;
static volatile  bit	TX9D			               @ ((unsigned)&TXSTA*8)+0;
/* Definitions for RCSTA register */
static volatile  bit    SPEN				           @ ((unsigned)&RCSTA*8)+7;
static volatile  bit    RX9				               @ ((unsigned)&RCSTA*8)+6;
static volatile  bit    SREN				           @ ((unsigned)&RCSTA*8)+5;
static volatile  bit    CREN       		               @ ((unsigned)&RCSTA*8)+4;
static volatile  bit    BGRM				           @ ((unsigned)&RCSTA*8)+3;
static volatile  bit    FERR				           @ ((unsigned)&RCSTA*8)+2;
static volatile  bit    OERR				           @ ((unsigned)&RCSTA*8)+1;
static volatile  bit    RX9D				           @ ((unsigned)&RCSTA*8)+0;
/* Definitions for UARTCON register */
static volatile bit     INVMODE		                   @ ((unsigned)&UARTCON*8)+7;
static volatile bit     PARITY	        	           @ ((unsigned)&UARTCON*8)+6;
static volatile bit     ODD_EVEN			           @ ((unsigned)&UARTCON*8)+5;
static volatile bit     BCLK			               @ ((unsigned)&UARTCON*8)+4;
static volatile bit     HALF_DUPLEX	                   @ ((unsigned)&UARTCON*8)+3;
static volatile bit     DLSB            	           @ ((unsigned)&UARTCON*8)+2;
static volatile bit     STOP_BIT1		               @ ((unsigned)&UARTCON*8)+1;
static volatile bit     STOP_BIT0		               @ ((unsigned)&UARTCON*8)+0;
/* Definitions for I2CACKDLY register */
static volatile bit     ACKDLYON                       @ ((unsigned)&I2CACKDLY*8)+7;
static volatile bit     ACKDLY6        	               @ ((unsigned)&I2CACKDLY*8)+6;
static volatile bit     ACKDLY5   	                   @ ((unsigned)&I2CACKDLY*8)+5;
static volatile bit     ACKDLY4    	                   @ ((unsigned)&I2CACKDLY*8)+4;
static volatile bit     ACKDLY3                        @ ((unsigned)&I2CACKDLY*8)+3;
static volatile bit     ACKDLY2   	                   @ ((unsigned)&I2CACKDLY*8)+2;
static volatile bit     ACKDLY1    	                   @ ((unsigned)&I2CACKDLY*8)+1;
static volatile bit     ACKDLY0    		               @ ((unsigned)&I2CACKDLY*8)+0;
/* Definitions for I2CSTAT register */
static volatile bit     SMP1                           @ ((unsigned)&I2CSTAT*8)+7;
static volatile bit     SMP0        	               @ ((unsigned)&I2CSTAT*8)+6;
static volatile bit     A     		                   @ ((unsigned)&I2CSTAT*8)+5;
static volatile bit     D    		                   @ ((unsigned)&I2CSTAT*8)+5;
static volatile bit     P       		               @ ((unsigned)&I2CSTAT*8)+4;
static volatile bit     S                              @ ((unsigned)&I2CSTAT*8)+3;
static volatile bit     R        		               @ ((unsigned)&I2CSTAT*8)+2;
static volatile bit     W      		                   @ ((unsigned)&I2CSTAT*8)+2;
static volatile bit     BPRX    	                   @ ((unsigned)&I2CSTAT*8)+1;
static volatile bit     BPTX                           @ ((unsigned)&I2CSTAT*8)+0;
/* Definitions for I2CADDR0 register */

static volatile bit     ADD0EN           	           @ ((unsigned)&I2CADDR0*8)+7;

/* Definitions for I2CADDR1 register */
static volatile bit     ADD1EN    	         	       @ ((unsigned)&I2CADDR1*8)+7;

/* Definitions for I2CCON0 register */
static volatile bit     WCOL                           @ ((unsigned)&I2CCON0*8)+7;
static volatile bit     I2COV    	                   @ ((unsigned)&I2CCON0*8)+6;
static volatile bit     I2CEN                          @ ((unsigned)&I2CCON0*8)+5;
static volatile bit     I2STCEN                        @ ((unsigned)&I2CCON0*8)+4;
static volatile bit     ACKDLYWREN                     @ ((unsigned)&I2CCON0*8)+3;
static volatile bit     ACKDLY9EN                      @ ((unsigned)&I2CCON0*8)+2;
/* Definitions for I2CCON1 register */
static volatile bit     GCEN                           @ ((unsigned)&I2CCON1*8)+7;
static volatile bit     ACKSTAT        	               @ ((unsigned)&I2CCON1*8)+6;
static volatile bit     ACKGET 		                   @ ((unsigned)&I2CCON1*8)+5;
static volatile bit     ACKEN      	                   @ ((unsigned)&I2CCON1*8)+4;
/* Definitions for I2CIE register */
static volatile bit     I2C_FLOATIE                    @ ((unsigned)&I2CIE*8)+4;
static volatile bit     I2C_STOPIE                     @ ((unsigned)&I2CIE*8)+3;
static volatile bit     I2C_STARTIE                    @ ((unsigned)&I2CIE*8)+2;
static volatile bit     I2C_TXIE                       @ ((unsigned)&I2CIE*8)+1;
static volatile bit     I2C_RCIE                       @ ((unsigned)&I2CIE*8)+0;
/* Definitions for I2CIF register */
static volatile bit     I2C_FLOATIF                    @ ((unsigned)&I2CIF*8)+4;
static volatile bit     I2C_STOPIF                     @ ((unsigned)&I2CIF*8)+3;
static volatile bit     I2C_STARTIF      	           @ ((unsigned)&I2CIF*8)+2;
static volatile bit     I2C_TXIF                       @ ((unsigned)&I2CIF*8)+1;
static volatile bit     I2C_RCIF                       @ ((unsigned)&I2CIF*8)+0;
/* Definitions for I2CIP register */
static volatile bit     I2C_FLOATIP                    @ ((unsigned)&I2CIP*8)+4;
static volatile bit     I2C_STOPIP        	           @ ((unsigned)&I2CIP*8)+3;
static volatile bit     I2C_STARTIP                    @ ((unsigned)&I2CIP*8)+2;
static volatile bit     I2C_TXIP                       @ ((unsigned)&I2CIP*8)+1;
static volatile bit     I2C_RCIP                       @ ((unsigned)&I2CIP*8)+0;

 /* Definitions for TX0_MAP  register */
static volatile  bit   TX0_MPORT1                      @ ((unsigned)&TX0_MAP*8)+4;
static volatile  bit   TX0_MPORT0                      @ ((unsigned)&TX0_MAP*8)+3;
static volatile  bit   TX0_MPIN2                       @ ((unsigned)&TX0_MAP*8)+2;
static volatile  bit   TX0_MPIN1                       @ ((unsigned)&TX0_MAP*8)+1;
static volatile  bit   TX0_MPIN0                       @ ((unsigned)&TX0_MAP*8)+0;
/* Definitions for RX0_MAP  register */
static volatile  bit   RX0_MPORT1                      @ ((unsigned)&RX0_MAP*8)+4;
static volatile  bit   RX0_MPORT0                      @ ((unsigned)&RX0_MAP*8)+3;
static volatile  bit   RX0_MPIN2                       @ ((unsigned)&RX0_MAP*8)+2;
static volatile  bit   RX0_MPIN1                       @ ((unsigned)&RX0_MAP*8)+1;
static volatile  bit   RX0_MPIN0                       @ ((unsigned)&RX0_MAP*8)+0;
 /* Definitions for SDA_MAP  register */
static volatile  bit   SDA_MPORT1                      @ ((unsigned)&SDA_MAP*8)+4;
static volatile  bit   SDA_MPORT0                      @ ((unsigned)&SDA_MAP*8)+3;
static volatile  bit   SDA_MPIN2                       @ ((unsigned)&SDA_MAP*8)+2;
static volatile  bit   SDA_MPIN1                       @ ((unsigned)&SDA_MAP*8)+1;
static volatile  bit   SDA_MPIN0                       @ ((unsigned)&SDA_MAP*8)+0;
/* Definitions for SCL_MAP  register */
static volatile  bit   SCL_MPORT1                      @ ((unsigned)&SCL_MAP*8)+4;
static volatile  bit   SCL_MPORT0                      @ ((unsigned)&SCL_MAP*8)+3;
static volatile  bit   SCL_MPIN2                       @ ((unsigned)&SCL_MAP*8)+2;
static volatile  bit   SCL_MPIN1                       @ ((unsigned)&SCL_MAP*8)+1;
static volatile  bit   SCL_MPIN0                       @ ((unsigned)&SCL_MAP*8)+0;
 /* Definitions for PWM10_MAP  register */
static volatile  bit   PWM10_MPORT1                    @ ((unsigned)&PWM10_MAP*8)+4;
static volatile  bit   PWM10_MPORT0                    @ ((unsigned)&PWM10_MAP*8)+3;
static volatile  bit   PWM10_MPIN2                     @ ((unsigned)&PWM10_MAP*8)+2;
static volatile  bit   PWM10_MPIN1                     @ ((unsigned)&PWM10_MAP*8)+1;
static volatile  bit   PWM10_MPIN0                     @ ((unsigned)&PWM10_MAP*8)+0;
/* Definitions for PWM11_MAP  register */
static volatile  bit   PWM11_MPORT1                    @ ((unsigned)&PWM11_MAP*8)+4;
static volatile  bit   PWM11_MPORT0                    @ ((unsigned)&PWM11_MAP*8)+3;
static volatile  bit   PWM11_MPIN2                     @ ((unsigned)&PWM11_MAP*8)+2;
static volatile  bit   PWM11_MPIN1                     @ ((unsigned)&PWM11_MAP*8)+1;
static volatile  bit   PWM11_MPIN0                     @ ((unsigned)&PWM11_MAP*8)+0;
/* Definitions for PWM12_MAP register */
static volatile  bit   PWM12_MPORT1                    @ ((unsigned)&PWM12_MAP*8)+4;
static volatile  bit   PWM12_MPORT0                    @ ((unsigned)&PWM12_MAP*8)+3;
static volatile  bit   PWM12_MPIN2                     @ ((unsigned)&PWM12_MAP*8)+2;
static volatile  bit   PWM12_MPIN1                     @ ((unsigned)&PWM12_MAP*8)+1;
static volatile  bit   PWM12_MPIN0                     @ ((unsigned)&PWM12_MAP*8)+0;
/* Definitions for PWM13_MAP  register */
static volatile  bit   PWM13_MPORT1                    @ ((unsigned)&PWM13_MAP*8)+4;
static volatile  bit   PWM13_MPORT0                    @ ((unsigned)&PWM13_MAP*8)+3;
static volatile  bit   PWM13_MPIN2                     @ ((unsigned)&PWM13_MAP*8)+2;
static volatile  bit   PWM13_MPIN1                     @ ((unsigned)&PWM13_MAP*8)+1;
static volatile  bit   PWM13_MPIN0                     @ ((unsigned)&PWM13_MAP*8)+0;
/* Definitions for PWM14_MAP register */
static volatile  bit   PWM14_MPORT1                    @ ((unsigned)&PWM14_MAP*8)+4;
static volatile  bit   PWM14_MPORT0                    @ ((unsigned)&PWM14_MAP*8)+3;
static volatile  bit   PWM14_MPIN2                     @ ((unsigned)&PWM14_MAP*8)+2;
static volatile  bit   PWM14_MPIN1                     @ ((unsigned)&PWM14_MAP*8)+1;
static volatile  bit   PWM14_MPIN0                     @ ((unsigned)&PWM14_MAP*8)+0;
/* Definitions for PWM15_MAP  register */
static volatile  bit   PWM15_MPORT1                    @ ((unsigned)&PWM15_MAP*8)+4;
static volatile  bit   PWM15_MPORT0                    @ ((unsigned)&PWM15_MAP*8)+3;
static volatile  bit   PWM15_MPIN2                     @ ((unsigned)&PWM15_MAP*8)+2;
static volatile  bit   PWM15_MPIN1                     @ ((unsigned)&PWM15_MAP*8)+1;
static volatile  bit   PWM15_MPIN0                     @ ((unsigned)&PWM15_MAP*8)+0;


//----------------------------CC_PHY------------------------------------------------
/* Definitions for CRC32CON register */
static volatile  bit	CRCINIT			               @ ((unsigned)&CRC32CON*8)+0;

/* Definitions for BMCRST register */
static volatile bit     SYNC64                         @ ((unsigned)&BMCRST*8)+7;
static volatile bit     SYNC1        	               @ ((unsigned)&BMCRST*8)+6;
static volatile bit     SYNC2    		               @ ((unsigned)&BMCRST*8)+5;
static volatile bit     SYNC3    		               @ ((unsigned)&BMCRST*8)+4;
static volatile bit     RST1                           @ ((unsigned)&BMCRST*8)+3;
static volatile bit     RST2    		               @ ((unsigned)&BMCRST*8)+2;
static volatile bit     EOP     		               @ ((unsigned)&BMCRST*8)+1;
static volatile bit     DATA                           @ ((unsigned)&BMCRST*8)+0;
/* Definitions for PDRCT register */
static volatile bit     PDERR   		               @ ((unsigned)&PDRCT*8)+7;
static volatile bit     OVER                           @ ((unsigned)&PDRCT*8)+6;
static volatile bit     WDT    		                   @ ((unsigned)&PDRCT*8)+5;
static volatile bit     RXFLT_TEREN    		           @ ((unsigned)&PDRCT*8)+4;
static volatile bit     TXINIVAL    		           @ ((unsigned)&PDRCT*8)+3;
static volatile bit     LDO1P2_EN    		           @ ((unsigned)&PDRCT*8)+2;
static volatile bit     CC1SEL    		               @ ((unsigned)&PDRCT*8)+1;
static volatile bit     PDRCEN    		               @ ((unsigned)&PDRCT*8)+0;

 /* Definitions for PDTCT register */
static volatile bit     PDTXDLY3   		               @ ((unsigned)&PDTCT*8)+7;
static volatile bit     PDTXDLY2                       @ ((unsigned)&PDTCT*8)+6;
static volatile bit     PDTXDLY1    		           @ ((unsigned)&PDTCT*8)+5;
static volatile bit     PDTXDLY0    		           @ ((unsigned)&PDTCT*8)+4;
static volatile bit     PDTXBF    		               @ ((unsigned)&PDTCT*8)+3;
static volatile bit     PDTX4BL                        @ ((unsigned)&PDTCT*8)+2;
static volatile bit     PDTX5BL    		               @ ((unsigned)&PDTCT*8)+1;
static volatile bit     PDTXEN     		               @ ((unsigned)&PDTCT*8)+0;
/* Definitions for MCTCON register */
static volatile bit     MCSAMPE5                       @ ((unsigned)&MCTCON*8)+7;
static volatile bit     MCSAMPE4                       @ ((unsigned)&MCTCON*8)+6;
static volatile bit     MCSAMPE3                       @ ((unsigned)&MCTCON*8)+5;
static volatile bit     MCSAMPE2                       @ ((unsigned)&MCTCON*8)+4;
static volatile bit     MCSAMPE1                       @ ((unsigned)&MCTCON*8)+3;
static volatile bit     MCSAMPE0                       @ ((unsigned)&MCTCON*8)+2;
static volatile bit     MCTON                          @ ((unsigned)&MCTCON*8)+0;
//----------------------------CC_PU_PD-------------------------------------------
/* Definitions for CCRPCON0 register */
static volatile bit     CC2PDEN    		               @ ((unsigned)&CCRPCON0*8)+7;
static volatile bit     CC1PDEN    		               @ ((unsigned)&CCRPCON0*8)+6;
static volatile bit     CUR21                          @ ((unsigned)&CCRPCON0*8)+5;
static volatile bit     CUR20        	               @ ((unsigned)&CCRPCON0*8)+4;
static volatile bit     TEMP_SW         	           @ ((unsigned)&CCRPCON0*8)+3;
static volatile bit     CCAB_SEL        	           @ ((unsigned)&CCRPCON0*8)+2;
static volatile bit     CUR11    		               @ ((unsigned)&CCRPCON0*8)+1;
static volatile bit     CUR10    	                   @ ((unsigned)&CCRPCON0*8)+0;
 /* Definitions for CCRPCON1 register */
static volatile bit     RP_TRIM4    		           @ ((unsigned)&CCRPCON1*8)+7;
static volatile bit     RP_TRIM3    		           @ ((unsigned)&CCRPCON1*8)+6;
static volatile bit     RP_TRIM2    		           @ ((unsigned)&CCRPCON1*8)+5;
static volatile bit     RP_TRIM1    		           @ ((unsigned)&CCRPCON1*8)+4;
static volatile bit     RP_TRIM0    		           @ ((unsigned)&CCRPCON1*8)+3;
static volatile bit     PDRXOUTEN    		           @ ((unsigned)&CCRPCON1*8)+2;
static volatile bit     RP2EN    		               @ ((unsigned)&CCRPCON1*8)+1;
static volatile bit     RP1EN    		               @ ((unsigned)&CCRPCON1*8)+0;
 /* Definitions for BMCTX register */
static volatile bit     PD_DTEN    		               @ ((unsigned)&BMCTX*8)+7;
static volatile bit     CCDAT    		               @ ((unsigned)&BMCTX*8)+6;
static volatile bit     DT3    		                   @ ((unsigned)&BMCTX*8)+3;
static volatile bit     DT2    		                   @ ((unsigned)&BMCTX*8)+2;
static volatile bit     DT1    		                   @ ((unsigned)&BMCTX*8)+1;
static volatile bit     DT0    		                   @ ((unsigned)&BMCTX*8)+0;


#define ROMSIZE 64 * 1024
#define RAMSIZE 256

#define EEPROM_SIZE 256

/* Macros to access bytes within words and words within longs */
#define LOW_BYTE(x)     ((unsigned char)((x)&0xFF))
#define HIGH_BYTE(x)    ((unsigned char)(((x)>>8)&0xFF))
#define LOW_WORD(x)     ((unsigned short)((x)&0xFFFF))
#define HIGH_WORD(x)    ((unsigned short)(((x)>>16)&0xFFFF))

/* C access to assembler insructions */
#define	CLRWDT()	    asm(" clrwdt")
#define	NOP()		    asm(" nop")
#define	RESET()		    asm(" reset")
#define SLEEP()		    asm(" sleep")

#define	___mkstr1(x)	#x
#define	___mkstr(x)	___mkstr1(x)

/* Store a word value to a particular configuration word register eg.
 * __CONFIG(4, DEBUGEN & LVPDIS); // write to config word 4
 * config mask attributes (such as DEBUGEN) defined in chip-specific
 * header file. */
#define	__CONFIG(n, x)	asm("\tpsect config,class=CONFIG");\
			asm("global config_word" ___mkstr(n)); \
			asm("\torg ("___mkstr(n)"-1)*2"); \
			asm("config_word" ___mkstr(n)":"); \
			asm("\tdw "___mkstr(x))


#define __IDLOC(w)      asm("\tpsect idloc,class=IDLOC");\
			asm("\tglobal\tidloc_word"); \
			asm("idloc_word:"); \
			asm("\tirpc\t__arg," ___mkstr(w)); \
			asm("\tdb 0f&__arg&h"); \
			asm("\tendm")


/* Address definitions for config word registers
 * (NOT TO BE USED WITH __CONFIG MACRO!) */
#define CONFIG1L	0x300000
#define CONFIG1H	0x300001
#define CONFIG2L	0x300002
#define CONFIG2H	0x300003
#define CONFIG3L	0x300004
#define CONFIG3H	0x300005
#define CONFIG4L	0x300006
#define CONFIG4H	0x300007
#define CONFIG5L	0x300008
#define CONFIG5H	0x300009
#define CONFIG6L	0x30000A
#define CONFIG6H	0x30000B
#define CONFIG7L	0x30000C
#define CONFIG7H	0x30000D

//;----- CONFIG0 Options --------------------------------------------------------

#define   _LVT22V_1L              0xFFF2     // LVR-out Reset set to 2.2V
#define   _LVT24V_1L              0xFFF3     // LVR-out Reset set to 2.4V
#define   _LVT26V_1L              0xFFF4     // LVR-out Reset set to 2.6V
#define   _LVT27V_1L              0xFFF5     // LVR-out Reset set to 2.7V
#define   _LVT29V_1L              0xFFF6     // LVR-out Reset set to 2.9V
#define   _LVT30V_1L              0xFFF7     // LVR-out Reset set to 3.0V
#define   _LVT31V_1L              0xFFF8     // LVR-out Reset set to 3.1V
#define   _LVT33V_1L              0xFFF9     // LVR-out Reset set to 3.3V
#define   _LVT36V_1L              0xFFFA     // LVR-out Reset set to 3.6V
#define   _LVT37V_1L              0xFFFB     // LVR-out Reset set to 3.7V
#define   _LVT38V_1L              0xFFFC     // LVR-out Reset set to 3.8V
#define   _LVT41V_1L              0xFFFD     // LVR-out Reset set to 4.1V
#define   _LVT42V_1L              0xFFFE     // LVR-out Reset set to 4.2V
#define   _LVT43V_1L              0xFFFF     // LVR-out Reset set to 4.3V


#define   _LVREN_ON_1L              0xFFFF    //  Enable  LVR  reset
#define   _LVREN_OFF_1L             0xFFEF    //  Disable LVR  reset

#define   _FINTOSC_DIV1_1L           0xFFFF     // Fosc DIVIDER 1:1  7
#define   _FINTOSC_DIV2_1L           0xFFDF     // Fosc DIVIDER 1:2  6
#define   _FINTOSC_DIV4_1L           0xFFBF     // Fosc DIVIDER 1:4  5
#define   _FINTOSC_DIV8_1L           0xFF9F     // Fosc DIVIDER 1:8  4
#define   _FINTOSC_DIV16_1L          0xFF5F     // Fosc DIVIDER 1:16 2

//;----- CONFIG1 Options --------------------------------------------------------
#define   _STV_OFF_2L               0xFFFE		//	Stack overflow reset disable
#define   _STV_ON_2L                0xFFFF		//  Stack overflow reset enable

#define  _RSEL_LOW_2L               0xFFFD		//   pullup 190K,pulldown 300K
#define  _RSEL_HIGH_2L              0xFFFF		//   pullup  30K, pulldown 30K

#define  _RESETE_ON_2L              0xFFFF		//  Reset Pin enable
#define  _RESETE_OFF_2L             0xFFFB		//  Reset Pin disable

#define  _CBP_ON_2L                0xFFFF		//  Program code encrypte enable
#define  _CBP_OFF_2L               0xFFF7		//  Program code encrypte disable

#define  _CKSUM_OFF_2L             0xFFEF		// 	cksum  disable
#define  _CKSUM_ON_2L              0xFFFF		//  cksum  enable

#define  _IDIS_OFF_2L              0xFFDF		//	 Read  data is always 0
#define  _IDIS_ON_2L               0xFFFF		//   Normal read data

#define  _CRYHEN_ON_2L             0xFFFF		//Enable the external crystal high-frequency oscillator
#define  _CRYHEN_OFF_2L            0xFFBF	    // disable the external crystal high-frequency oscillator

#define  _CRYLEN_ON_2L             0xFFFF		// Enable the external crystal low-frequency oscillator
#define  _CRYLEN_OFF_2L            0xFF7F		// disable the external crystal low-frequency oscillator

#define  _FLASH_CP0_ON_2L          0xFFFF		// flash space 0-1k protect enbale
#define  _FLASH_CP0_OFF_2L         0xFEFF		// flash space 0-1k protect disbale

#define  _FLASH_CP1_ON_2L          0xFFFF		// flash space 1k-2k protect enbale
#define  _FLASH_CP1_OFF_2L         0xFDFF		// flash space 1k-2k protect disbale

#define  _FLASH_CP2_ON_2L          0xFFFF		// flash space 2k-3k protect enbale
#define  _FLASH_CP2_OFF_2L         0xFBFF		// flash space 2k-3k protect disbale

#define  _FLASH_CP3_ON_2L          0xFFFF		// flash space 3k-4k protect enbale
#define  _FLASH_CP3_OFF_2L         0xF7FF		// flash space 3k-4k protect disbale

#define  _FLASH_CP4_ON_2L          0xFFFF		// flash space 4k-5k protect enbale
#define  _FLASH_CP4_OFF_2L         0xEFFF		// flash space 4k-5k protect disbale

#define  _FLASH_CP5_ON_2L          0xFFFF		// flash space 5k-6k protect enbale
#define  _FLASH_CP5_OFF_2L         0xDFFF		// flash space 5k-6k protect disbale

#define  _FLASH_CP6_ON_2L          0xFFFF		// flash space 6k-7k protect enbale
#define  _FLASH_CP6_OFF_2L         0xBFFF		// flash space 6k-7k protect disbale

#define  _FLASH_CP7_ON_2L          0xFFFF		// flash space 7k-8k protect enbale
#define  _FLASH_CP7_OFF_2L         0x7FFF		// flash space 7k-8k protect disbale


//;-------CONFIG2 Options --------------------------------------------------------
#define  _TWDT_111_3L              0xFFFF		// WDT overflow time 8.32s
#define  _TWDT_110_3L              0xFFFE		// WDT overflow time 4.224s
#define  _TWDT_101_3L              0xFFFD		// WDT overflow time 2.176s
#define  _TWDT_100_3L              0xFFFC		// WDT overflow time 1.152s
#define  _TWDT_011_3L              0xFFFB		// WDT overflow time 640ms
#define  _TWDT_010_3L              0xFFFA		// WDT overflow time 384ms
#define  _TWDT_001_3L              0xFFF9		// WDT overflow time 256ms
#define  _TWDT_000_3L              0xFFF8		// WDT overflow time 128ms

#define  _WDTEN_OFF_3L             0xFFF7		//   WDT disabled
#define  _WDTEN_ON_3L              0xFFFF		//   WDT enabled

#define  _FCPU_4T_3L               0xFFFF		//   4 Instruction cycle
#define  _FCPU_2T_3L               0xFFEF		//   2 Instruction cycle

#define  _PSUT_128_3L              0xFFFF		//  Power on delay  21ms
#define  _PSUT_64_3L               0xFFDF		//  Power on delay  12.6ms
#define  _PSUT_32_3L               0xFFBF		//  Power on delay  307ms
#define  _PSUT_16_3L               0xFF9F		//  Power on delay  78ms
#define  _PSUT_8_3L                0xFF7F		//  Power on delay  625ms
#define  _PSUT_4_3L                0xFF5F		//  Power on delay  1235ms
#define  _PSUT_2_3L                0xFF3F		//  Power on delay  2093ms
#define  _PSUT_1_3L                0xFF1F		//  Power on delay  2.5ms

//;-----  CONFIG3 Options --------------------------------------------------------
#define  _MAPEN_OFF_4L              0xFFFE    // disable MAP register
#define  _MAPEN_ON_4L               0xFFFF    // enableable MAP register

#define  _IESO_OFF_4L              0xFFFD    // disable dual-speed boot mode
#define  _IESO_ON_4L               0xFFFF    // enable dual-speed boot mode

#define  _FCMEN_OFF_4L             0xFFFB    // disable System clock failure monitoring
#define  _FCMEN_ON_4L              0xFFFF    // enable System clock failure monitoring


#define _BBP_ON_4L                0xFFFF     // disable the BOOT LOADER  for  the first 512bytes FLASH
#define _BBP_OFF_4L               0xFFF7     // enable the BOOT LOADER  for  the first 512bytes FLASH


#define _ENVDDL_ON_4L              0xFFFF    //enable  Low voltage read of FLASH
#define _ENVDDL_OFF_4L             0xFFEF    //disable  Low voltage read of FLASH


#define  _DBG_ON_4L                0xFFFF	//  enable   DBG mode
#define  _DBG_OFF_4L               0xFFDF	//  disable  DBG  mode


#define  _OSCM_HIRC_16M_4L         0xFFFF    // HIRC(16MHZ) AS MAIN CLOCK
#define  _OSCM_LIRC_1M_4L          0xFFBF    // LIRC(1MHZ) AS MAIN CLOCK
#define  _OSCM_LXTH_16M_4L         0xFF7F    // CRYSTALL HIGH(16MHZ) AS MAIN CLOCK
#define  _OSCM_LIRC_32K_4L         0xFF3F    // LIRC(32KHZ) AS MAIN CLOCK


/* Initialise device EEPROM (if available) with 8 bytes of data at a time eg.
 * // store initial values to first 16-bytes of EEPROM address range.
 * __EEPROM_DATA(0x00,0x01,0x02,0x03,0x04,0x05,0x06,0x07);
 * __EEPROM_DATA(0x08,0x09,0x0A,0x0B,0x0C,0x0D,0x0E,0x0F);*/
#if _EEPROMSIZE > 0
 #define __EEPROM_DATA(a, b, c, d, e, f, g, h) \
			 asm("\tpsect eeprom_data,class=EEDATA"); \
			 asm("\tdb\t" ___mkstr(a) "," ___mkstr(b) "," ___mkstr(c) "," ___mkstr(d) "," \
				      ___mkstr(e) "," ___mkstr(f) "," ___mkstr(g) "," ___mkstr(h))
#else
 #define __EEPROM_DATA(a, b, c, d, e, f, g, h)	// Added only for code portability
#endif

// Various helper macros used in EEPROM/flash routines
#if	_EEPROMSIZE > 256
 #define _LOAD_EEADR(addr)	(EEADRH=(((addr)>>8)&0xFF),EEADR=((addr)&0xFF))
#else
 #define _LOAD_EEADR(addr)	(EEADR=((addr)&0xFF))
#endif

#if	_EEPROMSIZE > 0
 #define _CLEAR_EEIF()	EEIF=0
#else
 #define _CLEAR_EEIF()
#endif

#if defined(SMALL_DATA)
 #define _LOAD_TBLPTR(addr)	TBLPTRU=0;TBLPTR=(far unsigned char*)(addr)
#else
 #define _LOAD_TBLPTR(addr)	TBLPTR=(far unsigned char*)(addr)
#endif

#if(_EEPROMSIZE == 0)
 #define EEPROM_READ(addr)	0	// Added only for code portability
#elif	(_ERRATA_TYPES & ERRATA_EEDATARD)
	/* For chips which must read EEDATA immediately after RD is
	 * set, EEDATA is read into temp variable EEADR because, if
	 * the result of EEPROM_READ is returned to an indirect
	 * object, it may take several instructions to set up access
	 * to that object. */
 #define EEPROM_READ(addr)   \
	 (_LOAD_EEADR(addr),\
	 CARRY=GIE,GIE=0,   \
	 EECON1&=0x3F,RD=1, \
	 EEADR=EEDATA,	    \
	 GIE=CARRY,	    \
	 (EEADR))
#else 	/* Plain and simple version */
 #define EEPROM_READ(addr)    \
	 (_LOAD_EEADR(addr),  \
	 EECON1&=0x3F,RD=1,   \
	 (EEDATA))
#endif

#if(_EEPROMSIZE == 0)
 #define EEPROM_WRITE(addr, value)	// Added only for code portability
#else
 #define EEPROM_WRITE(addr, value)			\
	do{						\
		while(WR)continue;			\
		_LOAD_EEADR(addr);			\
		EEDATA=(value);				\
		EECON1&=0x3F;				\
		CARRY=0;if(GIE)CARRY=1;GIE=0;		\
		WREN=1;EECON2=0x55;EECON2=0xAA;WR=1;	\
		_CLEAR_EEIF();WREN=0;			\
		if(CARRY)GIE=1;				\
	}while(0)
#endif



#endif
