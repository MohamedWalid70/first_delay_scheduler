/********************************************/
/*  author: Mohamed Walid               	*/
/*  version: V02                            */
/*  Date: 19 OCT 2023   					*/
/*  SWC : DIO                   			*/
/********************************************/


#ifndef		DIO_REG_H
#define		DIO_REG_H


#define PORTA (*((volatile uint8 *) 0x3B))
#define PORTB (*((volatile uint8 *) 0x38))
#define PORTC (*((volatile uint8 *) 0x35))
#define PORTD (*((volatile uint8 *) 0x32))

#define PINA  (*((volatile uint8 *) 0x39))
#define PINB  (*((volatile uint8 *) 0x36))
#define PINC  (*((volatile uint8 *) 0x33))
#define PIND  (*((volatile uint8 *) 0x30))


#endif
