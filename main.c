/*
 * File:   main.c
 * Author: emad_
 *
 * Created on June 7, 2020, 9:24 PM
 */

#define F_CPU 16000000 
#include <xc.h>
#include <string.h>
#include "mUART.h"
#include "DIO.h"


int main(void) {
    char led1 ;
    char led2 ;
    char _led1[20]="led 1 on .";
    char _led2[20]="led 2 on .";
    UART_init(_Asynchronous,_disabled_Parity,_1_stop_bit,_8bit,103);
    char string1[20];
  
    while(1){
        strcpy(string1,UART_ReceiveString());
    led1 = strcmp(_led1,string1);
    led2 = strcmp(_led2,string1);
    if(led1 == 0){
        setPINC(0);
        resetPIN(1,PORTC);
      
    } 
    if(led2 == 0){
        setPINC(1);
        resetPIN(0,PORTC);  
        
    }
    }
       
    return 0;
}
