#include "mygl.h"
// #include "pixel.h"
#include "pixel.cpp"
// #include "triangle.h"
#include "triangle.cpp"
#include "line.cpp"
#include <cmath>
#include <iostream>
using namespace std;

void drawLine(Pixel &start, Pixel &end, unsigned char r, unsigned char g, unsigned char b, unsigned char a) {
  Line line (start, end, r, g, b, a);
  line.draw();
}

void putPixel(int x, int y, unsigned char r, unsigned char g, unsigned char b, unsigned char a) {
  new Pixel(x, y, r, g, b, a);
}

void drawTriangle(Pixel &v1, Pixel &v2, Pixel &v3, unsigned char r, unsigned char g, unsigned char b, unsigned char a) {
  Triangle triangle (v1, v2, v3, r, g, b, a);
  triangle.draw();
}

void MyGlDraw(void) {
  Pixel origin (0, 0);
  Pixel destiny (511, 511);
  drawLine(origin, destiny, 50, 50, 50, 255);

  origin = Pixel(0, 511);
  destiny = Pixel(511, 0);
  drawLine(origin, destiny, 50, 50, 50, 255);

  origin = Pixel(0, 256);
  destiny = Pixel(511, 256);
  drawLine(origin, destiny, 50, 50, 50, 255);

  origin = Pixel(256, 0);
  destiny = Pixel(256, 511);
  drawLine(origin, destiny, 50, 50, 50, 255);

  origin = Pixel(0, 128);
  destiny = Pixel(256, 256);
  drawLine(origin, destiny, 0, 255, 255, 255);

  origin = Pixel(128, 0);
  destiny = Pixel(256, 256);
  drawLine(origin, destiny, 255, 0, 255, 255);

  origin = Pixel(512, 128);
  destiny = Pixel(256, 256);
  drawLine(origin, destiny, 255, 0, 0, 255);

  origin = Pixel(384, 0);
  destiny = Pixel(256, 256);
  drawLine(origin, destiny, 0, 255, 0, 255);

  origin = Pixel(0, 384);
  destiny = Pixel(256, 256);
  drawLine(origin, destiny, 255, 255, 0, 255);

  origin = Pixel(128, 512);
  destiny = Pixel(256, 256);
  drawLine(origin, destiny, 255, 255, 128, 255);

  origin = Pixel(512, 384);
  destiny = Pixel(256, 256);
  drawLine(origin, destiny, 0, 0, 255, 255);

  origin = Pixel(384, 512);
  destiny = Pixel(256, 256);
  drawLine(origin, destiny, 0, 0, 128, 255);

  Pixel v1 (256 - 80, 256 + 30);
  Pixel v2 (200 - 80, 200 + 30);
  Pixel v3 (100 - 80, 300 + 30);
  drawTriangle(v1, v2, v3, 226, 67, 41, 255);
}

