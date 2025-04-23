
/*
 * dio.h
 *
 * Created: 12/14/2022 4:40:08 AM
 *  Author: mahmoud saleh
 */ 
#ifndef DIO_H_
#define DIO_H_
#include "../../Utilities/registers.h"
// All internal driver typedef
//All deriver macro

#define PORT_A 'A'
#define PORT_B 'B'
#define PORT_C 'C'
#define PORT_D 'D'

// direction define
#define IN 0
#define OUT 1
// value define
#define LOW 0
#define HIGH 1
//Error return define
#define OK 0
#define ERROR 1
//this function to set direction if return 0 it field if return 1 success
uint8_t DIO_init(uint8_t pinNumber,uint8_t portNumber,uint8_t direction);  //initialize dio direction

uint8_t DIO_write(uint8_t pinNumber,uint8_t portNumber,uint8_t value);   // write data to dio

uint8_t DIO_toggel(uint8_t pinNumber,uint8_t portNumber);   //toggle dio

uint8_t DIO_read(uint8_t pinNumber,uint8_t portNumber,uint8_t* value);  // read dio

#endif  DIO_H_ 