#ifndef _LINE_
#define _LINE_

#include "pixel.h"

class Line {
  private:
    Pixel origin, destiny;
    unsigned char r, g, b, a;

  public:
    Line(Pixel &origin, Pixel &destiny);
    Line(Pixel &origin, Pixel &destiny, unsigned char r, unsigned char g, unsigned char b, unsigned char a);
    void draw(void);

  protected:
};

#endif // _LINE_
