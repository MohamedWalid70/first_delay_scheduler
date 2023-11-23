/********************************************/
/*  author: Mohamed Walid               	*/
/*  version: V03                            */
/*  Date: 18 NOV 2023	   					*/
/*  SWC : TIM2                   			*/
/********************************************/


#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "TIM2_int.h"
#include "TIM2_priv.h"
#include "TIM2_config.h"
#include "TIM2_reg.h"

static uint16 private_uint16msTicksCount;
static uint32 private_uint32CounterMax;
static uint8 private_uint8DelayType;
static void (*private_fptrCallBackFunc)(void)=NULL;		// since only one mode is selected, there is only one pointer to function

void TIM2_voidInit(void){
	
	private_uint16msTicksCount = TIM2_TICK_TIME_INVERSE;
	
#if  TIM2_MODE == TIM2_NORMAL_MODE
	
	CLEAR_BIT(TCCR2,TCCR2_WGM21);
	CLEAR_BIT(TCCR2,TCCR2_WGM20);
	
	
	CLEAR_BIT(TCCR2,TCCR2_COM20);			// disconnecting OC0 (Normal bit operation)
	CLEAR_BIT(TCCR2,TCCR2_COM21);


#elif	TIM2_MODE == TIM2_CTC_MODE

	SET_BIT(TCCR2,TCCR2_WGM21);
	CLEAR_BIT(TCCR2,TCCR2_WGM20);

	CLEAR_BIT(TCCR2,TCCR2_COM20);			// disconnecting OC0 (Normal bit operation)
	CLEAR_BIT(TCCR2,TCCR2_COM21);


#elif	TIM2_MODE == TIM2_FAST_PWM_MODE

	SET_BIT(TCCR2,TCCR2_WGM21);
	SET_BIT(TCCR2,TCCR2_WGM20);


#if		TIM2_PWM_MODE == TIM2_PWM_INVERTED

	SET_BIT(TCCR2,TCCR2_COM20);
	SET_BIT(TCCR2,TCCR2_COM21);

#elif	TIM2_PWM_MODE == TIM2_PWM_NON_INVERTED

	CLEAR_BIT(TCCR2,TCCR2_COM20);
	SET_BIT(TCCR2,TCCR2_COM21);


#endif

#elif	TIM2_MODE == TIM2_PHASE_CORRECT_PWM_MODE

	CLEAR_BIT(TCCR2,TCCR2_WGM21);
	SET_BIT(TCCR2,TCCR2_WGM20);


#if		TIM2_PWM_MODE == TIM2_PWM_INVERTED

	SET_BIT(TCCR2,TCCR2_COM20);
	SET_BIT(TCCR2,TCCR2_COM21);

#elif	TIM2_PWM_MODE == TIM2_PWM_NON_INVERTED

	CLEAR_BIT(TCCR2,TCCR2_COM20);
	SET_BIT(TCCR2,TCCR2_COM21);


#endif



#endif


	TCNT2 = 0;
	
}

#if TIM2_MODE == TIM2_NORMAL_MODE

void TIM2_voidSetBusyWaitSynch(uint16 copy_uint16_periodInMilliSeconds){
	
	uint8 local_uint8preloadValue;

	if(private_uint16msTicksCount>TIM2_TOP_VALUE_PLUS_1){

		uint8 local_uint8Count= private_uint16msTicksCount/TIM2_TOP_VALUE_PLUS_1;

		if(private_uint16msTicksCount%TIM2_TOP_VALUE_PLUS_1!=0){

			local_uint8Count++;

			local_uint8preloadValue = TIM2_TOP_VALUE_PLUS_1-(private_uint16msTicksCount%TIM2_TOP_VALUE_PLUS_1);

		}
		else{

			local_uint8preloadValue = 0;

		}


		for(uint16 j=0;j<copy_uint16_periodInMilliSeconds;j++){

			TCNT2 = local_uint8preloadValue;

			for(uint8 i=0;i<local_uint8Count;i++){

				while(GET_BIT(TIFR,TIFR_TOV2)==0);			// waiting for the TOV2 to be set
				SET_BIT(TIFR,TIFR_TOV2);							// clearing the TOV2 flag
															// counting a millisecond
			}
		}

	}
	else{


		local_uint8preloadValue = TIM2_TOP_VALUE_PLUS_1 - private_uint16msTicksCount;
		for(uint16 j=0;j<copy_uint16_periodInMilliSeconds;j++){

			TCNT2 = local_uint8preloadValue;
			while(GET_BIT(TIFR,TIFR_TOV2)==0);			// waiting for the TOV0 to be set
			SET_BIT(TIFR,TIFR_TOV2);							// clearing the TOV0 flag
													// counting a millisecond
		}
	}

}
#endif


