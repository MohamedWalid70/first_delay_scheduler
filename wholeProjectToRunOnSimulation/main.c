#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "PORT_int.h"
#include "DIO_int.h"
#include "GI_int.h"
#include "SCHED_int.h"
//#include "EXTI_int.h"
//#include <util/delay.h>

void led_toggle1(void*);
void led_toggle2(void*);
void led_toggle3(void*);
void led_toggle4(void*);
void led_toggle5(void*);

/*
void ex_fun(void){

	SCHED_voidResumeTask(1);
}
*/

void main(void){

	PORT_voidInit();
	GI_voidEnable();
	SCHED_voidInit();
	//EXTI_voidInit();
	//EXTI_voidSetCallbackFun(EXTI_INT_0,&ex_fun);

	SCHED_enumAddTask(&led_toggle1,1000,0,0,1);
	SCHED_enumAddTask(&led_toggle2,2000,1000,1,2);
	SCHED_enumAddTask(&led_toggle3,3000,0,2,3);
	SCHED_enumAddTask(&led_toggle4,4000,0,3,4);
	SCHED_enumAddTask(&led_toggle5,5000,0,4,5);

	SCHED_voidStart();

	while(1);


}

void led_toggle1(void* pvparam){

	static uint8 var=0;
	DIO_voidSetPinValue(DIO_PIN_NO_0,TOGGLE_BIT(var,0));

}
void led_toggle2(void* pvparam){

	static uint8 var=0;
	DIO_voidSetPinValue(DIO_PIN_NO_1,TOGGLE_BIT(var,0));

}
void led_toggle3(void* pvparam){

	static uint8 var=0,counter=0;
	DIO_voidSetPinValue(DIO_PIN_NO_2,TOGGLE_BIT(var,0));
	if(counter==1)
		SCHED_voidSuspendTask(1);
	counter++;

}
void led_toggle4(void* pvparam){

	static uint8 var=0;
	DIO_voidSetPinValue(DIO_PIN_NO_3,TOGGLE_BIT(var,0));

}
void led_toggle5(void* pvparam){

	static uint8 var=0,counter=0;
	DIO_voidSetPinValue(DIO_PIN_NO_4,TOGGLE_BIT(var,0));
	if(counter==2){
		SCHED_voidResumeTask(1);
		/*	just for the purpose of debugging
		_delay_ms(1000);
		DIO_voidSetPinValue(DIO_PIN_NO_5,DIO_PIN_HIGH);
		*/
	}
	counter++;
}
