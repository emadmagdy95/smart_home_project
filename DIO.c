/*
 * File:   DIO.c
 * Author: Safaa
 *
 * Created on April 10, 2020, 5:50 PM
 */


#include <xc.h>
#include "DIO.h"

void _setPINA(int pinNum) {
    PORTA |= (1 << pinNum);
}

void _resetPINA(int pinNum) {
    PORTA &= ~(1 << pinNum);
}

int isPressedA(int pinNum) {
    if (PINA & (1 << pinNum)) {
        return 1;
    } else {
        return 0;
    }
}

int isPressedB(int pinNum) {
    if (PINB & (1 << pinNum)) {
        return 1;
    } else {
        return 0;
    }
}

int isPressedC(int pinNum) {
    if (PINC & (1 << pinNum)) {
        return 1;
    } else {
        return 0;
    }
}

int isPressedD(int pinNum) {
    if (PIND & (1 << pinNum)) {
        return 1;
    } else {
        return 0;
    }
}
//setPIN(LED, portA);

void setPIN(int pinNum, char port) {

    switch (port) {

        case 1:
            PORTA |= (1 << pinNum);
            break;
        case 2:
            PORTB |= (1 << pinNum);
            break;
        case 3:
            PORTC |= (1 << pinNum);
            break;
        case 4:
            PORTD |= (1 << pinNum);
            break;
    }

}

void resetPIN(int pinNum, char port) {

    switch (port) {

        case 1:
            PORTA &= ~(1 << pinNum);
            break;
        case 2:
            PORTB &= ~(1 << pinNum);
            break;
        case 3:
            PORTC &= ~(1 << pinNum);
            break;
        case 4:
            PORTD &= ~(1 << pinNum);
            break;
    }

}

void setPINA(int pinNum) {
    PORTA |= (1 << pinNum);
}

void setPINB(int pinNum) {
    PORTB |= (1 << pinNum);
}

void setPINC(int pinNum) {
    PORTC |= (1 << pinNum);
}

void setPIND(int pinNum) {
    PORTD |= (1 << pinNum);
}

void setPORT(char port) {

    switch (port) {

        case 1:
            PORTA |= 0xFF;
            break;
        case 2:
            PORTB |= 0xFF;
            break;
        case 3:
            PORTC |= 0xFF;
            break;
        case 4:
            PORTD |= 0xFF;
            break;
    }

}

void resetPORT(char port) {

    switch (port) {

        case 1:
            PORTA = 0x00;
            break;
        case 2:
            PORTB = 0x00;
            break;
        case 3:
            PORTC = 0x00;
            break;
        case 4:
            PORTD = 0x00;
            break;
    }

}

void PINAas(int pinNum, int dir) {
    switch (dir) {
        case OUT:
            DDRA |= (1 << pinNum);
            break;
        case IN:
            DDRA &= ~(1 << pinNum);
            break;
        default:
            break;
    }


}

void PINBas(int pinNum, int dir) {
    switch (dir) {
        case OUT:
            DDRB |= (1 << pinNum);
            break;
        case IN:
            DDRB &= ~(1 << pinNum);
            break;
    }


}

void PINCas(int pinNum, int dir) {
    switch (dir) {
        case OUT:
            DDRC |= (1 << pinNum);
            break;
        case IN:
            DDRC &= ~(1 << pinNum);
            break;
    }


}

void PINDas(int pinNum, int dir) {
    switch (dir) {
        case OUT:
            DDRD |= (1 << pinNum);
            break;
        case IN:
            DDRD &= ~(1 << pinNum);
            break;
    }

}

void PORTAas(int dir) {
    switch (dir) {
        case OUT:
            DDRA = 0xFF;
            break;
        case IN:
            DDRA = 0x00;
            break;
        default:
            break;
    }
}

void PORTBas(int dir) {
    switch (dir) {
        case OUT:
            DDRB = 0xFF;
            break;
        case IN:
            DDRB = 0x00;
            break;
        default:
            break;
    }
}

void PORTCas(int dir) {
    switch (dir) {
        case OUT:
            DDRC = 0xFF;
            break;
        case IN:
            DDRC = 0x00;
            break;
        default:
            break;
    }
}

void PORTDas(int dir) {
    switch (dir) {
        case OUT:
            DDRD = 0xFF;
            break;
        case IN:
            DDRD = 0x00;
            break;
        default:
            break;
    }
}

void setPORTA(int data) {
    PORTA = data;
}

void setPORTB(int data) {
    PORTB = data;
}

void setPORTC(int data) {
    PORTC = data;
}

void setPORTD(int data) {
    PORTD = data;
}


void togglePIND(int pinNum){
    PORTD ^= (1<<pinNum);
}
void togglePINB(int pinNum){
    PORTB ^= (1<<pinNum);
}
void togglePINC(int pinNum){
    PORTC ^= (1<<pinNum);
}
void togglePINA(int pinNum){
    PORTA ^= (1<<pinNum);
}
