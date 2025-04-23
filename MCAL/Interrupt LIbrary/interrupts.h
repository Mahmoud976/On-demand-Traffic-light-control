
/*
 * interrupt.h
 *
 * Created: 12/14/2022 4:51:05 AM
 *  Author: mahmoud saleh
 */ 
#ifndef INTERRUPT_H
#define INTERRUPT_H
#include "../../Utilities/registers.h"
/************************************************************************/
/*                   Interrupt vector                                   */
/************************************************************************/
//External Interrupt Vectors 
//External Interrupt Request0
#define EXT_INT_0 __vector_1
//External Interrupt Request1
#define EXT_INT_1 __vector_2
//External Interrupt Request2
#define EXT_INT_2 __vector_3

//Set Global Interrupts ,Set The I-Bit In Status Register to 1
#define sei()__asm__ __volatile__("sei" ::: "memory")

//Clear Global Interrupts ,Set The I-Bit In Status Register to 0
#define cli()__asm__ __volatile__("cli" ::: "memory")

//ISR Definition
#define ISR(INT_VECT)void INT_VECT(void)__attribute__((signal,used));\
void INT_VECT(void)

#endif INTERRUPT_H