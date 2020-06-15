#include "setup_basic.h"

void system_initialize(void){
    pin_manager();
    oscillator_initialize();
    //array_init();
    interrupt_initialize();
    timer_0_initialize();
    //timer_1_initialize();
}

void pin_manager(void){
    TRISD = 0x00;
    LATD = 0x00;
    //LATD = 0b00000001;
    
    TRISBbits.TRISB0 = 1;
    
    TRISAbits.TRISA5 = 1;
    ADCON1 = 0b00001111;
}

void oscillator_initialize(void){
    //OSCCON = 0b00110000;    //0x30
    //OSCCON = 0b01000000;    // 1 MHz
    OSCCON = 0x73; // 8 000 000 Hz (8 MHz)
    OSCTUNE = 0b01000000;   //0x40
}

void interrupt_initialize(void){
    RCONbits.IPEN = 0; //no low priority or high priority
    //RCONbits.IPEN = 1;// have high priority interrupt function
    
    //Timer 0
    INTCON2bits.TMR0IP = 0; // 0 is Timer 0 no priority || 1 is Timer 0 is priority      
    //INTCON2bits.TMR0IP = 1;
    
    //Timer 1
    //IPR1bits.TMR1IP = 0; // no priority bit of Timer 1
    //IPR1bits.TMR1IP = 1; // priority bit of Timer 1
}

void timer_0_initialize(void){
    T0CON = 0b00001000;
    
    TMR0H = 0xB1;
    TMR0L = 0xE0;// 10 milliseconds to run from this -> 2^16
    
    timer0ReloadVal = TMR0;
    
    INTCONbits.TMR0IF = 0; //clear the interrupt flag of Timer 0 before enabling the interrupt
    INTCONbits.TMR0IE = 1; //enabling Timer 0 interrupt;
    T0CONbits.TMR0ON = 1; // Timer 0 starts to run
}

void __interrupt() function_interrupt_TMR0(void){
    if ((INTCONbits.TMR0IE == 1) &&(INTCONbits.TMR0IF == 1)){
        INTCONbits.TMR0IF = 0; // set the flag off
        TMR0H = (timer0ReloadVal >> 8);
        TMR0L = (unsigned char) timer0ReloadVal; // unsigned char is 1 byte (8 bits)
        
        //TO DO when interrupt
        //count_1_sec = count_1_sec + 1;
        //if (count_1_sec == 200){
        //    LATD = ~(LATD);
            //LATD = LATD << 1;
        //    count_1_sec = 0;
        //}
        
        //if (check_but_RB0()){
        //    LATD = LATD + 1;
        //}
        //
        count_1_sec = count_1_sec + 1;
        if (count_1_sec == 200){
            operate_DHT11();
            if ((current_state == state_03) || (current_state == state_04)|| (current_state == state_05)|| (current_state == state_06) ){
                print_DHT11();
            }
            count_1_sec = 0;
        }
        FSM();
    }
}

/*
void timer_1_initialize(void){
    T1CON = 0b10000000;

    TMR1H = 0xF6;
    TMR1L = 0x3B;// 1 milliseconds to run from this -> 2^16

    timer1ReloadVal=TMR1;

    PIR1bits.TMR1IF = 0;
    PIE1bits.TMR1IE = 1;
    T1CONbits.TMR1ON = 1;
}*/
/*
void __interrupt(high_priority) function_interrupt_TMR1(void){
    if(PIE1bits.TMR1IE == 1 && PIR1bits.TMR1IF == 1){
        PIR1bits.TMR1IF = 0;
        TMR1H = (timer1ReloadVal >> 8);
        TMR1L = (unsigned char) timer1ReloadVal;
        
        //TO DO when interrupt
  
    }
}
*/