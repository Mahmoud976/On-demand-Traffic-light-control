
/*
 * timer.h
 *
 * Created: 12/14/2022 7:25:23 AM
 *  Author: mahmoud saleh
 */ 
#ifndef TIMER_H
#define TIMER_H
#include "../../Utilities/registers.h"
#define Timer0 
void timer_init();

void timer_start();

void timer_stop();

uint8_t delay_second(uint8_t half_second);

#endif TIMER_H