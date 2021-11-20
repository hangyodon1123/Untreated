// LGFX_sprite_test03

//#define LGFX_M5STACK_CORE2
#define LGFX_AUTODETECT
#define LGFX_USE_V1

#include <iostream>
using namespace std;
#include "map_data_8x8.h"
#include "chr_data_8x8.h"
#include <LovyanGFX.hpp>
#include <LGFX_AUTODETECT.hpp>

static LGFX lcd;
static LGFX_Sprite sp1[4](&lcd);
static LGFX_Sprite sp2[4](&lcd);
static LGFX_Sprite sp3[4](&lcd);

static string msg[] = {"M5STACK","CORE2"};
static int msgx = 0;

void setup(void)
{
  lcd.init();

  lcd.setRotation(1);
  lcd.setBrightness(128);
  lcd.setColorDepth(16);

  lcd.setBaseColor(TFT_BLACK);

  chr_make();
  chr_disp1();
}

void data_disp1(void)
{
  for (uint32_t c = 0; c<msg[msgx].length(); ++c) {
    uint32_t i = map_name.find(msg[msgx][c]);
    if ( i == string::npos )  i = 40;  // not find
    lcd.startWrite();
    for (uint32_t x = 0; x < 8; ++x) {
      for (uint32_t y = 0; y < 8; ++y) {
        if (map_data[i][y][x] == 1) {
//          lcd.drawPixel((c*8)+x+1, y+1, TFT_WHITE);
          lcd.fillRect((c*8*5)+(x*5)+1, (y*5)+1, 5, 5, TFT_WHITE);
        }
        else {
//          lcd.drawPixel((c*8)+x+1, y+1, TFT_BLACK);
          lcd.fillRect((c*8*5)+(x*5)+1, (y*5)+1, 5, 5, TFT_BLACK);
        }
      }
    }
    lcd.endWrite();
  }
  
  if (msgx == 0) {
    msgx = 1;
  } else {
    msgx = 0;
  }
}

void chr_make(void)
{
  lcd.clear();

  for (uint32_t i = 0; i < 3; ++i) {
    sp1[i].setColorDepth(16);
    sp1[i].createSprite(10, 10);
    sp1[i].setPivot(5, 5);
    for (uint32_t x = 0; x < 8; ++x) {
      for (uint32_t y = 0; y < 8; ++y) {
        if (chr1_data[i][y][x] == 1) {
          sp1[i].drawPixel(x+1, y+1, TFT_YELLOW);
        }
        else {
          sp1[i].drawPixel(x+1, y+1, TFT_BLACK);
        }
      }
    }
  }
  sp1[3] = sp1[1];

  for (uint32_t i = 0; i < 3; ++i) {
    sp2[i].setColorDepth(16);
    sp2[i].createSprite(10, 10);
    sp2[i].setPivot(5, 5);
    for (uint32_t x = 0; x < 8; ++x) {
      for (uint32_t y = 0; y < 8; ++y) {
        if (chr2_data[i][y][x] == 1) {
          sp2[i].drawPixel(x+1, y+1, TFT_ORANGE);
        }
        else {
          sp2[i].drawPixel(x+1, y+1, TFT_BLACK);
        }
      }
    }
  }
  sp2[3] = sp2[1];

  for (uint32_t i = 0; i < 3; ++i) {
    sp3[i].setColorDepth(16);
    sp3[i].createSprite(10, 10);
    sp3[i].setPivot(5, 5);
    for (uint32_t x = 0; x < 8; ++x) {
      for (uint32_t y = 0; y < 8; ++y) {
        if (chr3_data[i][y][x] == 1) {
          sp3[i].drawPixel(x+1, y+1, TFT_GREEN);
        }
        else {
          sp3[i].drawPixel(x+1, y+1, TFT_BLACK);
        }
      }
    }
  }
  sp3[3] = sp3[1];

}

void chr_disp1(void)
{
  int32_t center_x = lcd.width()/2;
  int32_t center_y = lcd.height()/2;

  lcd.startWrite();
  uint32_t angle = 0;
  for (uint32_t j = 2; j < 6; ++j ) {
    lcd.clear();
    chr_move(1, center_x, center_y, angle, 7-j, 7-j);
    if (j == 5) {
      chr_move(1, center_x, center_y, angle, 7-j, 7-j);
      chr_move(1, center_x, center_y, angle, 7-j, 7-j);
    }
  }
  for (uint32_t j = 2; j < 6; ++j ) {
    lcd.clear();
    chr_move(1, center_x, center_y, angle, j, j);
    if (j == 5) {
      chr_move(1, center_x, center_y, angle, j, j);
      chr_move(1, center_x, center_y, angle, j, j);
    }
  }
  lcd.endWrite();
}

void chr_move(uint32_t s, uint32_t x, uint32_t y, uint32_t a, uint32_t zw, uint32_t zh)
{
  uint32_t d = 100;
  for (uint32_t c = 0; c < 4; ++c) {
    switch(s) {
    case 1:
      sp1[c].pushRotateZoom(x, y, a, zw, zh);
      break;
    case 2:
      sp2[c].pushRotateZoom(x, y, a, zw, zh);
      break;
    case 3:
      sp3[c].pushRotateZoom(x, y, a, zw, zh);
      break;
    }
    delay(d);
  }
}

void loop(void)
{
  int32_t center_x = lcd.width()/2;
  int32_t center_y = lcd.height()/2;

  lcd.startWrite();

  for (int32_t i = 0; i<5; ++i) {
    chr_move(1, center_x, center_y, 0, 5, 5);
  }
  
  lcd.clear();
  data_disp1();
  for (int32_t i = 0; i<5; ++i) {
    chr_move(2, center_x, center_y, 0, 5, 5);
  }
  lcd.clear();

  for (int32_t i = 0; i<5; ++i) {
    chr_move(3, center_x, center_y, 0, 5, 5);
  }
  
  lcd.endWrite();
}
