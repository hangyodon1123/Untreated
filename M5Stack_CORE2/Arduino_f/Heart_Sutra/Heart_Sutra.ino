#include<LovyanGFX.hpp>
#include "Heart_Sutra.h"

static LGFX tft;

void drawStr(const char* str, bool drawCursor = false) {
  int i = 0;
  do {
    delay(25);
    tft.print(str[i]);
    tft.setCursor(tft.getCursorX() , tft.getCursorY());
//    tft.setCursor(tft.getCursorX() - 1, tft.getCursorY());
    if (drawCursor) tft.fillRect(tft.getCursorX()+1, tft.getCursorY()+2, 31, 34, 0xFFFFFFU);
  } while (str[++i] != 0);
}

void blinkCursor(int loop) {
  tft.fillRect(tft.getCursorX()+1, tft.getCursorY()+2, 32, 34, 0);
  for (int i = 0 ; i < loop; ++i) {
    delay(130); tft.fillRect(tft.getCursorX()+1, tft.getCursorY()+2, 31, 34, 0xFFFFFFU);
    delay(200); tft.fillRect(tft.getCursorX()+1, tft.getCursorY()+2, 32, 34, 0);
  }
}

void setup(void) {
  tft.init();
}

void boot_msg(void) {
  int px = tft.width() >> 1;
  int py = tft.height() >> 1;
  int x = 160;
  int y = -80;

  tft.clear();
  tft.setFont(&fonts::lgfxJapanMinchoP_32);
  tft.setTextColor(0xFFFFFFU, 0);
  
  tft.setCursor( px - x, py - y );
  drawStr("", true);
  blinkCursor(5);

  int i = 0;
  char* text_dt;

  for (;;)
  {
    text_dt = text_data[i];
    if ( text_dt[0] == '.' ) break;
    tft.setCursor( px - x, py - y );
    drawStr(text_dt, true);
    blinkCursor(1);
    tft.scroll(0, -36);
    i++;
  }

//--------------------
  tft.setTextColor(0xFF0000U);
  tft.setTextWrap(false, false);
}

void loop(void)
{
  boot_msg();
  delay(5000);
}
