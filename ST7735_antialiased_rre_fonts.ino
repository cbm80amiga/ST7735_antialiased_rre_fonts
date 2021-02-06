// Antialiased RRE fonts example
// (C)2021 Pawel A. Hernik
// Set ENABLE_* in RREFont.h to free some flash memory if necessary

/*
 ST7735 128x160 1.8" LCD pinout (header at the top, from left):
 #1 LED   -> 3.3V
 #2 SCK   -> SCL/D13/PA5
 #3 SDA   -> MOSI/D11/PA7
 #4 A0/DC -> D8/PA1  or any digital
 #5 RESET -> D9/PA0  or any digital
 #6 CS    -> D10/PA2 or any digital
 #7 GND   -> GND
 #8 VCC   -> 3.3V
*/

#define SCR_WD   128
#define SCR_HT   160
#include <SPI.h>
#include <Adafruit_GFX.h>

#if (__STM32F1__) // bluepill
#define TFT_CS  PA2
#define TFT_DC  PA1
#define TFT_RST PA0
//#include <Arduino_ST7735_STM.h>
#else
#define TFT_CS 10
#define TFT_DC  8
#define TFT_RST 9
#include <Arduino_ST7735_Fast.h>
#endif

Arduino_ST7735 lcd = Arduino_ST7735(TFT_DC, TFT_RST, TFT_CS);

#include "RREFont.h"

#include "dig16x24_c1.h"
#include "dig16x24_c2.h"
#include "dig16x24_c3.h"
#include "dig16x24_c123.h"

#include "dig12x19_c1.h"
#include "dig12x19_c2.h"
#include "dig12x19_c3.h"
#include "dig12x19_c123.h"

#include "dig12x17_c1.h"
#include "dig12x17_c2.h"
#include "dig12x17_c3.h"
#include "dig12x17_c123.h"

#include "dig10x14_c1.h"
#include "dig10x14_c2.h"
#include "dig10x14_c3.h"
#include "dig10x14_c123.h"

#include "dig7x11_c1.h"
#include "dig7x11_c2.h"
#include "dig7x11_c3.h"
#include "dig7x11_c123.h"

#include "dig7x9_c1.h"
#include "dig7x9_c2.h"
#include "dig7x9_c3.h"
#include "dig7x9_c123.h"

#include "dig29x36_c1.h"
#include "dig29x36_c2.h"
#include "dig29x36_c3.h"

#include "font8x16_c1.h"
#include "font8x16_c2.h"
#include "font8x16_c3.h"
#include "font8x16_c123.h"

#include "fonti8x16_c1.h"
#include "fonti8x16_c2.h"
#include "fonti8x16_c3.h"
#include "fonti8x16_c123.h"

#include "font16x32_c1.h"
#include "font16x32_c2.h"
#include "font16x32_c3.h"
#include "font16x32_c123.h"

#include "fonti16x32_c1.h"
#include "fonti16x32_c2.h"
#include "fonti16x32_c3.h"
#include "fonti16x32_c123.h"

RREFont font;

// needed for RREFont library initialization, define your fillRect
void customRect(int x, int y, int w, int h, int c) { return lcd.fillRect(x, y, w, h, c); }

void setup() 
{
  Serial.begin(9600);
  lcd.init();
  font.init(customRect, SCR_WD, SCR_HT); // custom fillRect function and screen width and height values
}

uint16_t c0,c1,c2,c3;

#define RGBIto565(r,g,b,i) ((((((r)*(i))/255) & 0xF8) << 8) | ((((g)*(i)/255) & 0xFC) << 3) | ((((b)*(i)/255) & 0xFC) >> 3))  

uint16_t mixCol(int r1, int g1, int b1, int r2, int g2, int b2, int tr)
{
  int r = r1+(long)(r2-r1)*tr/255;
  int g = g1+(long)(g2-g1)*tr/255;
  int b = b1+(long)(b2-b1)*tr/255;
  return RGBto565(r,g,b);
}

void drawDigits(int y, int w)
{
  int ii=128/w;
  for(int i=0;i<ii;i++) font.drawChar(1+i*w,y,(i%10)+'0');
}

void showDigits7x9(int y)
{
  int w = 7;  // 7 or 8
  lcd.fillRect(0,y,128,80,c0);
  font.setFont(&rre_dig7x9_c1);
  font.setColor(c1);
  drawDigits(y+10,w);
  drawDigits(y+54,w);
  font.setFont(&rre_dig7x9_c123);
  font.setColor(c1);
  drawDigits(y+32,w);

  font.setFont(&rre_dig7x9_c2);
  font.setColor(c2);
  drawDigits(y+54,w);

  font.setFont(&rre_dig7x9_c3);
  font.setColor(c3);
  drawDigits(y+54,w);
}

