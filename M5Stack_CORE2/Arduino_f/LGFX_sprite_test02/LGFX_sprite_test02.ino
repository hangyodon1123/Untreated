// LGFX_sprite_test02

//#define LGFX_M5STACK_CORE2
#define LGFX_AUTODETECT
#define LGFX_USE_V1

#include "map_data_8x8.h"
#include "chr_data_8x8.h"
#include <LovyanGFX.hpp>
#include <LGFX_AUTODETECT.hpp>

static LGFX lcd;
static LGFX_Sprite sprite[3](&lcd);

void setup(void)
{
  lcd.init();

  lcd.setRotation(1);
  lcd.setBrightness(128);
  lcd.setColorDepth(24);

  lcd.setBaseColor(TFT_BLACK);

  chr_make();
}

void data_disp1(void)
{
  lcd.clear();
  for (uint32_t j = 0; j<30; ++j) {
    for (uint32_t i = 0; i < 39; ++i) {
      lcd.startWrite();
      for (uint32_t x = 0; x < 8; ++x) {
        for (uint32_t y = 0; y < 8; ++y) {
          if (map_data[i][y][x] == 1) {
            lcd.drawPixel((i*8)+x+1, (j*8)+y+1, TFT_WHITE);
          }
          else {
            lcd.drawPixel((i*8)+x+1, (j*8)+y+1, TFT_BLACK);
          }
        }
      }
      lcd.endWrite();
    }
  }
}

void chr_make(void)
{
  lcd.clear();

  for (uint32_t i = 0; i < 3; ++i) {
    sprite[i].setColorDepth(24);
    sprite[i].createSprite(10, 10);  // 8x8 +1dot
    for (uint32_t x = 0; x < 8; ++x) {
      for (uint32_t y = 0; y < 8; ++y) {
        if (chr_data[i][y][x] == 1) {
          sprite[i].drawPixel(x+1, y+1, TFT_WHITE);
        }
        else {
         sprite[i].drawPixel(x+1, y+1, TFT_BLACK);
        }
      }
    }
  }
}

void chr_disp1(void)
{
  lcd.clear();

  for (uint32_t i = 0; i < 3; ++i) {
    sprite[i].pushSprite(&lcd, 0, 0);
    
    sprite[i].setPivot(5, 5);
    int32_t center_x = lcd.width()/2;
    int32_t center_y = lcd.height()/2;
    lcd.startWrite();
    sprite[i].pushRotateZoom(center_x, center_y - (10*6), 0, 5, 5);
    for (int angle = 0; angle <= 360; ++angle) {
      sprite[i].pushRotateZoom(center_x, center_y, angle, 5, 5);
    }
    lcd.endWrite();
    delay(400);
  }
}

void chr_disp2(void)
{
  lcd.clear();

  for (uint32_t i = 0; i < 3; ++i) {    
    sprite[i].setPivot(0, 0);
  }
  int32_t center_x = lcd.width()/2;
  int32_t center_y = lcd.height()/2;

  lcd.startWrite();
  int d = 100;
  int angle = 0;
  int x = 0;
  for (;;) {
    sprite[0].pushRotateZoom(x, center_y, angle, 5, 5);
    delay(d); x++;
    sprite[1].pushRotateZoom(x, center_y, angle, 5, 5);
    delay(d); x++;
    sprite[2].pushRotateZoom(x, center_y, angle, 5, 5);
    delay(d); x++;
    sprite[1].pushRotateZoom(x, center_y, angle, 5, 5);
    delay(d); x++;
    if (x > (lcd.width() - 10 * 5))  break; 
  }
  lcd.endWrite();
}

void loop(void)
{
//  data_disp1();
//  delay(3000);
  chr_disp1();
  delay(3000);
  chr_disp2();
  delay(3000);
}
