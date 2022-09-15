#ifndef _PIXEL_
#define _PIXEL_

class Pixel {
  private:
     int x;
     int y;
     int offset;
     unsigned char r, g, b, a;

  public:
    Pixel();
    Pixel(int x, int y);
    Pixel(int x, int y, unsigned char r, unsigned char g, unsigned char b, unsigned char a);

    int getX();
    int getY();
};

#endif // _PIXEL_