#ifndef SETUP_BASIC_H
#define	SETUP_BASIC_H

#ifdef _18F8722
#pragma config  OSC = INTIO67
#pragma config 	FCMEN = OFF
#pragma config 	IESO = OFF
#pragma config 	PWRT = OFF
#pragma config 	BOREN = OFF
#pragma config 	WDT = OFF
#pragma config 	MCLRE = ON
#pragma config 	LVP = OFF
#pragma config 	XINST = OFF
#endif
    
#define _XTAL_FREQ 10000000 // 10 MHz

#include <xc.h>
#include <pic18f8722.h>
#include <stdio.h> //C program basic
#include <stdlib.h> //C program library 02

//files .h that I implement later
#include "solution01.h"    
#include "setup_LCD_2.h"
#include "dht11_01.h"
//close

//Very BASIC setup functions
void system_initialize(void);       
void pin_manager(void);
void oscillator_initialize(void);
void interrupt_initialize(void);

//using Timer 0
void timer_0_initialize(void);
volatile unsigned short timer0ReloadVal; //16 bits (2 bytes x 8 bits);
void __interrupt() function_interrupt_TMR0(void);
//close

//close

//if using Timer 1
//void timer_1_initialize(void);
//volatile unsigned short timer1ReloadVal;
//void __interrupt(high_priority) function_interrupt_TMR1(void);
//close

//for test variables
unsigned int count_1_sec = 0;
//close

#ifdef	__cplusplus
extern "C" {
#endif
    
    
#ifdef	__cplusplus
}
#endif

#endif	/* SETUP_BASIC_H */

