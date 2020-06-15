#ifndef SOLUTION01_H
#define	SOLUTION01_H

#include "setup_basic.h"
int check_but_RB0(void);
char flag_RB0 = 0;

int check_but_RA5(void);
char flag_RA5 = 0;

void set_defined_temp(void);
void print_temp_state1(void);
char defined_value_arr[3];

void set_defined_hum(void);
void print_hum_state2(void);

//Finite State Machine
enum {state_0, state_01, state_02, state_03, state_04, state_05, state_06, state_07} MY_FSM;
unsigned char current_state = state_0; //current_state variable is 1 byte (8 bits)
void FSM(void);
//close

//for test variable
unsigned int count_2_sec = 0;

unsigned int defined_temp = 25;
unsigned int defined_hum = 95;

unsigned int time_out_heater = 0;
unsigned int time_out_fan1 = 0;
unsigned int timeout_heatpump = 0;
//close

#ifdef	__cplusplus
extern "C" {
#endif

    
#ifdef	__cplusplus
}
#endif

#endif	/* SOLUTION01_H */

