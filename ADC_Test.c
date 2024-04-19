/*
 * File:   main.c
 * Author: Chris
 *
 * Created on April 18, 2024, 10:26 AM
 */
#define _XTAL_FREQ 4000000                 // Fosc  frequency for _delay()  library
#define FCY    _XTAL_FREQ/4

#include <xc.h>
#include "C:\Program Files\Microchip\xc8\v2.46\pic\include\proc\pic18f46k42.h"

void ADC_init(){
    TRISAbits.TRISA0 = 1;
    ANSELAbits.ANSELA0 = 1;
    
    ADCON0bits.FM = 1;
    ADCON0bits.CS = 1;
    
    ADCLK = 0x00;
    ADPCH = 0x00;
    
    ADCAP = 0x00;
    ADREF = 0x0;
    
    ADACQL = 0x00;
    ADACQH = 0x00;
    
    ADCON0bits.ON = 1;    
}

void LED_init(){
    //These are test LEDs to see if it is calculating values correctly
    //This is the "green" LED
    TRISAbits.TRISA2 = 0;
    PORTAbits.RA2 = 0;
    PORTAbits.RA2 = 1;
    __delay_ms(1000);
    PORTAbits.RA2 = 0;
    
    //This is the "orange" LED
    TRISAbits.TRISA3 = 0;
    PORTAbits.RA3 = 0;
    PORTAbits.RA3 = 1;
    __delay_ms(1000);
    PORTAbits.RA3 = 0;
}

void main(void) {
    
    ADC_init();
    LED_init();
    
    const float Vref = 4.8;
    float digital, voltage;
    
    while (1) {
        ADCON0bits.GO = 1;
        while (ADCON0bits.GO);
        digital = (ADRESH*256) | (ADRESL);
        voltage = digital*((float)Vref/(float)(4096));
        //__delay_ms(1000);
        if (voltage > 1.2){
            PORTAbits.RA2 = 1;
            __delay_ms(500);
            PORTAbits.RA2 = 0;
        }
        else {
            PORTAbits.RA2 = 1;
            __delay_ms(500);
            PORTAbits.RA2 = 0;
        }
    }
}
