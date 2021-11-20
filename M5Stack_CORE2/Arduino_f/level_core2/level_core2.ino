#include <M5Core2.h>

float ax = 0.0F;
float ay = 0.0F;
float az = 0.0F;

const int col_top = TFT_BLACK, col_bottom = TFT_YELLOW;

const float hx = 160, hy = 120;
int qx = hx, qy = 0;

const float d = atan2(hy, hx);

template <typename T>
int sgn(T val)
{
  return (T(0) < val) - (val < T(0));
}

void triangle(int x1, int y1, int x2, int y2, int x3, int y3, int color)
{
  M5.Lcd.fillTriangle(hx + x1, hy + y1, hx + x2, hy + y2, hx + x3, hy + y3, color);
}

void setup()
{
  M5.begin();
  M5.IMU.Init();
  M5.Lcd.fillRect(0, hy, 2 * hx, 2 * hy, col_bottom);
}

void loop()
{
  M5.IMU.getAccelData(&ax, &ay, &az);
  float theta = atan2(ax, -ay);

  int px, py;

  if (fabs(hx * tan(-theta)) < hy) {
    px = hx * sgn(cos(-theta));
    py = px * tan(-theta);
  }
  else {
    py = hy * sgn(sin(-theta));
    px = py / tan(-theta);
  }

  int col1, col2;
  if (px * qy - py * qx > 0) {
    col2 = col_bottom;
    col1 = col_top;
  }
  else {
    col2 = col_top;
    col1 = col_bottom;
  }

  triangle(0, 0, qx, qy, px, py, col1);
  triangle(0, 0, -qx, -qy, -px, -py, col2);

  if (qx != px && qy != py) {
    int cx = hx * sgn(qx);
    int cy = hy * sgn(qy);

    triangle(cx, cy, qx, qy, px, py, col1);
    triangle(-cx, -cy, -qx, -qy, -px, -py, col2);
  }

  qx = px;
  qy = py;
}
