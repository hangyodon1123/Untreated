#include<LovyanGFX.hpp>

static LGFX tft;

void drawStr(const char* str, bool drawCursor = false) {
  int i = 0;
  do {
    delay(25);
    tft.print(str[i]);
    tft.setCursor(tft.getCursorX() - 1, tft.getCursorY());
    if (drawCursor) tft.fillRect(tft.getCursorX()+1, tft.getCursorY()+2, 4, 12, 0xFFFFFFU);
  } while (str[++i] != 0);
}

void blinkCursor(int loop) {
  tft.fillRect(tft.getCursorX()+1, tft.getCursorY()+2, 5, 12, 0);
  for (int i = 0 ; i < loop; ++i) {
    delay(130); tft.fillRect(tft.getCursorX()+1, tft.getCursorY()+2, 4, 12, 0xFFFFFFU);
    delay(200); tft.fillRect(tft.getCursorX()+1, tft.getCursorY()+2, 5, 12, 0);
  }
}

void setup(void) {
  tft.init();
}

void boot_msg(void) {
  int px = tft.width() >> 1;
  int py = tft.height() >> 1;
  int x = 100;
  int y = -90;
  int xb = 0;
  int yb = 0;
  char moji[] = "100%";

  tft.clear();
  tft.setTextFont(2);
  tft.setTextColor(0xFFFFFFU, 0);

  tft.setTextSize(2);
  
  tft.setCursor( px - x, py - y );  drawStr("", true);
  blinkCursor(5);  drawStr("LOADING ", true);
  blinkCursor(1);
  tft.scroll(0, -14);

  tft.setTextSize(1);

  drawStr("- BOOTING SYSTEM...", true);
  blinkCursor(9);
  tft.scroll(0, -14);
  tft.scroll(0, -14);

  tft.setCursor( px - x, py - y );  drawStr("Commencing System Check", true);
  blinkCursor(2);
  tft.scroll(0, -14);

  tft.setCursor( px - x, py - y );  drawStr("Memory Unit: ", true);
  blinkCursor(3);  drawStr("Green", true);  blinkCursor(1);
  tft.scroll(0, -14);

  tft.setCursor( px - x, py - y );  drawStr("Initializing Geographic Data", true);
  blinkCursor(2);
  tft.scroll(0, -14);

  tft.setCursor( px - x, py - y );  drawStr("Vitals: ", true);
  blinkCursor(3);  drawStr("Green", true);  blinkCursor(1);
  tft.scroll(0, -14);

  tft.setCursor( px - x, py - y );  drawStr("Remaining MP: ", true);
  blinkCursor(3);
  xb = tft.getCursorX();
  yb = tft.getCursorY();
  for (int i = 0; i <= 100; i++)
  {
    tft.setCursor(xb,yb);
    sprintf(moji,"%03d%%",i);
    drawStr(moji, true);
  }
  blinkCursor(1);
  tft.scroll(0, -14);

  tft.setCursor( px - x, py - y );  drawStr("Black Box Temperature: ", true);
  blinkCursor(3);  drawStr("Normal", true);  blinkCursor(1);
  tft.scroll(0, -14);

  tft.setCursor( px - x, py - y );  drawStr("Black Box Internal Pressure: ", true);
  blinkCursor(3);  drawStr("Normal", true);  blinkCursor(1);
  tft.scroll(0, -14);

  tft.setCursor( px - x, py - y );  drawStr("Activating IFF", true);
  blinkCursor(2);
  tft.scroll(0, -14);

  tft.setCursor( px - x, py - y );  drawStr("Activating FCS", true);
  blinkCursor(2);
  tft.scroll(0, -14);

  tft.setCursor( px - x, py - y );  drawStr("Initializing Pod Connection", true);
  blinkCursor(2);
  tft.scroll(0, -14);

  tft.setCursor( px - x, py - y );  drawStr("Launching DBU Setup", true);
  blinkCursor(2);
  tft.scroll(0, -14);

  tft.setCursor( px - x, py - y );  drawStr("Activating Inertia Control System", true);
  blinkCursor(2);
  tft.scroll(0, -14);

  tft.setCursor( px - x, py - y );  drawStr("Activating Environmental Sensors", true);
  blinkCursor(2);
  tft.scroll(0, -14);

  tft.setCursor( px - x, py - y );  drawStr("Equipment Authentication: ", true);
  blinkCursor(3);  drawStr("Complete", true);  blinkCursor(1);
  tft.scroll(0, -14);

  tft.setCursor( px - x, py - y );  drawStr("Equipment Status: ", true);
  blinkCursor(3);  drawStr("Green", true);  blinkCursor(1);
  tft.scroll(0, -14);

  tft.setCursor( px - x, py - y );  drawStr("All System Green", true);
  blinkCursor(2);
  tft.scroll(0, -14);

  tft.setCursor( px - x, py - y );  drawStr("Combat Preparations Complete_", true);
  blinkCursor(2);
//  tft.scroll(0, -14);

//--------------------
  tft.setTextColor(0xFF0000U);
  tft.setTextWrap(false, false);
}

void loop(void)
{
  boot_msg();
  delay(5000);
}
