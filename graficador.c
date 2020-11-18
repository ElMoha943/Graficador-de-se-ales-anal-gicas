#include<xc.h>
#include"graficador.h"

void Pixel(unsigned char x, unsigned char y, unsigned char on)
{
    unsigned char datos[3];
    datos[1]=x;
    datos[2]=y;
    if(on) datos[0]=128;
    else datos[0]=129;
    SendSerial(datos,3);
}

void SendSerial(unsigned char *data, unsigned char lenght)
{
    unsigned char x=0;
    while(x<lenght){
        while(PIR1bits.TXIF==0){}        
        TXREG=data[x];        
        x++;
    }            
}

void Clear(void)
{
    unsigned char datos[1];
    datos[0]=134;
    SendSerial(datos,1);   
}

void ClearLinea(unsigned char x1, unsigned char y1, unsigned char x2, unsigned char y2)
{
    unsigned char datos[5];
    datos[0]=135;
    datos[1]=x1;
    datos[2]=y1;
    datos[3]=x2;
    datos[4]=y2;
    SendSerial(datos,5); 
}

