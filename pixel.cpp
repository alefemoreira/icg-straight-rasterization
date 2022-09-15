#include "pixel.h"
#include "definitions.h"


Pixel::Pixel(){}
Pixel::Pixel(int x, int y) {
  int offset = 4 * x + IMAGE_WIDTH * 4 * y;
  this->x = x;
  this->y = y;
  this->offset = offset;
  FBptr[offset + 0] = 255; //r
  FBptr[offset + 1] = 255; //g
  FBptr[offset + 2] = 255; //b
  FBptr[offset + 3] = 255; //a
}

Pixel::Pixel(int x, int y, unsigned char r, unsigned char g, unsigned char b, unsigned char a) {
  int offset = 4 * x + IMAGE_WIDTH * 4 * y;
  this->x = x;
  this->y = y;
  this->offset = offset;
  this->r = r;
  this->g = g;
  this->b = b;
  this->a = a;
  FBptr[offset + 0] = r;
  FBptr[offset + 1] = g;
  FBptr[offset + 2] = b;
  FBptr[offset + 3] = a;
}

int Pixel::getX() { return this->x; }
int Pixel::getY() { return this->y; }

