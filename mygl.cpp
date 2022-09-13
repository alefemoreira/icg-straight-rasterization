#include "mygl.h"
// #include "pixel.h"
#include "pixel.cpp"
// #include "triangle.h"
#include "triangle.cpp"
// #include "pipx.cpp"
#include <cmath>

void drawLine(Pixel &start, Pixel &end) {

  Pixel origin = start;
  Pixel destiny = end;
  
  // Calculando delta x e delta y
  float deltay = (destiny.getY() - origin.getY());
  float deltax = (destiny.getX() - origin.getX());

  if ((deltax < 0 && deltay < 0) || (deltax < 0 && deltay >= 0)) {
    origin = end;
    destiny = start;

    deltay = (destiny.getY() - origin.getY());
    deltax = (destiny.getX() - origin.getX());
  }

  float m =  deltay / deltax; // Coeficiente angular
  float d = origin.getY() - m * origin.getX(); // Coeficiente linear

  // std::cout << m << '\n';

  // Coordenadas x e y do pixel
  int x = origin.getX();
  int y = round(origin.getX() * m + d); // y0 = x0.m + d
  float e = m * x + d - y; // Erro
  // std::cout << deltay << '\n';
  
  if (deltax == 0) {// Reta horientada na vertical
    for (int i = origin.getY(); i < destiny.getY(); i++) {
      new Pixel(origin.getX(), i);
    // std::cout << origin.getX() << " " << i << '\n';
    }
  } else if (deltay == 0) {// Reta orientada na horizontal
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
  } else if(m >= 1) {
    d = origin.getX() - m * origin.getY();
    m = deltax / deltay;
    x = round(origin.getY() * m + d);
    y = origin.getY();
    e = m * y + d - x; // mudança no calculo do erro(inversão entre x e y)

    while (y <= destiny.getY()) {
      new Pixel(x, y);
      y++;
      e += m;
      if (e >= 0.5) {
        x++;
        e--;
      }
    }
  }  else if(m < 0 && m > -1) {
    // std::cout << m << '\n';
    x = origin.getX();
    y = round(x * m + d);
    e = (m * x + d - y );// mudança no calculo do erro(inversão do sinal de y)
    // std::cout << e << '\n';


    while (x <= destiny.getX() && y >= destiny.getY()) {
      new Pixel(x, y);
      x++;
      e -= m;
      if (e >= 0.5) {
        y--;
        e--;
      }
    }
  } else { // m <= 1
    m = deltax / deltay;

   d = origin.getX() - m * origin.getY();
    x = round(origin.getY() * m + d);
    y = origin.getY();
    e = m * y + d - x; // mudança no calculo do erro(inversão entre x e y)

    while (y >= destiny.getY()) {
      new Pixel(x, y);
      y--;
      e -= m;
      if (e >= 0.5) {
        x++;
        e--;
      }
    }
  }
}

void MyGlDraw(void)
{
  //*************************************************************************
  // Pixel pixel0 = new Pixel(0,0);
  // Pixel pixel1 = new Pixel(0,1);
  // Pixel pixel2 = new Pixel(0,2);

  Pixel origin {0, 0};
  Pixel destiny {0, 200};
  drawLine(origin, destiny);

  Pixel origin1 {0, 0};
  Pixel destiny1 {200, 0};
  drawLine(origin1, destiny1);

  Pixel origin2 {0, 0};
  Pixel destiny2 {200, 200};
  drawLine(origin2, destiny2);

  Pixel origin3 {0, 0};
  Pixel destiny3 {100, 200};
  drawLine(origin3, destiny3);

  Pixel origin4 {0, 0};
  Pixel destiny4 {50, 200};
  drawLine(origin4, destiny4);

  Pixel origin5 {0, 0};
  Pixel destiny5 {200, 100};
  drawLine(origin5, destiny5);

  Pixel origin6 {0, 0};
  Pixel destiny6 {200, 50};
  drawLine(origin6, destiny6);

  // //***************************************************

  Pixel origin7 {0, 511};
  Pixel destiny7 {200, 511};
  drawLine(origin7, destiny7);

  Pixel origin8 {0, 311};
  Pixel destiny8 {0, 511};
  drawLine(origin8, destiny8);

  Pixel origin9 {0, 511};
  Pixel destiny9 {200, 350};
  drawLine(origin9, destiny9);

  Pixel origin10 {0, 511};
  Pixel destiny10 {300, 450};
  drawLine(origin10, destiny10);

  Pixel origin11 {0, 511};
  Pixel destiny11 {300, 400};
  drawLine(origin11, destiny11);

  Pixel origin12 {0, 511};
  Pixel destiny12 {100, 400};
  drawLine(origin12, destiny12);

  Pixel origin13 {0, 511};
  Pixel destiny13 {100, 300};
  drawLine(origin13, destiny13);


  Pixel origin14 {0, 511};
  Pixel destiny14 {50, 350};
  drawLine(origin14, destiny14);

  Pixel origin15 {0, 511};
  Pixel destiny15 {50, 250};
  drawLine(origin15, destiny15);

  Pixel origin16 {512, 0};
  Pixel destiny16 {512 - 40, 80};
  drawLine(origin16, destiny16);

  Pixel origin17 {512/2+5, 512/2-10};
  Pixel destiny17 {512/2 + 20, 512/2-80};
  drawLine(origin17, destiny17);

  Triangle triangle {origin17, destiny17, destiny9};
  triangle.draw();


  //*************************************************************************

}

