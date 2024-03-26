// CONFIG1L
#pragma config FEXTOSC = LP     // External Oscillator Selection (LP (crystal oscillator) optimized for 32.768 kHz; PFM set to low power)
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

#define RS LATD0                   /* PORTD 0 pin is used for Register Select */
#define ON LATD1                   /* PORTD 1 pin is used for Enable */
#define ldata LATC                 /* PORTC is used for transmitting data to LCD */
#define LCD_Port TRISC              
#define LCD_Control TRISD

#define LED1 LATD2
#define LED2 LATA3
#define LED3 LATA4
#define LED4 LATA5
#define AttS LATD3 //on high so att is on serial

void SPI1_Init();
void LCD_Init();
void LCD_Command(char cmd );
void LCD_String_xy(char row,char pos,const char *msg);
void LCD_Char(char dat);
void LCD_String(const char *msg);
void MSdelay(unsigned int val);

//--------------------------------------------- Functions --------------------------------------------------------------------------
void SPI1_Init()
{
    // rewrite//EN disabled; LSBF MSb first; MST bus master; BMODE every byte; 
    SPI1CON0 = 0b00000111;
    // rewrite//SMP Middle; CKE Active to idle; CKP Idle:High, Active:Low; FST disabled; SSP active high; SDIP active high; SDOP active high; 
    SPI1CON1 = 0b00000000;
    // rewrite//SSET disabled; TXR required for a transfer; RXR data is not stored in the FIFO; 
    SPI1CON2 = 0b00000010;
    // rewrite//CLKSEL FOSC; 
    SPI1CLK = 0b00000000;
    // rewrite//BAUD 3; 
    SPI1BAUD = 0b00000001;
   // check TRISCbits.TRISC1 = 0;
    
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

void LCD_Init()
{
    MSdelay(15);           /* 15ms,16x2 LCD Power on delay */
    LCD_Port = 0x00;       /* Set PORTC as output PORT for LCD data(C0-C7) pins */
    LCD_Control = 0x00;    /* Set PORTD as output PORT LCD Control(RS,EN) Pins */ 
    LCD_Command(0x38);     /* uses 2 line and initialize 5*7 matrix of LCD */
    LCD_Command(0x01);     /* clear display screen */
    LCD_Command(0x0c);     /* display on cursor off */
    LCD_Command(0x06);     /* increment cursor (shift cursor to right) */
    }

void LCD_Command(char cmd )
{
	ldata= cmd;            /* Send data to PORT as a command for LCD */   
	RS = 0;                /* Command Register is selected */
	ON = 1;                /* High-to-Low pulse on Enable pin to latch data */ 
	NOP();
	ON = 0;
	MSdelay(3);	
}

void LCD_String_xy(char row,char pos,const char *msg)
{
    char location=0;
    if(row<=1)
    {
        location=(0x80) | ((pos) & 0x0f); /*Print message on 1st row and desired location*/
        LCD_Command(location);
    }
    else
    {
        location=(0xC0) | ((pos) & 0x0f); /*Print message on 2nd row and desired location*/
        LCD_Command(location);    
    }  
    LCD_String(msg);

}

void LCD_Char(char dat)
{
	ldata= dat;            /* Send data to LCD */  
	RS = 1;                /* Data Register is selected */
	ON=1;                  /* High-to-Low pulse on Enable pin to latch data */   
	NOP();
	ON=0;
	MSdelay(1);
}

void LCD_String(const char *msg)
{
	while((*msg)!=0)
	{		
	  LCD_Char(*msg);
	  msg++;	
    	}
}

void MSdelay(unsigned int val)
{
     unsigned int b,c;
        for(b=0;b<val;b++)
            for(c=0;c<165;c++);      /*This count Provide delay of 1 ms for 8MHz Frequency */
}
//----------------------------------------------------------------------------------------------------------------------------
void main() {
    RB3PPS = 0x1E;  // SPI clk set to B3
    RB4PPS = 0x1F;  // SPI data outset to B4    
    PORTB = 0; LATB = 0; TRISB = 0x00; // clk and data for spi
    PORTA = 0; LATA = 0; ANSELA = 0;  TRISA = 0b00000111; // PORTA 0-2 inputs
    // A 0-2 for buttons,A 3-5 LEDS

    //start with initialization
    SPI1_Init();
    LCD_Init();
    AttS = 1;
    
    LED2 = 1;    
    __delay_ms(1000);
    LED2 = 0;
    
    while (1) {
    
        LED1 = 1;    
        __delay_ms(500);
        LED1 = 0;
        
    ////    LCD_String_xy(1,0,"Waiting for input");
        
        //button 1 is pressed (to set atten to zero)
        if (PORTA == 0x01) { 
            LED3 = 1;    
            __delay_ms(1000);
            LED3 = 0;
        ////    __delay_ms(1000);
        ////    LCD_Command(0x01); 
        ////    LCD_String_xy(1,0,"Att at zero");
        ////    __delay_ms(5000);
            //SPI stuff
           //////////////////////////////// SPI1CON0bits.EN = 1;  //enable spi
           //// SPI1TCNTL = 1;
           //// SPI1TXB = 0x00;
           //////////////////////////////// SPI1_Exchange8bit(0x00);
           /////////////////////////// SPI1CON0bits.EN = 0; // turn off spi 
           //// LCD_Command(0x01);
        } // end of button 1 if statement 
        
        //button 2 is pressed (to set atten to one)
        if (PORTA == 0x02) { 
            LED4 = 1;    
            __delay_ms(1000);
            LED4 = 0;
        ////    __delay_ms(1000);
        ////    LCD_Command(0x01); 
        ////    LCD_String_xy(1,0,"Att at one");
        ////    __delay_ms(5000);
            //SPI stuff
            /////////////////////SPI1CON0bits.EN = 1;  //enable spi
            ////SPI1TCNTL = 1;
            ////SPI1TXB = 0x01;
            ////////////////////SPI1_Exchange8bit(0x04);
            /////////////SPI1CON0bits.EN = 0; // turn off spi  
           //// LCD_Command(0x01);            
        } // end of button 2 if statement 
            
        //button 3 is pressed (to check if code works)
        if (PORTA == 0x04) { 
            LED2 = 1;    
            __delay_ms(1000);
            LED2 = 0;
        }      
        
     } // end of loop
               
}
