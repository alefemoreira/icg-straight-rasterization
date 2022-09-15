#ifndef _TRIANGLE_
#define _TRIANGLE_

#include "pixel.h"

class Triangle {
  private:
    Pixel v1, v2, v3;
    unsigned char r, g, b, a;

  public:
    Triangle(Pixel &v1, Pixel &v2, Pixel &v3);
    Triangle(Pixel &v1, Pixel &v2, Pixel &v3, unsigned char r, unsigned char g, unsigned char b, unsigned char a);
    void draw();
};


#endif // _TRIANGLE_
