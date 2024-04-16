/* 
 * File:   main.c
 * Author: Chris Sanchez
 *
 * Created on April 11, 2024, 1:55 PM
 */

///////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <xc.h>
#include "C:\Program Files\Microchip\xc8\v2.46\pic\include\proc\pic18f46k42.h"


#define _XTAL_FREQ 4000000                 // Fosc  frequency for _delay()  library
#define FCY    _XTAL_FREQ/4

void SPI_Master_Init() {
    TRISCbits.TRISC3 = 0; // Set SCK pin (RC3) as output
    TRISCbits.TRISC5 = 0; // Set SDO pin (RC5) as output
    TRISBbits.TRISB1 = 0; // Set Pbar/S (RB1) as output
    PORTBbits.RB1 = 1; //Set Pbar/S (RB1) to high for Serial
    TRISBbits.TRISB0 = 0; // Set RB0 as an output for LED
    
    SPI1CON0 = 0b10000010; // Enables SPI
    SPI1SDIPPS = 0b01001;  // Changes the SPI output to RB2
    
}

void PARALLEL_Init() {
    //Setting relevant pins as outputs for parallel programming
    TRISAbits.TRISA5 = 0;
    TRISEbits.TRISE0 = 0;
    TRISEbits.TRISE1 = 0;
    TRISEbits.TRISE2 = 0;
    TRISAbits.TRISA7 = 0;
    TRISAbits.TRISA6 = 0;
    TRISCbits.TRISC0 = 0;
    TRISCbits.TRISC1 = 0;
    
    //Setting RA1 as an output for SHIFT_LE_1
    TRISAbits.TRISA1 = 0;
}

void SPI_Write(unsigned char data) {
    PORTBbits.RB6 = 0; // ATT_LE_1 set to low
    SPI1TXB = data; // Write data to SPI buffer
    while(SPI1CON2 >= 128); // Wait for transmission to complete
    PORTBbits.RB3 = 1; // ATT_LE_1 set to high
    __delay_ms(500); // Delay to let it set
    PORTBbits.RB3 = 0; // ATT_LE_1 set to low
}

void Parallel_Write() {
    PORTDbits.RD0 = 1; // Set SHIFT_LE_1 to high
    PORTB = 0b00000000;
    __delay_ms(1000);
    
    //Just for testing purposes
//    PORTBbits.RB0 = 1; //This lights up an LED for testing
//    __delay_ms(1000);
//    PORTBbits.RB0 = 0; //Turns the LED back off
//    
//    PORTDbits.RD0 = 0; // Set SHIFT_LE_1 to low
}

void main() {
    SPI_Master_Init(); // Initialize SPI as master
    PARALLEL_Init(); //Initialize Parallel Ports (RB0-RB5)
    
    while(1) {
        SPI_Write(0x00); // Write data over SPI
        Parallel_Write();
        __delay_ms(1000); // Delay
        
    }
}


