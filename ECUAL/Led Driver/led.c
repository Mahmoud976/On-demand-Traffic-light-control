
/*
 * led.c
 *
 * Created: 12/14/2022 4:55:08 AM
 *  Author: mahmoud saleh
 */ 
#include "led.h"

uint8_t led_init(uint8_t ledNumber,uint8_t ledport)
{
	if(DIO_init(ledNumber,ledport,OUT))return OK;
	return ERROR;
}


uint8_t led_on(uint8_t ledNumber,uint8_t ledport)
{
	if(DIO_write(ledNumber,ledport,HIGH))return OK;
	return ERROR;
}

uint8_t led_off(uint8_t ledNumber,uint8_t ledport)
{
	if(DIO_write(ledNumber,ledport,LOW))return OK;
	return ERROR;
}

uint8_t led_toggel(uint8_t ledNumber,uint8_t ledport)
{
	if(DIO_toggel(ledNumber,ledport))return OK;
	return ERROR;
}
