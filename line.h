#ifndef _LINE_
#define _LINE_

#include "pixel.h"

class Line {
  private:
    Pixel origin, destiny;

  public:
    Line(Pixel &origin, Pixel &destiny);
    void draw(void);

  protected:
};

#endif // _LINE_
