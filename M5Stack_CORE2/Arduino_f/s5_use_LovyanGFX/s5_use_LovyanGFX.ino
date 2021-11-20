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

RTC_TimeTypeDef  RTCtime;
static uint64_t count;
static char *time_d[] = {"零","壱","弐","参","肆","伍","陸","漆","捌","玖"};

void setup()
{
	// put your setup code here, to run once:
	M5.begin();

	lcd.begin();
	lcd.setRotation(1);
	lcd.fillScreen(TFT_BLACK);

	render.showFreeTypeVersion(); // print FreeType version
	render.showCredit();		  // print FTL credit

  if (render.loadFont("/ipam.ttf"))
  {
    Serial.println("Render initialize error");
    return;
  }

	render.setDrawer(lcd); // Set drawer object
	/* You can also be written as follows. */
	// render.setDrawPixel(lcd.drawPixel);
	// render.setStartWrite(lcd.startWrite); // optional
	// render.setEndWrite(lcd.endWrite);	 // optional

  render.setCursor(0, 0);

  render.setFontSize(24);
  render.setFontColor(TFT_WHITE);
  render.printf("Use ipam.ttf in SDcard.\n");
  render.seekCursor(0, 10);

  render.setFontSize(24);
  render.setFontColor(TFT_GREEN);
  for ( int i=0; i<=9; ++i) {
    render.printf("%s",time_d[i]);
  }
  render.printf("\n");
  render.printf("０１２３４５６７８９\n");

  M5.Rtc.GetTime(&RTCtime);
  count = 1000 * ((RTCtime.Seconds) + (RTCtime.Minutes * 60) + (RTCtime.Hours * 60 * 60));
}

void disp_f()
{  
//  lcd.fillScreen(TFT_BLACK);

//	unsigned long t_start = millis();

  render.setCursor(0, 100);

  render.setFontSize(24);
  render.setFontColor(TFT_ORANGE,TFT_BLACK);
  M5.Rtc.GetTime(&RTCtime);
  int t_h = RTCtime.Hours;
  int t_m = RTCtime.Minutes;
  int t_s = RTCtime.Seconds;
  char data_s[9];
  sprintf(data_s,"%02d:%02d:%02d",t_h,t_m,t_s);
  render.printf(data_s);
  render.printf("\n");

  render.setFontSize(40);
  render.setFontColor(TFT_ORANGE,TFT_BLACK);
  for ( int i=0; i<=7; ++i) {
    switch(data_s[i]) {
      case '0': render.printf("%s",time_d[0]); break;
      case '1': render.printf("%s",time_d[1]); break;
      case '2': render.printf("%s",time_d[2]); break;
      case '3': render.printf("%s",time_d[3]); break;
      case '4': render.printf("%s",time_d[4]); break;
      case '5': render.printf("%s",time_d[5]); break;
      case '6': render.printf("%s",time_d[6]); break;
      case '7': render.printf("%s",time_d[7]); break;
      case '8': render.printf("%s",time_d[8]); break;
      case '9': render.printf("%s",time_d[9]); break;
      case ':': render.printf("："); break;
    }
  }
  render.printf("\n");

//	unsigned long t_end = millis();
//	Serial.printf("Time: %ld ms\n", t_end - t_start);
}

void loop()
{
	// put your main code here, to run repeatedly:
  disp_f();
//  render.unloadFont();
  delay(1000);
}
