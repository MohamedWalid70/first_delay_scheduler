/********************************************/
/*  author: Mohamed Walid               	*/
/*  version: V03                            */
/*  Date: 18 NOV 2023	   					*/
/*  SWC : TIM2                   			*/
/********************************************/

#ifndef		TIM2_INT_H
#define 	TIM2_INT_H

#define		TIM2_DELAY_SINGLE		1
#define		TIM2_DELAY_CONTINUOUS	2


void TIM2_voidInit(void);

void TIM2_voidStop(void);

void TIM2_voidSetBusyWaitSynch(uint16 copy_uint16_periodInMilliSeconds);

/*
 * copy_uint8DelayType parameter options :
 *
 *        TIM2_DELAY_SINGLE
 *        TIM2_DELAY_CONTINUOUS
 *
 */

void TIM2_voidSetDelayAsynch_ms(uint16 copy_uint16Delay_ms, uint8 copy_uint8DelayType);

void TIM2_voidClearCounter(void);

uint8 TIM2_uint8ReadCounter(void);

void TIM2_voidStart(void);

void TIM2_voidSetCallBackFunc(void (*copy_fptrCallBackFunc) (void));

void TIM2_voidSetCompareMatchValue(uint8 copy_uint8CompareMatchValue);

void TIM2_voidGeneratePWMSignal(uint8 copy_uint8SignalDC);

void TIM2_voidGeneratePhaseCorrectPWMSignal(uint8 copy_uint8SignalDC);

void TIM2_voidDisableTOVInt(void);

void TIM2_voidEnableTOVInt(void);

void TIM2_voidEnableOCMInt(void);

void TIM2_voidDisableOCMInt(void);


#endif