void showDigits7x11(int y)
{ 
  int w = 9;  // 7 to 90-
  lcd.fillRect(0,y,128,80,c0);
  font.setFont(&rre_dig7x11_c1);
  font.setColor(c1);
  drawDigits(y+10,w);
  drawDigits(y+54,w);
  font.setFont(&rre_dig7x11_c123);
  font.setColor(c1);
  drawDigits(y+32,w);

  font.setFont(&rre_dig7x11_c2);
  font.setColor(c2);
  drawDigits(y+54,w);

  font.setFont(&rre_dig7x11_c3);
  font.setColor(c3);
  drawDigits(y+54,w);
}

void showDigits10x14(int y)
{
  int w = 11;  // 10 or 11
  lcd.fillRect(0,y,128,80,c0);
  font.setFont(&rre_dig10x14_c1);
  font.setColor(c1);
  drawDigits(y+10,w);
  drawDigits(y+56,w);
  font.setFont(&rre_dig10x14_c123);
  font.setSpacing(2);
  font.setColor(c1);
  drawDigits(y+33,w);

  font.setFont(&rre_dig10x14_c2);
  font.setColor(c2);
  drawDigits(y+56,w);

  font.setFont(&rre_dig10x14_c3);
  font.setColor(c3);
  drawDigits(y+56,w);
}


void showDigits12x17(int y)
{
  int w = 12;  // 12 or 13
  lcd.fillRect(0,y,128,80,c0);
  font.setFont(&rre_dig12x17_c1);
  font.setColor(c1);
  drawDigits(y+6,w);
  drawDigits(y+52,w);
  font.setFont(&rre_dig12x17_c123);
  font.setColor(c1);
  drawDigits(y+29,w);

  font.setFont(&rre_dig12x17_c2);
  font.setColor(c2);
  drawDigits(y+52,w);

  font.setFont(&rre_dig12x17_c3);
  font.setColor(c3);
  drawDigits(y+52,w);
}

void showDigits12x19(int y)
{
  int w = 14;  // 12-14
  lcd.fillRect(0,y,128,80,c0);
  font.setFont(&rre_dig12x19_c1);
  font.setColor(c1);
  drawDigits(y+4,w);
  drawDigits(y+52,w);
  font.setFont(&rre_dig12x19_c123);
  font.setColor(c1);
  drawDigits(y+28,w);

  font.setFont(&rre_dig12x19_c2);
  font.setSpacing(2);
  font.setColor(c2);
  drawDigits(y+52,w);

  font.setFont(&rre_dig12x19_c3);
  font.setSpacing(2);
  font.setColor(c3);
  drawDigits(y+52,w);
}


void showDigits16x24(int y)
{
  int w = 18;  // 17 or 18
  lcd.fillRect(0,y,128,80,c0);
  font.setFont(&rre_dig16x24_c1);
  font.setColor(c1);
  drawDigits(y+8,w);
  drawDigits(y+40,w);

  font.setFont(&rre_dig16x24_c2);
  font.setColor(c2);
  drawDigits(y+40,w);

  font.setFont(&rre_dig16x24_c3);
  font.setColor(c3);
  drawDigits(y+40,w);
}


void drawClockDigits(int y, int w)
{
  int x=0;
  font.drawChar(x+0*w,y,'2');
  font.drawChar(x+1*w,y,'0');
  font.drawChar(x+2*w,y-5,':');
  font.drawChar(x+2*w,y-20,':');
  font.drawChar(x+12+2*w,y,'3');
  font.drawChar(x+12+3*w,y,'5');
}

void showClock29x36(int y)
{
  int w = 29;
  lcd.fillRect(0,y,128,80,c0);
  font.setFont(&rre_dig29x36_c1);
  font.setColor(c1);
  drawClockDigits(y+2,w);
  drawClockDigits(y+42,w);

  font.setFont(&rre_dig29x36_c2);
  font.setColor(c2);
  drawClockDigits(y+42,w);

  font.setFont(&rre_dig29x36_c3);
  font.setColor(c3);
  drawClockDigits(y+42,w);
}

void drawChars(int y, int w)
{
  int i,ii=128/w;
  int x=1,h=26;
  for(i=0;i<ii;i++) {
    font.drawChar(x+i*w,y,'A'+i);
    font.drawChar(x+i*w,y+h*1,'a'+i);
    font.drawChar(x+i*w,y+h*2,'0'+i);
  }
}

void drawChars8(int y, int w)
{
  int i,ii=16;
  int x=1,h=13;
  for(i=0;i<ii;i++) {
    font.drawChar(x+i*w,y+h*0,32+i);
    font.drawChar(x+i*w,y+h*1,32+16+i);
    font.drawChar(x+i*w,y+h*2,64+i);
    font.drawChar(x+i*w,y+h*3,'P'+i);
    font.drawChar(x+i*w,y+h*4,64+32+i);
    font.drawChar(x+i*w,y+h*5,'p'+i);
  }
}

void showFont8x16(int y)
{
  int w = 8;
  lcd.fillRect(0,y,128,80,c0);
  font.setFont(&rre_font8x16_c1);
  font.setColor(c1);
  drawChars8(y+1,w);

  font.setFont(&rre_font8x16_c2);
  font.setColor(c2);
  drawChars8(y+1,w);

  font.setFont(&rre_font8x16_c3);
  font.setColor(c3);
  drawChars8(y+1,w);
}

