
/*
 * led.h
 *
 * Created: 12/14/2022 4:55:17 AM
 *  Author: mahmoud saleh
 */ 
#ifndef LED_H_
#define LED_H_

#include "../../MCAL/DIO Driver/dio.h"
#include "../../MCAL/Interrupt LIbrary/interrupts.h"
#include "../../MCAL/Timer Driver/timer.h"

uint8_t led_init(uint8_t ledNumber,uint8_t ledport);

uint8_t led_on(uint8_t ledNumber,uint8_t ledport);

uint8_t led_off(uint8_t ledNumber,uint8_t ledport);

uint8_t led_toggel(uint8_t ledNumber,uint8_t ledport);

#endif LED_H_ 