void TIM2_voidSetDelayAsynch_ms(uint16 copy_uint16Delay_ms, uint8 copy_uint8DelayType){

#if TIM2_MODE==TIM2_NORMAL_MODE

	SET_BIT(TIMSK,TIMSK_TOIE2);		// enabling OVF interrupt

	// overflow method
	uint32	local_uint32TicksNO = (uint32)copy_uint16Delay_ms * TIM2_TICK_TIME_INVERSE;		// number of ticks need to get the required delay
	TCNT2 = TIM2_TOP_VALUE_PLUS_1-(local_uint32TicksNO % TIM2_TOP_VALUE_PLUS_1) ;	 // preload value

	private_uint32CounterMax = (local_uint32TicksNO/TIM2_TOP_VALUE_PLUS_1)+1;						// counter value + preload cycle


#elif TIM2_MODE==TIM2_CTC_MODE

	SET_BIT(TIMSK,TIMSK_OCIE2);		// enabling OCM interrupt

	uint32	local_uint32TicksNO = (uint32)copy_uint16Delay_ms * TIM2_TICK_TIME_INVERSE;		// number of ticks need to get the required delay

	if((local_uint32TicksNO%TIM2_CTC_VALUE_PLUS_1)!=0){

		if(local_uint32TicksNO<=TIM2_CTC_VALUE_PLUS_1){

			OCR2 = local_uint32TicksNO-1;
			private_uint32CounterMax = 1;
		}
		else if(local_uint32TicksNO>TIM2_CTC_VALUE_PLUS_1){

			OCR2 = TIM2_CTC_VALUE;
			TCNT2 = TIM2_CTC_VALUE_PLUS_1 - (local_uint32TicksNO % TIM2_CTC_VALUE_PLUS_1);
			private_uint32CounterMax = local_uint32TicksNO / TIM2_CTC_VALUE_PLUS_1;

		}

	}
	else{

		OCR2 = TIM2_CTC_VALUE;
		private_uint32CounterMax = local_uint32TicksNO / TIM2_CTC_VALUE_PLUS_1;

	}

#endif

	private_uint8DelayType = copy_uint8DelayType;


}



uint8 TIM2_uint8ReadCounter(void){

	return TCNT2;
}


void TIM2_voidStop(void){
	
	TCCR2 &= TIM2_TCCR2_PRESCALER_MASK;
	
}

void TIM2_voidStart(void){

	TCCR2 &= TIM2_TCCR2_PRESCALER_MASK;
	TCCR2 |= TIM2_PRESCALER_CHOICE;
	
}

void TIM2_voidClearCounter(void){

	TCCR2 &= TIM2_TCCR2_PRESCALER_MASK;			// stopping timer
	TCNT2=0;
	TCCR2 |= TIM2_PRESCALER_CHOICE;				// starting timer
}

void TIM2_voidEnableTOVInt(void){

	SET_BIT(TIMSK,TIMSK_TOIE2);
}

void TIM2_voidDisableTOVInt(void){

	CLEAR_BIT(TIMSK,TIMSK_TOIE2);
}

void TIM2_voidEnableOCMInt(void){

	SET_BIT(TIMSK,TIMSK_OCIE2);
}

