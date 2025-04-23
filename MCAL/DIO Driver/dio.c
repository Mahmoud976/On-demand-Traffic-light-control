
/*
 * dio.c
 *
 * Created: 12/14/2022 4:39:54 AM
 *  Author: mahmoud saleh
 */ 
#include "dio.h"
uint8_t DIO_init(uint8_t pinNumber,uint8_t portNumber,uint8_t direction)
{
	switch (portNumber)
	{
		case  PORT_A:
		if (direction==IN)
		DDRA &=~(1<<pinNumber); //input direction
		else if (direction==OUT)
		DDRA |=(1<<pinNumber);  //output direction
		else return ERROR; //error handling
		break;
		
		case  PORT_B:
		if (direction==IN)
		DDRB &=~(1<<pinNumber); //input direction
		else if (direction==OUT)
		DDRB |=(1<<pinNumber);  //output direction
		else return ERROR; //error handling
		break;
		
		case  PORT_C:
		if (direction==IN)
		DDRC &=~(1<<pinNumber); //input direction
		else if (direction==OUT)
		DDRC |=(1<<pinNumber);  //output direction
		else return ERROR; //error handling
		break;
		
		case  PORT_D:
		if (direction==IN)
		DDRD &=~(1<<pinNumber); //input direction
		else if (direction==OUT)
		DDRD |=(1<<pinNumber);  //output direction
		else return ERROR;  //error handling
		break;
	}
	return OK;
}

uint8_t DIO_write(uint8_t pinNumber,uint8_t portNumber,uint8_t value)
{
	switch (portNumber){

		case  PORT_A:
		if (value==LOW)
		PORTA &=~(1<<pinNumber); //write 0
		else if (value==HIGH)
		PORTA |=(1<<pinNumber);  //write 1
		else return ERROR; //error handling
		break;

		case  PORT_B:
		if (value==LOW)
		PORTB &=~(1<<pinNumber); //write 0
		else if (value==HIGH)
		PORTB |=(1<<pinNumber);  //write 1
		else return ERROR; //error handling
		break;
		
		case  PORT_C:
		if (value==LOW)
		PORTC &=~(1<<pinNumber); //write 0
		else if (value==HIGH)
		PORTC |=(1<<pinNumber);  //write 1
		else return ERROR; //error handling
		break;
		
		case  PORT_D:
		if (value==LOW)
		PORTD &=~(1<<pinNumber); //write 0
		else if (value==HIGH)
		PORTD |=(1<<pinNumber);  //write 1
		else return ERROR; //error handling
		break;
	}
return OK;	}

uint8_t DIO_toggel(uint8_t pinNumber,uint8_t portNumber)
{
	switch (portNumber){
		case  PORT_A:
		if(PORTA ^=(1<<pinNumber))return OK;  //write 0 if =1 or  write 1 if =0
		return ERROR;
		
		case  PORT_B:
		if(PORTB ^=(1<<pinNumber))return OK;  //write 0 if =1 or  write 1 if =0
		return ERROR;
		
		case  PORT_C:
		if(PORTC ^=(1<<pinNumber)){return OK;}  //write 0 if =1 or  write 1 if =0
		return ERROR;
		
		case  PORT_D:
		if(PORTD ^=(1<<pinNumber))return OK;  //write 0 if =1  or write 1 if =0
		return ERROR;
	}
	
}

uint8_t DIO_read(uint8_t pinNumber,uint8_t portNumber,uint8_t* value)
{
	switch (portNumber){
		case  PORT_A:
		*value =(PINA & (1<<pinNumber))>>pinNumber;  //read pinNumber
		break;
		
		case  PORT_B:
		*value =(PINB & (1<<pinNumber))>>pinNumber;  //read pinNumber
		break;
		
		case  PORT_C:
		*value =(PINC & (1<<pinNumber))>>pinNumber;  //read pinNumber
		break;
		
		case  PORT_D:
		*value =(PIND & (1<<pinNumber))>>pinNumber;  //read pinNumber
		break;
	}
}
