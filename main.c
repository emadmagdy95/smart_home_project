/*
 * File:   main.c
 * Author: emad_
 *
 * Created on June 7, 2020, 9:24 PM
 */

#define F_CPU 16000000UL	
#include <xc.h>
#include <util/delay.h>	
#include <string.h>
#include "mUART.h"
#include "DIO_1.h"
#include "lcd.h"
#include "mSPI.h"
#include "DIO.h"

int main(void) {
    char led1on;
    char led2on;
    char led1off;
    char led2off;
    char doubledot_led1on_char;
    char doubledot_led2on_char;
    char _spi = 0;
    PORTCas(OUT);
    PINDas(7, IN);
    char _led1on[20] = "led 1 on.";
    char doubledot_led1on[20] = "led 1 on..";
    char _led2on[20] = "led 2 on.";
    char doubledot_led2on[20] = "led 2 on..";
    char _led1off[20] = "led 1 off.";
    char _led2off[20] = "led 2 off.";
    UART_init(_Asynchronous, _disabled_Parity, _1_stop_bit, _8bit, 103);
    char string1[40];
    LCD_Init();

    while (1) {

        strcpy(string1, UART_ReceiveString());
        LCD_String_xy(3,0,string1);
        led1on = strcmp(_led1on, string1);
        led2on = strcmp(_led2on, string1);
        led1off = strcmp(_led1off, string1);
        led2off = strcmp(_led2off, string1);
        doubledot_led1on_char=strcmp(doubledot_led1on,string1);
        doubledot_led2on_char=strcmp(doubledot_led2on,string1);

        if (led1on == 0 || doubledot_led1on_char == 0) {
            setPINC(0);
            _spi = 1;
            
            LCD_Clear();
            LCD_String(string1);
            *string1 = '\0';
        }
        else if (led2on == 0 || doubledot_led2on_char == 0) {
            setPINC(1);
            _spi = 2;
            LCD_Clear();
            LCD_String(string1);
            *string1 = '\0';
        }
        else if (led1off == 0) {
            resetPIN(0, _portC);
            _spi = 3;
            LCD_Clear();
            LCD_String(string1);
            *string1 = '\0';
        } else if (led2off == 0) {
            resetPIN(1, _portC);
            _spi = 4;
            LCD_Clear();
            LCD_String(string1);
            *string1 = '\0';

        }
        
        if(isPressedD(7)==1){
             *string1 = '\0';
                LCD_Clear();
        }
      
    }
    return 0;
}




/*
      led1 = UART_ReceiveChar();
   if(led1=='O'){
       setPINC(0);
       resetPIN(1,PORTC);
   }
   if(led1=='C'){
       setPINC(1);
        resetPIN(0,PORTC);  
        
    }*/

