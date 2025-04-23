
/*
 * button.h
 *
 * Created: 12/14/2022 4:54:55 AM
 *  Author: mahmoud saleh
 */ 
#ifndef BUTTON_H_
#define BUTTON_H_
#include "../../MCAL/DIO Driver/dio.h"
#include "../../MCAL/Interrupt LIbrary/interrupts.h"
#include "../../MCAL/Timer Driver/timer.h"

//uint8_t sate=0;

//state define
#define LOW 0
#define  HIGH 1
uint8_t button_init(uint8_t buttonNumber, uint8_t buttonPort);

uint8_t button_read(uint8_t buttonNumber,uint8_t buttonPort,uint8_t *value);

//uint8_t button_getState(uint8_t buttonNumber , uint8_t buttonPort);


#endif BUTTON_H_ 