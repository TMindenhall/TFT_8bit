/*
 * File:   spi_pic18f.h
 * Author: http://pic18fxx.blogspot.com 
 */
#ifndef SPI_PIC18F_H
#define	SPI_PIC18F_H

#define TRIS_SCK1   TRISCbits.RC3         
#define TRIS_SDO1   TRISCbits.RC5
#define TRIS_SDI1   TRISCbits.RC4
#define TRIS_SS1    TRISAbits.RA5

void SPI1_Init(void);
void SPI1_Close(void);
void SPI1_Write(unsigned char data);
unsigned char SPI1_Read(void);

#endif	/* SPI_PIC18F_H */