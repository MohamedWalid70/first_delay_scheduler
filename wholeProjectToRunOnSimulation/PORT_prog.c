/********************************************/
/*  author: Mohamed Walid               	*/
/*  version: V01                            */
/*  Date: 31 JUL 2023   					*/
/*  SWC : PORT                   			*/
/********************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "PORT_int.h"
#include "PORT_config.h"
#include "PORT_priv.h"
#include "PORT_reg.h"


void PORT_voidInit(void){
	
	DDRA = PORTA_DIR_VALUE;
	DDRB = PORTB_DIR_VALUE;
	DDRC = PORTC_DIR_VALUE;
	DDRD = PORTD_DIR_VALUE;
	
	PORTA = PORTA_INITIAL_VALUE;
	PORTB = PORTB_INITIAL_VALUE;
	PORTC = PORTC_INITIAL_VALUE;
	PORTD = PORTD_INITIAL_VALUE;
	
}
