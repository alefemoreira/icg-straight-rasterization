#include "line.h"
#include <cmath>

Line::Line(Pixel &origin, Pixel &destiny) {
  int deltax = destiny.getX() - origin.getX();
  int deltay = destiny.getY() - origin.getY();
  if (deltax < 0 && deltay < 0 || deltax < 0 && deltay >= 0) {
    this->destiny = origin;
    this->origin = destiny;
  } else {
    this->destiny = destiny;
    this->origin = origin;
  }
}

void Line::draw() {
  float deltay = (this->destiny.getY() - this->origin.getY());
  float deltax = (this->destiny.getX() - this->origin.getX());

  float m =  deltay / deltax; // Coeficiente angular
  float d = this->origin.getY() - m * this->origin.getX(); // Coeficiente linear

  // std::cout << m << '\n';

  // Coordenadas x e y iniciais do pixel
  int x = this->origin.getX();
  int y = round(this->origin.getX() * m + d); // y0 = x0.m + d
  float e = m * x + d - y; // Erro
  // std::cout << deltay << '\n';
  
  if (deltax == 0) {// Reta horientada na vertical
    for (int i = this->origin.getY(); i < this->destiny.getY(); i++) {
      new Pixel(this->origin.getX(), i);
    // std::cout << this->origin.getX() << " " << i << '\n';
    }
  } else if (deltay == 0) {// Reta orientada na horizontal
    for (int i = this->origin.getX(); i < this->destiny.getX(); i++) {
      new Pixel(i, this->origin.getY());
    }
  } else if (m > 0 && m < 1) {
    while (x <= this->destiny.getX()) {
      new Pixel(x, y);
      x++;
      e += m;
      if (e >= 0.5) {
        y++;
        e--;
      }
    }
  } else if(m >= 1) {
    d = this->origin.getX() - m * this->origin.getY();
    m = deltax / deltay;
    x = round(this->origin.getY() * m + d);
    y = this->origin.getY();
    e = m * y + d - x; // mudança no calculo do erro(inversão entre x e y)

    while (y <= this->destiny.getY()) {
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
    x = this->origin.getX();
    y = round(x * m + d);
    e = (m * x + d - y );// mudança no calculo do erro(inversão do sinal de y)
    // std::cout << e << '\n';


    while (x <= this->destiny.getX() && y >= this->destiny.getY()) {
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

   d = this->origin.getX() - m * this->origin.getY();
    x = round(this->origin.getY() * m + d);
    y = this->origin.getY();
    e = m * y + d - x; // mudança no calculo do erro(inversão entre x e y)

    while (y >= this->destiny.getY()) {
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