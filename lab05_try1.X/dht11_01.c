#include "dht11_01.h"

void DHT11_Start(){    
    Data_Dir = 0;  
    Data_Out = 0;  
    __delay_ms(18);
    Data_Out = 1;  
    __delay_us(20);
    Data_Dir = 1;
}

void DHT11_CheckResponse(){
    while(Data_In & 1);      
    while(!(Data_In & 1));  
    while(Data_In & 1);  
}

char DHT11_ReadData(){
    char i,data_dht = 0;  
    for(i=0;i<8;i++){
        while(!(Data_In & 1));  
        __delay_us(30);         
        if(Data_In & 1)  
          data_dht = ((data_dht<<1) | 1); 
        else
          data_dht = (data_dht<<1);  
        while(Data_In & 1);
    }
    return data_dht;
}

int operate_DHT11(void){
    DHT11_Start();
    DHT11_CheckResponse();
    
    RH_Integral = DHT11_ReadData();  
    RH_Decimal = DHT11_ReadData();   
    T_Integral = DHT11_ReadData();  
    T_Decimal = DHT11_ReadData();    
    Checksum = DHT11_ReadData();
    
    //if (Checksum != ( (RH_Integral + RH_Decimal + T_Integral + T_Decimal) && 0xFF) ){
    if (Checksum !=  (RH_Integral + RH_Decimal + T_Integral + T_Decimal) ){
        return 0;
    }
    return 1;
}

void print_DHT11(void){
    sprintf(value, "%d", RH_Integral);
    LCDPutInst(0x80);
    LCDPutStr(value);
    LCDPutChar('%');
            
    sprintf(value, "%d", T_Integral);
    LCDPutInst(0xC0);
    LCDPutStr(value);
    LCDPutChar('C');
}