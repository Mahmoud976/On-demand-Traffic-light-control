
/*
 * application.c
 *
 * Created: 12/14/2022 4:29:40 AM
 *  Author: mahmoud saleh
 */ 

#include "application.h"

#define time_of_delay 10  //1 equal half second

uint8_t flag_no_red=0;

void APP_init(void){
	
	button_init(2,PORT_D);
	
	led_init(0,PORT_A);
	led_init(1,PORT_A);
	led_init(2,PORT_A);
	
	led_init(0,PORT_B);
	led_init(1,PORT_B);
	led_init(2,PORT_B);
	
	
	sei();
	
	MCUCR|=(1<<0)|(1<<1);
	
	GICR|=(1<<6);
		
		
	
}

void green(){
	flag_no_red=1;
	led_on(0,PORT_A);
	delay_second(1);
	led_on(0,PORT_A);
	delay_second(1);
	led_on(0,PORT_A);
	delay_second(1);
	led_on(0,PORT_A);
	delay_second(1);
	led_on(0,PORT_A);
	delay_second(1);
	led_on(0,PORT_A);
	delay_second(1);
	led_on(0,PORT_A);
	delay_second(1);
	led_on(0,PORT_A);
	delay_second(1);
	led_on(0,PORT_A);
	delay_second(1);
	led_on(0,PORT_A);
	delay_second(1);
	led_off(0,PORT_A);
}

void yellow(){
		flag_no_red=1;
		led_on(1,PORT_A);
		delay_second(1);
		led_off(1,PORT_A);
		delay_second(1);
		led_on(1,PORT_A);
		delay_second(1);
		led_off(1,PORT_A);
		delay_second(1);
		led_on(1,PORT_A);
		delay_second(1);
		led_off(1,PORT_A);
		delay_second(1);
		led_on(1,PORT_A);
		delay_second(2);
		led_off(1,PORT_A);
		delay_second(1);
		led_on(1,PORT_A);
		led_off(1,PORT_A);
	flag_no_red=0;
}

void red(){
		led_on(2,PORT_A);
		delay_second(1);
		led_on(2,PORT_A);
		delay_second(1);
		led_on(2,PORT_A);
		delay_second(1);
		led_on(2,PORT_A);
		delay_second(1);
		led_on(2,PORT_A);
		delay_second(1);
		led_on(2,PORT_A);
		delay_second(1);
		led_on(2,PORT_A);
		delay_second(1);
		led_on(2,PORT_A);
		delay_second(1);
		led_on(2,PORT_A);
		delay_second(1);
		led_on(2,PORT_A);
		delay_second(1);
		led_off(2,PORT_A);
}	

void convert(){
	led_on(1,PORT_A);
	led_on(1,PORT_B);
	delay_second(1);
	led_off(1,PORT_A);
	led_off(1,PORT_B);
	delay_second(1);
	led_on(1,PORT_A);
	led_on(1,PORT_B);
	delay_second(1);
	led_off(1,PORT_A);
	led_off(1,PORT_B);
	delay_second(1);
	led_on(1,PORT_A);
	led_on(1,PORT_B);
	delay_second(1);
	led_off(1,PORT_A);
	led_off(1,PORT_B);
	delay_second(1);
	led_on(1,PORT_A);
	led_on(1,PORT_B);
	delay_second(1);
	led_off(1,PORT_A);
	led_off(1,PORT_B);
	delay_second(1);
	led_on(1,PORT_A);
	led_on(1,PORT_B);
	delay_second(2);
	led_off(1,PORT_A);
	led_off(1,PORT_B);
	
}

void if_not_red(){
	led_off(0,PORT_A);
	led_off(1,PORT_A);
	
	led_on(2,PORT_B);
	convert();
	led_off(2,PORT_B);
	
	led_on(2,PORT_A);
	led_on(0,PORT_B);
	delay_second(time_of_delay);
	led_off(2,PORT_A);
	led_off(0,PORT_B);
	convert();
}

void normal_mode(){
		green();
		yellow();
		red();
		yellow();
}

void APP_start(void){
     normal_mode();	
}



ISR(EXT_INT_0){
	if (flag_no_red)
		if_not_red();
}
