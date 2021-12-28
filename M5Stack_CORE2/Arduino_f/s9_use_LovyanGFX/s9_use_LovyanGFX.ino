#if defined(ARDUINO_M5Stack_Core_ESP32) || defined(ARDUINO_M5STACK_FIRE)
#include "M5Stack.h"
#elif defined(ARDUINO_M5STACK_Core2) // M5Stack Core2
#include "M5Core2.h"
#endif

//#include "binaryttf.h"
#include "OpenFontRender.h"

#define LGFX_M5STACK
#define LGFX_USE_V1

#include <LovyanGFX.hpp>
#include <LGFX_AUTODETECT.hpp>
static LGFX lcd; 

OpenFontRender render;

int font_n;

void setup()
{
	// put your setup code here, to run once:
	M5.begin();

	lcd.begin();
	lcd.setRotation(1);
	lcd.fillScreen(TFT_BLACK);

	render.showFreeTypeVersion(); // print FreeType version
	render.showCredit();		  // print FTL credit

	render.setDrawer(lcd); // Set drawer object
	/* You can also be written as follows. */
	// render.setDrawPixel(lcd.drawPixel);
	// render.setStartWrite(lcd.startWrite); // optional
	// render.setEndWrite(lcd.endWrite);	 // optional

  font_n = 0;
}

void disp_f()
{  
  lcd.fillScreen(TFT_BLACK);
  render.setCursor(0, 0);

//	unsigned long t_start = millis();

  int s = 40;
  int d = 1000;
  int m = -40;

  render.setFontSize(24);
  render.setFontColor(TFT_WHITE);
  render.printf("Use ttf-font in SDcard.\r");
  render.seekCursor(0, 24);
  switch(font_n) {
  case 0:
    render.printf("  Font is Krungthep.\r");
    font_n = 1;
    break;
  case 1:
    render.printf("  Font is ipam.\r");
    font_n = 2;
    break;
  case 2:
    render.printf("  Font is ipag.\r");    
    font_n =0;
    break;
  default:
    break;
  }
  render.seekCursor(0, 24);

  delay(d);  
	render.setFontSize(32);
	render.setFontColor(TFT_GREEN);
	render.printf("A unit that\r");
  render.seekCursor(0, 32);
  render.printf("  kills demons\r");
	render.seekCursor(0, 32);

  delay(d);  
  render.setFontSize(48);
  render.setFontColor(TFT_CYAN);
  render.printf("<Pillar>\r");

  delay(d);  

  delay(d);  
  lcd.fillScreen(TFT_BLACK);
  render.setCursor(0, 0);

	render.setFontSize(s);
	render.setFontColor(TFT_ORANGE);
	render.printf("Water Pillar\r");
  render.seekCursor(0, s);
//  lcd.scroll(0,m);

  delay(d);  
  render.setFontSize(s);
  render.setFontColor(TFT_ORANGE);
  render.printf("Insect Pillar\r");
  render.seekCursor(0, s);
//  lcd.scroll(0,m);

  delay(d);  
  render.setFontSize(s);
  render.setFontColor(TFT_ORANGE);
  render.printf("Flame Pillar\r");
  render.seekCursor(0, s);
//  lcd.scroll(0,m);
  
  delay(d);  
  render.setFontSize(s);
  render.setFontColor(TFT_ORANGE);
  render.printf("Sound Pillar\r");
//  render.seekCursor(0, s);
  lcd.scroll(0,m);
 
  delay(d);  
  render.setFontSize(s);
  render.setFontColor(TFT_ORANGE);
  render.printf("Love Pillar\r");
//  render.seekCursor(0, s);
  lcd.scroll(0,m);
  
  delay(d);  
  render.setFontSize(s);
  render.setFontColor(TFT_ORANGE);
  render.printf("Snake Pillar\r");
//  render.seekCursor(0, s);
  lcd.scroll(0,m);
  
  delay(d);  
  render.setFontSize(s);
  render.setFontColor(TFT_ORANGE);
  render.printf("Wind Pillar\r");
//  render.seekCursor(0, s);
  lcd.scroll(0,m);
  
  delay(d);  
  render.setFontSize(s);
  render.setFontColor(TFT_ORANGE);
  render.printf("Haze Pillar\r");
//  render.seekCursor(0, s);
  lcd.scroll(0,m);
  
  delay(d);  
  render.setFontSize(s);
  render.setFontColor(TFT_ORANGE);
  render.printf("Rock Pillar\r");
//  render.seekCursor(0, s);

//	unsigned long t_end = millis();
//	Serial.printf("Time: %ld ms\n", t_end - t_start);
  delay(d*3);  

}

void loop()
{
	// put your main code here, to run repeatedly:
  if (font_n == 0) {
    if (render.loadFont("/Krungthep.ttf"))
    {
      Serial.println("Render initialize error");
      return;
    }
  }
  if (font_n == 1) {
    if (render.loadFont("/ipam.ttf"))
    {
      Serial.println("Render initialize error");
      return;
    }
  }
  if (font_n == 2) {
    if (render.loadFont("/ipag.ttf"))
    {
      Serial.println("Render initialize error");
      return;
    }    
  }  
  disp_f();
  render.unloadFont();
}
