/********************************************/
/*  author: Mohamed Walid               	*/
/*  version: V02                            */
/*  Date: 22 OCT 2023 	  					*/
/*  SWC : GI	                   			*/
/********************************************/

#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "GI_int.h"
#include "GI_reg.h"

void GI_voidEnable(void){

	SET_BIT(SREG,Global_EXTI);
}

void GI_voidDisable(void){

	CLEAR_BIT(SREG,Global_EXTI);
}
