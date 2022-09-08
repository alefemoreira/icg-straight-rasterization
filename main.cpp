#include "main.h"
#include <cmath>
#include <iostream>

class Pixel {
  private:
     int x;
     int y;
     int offset;
     unsigned char *r, *g, *b, *a;

  public:
    Pixel(int x, int y) {
      int offset = 4 * x + IMAGE_WIDTH * 4 * y;
      this->x = x;
      this->y = y;
      this->offset = offset;
      FBptr[offset + 0] = 255; //r
      FBptr[offset + 1] = 255; //g
      FBptr[offset + 2] = 255; //b
      FBptr[offset + 3] = 255; //a
    }

    int getX() { return this->x; }
    int getY() { return this->y; }
};

void DesenhaPixels(void) {
  // Escreve um pixel vermelho na posicao (0,0) da tela:
  FBptr[0] = 255; // componente R
  FBptr[1] = 0; // componente G
  FBptr[2] = 0; // componente B
  FBptr[3] = 255; // componente A
  // Escreve um pixel verde na posicao (1,0) da tela:
  FBptr[4] = 0; // componente R
  FBptr[5] = 255; // componente G
  FBptr[6] = 0; // componente B
  FBptr[7] = 255; // componente A
  // Escreve um pixel azul na posicao (2,0) da tela:
  FBptr[8] = 0; // componente R
  FBptr[9] = 0; // componente G
  FBptr[10] = 255; // componente B
  FBptr[11] = 255; // componente A
}

void DesenhaLinha(void) {
  for (unsigned int i=0; i<250; ++i) {
    new Pixel(i, i);
  }
}

void drawLine(Pixel &origin, Pixel &destiny) {
  
  float deltay = (destiny.getY() - origin.getY());
  float deltax = (destiny.getX() - origin.getX());
  float m =  deltay / deltax;
  float d = origin.getY() - m * origin.getX();
  std::cout << m << '\n';
  int x = origin.getX();
  int y = round(origin.getX() * m + d);
  float e = m * x + d - y;

  if (deltax == 0) {
    for (int i = origin.getY(); i < destiny.getY(); i++) {
      new Pixel(origin.getX(), i);
    }
  } else if (deltay == 0) {
    for (int i = origin.getX(); i < destiny.getX(); i++) {
      new Pixel(i, origin.getY());
    }
  } else if (m > 0 && m < 1) {
    while (x <= destiny.getX()) {
      new Pixel(x, y);
      x++;
      e += m;
      if (e >= 0.5) {
        y++;
        e--;
      }
    }
  } else {
    d = origin.getX() - m * origin.getY();
    m = deltax / deltay;
    x = round(origin.getY() * m + d);
    y = origin.getY();
    e = m * y + d - x;

    while (y <= destiny.getY()) {
      new Pixel(x, y);
      y++;
      e += m;
      if (e >= 0.5) {
        x++;
        e--;
      }
    }
  }


}
//-----------------------------------------------------------------------------
void MyGlDraw(void)
{
  //*************************************************************************
  // Pixel pixel0 = new Pixel(0,0);
  // Pixel pixel1 = new Pixel(0,1);
  // Pixel pixel2 = new Pixel(0,2);
  Pixel origin {0, 0};
  Pixel destiny {50, 40};
  drawLine(origin, destiny);

  Pixel origin1 {0, 0};
  Pixel destiny1 {50, 60};
  drawLine(origin1, destiny1);

  Pixel origin2 {0, 0};
  Pixel destiny2 {50, 50};
  drawLine(origin2, destiny2);
  
  Pixel origin3 {0, 0};
  Pixel destiny3 {50, 0};
  drawLine(origin3, destiny3);

  Pixel origin4 {0, 0};
  Pixel destiny4 {0, 50};
  drawLine(origin4, destiny4);
  //*************************************************************************

}

//-----------------------------------------------------------------------------
int main(int argc, char **argv)
{
  // Inicializações.
  InitOpenGL(&argc, argv);
  InitCallBacks();
  InitDataStructures();

  // Ajusta a função que chama as funções do mygl.h
  DrawFunc = MyGlDraw;  

  // Framebuffer scan loop.
  glutMainLoop();

  return 0;
}

