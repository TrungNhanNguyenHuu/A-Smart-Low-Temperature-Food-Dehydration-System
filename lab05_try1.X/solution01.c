#include "solution01.h"

int check_but_RB0(void){
    if (PORTBbits.RB0 != 0){
        flag_RB0 = 0;
        return 0;
    }
    if ((PORTBbits.RB0 == 0) && (flag_RB0 == 0)){
        flag_RB0 = 1;
        return 1;
    }
    return 0;
}

int check_but_RA5(void){
    if (PORTAbits.RA5 != 0){
        flag_RA5 = 0;
        return 0;
    }
    if ((PORTAbits.RA5 == 0) && (flag_RA5 == 0)){
        flag_RA5 = 1;
        return 1;
    }
    return 0;
}


void set_defined_temp(void){
    if (check_but_RA5()){
        defined_temp = defined_temp + 1;
        if (defined_temp == 99){
            defined_temp = 25;
        }
    }
}

void print_temp_state1(void){
    LCDPutInst(0x80);
    LCDPutStr("Set Temp: ");
    sprintf(defined_value_arr, "%d", defined_temp);
    LCDPutStr(defined_value_arr);
}

void set_defined_hum(void){
    if (check_but_RA5()){
        defined_hum = defined_hum - 1;
        if (defined_temp == 0){
            defined_temp = 72;
        }
    }
}

void print_hum_state2(void){
    LCDPutInst(0x80);
    LCDPutStr("Set Hum: ");
    sprintf(defined_value_arr, "%d", defined_hum);
    LCDPutStr(defined_value_arr);
}

void FSM(void){
    switch (current_state){
/*        case state_01:{
            count_2_sec = count_2_sec + 1;
            if (count_2_sec == 200){
                count_2_sec = 0;
                current_state = state_02;
            }
            break;
        }
        
        case state_02:{
            if (operate_DHT11()){
                current_state = state_03;
            }
            break;
        }
        
        case state_03:{
            sprintf(value, "%d", RH_Integral);
            LCDPutInst(0x80);
            LCDPutStr(value);
            LCDPutChar('%');
            
            sprintf(value, "%d", T_Integral);
            LCDPutInst(0xC0);
            LCDPutStr(value);
            LCDPutChar('C');
            
            current_state = state_01;
            break;
        }*/
        
        /*case state_01:{
            if (check_but_RB0()){
                current_state = state_02;
            }
            LATD = 0x00;
            break;
        }
        
        case state_02:{
            LATD = 0b10100000;
            time_out_heater = time_out_heater + 1;
            if (time_out_heater == 300){
                time_out_heater = 0;
                current_state = state_03;
            } 
            break;
        }
        
        case state_03:{
            if (RH_Integral > defined_hum){
                current_state = state_04;
                break;
            }
            if (RH_Integral <= defined_hum){
                current_state = state_05;
            }
            break;
        }
        
        case state_04:{
            LATD = 0b01000000;
            time_out_fan1 = time_out_fan1 + 1;
            if ((time_out_fan1 >= 300) && (RH_Integral <= defined_hum)){
                time_out_fan1 = 0;
                current_state = state_05;
            } 
            break;
        }
        
        case state_05:{
            LATD = 0b00011000; 
            timeout_heatpump = timeout_heatpump + 1;
            if (timeout_heatpump == 500){
                timeout_heatpump = 0;
                if (T_Integral >= defined_temp){
                    current_state = state_01;
                }
                else{
                    current_state = state_02;
                }
            }
            break;
        }*/
        
        case state_0:{
            mLCD_CLEAR;
            LATD = 0x00;
            if (check_but_RB0()){
                current_state = state_01;
            }
            break;
        }
        
        case state_01:{
            print_temp_state1();
            set_defined_temp();
            if (check_but_RB0()){
                current_state = state_02;
                mLCD_CLEAR;
            }
            break;
        }
        
        case state_02:{
            print_hum_state2();
            set_defined_hum();
            if (check_but_RB0()){
                current_state = state_03;
                mLCD_CLEAR;
            }
            break;
        }
        
        case state_03:{
            LATD = 0b10100000;
            time_out_heater = time_out_heater + 1;
            if (time_out_heater == 600){
                time_out_heater = 0;
                current_state = state_04;
            } 
            break;
        }
        
        case state_04:{
            if (RH_Integral > defined_hum){
                current_state = state_05;
                break;
            }
            if (RH_Integral <= defined_hum){
                current_state = state_06;
            }
            break;
        }
        
        case state_05:{
            LATD = 0b01000000;
            time_out_fan1 = time_out_fan1 + 1;
            if ((time_out_fan1 >= 500) && (RH_Integral <= defined_hum)){
                time_out_fan1 = 0;
                current_state = state_06;
            } 
            break;
        }
        
        case state_06:{
            LATD = 0b00011000; 
            timeout_heatpump = timeout_heatpump + 1;
            if (timeout_heatpump == 500){
                timeout_heatpump = 0;
                if (T_Integral >= defined_temp){
                    current_state = state_0;
                }
                else{
                    current_state = state_03;
                }
            }
            break;
        }
    }
}
