/********************************************/
/*  author: Mohamed Walid               	*/
/*  version: V02                            */
/*  Date: 19 OCT 2023   					*/
/*  SWC : DIO                   			*/
/********************************************/



#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "DIO_int.h"
#include "DIO_reg.h"
#include "DIO_priv.h"


void DIO_voidSetPinValue(uint8 copy_uint8PinNO , uint8 copy_uint8PinValue){

	if(copy_uint8PinNO<=DIO_PORT_A_END ){

       if(copy_uint8PinValue==DIO_PIN_HIGH){

    	   SET_BIT(PORTA , copy_uint8PinNO);

       }else{

    	   CLEAR_BIT(PORTA , copy_uint8PinNO);
       }

	}else if(copy_uint8PinNO>=DIO_PORT_B_START && copy_uint8PinNO<=DIO_PORT_B_END ){

	       if(copy_uint8PinValue==DIO_PIN_HIGH){

	    	   SET_BIT(PORTB , copy_uint8PinNO%DIO_PORT_SIZE);

	       }else{

	    	   CLEAR_BIT(PORTB , copy_uint8PinNO%DIO_PORT_SIZE);
	       }

	}else if(copy_uint8PinNO>=DIO_PORT_C_START && copy_uint8PinNO<=DIO_PORT_C_END ){

	       if(copy_uint8PinValue==DIO_PIN_HIGH){

	    	   SET_BIT(PORTC , copy_uint8PinNO%DIO_PORT_SIZE);

	       }else{

	    	   CLEAR_BIT(PORTC , copy_uint8PinNO%DIO_PORT_SIZE);
	       }

	}else if(copy_uint8PinNO>=DIO_PORT_D_START){

	       if(copy_uint8PinValue==DIO_PIN_HIGH){

	    	   SET_BIT(PORTD , copy_uint8PinNO%DIO_PORT_SIZE);

	       }else{

	    	   CLEAR_BIT(PORTD , copy_uint8PinNO%DIO_PORT_SIZE);
	       }
	}

}

void DIO_voidSetPortNibbleValue(uint8 copy_uint8Port, uint8 copy_uint8NibbleValue, uint8 copy_uint8PortNibble){

	switch(copy_uint8Port){

		case DIO_PORT_A:

			if(copy_uint8PortNibble==DIO_PORT_LOWER_NIBBLE){
				PORTA &= DIO_LOWER_NIBBLE_MASK;
				PORTA |= copy_uint8NibbleValue>>4;
			}
			else{
				PORTA &= DIO_HIGHER_NIBBLE_MASK;
				PORTA |= copy_uint8NibbleValue<<4;
			}
			break;

		case DIO_PORT_B:

			if(copy_uint8PortNibble==DIO_PORT_LOWER_NIBBLE){
				PORTB &= DIO_LOWER_NIBBLE_MASK;
				PORTB |= copy_uint8NibbleValue>>4;
			}
			else{
				PORTB &= DIO_HIGHER_NIBBLE_MASK;
				PORTB |= copy_uint8NibbleValue<<4;
			}
			break;
		case DIO_PORT_C:

			if(copy_uint8PortNibble==DIO_PORT_LOWER_NIBBLE){
				PORTC &= DIO_LOWER_NIBBLE_MASK;
				PORTC |= copy_uint8NibbleValue>>4;
			}
			else{
				PORTC &= DIO_HIGHER_NIBBLE_MASK;
				PORTC |= copy_uint8NibbleValue<<4;
			}
			break;
		case DIO_PORT_D:

			if(copy_uint8PortNibble==DIO_PORT_LOWER_NIBBLE){
				PORTD &= DIO_LOWER_NIBBLE_MASK;
				PORTD |= copy_uint8NibbleValue>>4;
			}
			else{
				PORTD &= DIO_HIGHER_NIBBLE_MASK;
				PORTD |= copy_uint8NibbleValue<<4;
			}
			break;
	}

}

uint8 DIO_uint8GetPinValue(uint8 copy_uint8PinNO){

	uint8 Local_uint8Result;

      if(copy_uint8PinNO<=DIO_PORT_A_END ){

    	  if(GET_BIT(PINA , copy_uint8PinNO)==DIO_PIN_HIGH){

    		  Local_uint8Result=DIO_PIN_HIGH;

    	  }else{

    		  Local_uint8Result=DIO_PIN_LOW;

    	  }

      }else if(copy_uint8PinNO>=DIO_PORT_B_START && copy_uint8PinNO<=DIO_PORT_B_END ){

    	  if(GET_BIT(PINB , copy_uint8PinNO%DIO_PORT_SIZE)==DIO_PIN_HIGH){

    		  Local_uint8Result=DIO_PIN_HIGH;

    	  }else{

    		  Local_uint8Result=DIO_PIN_LOW;

    	  }

      }else if(copy_uint8PinNO>=DIO_PORT_C_START && copy_uint8PinNO<=DIO_PORT_C_END ){

    	  if(GET_BIT(PINC , copy_uint8PinNO%DIO_PORT_SIZE)==DIO_PIN_HIGH){

    		  Local_uint8Result=DIO_PIN_HIGH;

    	  }else{

    		  Local_uint8Result=DIO_PIN_LOW;

    	  }

      }else if(copy_uint8PinNO>=DIO_PORT_D_START){

    	  if(GET_BIT(PIND , copy_uint8PinNO%DIO_PORT_SIZE)==DIO_PIN_HIGH){

    		  Local_uint8Result=DIO_PIN_HIGH;

    	  }else{

    		  Local_uint8Result=DIO_PIN_LOW;

    	  }

      }

      return Local_uint8Result;
}
