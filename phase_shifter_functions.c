#define ADC LATAbits.LATA0

//phase shifter LEs
#define P_LE1 LATAbits.LATA1
#define P_LE2 LATAbits.LATA2
#define P_LE3 LATAbits.LATA3
#define P_LE4 LATAbits.LATA4

//phase shifter bits
#define PS180 LATAbits.LATA5
#define PS90 LATEbits.LATE0
#define PS45 LATEbits.LATE1
#define PS22 LATEbits.LATE2
#define PS11 LATAbits.LATA7
#define PS5 LATAbits.LATA6
#define PS2 LATCbits.LATC0
#define PS1 LATCbits.LATC1
#define OPT LATCbits.LATC2

//other stuff
#define ButtonIn LATDbits.LATD0
#define ButtonOut LATDbits.LATD1
#define R_LED LATDbits.LATD2
#define G_LED LATDbits.LATD3

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

void main() {
    PORTA = 0; LATA = 0; ANSELA = 0;  TRISA = 0b00000001; // PORTA 0 input / 1-7 outputs
    PORTB = 0; LATB = 0; ANSELB = 0;  TRISB = 0b00000000; // PORTB outputs
    PORTC = 0; LATC = 0; ANSELC = 0;  TRISC = 0b00000000; // PORTC outputs
    PORTD = 0; LATD = 0; ANSELD = 0;  TRISD = 0b00000001; // PORTD 0 input / 1-7 outputs 
    PORTE = 0; LATE = 0; ANSELE = 0;  TRISE = 0b1000; // PORTE 0-2 outputs
}
