// LGFX_sprite_8x8

//#define LGFX_M5STACK_CORE2
#define LGFX_AUTODETECT
#define LGFX_USE_V1

#include "map_data_8x8.h"
#include <LovyanGFX.hpp>
#include <LGFX_AUTODETECT.hpp>

static LGFX lcd;
static LGFX_Sprite sprite(&lcd);

void setup(void)
{
  lcd.init();

  lcd.setRotation(1);
  lcd.setBrightness(128);
  lcd.setColorDepth(24);

  lcd.setBaseColor(TFT_BLACK);
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

void data_disp2(void)
{
  lcd.clear();

  sprite.setColorDepth(24);

  sprite.createSprite(9, 9); // 8x8 +1dot

  for (uint32_t i = 0; i < 39; ++i) {
    for (uint32_t x = 0; x < 8; ++x) {
      for (uint32_t y = 0; y < 8; ++y) {
        if (map_data[i][y][x] == 1) {
          sprite.drawPixel(x+1, y+1, TFT_WHITE);
        }
        else {
         sprite.drawPixel(x+1, y+1, TFT_BLACK);
        }
      }
    }
    sprite.pushSprite(&lcd, 0, 0);
    
    sprite.setPivot(4, 4);
    int32_t center_x = lcd.width()/2;
    int32_t center_y = lcd.height()/2;
    lcd.startWrite();
    sprite.pushRotateZoom(center_x, center_y - (9*6), 0, 5, 5);
    for (int angle = 0; angle <= 360; ++angle) {
      sprite.pushRotateZoom(center_x, center_y, angle, 5, 5);
    }
    lcd.endWrite();
    delay(400);
  }
}

void loop(void)
{
  data_disp1();
  delay(3000);
  data_disp2();
  delay(3000);
}
