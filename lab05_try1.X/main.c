/*
 * File:   main.c
 * Author: ASUS
 *
 * Created on November 23, 2019, 9:19 AM
 */
#include "setup_basic.h"

void main(void) {
    system_initialize();
    LCDInit();
    INTCONbits.GIE = 1;
    INTCONbits.PEIE = 1;
    //LCDPutInst(0x80);
    //LCDPutStr("LAB 05");    
    while(1){
    }    
    return;
}
