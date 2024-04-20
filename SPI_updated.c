// CONFIG1L
#pragma config FEXTOSC = 0x4     // External Oscillator Selection (LP (crystal oscillator) optimized for 32.768 kHz; PFM set to low power)
#pragma config RSTOSC = EXTOSC  // Reset Oscillator Selection (EXTOSC operating per FEXTOSC bits (device manufacturing default))

// CONFIG1H
#pragma config CLKOUTEN = OFF   // Clock out Enable bit (CLKOUT function is disabled)
#pragma config PR1WAY = ON      // PRLOCKED One-Way Set Enable bit (PRLOCK bit can be cleared and set only once)
#pragma config CSWEN = ON       // Clock Switch Enable bit (Writing to NOSC and NDIV is allowed)
#pragma config FCMEN = ON       // Fail-Safe Clock Monitor Enable bit (Fail-Safe Clock Monitor enabled)

// CONFIG2L
#pragma config MCLRE = EXTMCLR  // MCLR Enable bit (If LVP = 0, MCLR pin is MCLR; If LVP = 1, RE3 pin function is MCLR )
#pragma config PWRTS = PWRT_OFF // Power-up timer selection bits (PWRT is disabled)
#pragma config MVECEN = ON      // Multi-vector enable bit (Multi-vector enabled, Vector table used for interrupts)
#pragma config IVT1WAY = ON     // IVTLOCK bit One-way set enable bit (IVTLOCK bit can be cleared and set only once)
#pragma config LPBOREN = OFF    // Low Power BOR Enable bit (ULPBOR disabled)
#pragma config BOREN = SBORDIS  // Brown-out Reset Enable bits (Brown-out Reset enabled , SBOREN bit is ignored)

// CONFIG2H
#pragma config BORV = VBOR_2P45 // Brown-out Reset Voltage Selection bits (Brown-out Reset Voltage (VBOR) set to 2.45V)
#pragma config ZCD = OFF        // ZCD Disable bit (ZCD disabled. ZCD can be enabled by setting the ZCDSEN bit of ZCDCON)
#pragma config PPS1WAY = ON     // PPSLOCK bit One-Way Set Enable bit (PPSLOCK bit can be cleared and set only once; PPS registers remain locked after one clear/set cycle)
#pragma config STVREN = ON      // Stack Full/Underflow Reset Enable bit (Stack full/underflow will cause Reset)
#pragma config DEBUG = OFF      // Debugger Enable bit (Background debugger disabled)
#pragma config XINST = OFF      // Extended Instruction Set Enable bit (Extended Instruction Set and Indexed Addressing Mode disabled)

// CONFIG3L
#pragma config WDTCPS = WDTCPS_31// WDT Period selection bits (Divider ratio 1:65536; software control of WDTPS)
#pragma config WDTE = OFF       // WDT operating mode (WDT Disabled; SWDTEN is ignored)

// CONFIG3H
#pragma config WDTCWS = WDTCWS_7// WDT Window Select bits (window always open (100%); software control; keyed access not required)
#pragma config WDTCCS = SC      // WDT input clock selector (Software Control)

// CONFIG4L
#pragma config BBSIZE = BBSIZE_512// Boot Block Size selection bits (Boot Block size is 512 words)
#pragma config BBEN = OFF       // Boot Block enable bit (Boot block disabled)
#pragma config SAFEN = OFF      // Storage Area Flash enable bit (SAF disabled)
#pragma config WRTAPP = OFF     // Application Block write protection bit (Application Block not write protected)

// CONFIG4H
#pragma config WRTB = OFF       // Boot Block Write Protection bit (Boot Block not write-protected)
#pragma config WRTC = OFF       // Configuration Register Write Protection bit (Configuration registers not write-protected)
#pragma config WRTD = OFF       // Data EEPROM Write Protection bit (Data EEPROM not write-protected)
#pragma config WRTSAF = OFF     // SAF Write protection bit (SAF not Write Protected)
#pragma config LVP = ON         // Low Voltage Programming Enable bit (Low voltage programming enabled. MCLR/VPP pin function is MCLR. MCLRE configuration bit is ignored)

// CONFIG5L
#pragma config CP = OFF         // PFM and Data EEPROM Code Protection bit (PFM and Data EEPROM code protection disabled)

