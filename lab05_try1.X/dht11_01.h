#ifndef DHT11_01_H
#define	DHT11_01_H
#include "setup_basic.h"

#define Data_Out LATC0         
#define Data_In PORTCbits.RC0  
#define Data_Dir TRISCbits.RC0

void DHT11_Start();
void DHT11_CheckResponse();
char DHT11_ReadData();

//declare needed variables
char RH_Decimal,RH_Integral,T_Decimal,T_Integral;
char Checksum;
char value[10];
//close

int operate_DHT11(void);
void print_DHT11(void);

#ifdef	__cplusplus
extern "C" {
#endif

    
#ifdef	__cplusplus
}
#endif

#endif	/* DHT11_01_H */

