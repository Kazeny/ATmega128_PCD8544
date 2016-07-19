/*
 * main.c
 *
 * Created: 2016/7/17 1:56:31
 * Author : XU
 */ 

#include <avr/io.h>
#include <avr/pgmspace.h>
#include <util/delay.h>

#include "pcd8544.h"
#include "main.h"

int main(void)
{
    /* Replace with your application code */
    LcdInit();
	
    //display image
    LcdContrast(0x7F);
    LcdClear();
    LcdImage(waitImage);
    LcdUpdate();

    _delay_ms(2500);
    LcdContrast(0x00);
    LcdUpdate();
    _delay_ms(2500);

    //display string
    LcdClear();
    LcdGotoXYFont(1,1);
    LcdFStr(FONT_1X,(unsigned char*)PSTR("Test"));
    LcdGotoXYFont(1,2);
    LcdFStr(FONT_1X,(unsigned char*)PSTR("Goto Test"));
	  LcdLine(0,83,0,47,PIXEL_ON);
	  LcdSingleBar(10,40,3,20,PIXEL_ON);
    LcdUpdate();

    _delay_ms(5000);


    return 0;
}


