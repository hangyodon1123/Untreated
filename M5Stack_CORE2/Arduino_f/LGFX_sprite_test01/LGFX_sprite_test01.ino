// LGFX_sprite_test01

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
  lcd.setColorDepth(8);

  lcd.setBaseColor(TFT_BLACK);

  map_make();
}

void map_make(void)
{
  lcd.clear();

  sprite.setColorDepth(8);

//  sprite.createSprite(lcd.width(), lcd.height());
  sprite.createSprite(lcd.width(), 64*6);

  uint32_t w = 0;
  uint32_t h = 0;

//for (uint32_t i = 0; i < 39; ++i) {
  for (uint32_t i = 0; i < 30; ++i) {
    for (uint32_t x = 0; x < 8; ++x) {
      for (uint32_t y = 0; y < 8; ++y) {
//----------
//lcd.setCursor(0,230);
//lcd.printf("i=%02d,w=%02d,h=%02d\n", i, w, h);
//----------
        if (map_data[i][y][x] == 1) {
          block_draw(x*8+w*64, y*8+h*64);
        }
      }
    }
    w++;
    if ( w % 5 == 0 ) {
      w = 0;
      h++;
    }  
//----------
//sprite.pushSprite(&lcd, 0, 0);
//----------
  }
}

void block_draw(uint32_t xx, uint32_t yy)
{  
  uint32_t i = 41; // 41:block full
  for (uint32_t x = 0; x < 8; ++x) {
    for (uint32_t y = 0; y < 8; ++y) {
      if (map_data[i][y][x] == 1) {
        sprite.drawPixel(xx+x, yy+y, TFT_WHITE);
      }
      else {
        sprite.drawPixel(xx+x, yy+y, TFT_BLACK);
      }
    }
  }
}

void map_disp1(void) {
  int32_t center_x = lcd.width()/2;
  int32_t center_y = lcd.height()/2;
  sprite.setPivot(center_x, center_y);

  lcd.startWrite();
  for (int angle = 0; angle <= 360; ++angle) {
    sprite.pushRotateZoom(center_x, center_y, angle, 1, 1);
  }
  lcd.endWrite();
}

void map_disp2(void) {
  lcd.startWrite();
  for (int y = 0; y < 64*3; ++y) {
    sprite.pushSprite(&lcd, 0, 0-y);
  }
  for (int y = 0; y < 64*3; ++y) {
    sprite.pushSprite(&lcd, 0, (-64)*3+y);
  }
  for (int x = 0; x < 64*3; ++x) {
    sprite.pushSprite(&lcd, 0-x, 0);
  }
  for (int x = 0; x < 64*3; ++x) {
    sprite.pushSprite(&lcd, (-64)*3+x, 0);
  }
  lcd.endWrite();
}

void map_disp3(void) {
  int32_t center_x = lcd.width()/2;
  int32_t center_y = lcd.height()/2;
  sprite.setPivot(center_x, center_y);

  lcd.startWrite();
  for (int angle = 0; angle <= 360; ++angle) {
    sprite.pushRotateZoom(center_x, center_y, angle, angle/100+1, angle/100+1);
  }
  for (int angle = 3; angle >=0; --angle) {
    sprite.pushRotateZoom(center_x, center_y, 0, angle, angle);
  }
  lcd.endWrite();
}

void loop(void)
{
  map_disp1();
  delay(2000);
  map_disp2();
  delay(2000);
  map_disp3();
  delay(2000);
}
