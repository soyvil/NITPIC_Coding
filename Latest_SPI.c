//attenuator stuff 
#define A_SP LATDbits.LATD0
#define A_LE1 LATDbits.LATD1
#define A_LE2 LATBbits.LATB5
#define A_LE3 LATBbits.LATB4
#define A_LE4 LATBbits.LATB3
#define SP_data LATBbits.LATB2

#define LED1 LATDbits.LATD2
#define LED2 LATDbits.LATD3

//--------------------------------------------- Functions --------------------------------------------------------------------------
void SPI1_Init()
{
    A_SP = 1; // set to serial 
    SPI1INTE = 0x00;
    SPI1CON0 = 0b00000111;
    SPI1CON1 = 0b00000000;
    SPI1CON2 = 0b00000110;
    SPI1CLK = 0x00;
    SPI1BAUD = 0x7;
    SPI1CON0bits.EN = 1; // Enable
}

uint8_t SPI1_Exchange8bit(uint8_t data)
{
    SPI1TXB = 0;  
    __delay_ms(500);
    SPI1TCNT = 1; //One byte transfer count
    SPI1TXB = data;
    //__delay_ms(100);
}

//----------------------------------------------------------------------------------------------------------------------------
void main() {
    RB2PPS = 0b011111;    // SPI1 SDO -> RB2 from "TABLE 17-2: PPS OUTPUT REGISTER DETAILS"
    PORTB = 0; LATB = 0; ANSELB = 0;  TRISB = 0b00000000; // PORTB outputs
    PORTD = 0; LATD = 0; ANSELD = 0;  TRISD = 0b00000000; // PORTD 0-7 outputs
    
    //start with initialization
    SPI1_Init();
        
    while(1){
        
        __delay_ms(500);            
        LED1 = 1; //check on
        SPI1_Exchange8bit(0); //0dB attenuation 
        A_LE1 = 1; //LE on
        __delay_ms(500);
        A_LE1 = 0; //LE off
        LED1 = 0; //check off
                     
        __delay_ms(500);
        LED2 = 1; //check on
        SPI1_Exchange8bit(64); //16dB attenuation 
        A_LE1 = 1; //LE on
        __delay_ms(500);
        A_LE1 = 0; //LE off
        LED2 = 0; //check off
        
    }
            
}
