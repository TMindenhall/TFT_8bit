/*
 * File:   time_delay.c
 * Author: Thomas Mindenhall
 */
#include <xc.h>
#include "DELAY.h"
#define _XTAL_FREQ 32000000L // Select your XTAL

void Delay_ms(unsigned int count){
unsigned int i;
for(i = 0; i < count; i++){
__delay_ms(1);
}
}

void Delay_us(unsigned int count){
unsigned int i;
for(i = 0; i < count; i++){
__delay_us(1);
}
}