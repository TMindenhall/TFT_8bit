/*
 * File:   main.c
 * Author: Thomas Mindenhall 
 */
#include <xc.h>
#include <stdio.h>
#include <stdlib.h>
#include "bit_settings.h"
#include "SPI_INTERFACE.h"
#include "ILI9341.h"
#include "FONT.h"
#include "BIT_MAP.h"
#include "DELAY.h"

#define MAX_X 240
#define MAX_Y 320
    int i;
    char buffer1[20];
    char countBuffer [10];
void main(void) {

    //OSCCON = 0b01110000;
    OSCTUNEbits.PLLEN = 1; // turn on the PLL 32 MHz
    //ANSELA = 0; ANSELB = 0; ANSELC = 0; ANSELD = 0; ANSELE = 0;
    PORTA = 0;
    PORTB = 0;
    PORTC = 0;
    PORTD = 0;
    PORTE = 0;
    TRISA = 0;
    TRISB = 0;
    TRISC = 0;
    TRISD = 0;
    TRISE = 0;
    SPI1_Close();
    SPI1_Init();
    TFT_Init();

    TFT_SetDotSize(1);
    TFT_RectangleRound(5, 115, 234, 314, 10, BLACK);
    TFT_SetFont(Courier_New_Bold_20, 1);
    TFT_ConstText("Hi Austin", 20, 10, BLACK, WHITE);
    TFT_ConstText("It's Working", 20, 34, BLACK, WHITE);
    TFT_ConstText("Interface: SPI", 20, 58, BLACK, WHITE);
    TFT_ConstText("Version", 20, 82, BLACK, WHITE);
    Delay_ms(1000);

    TFT_WriteChar('>', 0, 10, BLACK, WHITE);
    TFT_ConstText("Hi Austin", 20, 10, WHITE, BLACK);
    Delay_ms(800);
    TFT_WriteChar('>', 0, 10, WHITE, WHITE);
    TFT_ConstText("Hi Austin", 20, 10, BLACK, WHITE);
    TFT_WriteChar('>', 0, 34, BLACK, WHITE);
    TFT_ConstText("It's Working", 20, 34, WHITE, BLACK);
    Delay_ms(800);
    TFT_WriteChar('>', 0, 34, WHITE, WHITE);
    TFT_ConstText("It's Working", 20, 34, BLACK, WHITE);
    TFT_WriteChar('>', 0, 58, BLACK, WHITE);
    TFT_ConstText("Interface: SPI", 20, 58, WHITE, BLACK);
    Delay_ms(800);
    TFT_WriteChar('>', 0, 58, WHITE, WHITE);
    TFT_ConstText("Interface: SPI", 20, 58, BLACK, WHITE);
    TFT_WriteChar('>', 0, 82, BLACK, WHITE);
    TFT_ConstText("Version", 20, 82, WHITE, BLACK);
    Delay_ms(800);

    for (i = 31; i > 1; i--) {
        sprintf(buffer1, "Version%3d ", i);
        TFT_Text(buffer1, 20, 82, WHITE, BLACK);
        Delay_ms(200);
    }

    TFT_Box(33, 150, 63, 180, RED);
    TFT_Box(103, 150, 133, 180, GREEN);
    TFT_Box(173, 150, 203, 180, BLUE);

    TFT_Circle(48, 165, 26, BLACK);
    TFT_RectangleRound(93, 140, 143, 190, 10, BLACK);
    TFT_Rectangle(163, 140, 213, 190, BLACK);

    //TFT_Icon(icon1, 20, 220, 64, 64);

    TFT_SetDotSize(3);
    TFT_RectangleRound(93, 210, 213, 300, 10, BLACK);

    TFT_SetDotSize(0);
    TFT_Line(93, 255, 213, 255, BLACK);
    TFT_Line(153, 210, 153, 300, BLACK);
    TFT_SetDotSize(2);
    TFT_Line(0, 0, 240, 320, BLUE);

    while (1) {
            i = 0;
    for (i = 0; i < 10; i++) {
        sprintf(countBuffer, "%d", i);
        TFT_Text(countBuffer, 20, 220, BLACK, WHITE);
        Delay_ms(100);
    }
    }

}
