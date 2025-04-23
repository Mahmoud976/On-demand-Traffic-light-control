
/*
 * timer.c
 *
 * Created: 12/14/2022 7:25:11 AM
 *  Author: mahmoud saleh
 */ 

#include "timer.h"

void timer_init(){
	
	TCCR0=0x00;  // normal mode
	TCNT0=0x00; // set zero inatial value
}
// 

 void timer_start(){
 TCCR0 |=(1<<0);  //set 1 in bit 0
 }
 
	
void timer_stop(){
	TCCR0=0x00;}
 	
 uint8_t delay_second(uint8_t half_second){
			  timer_init();timer_start();
	 unsigned int counter=0;
while(counter<(half_second*2000)){
	while((TIFR & (1<<0))==0);
	TIFR |=(1<<0);	//clear the overflow flag
	counter++;	
}
counter=0;

return OK;
 }
 
 
 
 	
		
