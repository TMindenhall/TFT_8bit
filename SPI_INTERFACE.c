/*
 * File:   SPI_INTERFACE.c
 * Author: Thomas Mindenhall 
 */
#include <xc.h>
#include "SPI_INTERFACE.h"

void SPI1_Init(void){
    //Set the TRIS for Communication
TRIS_SCK1 = 0; TRIS_SDO1 = 0; TRIS_SDI1 = 1; TRIS_SS1 = 0;

/*SMP = 1, CKE = 1
  Sample is done at end, Transmit occurs from active to Idle*/
SSP1STAT = 0xC0;

/*SSPEN = 1, CKP = 0
  Turn on SPI, Clock Idle is Low*/
SSP1CON1 = 0x22;
}

void SPI1_Close(void){
    //turn off the SSPEN leave the rest the same
SSP1CON1 &= 0xDF;
}

void SPI1_Write(unsigned char data){    
//SSP1CON1bits.WCOL = 0;//If we want to check for collision
SSP1BUF = data; // Clear the buffer
while(!SSP1STATbits.BF);  //While the buffer is not full wait
data = SSP1BUF; //Read the buffer
}

unsigned char SPI1_Read(void){    
SSP1BUF = 0x00; //Put something into the register
while(!SSP1STATbits.BF); //Wait till our buffer is full
return SSP1BUF; //Return the byte we get
}