void TIM2_voidDisableOCMInt(void){

	CLEAR_BIT(TIMSK,TIMSK_OCIE2);
}


void TIM2_voidSetCallBackFunc(void (*copy_fptrCallBackFunc) (void)){

	if (copy_fptrCallBackFunc != NULL) {

			private_fptrCallBackFunc = copy_fptrCallBackFunc;

	}
}

void TIM2_voidSetCompareMatchValue(uint8 copy_uint8CompareMatchValue){

	OCR2 = copy_uint8CompareMatchValue;
}

#if	TIM2_MODE == TIM2_FAST_PWM_MODE

void TIM2_voidGeneratePWMSignal(uint8 copy_uint8SignalDC){

#if		TIM2_PWM_MODE == TIM2_PWM_NON_INVERTED

	if((copy_uint8SignalDC>0)&&(copy_uint8SignalDC<101))
		OCR2 = (((uint16)copy_uint8SignalDC * TIM2_TOP_VALUE_PLUS_1)/100)-1;  // because of the OVF tick

#elif 	TIM2_PWM_MODE == TIM2_PWM_INVERTED

	if((copy_uint8SignalDC>=0)&&(copy_uint8SignalDC<100)){

		copy_uint8SignalDC = 100 - copy_uint8SignalDC;
		OCR2 = (((uint16)copy_uint8SignalDC * TIM2_TOP_VALUE_PLUS_1)/100)-1;
	}
#endif

}

#elif TIM2_MODE == TIM2_PHASE_CORRECT_PWM_MODE

void TIM2_voidGeneratePhaseCorrectPWMSignal(uint8 copy_uint8SignalDC){

#if		TIM2_PWM_MODE == TIM2_PWM_NON_INVERTED

		OCR2 = (((uint16)copy_uint8SignalDC * TIM2_TOP_VALUE)/100);

#elif 	TIM2_PWM_MODE == TIM2_PWM_INVERTED


		copy_uint8SignalDC = 100 - copy_uint8SignalDC;
		OCR2 = (((uint16)copy_uint8SignalDC * TIM2_TOP_VALUE)/100);

#endif

}

#endif

void __vector_4(void)	__attribute__((signal, used));		// OCM interrupt
void __vector_4(void){

#if (TIM2_MODE==TIM2_CTC_MODE) && (TIM2_ASYNCH_FUNC_USE_STATE==TIM2_ASYNCH_FUNC_USED)

	static uint32 local_uint32Counter = 0;
	local_uint32Counter++;
	if(local_uint32Counter==private_uint32CounterMax){
		local_uint32Counter=0;
		private_fptrCallBackFunc();
		if(TIM2_DELAY_SINGLE==private_uint8DelayType){
			CLEAR_BIT(TIMSK, TIMSK_OCIE2);					// disabling interrupt
		}
	}
#elif (TIM2_MODE==TIM2_CTC_MODE) && (TIM2_ASYNCH_FUNC_USE_STATE==TIM2_ASYNCH_FUNC_NOT_USED)

	private_fptrCallBackFunc();

#endif

}

void __vector_5(void)	__attribute__((signal, used));		// overflow interrupt
void __vector_5(void){

#if (TIM2_MODE==TIM2_NORMAL_MODE) && (TIM2_ASYNCH_FUNC_USE_STATE==TIM2_ASYNCH_FUNC_USED)

	static uint32 local_uint32Counter = 0;
	local_uint32Counter++;
	if(local_uint32Counter==private_uint32CounterMax){
		local_uint32Counter=0;
		private_fptrCallBackFunc();
		if(private_uint8DelayType == TIM2_DELAY_SINGLE){
			CLEAR_BIT(TIMSK, TIMSK_TOIE2);					// disabling interrupt
		}
	}
#elif (TIM2_MODE==TIM2_NORMAL_MODE) && (TIM2_ASYNCH_FUNC_USE_STATE==TIM2_ASYNCH_FUNC_NOT_USED)

	private_fptrCallBackFunc();

#endif

}