#include <xc.h> // must have this
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <pic18f46k42.h>

#define _XTAL_FREQ 4000000                 // Fosc  frequency for _delay()  library
#define FCY    _XTAL_FREQ/40

#define ADC PORTAbits.RA0

//phase shifter LEs
#define P_LE1 PORTAbits.RA1
#define P_LE2 PORTAbits.RA2
#define P_LE3 PORTAbits.RA3
#define P_LE4 PORTAbits.RA4

//phase shifter bits
#define PS180 PORTAbits.RA5
#define PS90 PORTEbits.RE0
#define PS45 PORTEbits.RE1
#define PS22 PORTEbits.RE2
#define PS11 PORTAbits.RA7
#define PS5 PORTAbits.RA6
#define PS2 PORTCbits.RC0
#define PS1 PORTCbits.RC1
#define OPT PORTCbits.RC2

//attenuator stuff 
#define A_SP PORTBbits.RB7
#define A_LE1 PORTBbits.RB6
#define A_LE2 PORTBbits.RB5
#define A_LE3 PORTBbits.RB4
#define A_LE4 PORTBbits.RB3
#define SP_data PORTBbits.RB2

//other stuff
#define ButtonIn PORTDbits.RD0
#define ButtonOut PORTDbits.RD1
#define R_LED PORTDbits.RD2
#define G_LED PORTDbits.RD3

//--------------------------------------------- Functions --------------------------------------------------------------------------
void SPI1_Init()
{
    A_SP = 1; // set to serial 
    SPI1CON0 = 0b00000110;
    SPI1CON1 = 0b00000000;
    SPI1CON2 = 0b00000010;
    SPI1CLK = 0x0;
    SPI1BAUD = 0x7;
    SPI1CON0bits.EN = 1; // Enable
    
}

void Beam_1 () //106.8, 267.1, 160.3, 194
{
    // phase shifter 1
    PS90 = 1; PS11 = 1; PS5 = 1; __delay_ms(500);
    P_LE1 = 1; __delay_ms(500); 
    P_LE1 = 0; __delay_ms(500);
    PS90 = 0; PS11 = 0; PS5 = 0; __delay_ms(500);
    
    // phase shifter 2
    PS180 = 1; PS45 = 1; PS22 = 1; PS11 = 1; PS5 = 1; PS2 = 1; __delay_ms(500);
    P_LE2 = 1; __delay_ms(500); 
    P_LE2 = 0; __delay_ms(500);
    PS180 = 0; PS45 = 0; PS22 = 0; PS11 = 0; PS5 = 0; PS2 = 0; __delay_ms(500);
    
    // phase shifter 3
    PS90 = 1; PS45 = 1; PS22 = 1; PS2 = 1; __delay_ms(500);
    P_LE3 = 1; __delay_ms(500); 
    P_LE3 = 0; __delay_ms(500);
    PS90 = 0; PS45 = 0; PS22 = 0; PS2 = 0; __delay_ms(500);
    
    // phase shifter 4
    PS180 = 1; PS11 = 1; PS2 = 1; __delay_ms(500);
    P_LE4 = 1; __delay_ms(500); 
    P_LE4 = 0; __delay_ms(500);
    PS180 = 0; PS11 = 0; PS2 = 0; __delay_ms(500);
}

void Beam_2 () //194, 160.3, 267.1, 106.8
{
    // phase shifter 1
    PS180 = 1; PS11 = 1; PS2 = 1; __delay_ms(500);
    P_LE1 = 1; __delay_ms(500); 
    P_LE1 = 0; __delay_ms(500);
    PS180 = 0; PS11 = 0; PS2 = 0; __delay_ms(500);
    
    // phase shifter 2
    PS90 = 1; PS45 = 1; PS22 = 1; PS2 = 1; __delay_ms(500);
    P_LE2 = 1; __delay_ms(500); 
    P_LE2 = 0; __delay_ms(500);
    PS90 = 0; PS45 = 0; PS22 = 0; PS2 = 0; __delay_ms(500);
    
    // phase shifter 3
    PS180 = 1; PS45 = 1; PS22 = 1; PS11 = 1; PS5 = 1; PS2 = 1; __delay_ms(500);
    P_LE3 = 1; __delay_ms(500); 
    P_LE3 = 0; __delay_ms(500);
    PS180 = 0; PS45 = 0; PS22 = 0; PS11 = 0; PS5 = 0; PS2 = 0; __delay_ms(500);
    
    // phase shifter 4
    PS90 = 1; PS11 = 1; PS5 = 1; __delay_ms(500);
    P_LE4 = 1; __delay_ms(500); 
    P_LE4 = 0; __delay_ms(500);
    PS90 = 0; PS11 = 0; PS5 = 0; __delay_ms(500);
}