void showFonti8x16(int y)
{
  int w = 7;
  lcd.fillRect(0,y,128,80,c0);
  font.setFont(&rre_fonti8x16_c1);
  font.setColor(c1);
  drawChars8(y+1,w);

  font.setFont(&rre_fonti8x16_c2);
  font.setColor(c2);
  drawChars8(y+1,w);

  font.setFont(&rre_fonti8x16_c3);
  font.setColor(c3);
  drawChars8(y+1,w);
}


void showFont16x32(int y)
{
  int w = 15;
  lcd.fillRect(0,y,128,80,c0);
  font.setFont(&rre_font16x32_c1);
  font.setColor(c1);
  drawChars(y+2,w);

  font.setFont(&rre_font16x32_c2);
  font.setColor(c2);
  drawChars(y+2,w);

  font.setFont(&rre_font16x32_c3);
  font.setColor(c3);
  drawChars(y+2,w);
}

void showFonti16x32(int y)
{
  int w = 13;
  lcd.fillRect(0,y,128,80,c0);
  font.setFont(&rre_fonti16x32_c1);
  font.setColor(c1);
  drawChars(y+2,w);

  font.setFont(&rre_fonti16x32_c2);
  font.setColor(c2);
  drawChars(y+2,w);

  font.setFont(&rre_fonti16x32_c3);
  font.setColor(c3);
  drawChars(y+2,w);
}

void dark()
{ 
  /*
  c0 = RGBto565(240,240,240);
  c3 = RGBto565(180,180,180);
  c2 = RGBto565(100,100,100);
  c1 = RGBto565(0,0,0);
  */
  c0 = mixCol(250,250,250, 0,0,0, 0);
  c1 = mixCol(250,250,250, 0,0,0, 255);
  c2 = mixCol(250,250,250, 0,0,0, 180);
  c3 = mixCol(250,250,250, 0,0,0, 100);
}

void dark2()
{ 
  c0 = mixCol(255,255,50, 240,0,0, 0);
  c3 = mixCol(255,255,50, 240,0,0, 100);
  c2 = mixCol(255,255,50, 240,0,0, 180);
  c1 = mixCol(255,255,50, 240,0,0, 255);
}

void bright()
{
  /*
  c1 = RGBto565(240,240,240);
  c2 = RGBto565(180,180,180);
  c3 = RGBto565(100,100,100);
  c0 = RGBto565(0,0,0);
*/
  
  c1 = RGBto565(250,250,250);
  c2 = RGBto565(180,180,180);
  c3 = RGBto565(100,100,100);
  c0 = RGBto565(0,0,0);
}

void bright2()
{
  c1 = mixCol(0,0,130, 255,255,255, 240);
  c2 = mixCol(0,0,130, 255,255,255, 180);
  c3 = mixCol(0,0,130, 255,255,255, 100);
  c0 = mixCol(0,0,130, 255,255,255, 0);
}

int del = 6000;

void bigFontItalicDemo()
{
  dark(); c2 = c3 = c1;
  showFonti16x32(0);
  bright(); c2 = c3 = c1;
  showFonti16x32(80);
  delay(del);

  dark();
  showFonti16x32(0);
  bright();
  showFonti16x32(80);
  delay(del);
}

void bigFontDemo()
{
  dark(); c2 = c3 = c1;
  showFont16x32(0);
  bright(); c2 = c3 = c1;
  showFont16x32(80);
  delay(del);

  dark();
  showFont16x32(0);
  bright();
  showFont16x32(80);
  delay(del);
}

void smallFontsDemo()
{
  dark(); c2 = c3 = c1;
  showFont8x16(0);
  bright(); c2 = c3 = c1;
  showFont8x16(80);
  delay(del);

  dark();
  showFont8x16(0);
  bright();
  showFont8x16(80);
  delay(del);

  dark(); c2 = c3 = c1;
  showFonti8x16(0);
  bright(); c2 = c3 = c1;
  showFonti8x16(80);
  delay(del);

  dark();
  showFonti8x16(0);
  bright();
  showFonti8x16(80);
  delay(del);
}

void digitsDemo()
{
  dark();
  showClock29x36(0);
  bright();
  showClock29x36(80);
  delay(del);

  dark();
  showDigits7x9(0);
  bright();
  showDigits7x9(80);
  delay(del);

  dark();
  showDigits7x11(0);
  bright();
  showDigits7x11(80);
  delay(del);

  dark();
  showDigits10x14(0);
  bright();
  showDigits10x14(80);
  delay(del);

  dark2();
  showDigits12x17(0);
  bright2();
  showDigits12x17(80);
  delay(del);

  dark();
  showDigits12x19(0);
  bright();
  showDigits12x19(80);
  delay(del);

  dark2();
  showDigits16x24(0);
  bright2();
  showDigits16x24(80);
  delay(del);
}

void loop()
{
  //bigFontDemo();
  //bigFontItalicDemo();
  smallFontsDemo();
  //digitsDemo();
}

