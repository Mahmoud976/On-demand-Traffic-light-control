
/*
 * button.c
 *
 * Created: 12/14/2022 4:54:41 AM
 *  Author: mahmoud saleh
 */ 


#include "button.h"

uint8_t button_init(uint8_t buttonNumber, uint8_t buttonPort){
	if(DIO_init(buttonNumber,buttonPort,IN)) return OK;
	return ERROR;
}

uint8_t button_read(uint8_t buttonNumber,uint8_t buttonPort,uint8_t *value){
	if (DIO_read(buttonNumber,buttonPort,value))return OK;
	return ERROR;
}