void Beam_3 () //182.8, 61.8, 334.6, 262.9
{
    // phase shifter 1
    PS180 = 1; PS2 = 1; __delay_ms(500);
    P_LE1 = 1; __delay_ms(500); 
    P_LE1 = 0; __delay_ms(500);
    PS180 = 0; PS2 = 0; __delay_ms(500);
    
    // phase shifter 2
    PS45 = 1; PS11 = 1; PS5 = 1; __delay_ms(500);
    P_LE2 = 1; __delay_ms(500); 
    P_LE2 = 0; __delay_ms(500);
    PS45 = 0; PS11 = 0; PS5 = 0; __delay_ms(500);
    
    // phase shifter 3
    PS180 = 1; PS90 = 1; PS45 = 1; PS11 = 1; PS5 = 1; PS2 = 1; __delay_ms(500);
    P_LE3 = 1; __delay_ms(500); 
    P_LE3 = 0; __delay_ms(500);
    PS180 = 0; PS90 = 0; PS45 = 0; PS11 = 0; PS5 = 0; PS2 = 0; __delay_ms(500);
    
    // phase shifter 4
    PS180 = 1; PS45 = 1; PS22 = 1; PS11 = 1; PS2 = 1; PS1 = 1; __delay_ms(500);
    P_LE4 = 1; __delay_ms(500); 
    P_LE4 = 0; __delay_ms(500);
    PS180 = 0; PS45 = 0; PS22 = 0; PS11 = 0; PS2 = 0; PS1 = 0; __delay_ms(500);
}

void Beam_4 () //246.0, 243.2, 201.0, 209.5
{
    // phase shifter 1
    PS180 = 1; PS45 = 1; PS11 = 1; PS5 = 1; PS2 = 1; PS1 = 1; __delay_ms(500);
    P_LE1 = 1; __delay_ms(500); 
    P_LE1 = 0; __delay_ms(500);
    PS180 = 0; PS45 = 0; PS11 = 0; PS5 = 0; PS2 = 0; PS1 = 0; __delay_ms(500);
    
    // phase shifter 2
    PS180 = 1; PS45 = 1; PS11 = 1; PS5 = 1; PS1 = 1; __delay_ms(500);
    P_LE2 = 1; __delay_ms(500); 
    P_LE2 = 0; __delay_ms(500);
    PS180 = 0; PS45 = 0; PS11 = 0; PS5 = 0; PS1 = 0; __delay_ms(500);
    
    // phase shifter 3
    PS180 = 1; PS11 = 1; PS5 = 1; PS2 = 1; PS1 = 1; __delay_ms(500);
    P_LE3 = 1; __delay_ms(500); 
    P_LE3 = 0; __delay_ms(500);
    PS180 = 0; PS11 = 0; PS5 = 0; PS2 = 0; PS1 = 0; __delay_ms(500);
    
    // phase shifter 4
    PS180 = 1; PS22 = 1; PS5 = 1; PS1 = 1; __delay_ms(500);
    P_LE4 = 1; __delay_ms(500); 
    P_LE4 = 0; __delay_ms(500);
    PS180 = 0; PS22 = 0; PS5 = 0; PS1 = 0; __delay_ms(500);
}

