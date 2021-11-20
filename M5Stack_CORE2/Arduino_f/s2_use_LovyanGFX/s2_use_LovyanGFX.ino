#if defined(ARDUINO_M5Stack_Core_ESP32) || defined(ARDUINO_M5STACK_FIRE)
#include "M5Stack.h"
#elif defined(ARDUINO_M5STACK_Core2) // M5Stack Core2
#include "M5Core2.h"
#endif

#include "binaryttf.h"
#include "OpenFontRender.h"

#define LGFX_M5STACK
#define LGFX_USE_V1

#include <LovyanGFX.hpp>
#include <LGFX_AUTODETECT.hpp>
static LGFX lcd; 

OpenFontRender render;

void setup()
{
	// put your setup code here, to run once:
	M5.begin();

	lcd.begin();
	lcd.setRotation(1);
	lcd.fillScreen(TFT_BLACK);

	render.showFreeTypeVersion(); // print FreeType version
	render.showCredit();		  // print FTL credit

	if (render.loadFont(binaryttf, sizeof(binaryttf)))
	{
		Serial.println("Render initialize error");
		return;
	}

	render.setDrawer(lcd); // Set drawer object
	/* You can also be written as follows. */
	// render.setDrawPixel(lcd.drawPixel);
	// render.setStartWrite(lcd.startWrite); // optional
	// render.setEndWrite(lcd.endWrite);	 // optional
}

void disp_f()
{
  lcd.fillScreen(TFT_BLACK);
  render.setCursor(0, 0);

//	unsigned long t_start = millis();

	render.setFontSize(32);
	render.setFontColor(TFT_GREEN);
	render.printf("鬼殺隊最高位の剣士\n");
	render.seekCursor(0, 10);

  render.setFontSize(80);
  render.setFontColor(TFT_CYAN);
  render.printf("《柱》\n");
  render.seekCursor(0, 10);

  int s = 40;
  int d = 1000;
  int m = -40;

  delay(d);  
	render.setFontSize(s);
	render.setFontColor(TFT_ORANGE);
	render.printf("水柱・冨岡義勇\n");
//  render.seekCursor(0, m);
//  lcd.scroll(0,m);

  delay(d);  
  render.setFontSize(s);
  render.setFontColor(TFT_ORANGE);
  render.printf("蟲柱・胡蝶しのぶ\n");
  render.seekCursor(0, m);
  lcd.scroll(0,m);

  delay(d);  
  render.setFontSize(s);
  render.setFontColor(TFT_ORANGE);
  render.printf("炎柱・煉獄杏寿郎\n");
  render.seekCursor(0, m);
  lcd.scroll(0,m);
  
  delay(d);  
  render.setFontSize(s);
  render.setFontColor(TFT_ORANGE);
  render.printf("音柱・宇髄天元\n");
  render.seekCursor(0, m);
  lcd.scroll(0,m);
 
  delay(d);  
  render.setFontSize(s);
  render.setFontColor(TFT_ORANGE);
  render.printf("恋柱・甘露寺蜜璃\n");
  render.seekCursor(0, m);
  lcd.scroll(0,m);
  
  delay(d);  
  render.setFontSize(s);
  render.setFontColor(TFT_ORANGE);
  render.printf("蛇柱・伊黒小芭内\n");
  render.seekCursor(0, m);
  lcd.scroll(0,m);
  
  delay(d);  
  render.setFontSize(s);
  render.setFontColor(TFT_ORANGE);
  render.printf("風柱・不死川実弥\n");
  render.seekCursor(0, m);
  lcd.scroll(0,m);
  
  delay(d);  
  render.setFontSize(s);
  render.setFontColor(TFT_ORANGE);
  render.printf("霞柱・時透無一郎\n");
  render.seekCursor(0, m);
  lcd.scroll(0,m);
  
  delay(d);  
  render.setFontSize(s);
  render.setFontColor(TFT_ORANGE);
  render.printf("岩柱・悲鳴嶼行冥\n");
  render.seekCursor(0, m);

//	unsigned long t_end = millis();
//	Serial.printf("Time: %ld ms\n", t_end - t_start);
  delay(d*3);  

}

void loop()
{
	// put your main code here, to run repeatedly:
  disp_f();
}
