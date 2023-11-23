/********************************************/
/*  author: Mohamed Walid               	*/
/*  version: V03                            */
/*  Date: 18 NOV 2023	   					*/
/*  SWC : TIM2                   			*/
/********************************************/


#ifndef		TIM2_REG_H
#define 	TIM2_REG_H

#define 	TCCR2  		(*((volatile uint8 *) 0x45))
#define     TCCR2_CS20          0
#define     TCCR2_CS21          1
#define     TCCR2_CS22          2
#define     TCCR2_WGM21         3
#define     TCCR2_COM20         4
#define     TCCR2_COM21         5
#define     TCCR2_WGM20         6
#define     TCCR2_FOC2          7


#define 	TCNT2  		(*((volatile uint8 *) 0x44))
#define 	OCR2		(*((volatile uint8 *) 0x43))
#define 	TIMSK	  	(*((volatile uint8 *) 0x59))
#define     TIMSK_TOIE2         6
#define     TIMSK_OCIE2         7


#define 	TIFR		(*((volatile uint8 *) 0x58))
#define     TIFR_TOV2           6
#define     TIFR_OCF2           7

#define		ASSR		(*((volatile uint8 *) 0x42))


#endif
