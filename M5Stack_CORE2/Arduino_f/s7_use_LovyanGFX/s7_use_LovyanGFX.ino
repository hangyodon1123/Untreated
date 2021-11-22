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
	M5.begin();

	lcd.begin();
	lcd.setRotation(1);
	lcd.fillScreen(TFT_BLUE);

	render.showFreeTypeVersion(); // print FreeType version
	render.showCredit();		  // print FTL credit

//  if (render.loadFont("/ipam.ttf"))
  if (render.loadFont("/KswTouryu.ttf"))
  {
    Serial.println("Render initialize error");
    return;
  }

	render.setDrawer(lcd); // Set drawer object
}

void disp_f()
{  
//  lcd.fillScreen(TFT_BLACK);

  render.setCursor(0, 0);

  render.setFontSize(24);
  render.setFontColor(TFT_GREEN,TFT_BLUE);
  M5.Rtc.GetTime(&RTCtime);
  int t_h = RTCtime.Hours;
  int t_m = RTCtime.Minutes;
  int t_s = RTCtime.Seconds;
  char data_s[10];
  sprintf(data_s,"%02d:%02d:%02d\n",t_h,t_m,t_s);
  M5.lcd.fillRect(0,0,12*8,24+6,TFT_BLUE);
  render.printf(data_s);

  render.setFontSize(64);
  render.setFontColor(TFT_ORANGE,TFT_BLUE);
  for ( int i=0; i<=4; ++i) {
    M5.lcd.fillRect((64*i),24+8,64,64+6,TFT_BLUE);
    disp_k(data_s[i]);
  }
  render.printf("\n");

  render.setFontSize(120);
  render.setFontColor(TFT_ORANGE,TFT_BLUE);
  render.printf(" ");
  for ( int i=6; i<=7; ++i) {
    M5.lcd.fillRect(60+(120*(i-6)),24+64+16,120,120+12,TFT_BLUE);
    disp_k(data_s[i]);
  }
}

void disp_k(char data_d)
{
  switch(data_d) {
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

void loop()
{
	// put your main code here, to run repeatedly:
  disp_f();
  delay(800);
}
