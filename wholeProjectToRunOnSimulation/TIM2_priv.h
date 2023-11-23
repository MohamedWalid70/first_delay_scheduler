/********************************************/
/*  author: Mohamed Walid               	*/
/*  version: V03                            */
/*  Date: 18 NOV 2023	   					*/
/*  SWC : TIM2                   			*/
/********************************************/


#ifndef		TIM2_PRIV_H
#define 	TIM2_PRIV_H

#define 	TIM2_NORMAL_MODE							1
#define 	TIM2_CTC_MODE								3
#define 	TIM2_FAST_PWM_MODE							5
#define 	TIM2_PHASE_CORRECT_PWM_MODE					7


#define 	TIM2_PRESCALER_CLK_BY_1					1
#define 	TIM2_PRESCALER_CLK_BY_8					2
#define 	TIM2_PRESCALER_CLK_BY_32				3
#define 	TIM2_PRESCALER_CLK_BY_64				4
#define 	TIM2_PRESCALER_CLK_BY_128				5
#define 	TIM2_PRESCALER_CLK_BY_256				6
#define 	TIM2_PRESCALER_CLK_BY_1024				7



#define     TIM2_PWM_INVERTED                  1
#define     TIM2_PWM_NON_INVERTED              2


#define 	TIM2_CLK_PRESCALER_1				1
#define 	TIM2_CLK_PRESCALER_8				8
#define 	TIM2_CLK_PRESCALER_32				32
#define 	TIM2_CLK_PRESCALER_64				64
#define 	TIM2_CLK_PRESCALER_128				128
#define 	TIM2_CLK_PRESCALER_256				256
#define 	TIM2_CLK_PRESCALER_1024				1024


#define		TIM2_TOP_VALUE					   255

#define		TIM2_TOP_VALUE_PLUS_1			   256

#define 	TIM2_CTC_VALUE					   249
#define 	TIM2_CTC_VALUE_PLUS_1			   250

#define		TIM2_TCCR2_PRESCALER_MASK		   0xF8


#define     TIM2_ASYNCH_FUNC_USED              2
#define     TIM2_ASYNCH_FUNC_NOT_USED          4


#endif
