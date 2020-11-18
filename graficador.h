/* 
 * File:   graficador.h
 * Author: valen
 *
 * Created on 18 de noviembre de 2020, 18:53
 */

#ifndef GRAFICADOR_H
#define	GRAFICADOR_H

#include <xc.h> // include processor files - each processor file is guarded.  
//Variables


//Funciones
void Pixel(unsigned char x, unsigned char y, unsigned char on);
void SendSerial(unsigned char *data, unsigned char lenght);
void Clear(void);
void ClearLinea(unsigned char x1, unsigned char y1, unsigned char x2, unsigned char y2);

#endif	/* GRAFICADOR_H */

