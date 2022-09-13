#ifndef _TRIANGLE_
#define _TRIANGLE_

#include "Pixel.h"
// #include "mygl.h"


class Triangle {
  private:
     Pixel v1;
     Pixel v2;
     Pixel v3;

  public:
    Triangle(Pixel &v1, Pixel &v2, Pixel &v3);
    void draw();
};


#endif // _TRIANGLE_
