#include "mygl.h"
// #include "pixel.h"
#include "pixel.cpp"
// #include "triangle.h"
#include "triangle.cpp"
#include "line.cpp"
#include <cmath>
#include <iostream>
using namespace std;

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

void MyGlDraw(void) {
  //*************************************************************************

  Pixel origin (0, 0);
  Pixel destiny (0, 200);
  Line line(origin, destiny);
  line.draw();

  Pixel origin1 (0, 0);
  Pixel destiny1 (200, 0);
  line = Line(origin1, destiny1);
  line.draw();

  Pixel origin2 (0, 0);
  Pixel destiny2 (200, 200);
  line = Line(origin2, destiny2);
  line.draw();

  Pixel origin3 (0, 0);
  Pixel destiny3 (100, 200);
  line = Line(origin3, destiny3);
  line.draw();

  Pixel origin4 (0, 0);
  Pixel destiny4 (50, 200);
  line = Line(origin4, destiny4);
  line.draw();

  Pixel origin5 (0, 0);
  Pixel destiny5 (200, 100);
  line = Line(origin5, destiny5);
  line.draw();

  Pixel origin6 (0, 0);
  Pixel destiny6 (200, 50);
  line = Line(origin6, destiny6);
  line.draw();

  // //***************************************************

  Pixel origin7 (0, 511);
  Pixel destiny7 (200, 511);
  line = Line(origin7, destiny7);
  line.draw();

  Pixel origin8 (0, 311);
  Pixel destiny8 (0, 511);
  line = Line(origin8, destiny8);
  line.draw();

  Pixel origin9 (0, 511);
  Pixel destiny9 (200, 350);
  line = Line(origin9, destiny9);
  line.draw();

  Pixel origin10 (0, 511);
  Pixel destiny10 (300, 450);
  line = Line(origin10, destiny10);
  line.draw();

  Pixel origin11 (0, 511);
  Pixel destiny11 (300, 400);
  line = Line(origin11, destiny11);
  line.draw();

  Pixel origin12 (0, 511);
  Pixel destiny12 (100, 400);
  line = Line(origin12, destiny12);
  line.draw();

  Pixel origin13 (0, 511);
  Pixel destiny13 (100, 300);
  line = Line(origin13, destiny13);
  line.draw();


  Pixel origin14 (0, 511);
  Pixel destiny14 (50, 350);
  line = Line(origin14, destiny14);
  line.draw();

  Pixel origin15 (0, 511);
  Pixel destiny15 (50, 250);
  line = Line(origin15, destiny15, 255, 255, 255, 255);
  line.draw();

  Pixel origin16 (511, 0);
  Pixel destiny16 (511 - 40, 80);
  line = Line(origin16, destiny16, 0, 0, 255, 255);
  line.draw();

  Pixel origin18 (511, 0);
  Pixel destiny18 (511 - 80, 40);
  line = Line(origin18, destiny18, 0, 0, 255, 255);
  line.draw();

  Pixel origin17 (511/2+5, 511/2-10);
  Pixel destiny17 (511/2 + 20, 511/2-80);
  line = Line(origin17, destiny17, 0, 255, 0, 255);
  line.draw();

  Pixel origin20 (511, 511, 255, 255, 0, 255);
  Pixel destiny20 (511 - 20, 511 - 80, 255, 255, 0, 255);
  float m =  (destiny20.getX() - origin20.getX());
  line = Line (origin20, destiny20, 100, 255, 100, 255);
  line.draw();

  Pixel v1 (356, 356);
  Pixel v2 (306, 206);
  Pixel v3 (256, 256);
  Triangle triangle (v1, v2, v3, 255, 0, 0, 255);
  triangle.draw();


  //*************************************************************************

}

