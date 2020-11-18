// CONFIG1
#pragma config FOSC = INTRC_NOCLKOUT// Oscillator Selection bits (INTOSCIO oscillator: I/O function on RA6/OSC2/CLKOUT pin, I/O function on RA7/OSC1/CLKIN)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled and can be enabled by SWDTEN bit of the WDTCON register)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config MCLRE = OFF      // RE3/MCLR pin function select bit (RE3/MCLR pin function is digital input, MCLR internally tied to VDD)
#pragma config CP = OFF         // Code Protection bit (Program memory code protection is disabled)
#pragma config CPD = OFF        // Data Code Protection bit (Data memory code protection is disabled)
#pragma config BOREN = OFF      // Brown Out Reset Selection bits (BOR disabled)
#pragma config IESO = OFF       // Internal External Switchover bit (Internal/External Switchover mode is disabled)
#pragma config FCMEN = OFF      // Fail-Safe Clock Monitor Enabled bit (Fail-Safe Clock Monitor is disabled)
#pragma config LVP = OFF        // Low Voltage Programming Enable bit (RB3 pin has digital I/O, HV on MCLR must be used for programming)

// CONFIG2
#pragma config BOR4V = BOR40V   // Brown-out Reset Selection bit (Brown-out Reset set to 4.0V)
#pragma config WRT = OFF        // Flash Program Memory Self Write Enable bits (Write protection off)

#include<xc.h>
#include "graficador.h"

#define _XTAL_FREQ 4000000

void main(){
    unsigned char x=11, y, valor;
    TRISBbits.TRISB7=0;
    TRISBbits.TRISB6=0;
    ANSEL=0;
    
    //Configura puerto AD
    ANSELH=0;
    ANSELHbits.ANS9=1; 
    ADCON1bits.ADFM=1;
    ADCON1bits.VCFG0=0; ADCON1bits.VCFG1=0;
    ADCON0bits.ADON=1;
    ADCON0bits.CHS0=1; ADCON0bits.CHS1=0; ADCON0bits.CHS2=0; ADCON0bits.CHS3=1;
    
    //Configura UART a 9600 baudios
    TXSTAbits.TXEN=1;
    TXSTAbits.BRGH=1;
    RCSTAbits.SPEN=1;
    RCSTAbits.CREN=1;
    BAUDCTLbits.BRG16=0;
    SPBRG=25;
    SPBRGH=0;
	
	//DIBUJAR EJES
	for(x=10; x<127; x++){
		Pixel(x,94,1);
	}
	for(y=30; y<95; y++){
		Pixel(10,y,1);
	}
    
    //Borra display
    Clear();
    
    while(1){
		ADCON0bits.GO=1;
		while(ADCON0bits.GO==1){}
		valor=(ADRESH<<8)+ADRESL;
		__delay_ms(1);
		valor=valor/16;
		if(x==127)
		{
			x=11;
		}
		ClearLinea(x, 30, 1, 1);
		Pixel(x,94-valor,1);
		Pixel(x,94,1);
		x++; 
    }
}
