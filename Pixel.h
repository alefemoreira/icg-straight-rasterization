#ifndef _PIXEL_
#define _PIXEL_

// #include "definitions.h"

class Pixel {
  private:
     int x;
     int y;
     int offset;
     unsigned char *r, *g, *b, *a;

  public:
    Pixel();
    Pixel(int x, int y);

    int getX();
    int getY();
};

#endif // _PIXEL_