void Beam_5 () //209.5, 201.0, 243.2, 246.0
{
    // phase shifter 1
    PS180 = 1; PS22 = 1; PS5 = 1; PS1 = 1; __delay_ms(500);
    P_LE1 = 1; __delay_ms(500); 
    P_LE1 = 0; __delay_ms(500);
    PS180 = 0; PS22 = 0; PS5 = 0; PS1 = 0; __delay_ms(500);
    
    // phase shifter 2
    PS180 = 1; PS11 = 1; PS5 = 1; PS2 = 1; PS1 = 1; __delay_ms(500);
    P_LE2 = 1; __delay_ms(500); 
    P_LE2 = 0; __delay_ms(500);
    PS180 = 0; PS11 = 0; PS5 = 0; PS2 = 0; PS1 = 0; __delay_ms(500);
    
    // phase shifter 3
    PS180 = 1; PS45 = 1; PS11 = 1; PS5 = 1; PS1 = 1; __delay_ms(500);
    P_LE3 = 1; __delay_ms(500); 
    P_LE3 = 0; __delay_ms(500);
    PS180 = 0; PS45 = 0; PS11 = 0; PS5 = 0; PS1 = 0; __delay_ms(500);
    
    // phase shifter 4
    PS180 = 1; PS45 = 1; PS11 = 1; PS5 = 1; PS2 = 1; PS1 = 1; __delay_ms(500);
    P_LE4 = 1; __delay_ms(500); 
    P_LE4 = 0; __delay_ms(500);
    PS180 = 0; PS45 = 0; PS11 = 0; PS5 = 0; PS2 = 0; PS1 = 0; __delay_ms(500);
}

void Beam_6 () //262.9, 334.6, 61.8, 182.8
{
    // phase shifter 1
    PS180 = 1; PS45 = 1; PS22 = 1; PS11 = 1; PS2 = 1; PS1 = 1; __delay_ms(500);
    P_LE1 = 1; __delay_ms(500); 
    P_LE1 = 0; __delay_ms(500);
    PS180 = 0; PS45 = 0; PS22 = 0; PS11 = 0; PS2 = 0; PS1 = 0; __delay_ms(500);
    
    // phase shifter 2
    PS180 = 1; PS90 = 1; PS45 = 1; PS11 = 1; PS5 = 1; PS2 = 1; __delay_ms(500);
    P_LE2 = 1; __delay_ms(500); 
    P_LE2 = 0; __delay_ms(500);
    PS180 = 0; PS90 = 0; PS45 = 0; PS11 = 0; PS5 = 0; PS2 = 0; __delay_ms(500);
    
    // phase shifter 3
    PS45 = 1; PS11 = 1; PS5 = 1; __delay_ms(500);
    P_LE3 = 1; __delay_ms(500); 
    P_LE3 = 0; __delay_ms(500);
    PS45 = 0; PS11 = 0; PS5 = 0; __delay_ms(500);
    
    // phase shifter 4
    PS180 = 1; PS2 = 1; __delay_ms(500);
    P_LE4 = 1; __delay_ms(500); 
    P_LE4 = 0; __delay_ms(500);
    PS180 = 0; PS2 = 0; __delay_ms(500);
}

uint8_t SPI1_Exchange8bit(uint8_t data)
{
 uint8_t read;
 SPI1TCNTL = 1; //One byte transfer count
 SPI1TXB = data;
 while(SPI1CON2bits.BUSY == 1); 
 read = SPI1RXB;
 return (read);
 
}

void MSdelay(unsigned int val)
{
     unsigned int b,c;
        for(b=0;b<val;b++)
            for(c=0;c<165;c++);      /*This count Provide delay of 1 ms for 8MHz Frequency */
}
//----------------------------------------------------------------------------------------------------------------------------
void main() {
    //OSCFRQ = 0x3E8; // setting internal oscillator to 64 MHz
    //RB3PPS = 0x1E;  // SPI clk set to B3
    //RB4PPS = 0x1F;  // SPI data outset to B4    
    SPI1SDIPPS = 0b01001;  // Changes the SPI output to RB2
    PORTA = 0; LATA = 0; ANSELA = 0;  TRISA = 0b00000001; // PORTA 0 input / 1-7 outputs
    PORTB = 0; LATB = 0; ANSELB = 0;  TRISB = 0b00000000; // PORTB outputs
    PORTC = 0; LATC = 0; ANSELC = 0;  TRISC = 0b00000000; // PORTC outputs
    PORTD = 0; LATD = 0; ANSELD = 0;  TRISD = 0b00000001; // PORTD 0 input / 1-7 outputs 
    PORTE = 0; LATE = 0; ANSELE = 0;  TRISE = 0b1000; // PORTE 0-2 outputs
    
    //start with initialization
    SPI1_Init();
    
    SPI1_Exchange8bit(4);
    A_LE1 = 1;
    //__delay_ms(500);
    A_LE1 = 0;
        
        
}
