#if defined(ARDUINO_M5Stack_Core_ESP32) || defined(ARDUINO_M5STACK_FIRE)
#include "M5Stack.h"
#elif defined(ARDUINO_M5STACK_Core2) // M5Stack Core2
#include "M5Core2.h"
#endif

#include "OpenFontRender.h" // Include after M5Stack.h / M5Core2.h

OpenFontRender render;

void setup()
{
	// put your setup code here, to run once:
	M5.begin();
	M5.Lcd.fillScreen(BLACK);

	render.showFreeTypeVersion(); // print FreeType version
	render.showCredit();		  // print FTL credit

//	if (render.loadFont("/JKG-M_3_Tiny.ttf"))
  if (render.loadFont("/KswTouryu.ttf"))
	{
		Serial.println("Render initialize error");
		return;
	}

	render.setDrawer(M5.Lcd); // Set drawer object
	/* You can also be written as follows. */
	// render.setDrawPixel(M5.Lcd.drawPixel);
	// render.setStartWrite(M5.Lcd.startWrite); // optional
	// render.setEndWrite(M5.Lcd.endWrite);	 // optional
}

  void disp_f()
{
  M5.Lcd.fillScreen(BLACK);
  render.setCursor(0, 0);

//  unsigned long t_start = millis();

  render.setFontSize(40);
	render.setFontColor(WHITE);
	render.printf("Hello World\n");
//	render.seekCursor(0, 5);

	render.setFontSize(30);
	render.setFontColor(GREEN);
	render.printf("完全なUnicodeサポート\n");
//	render.seekCursor(0, 5);
	
	render.setFontSize(40);
	render.setFontColor(ORANGE);
	render.printf("こんにちは世界\n");
//  render.seekCursor(0, 5);
  
  render.setFontSize(40);
  render.setFontColor(CYAN);
  render.printf("TTFont in SDcard\n");
//  render.seekCursor(0, 5);
  
  render.setFontSize(60);
  render.setFontColor(PINK);
  render.printf("Good Job !\n");

//	unsigned long t_end = millis();
//	Serial.printf("Time: %ld ms\n", t_end - t_start);

  delay(3000);
}

void loop()
{
  disp_f();
	// put your main code here, to run repeatedly:
}
