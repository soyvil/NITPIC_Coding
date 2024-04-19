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
