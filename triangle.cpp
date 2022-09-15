#include "triangle.h"
#include "pixel.h"
#include "line.h"
// #include "mygl.h"

Triangle::Triangle(Pixel &v1, Pixel &v2, Pixel &v3) {
  this->v1 = v1;
  this->v2 = v2;
  this->v3 = v3;
}
Triangle::Triangle(Pixel &v1, Pixel &v2, Pixel &v3, unsigned char r, unsigned char g, unsigned char b, unsigned char a) {
  this->v1 = v1;
  this->v2 = v2;
  this->v3 = v3;

  this->r = r;
  this->g = g;
  this->b = b;
  this->a = a;
}

void Triangle::draw() {
  Line line1 (this->v1, this->v2, this->r, this->g, this->b, this->a);
  Line line2 (this->v1, this->v3, this->r, this->g, this->b, this->a);
  Line line3 (this->v2, this->v3, this->r, this->g, this->b, this->a);
  line1.draw();
  line2.draw();
  line3.draw();
}
