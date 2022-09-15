# Rasterização de Retas

Professor: Maelso B. Pacheco
Disciplina: Introdução à Computação Gráfica

Grupo:

- Álefe de Lima Moreira
- José Alisson
- Weverton Vitor

## 1 - Introdução 

O presente trabalho tem como tema a rasterização de retas pelo algoritmo de Bresenham, usado para rasterizar retas com baixo custo computacional, neste trabalho serão implementadas classes e funções para desenhar os seguintes objetos gráficos: ponto, reta e triangulo.

## 2 -  Pixel

Para o pixel foi criada uma classe chamada Pixel. Ao instanciar um objeto do tipo Pixel, um pixel é plotado na tela. O pixel é a unidade mais básica que vamos trabalhar, com ele acessamos o frame buffer para setar as coodenadas e as cores do pixel, a partir dele construiremos retas e  triangulo. No código abaixo é possível perceber que há 2 construtores para a classe, um deles só é necessário as coodenadas e a cor padrão é branca, já no segundo construtor além das coodenadas é preciso informar as cores em rgba(*red*, *green*, *blue*, *alpha*)

### 2.1 - pixel.cpp
```C++
#include "pixel.h"
#include "definitions.h"


Pixel::Pixel(){}
Pixel::Pixel(int x, int y) {
  int offset = 4 * x + IMAGE_WIDTH * 4 * y;
  this->x = x;
  this->y = y;
  this->offset = offset;
  FBptr[offset + 0] = 255; //r
  FBptr[offset + 1] = 255; //g
  FBptr[offset + 2] = 255; //b
  FBptr[offset + 3] = 255; //a
}

Pixel::Pixel(int x, int y, unsigned char r, unsigned char g, unsigned char b, unsigned char a) {
  int offset = 4 * x + IMAGE_WIDTH * 4 * y;
  this->x = x;
  this->y = y;
  this->offset = offset;
  this->r = r;
  this->g = g;
  this->b = b;
  this->a = a;
  FBptr[offset + 0] = r;
  FBptr[offset + 1] = g;
  FBptr[offset + 2] = b;
  FBptr[offset + 3] = a;
}

int Pixel::getX() { return this->x; }
int Pixel::getY() { return this->y; }


```
## 3 -  Reta

## 4 -   Triangulo
A abordagem que utilizamos no triangulo foi renderiza-lo a partir de 3 pixeis, o triangulo só será plotado na tela quando o método draw() for chamado, há um construtor padrão com 3 objetos da classe Pixel e outro com 3 pixeis e as cores em rgba, com 3 instâncias de Pixel é possível formar 3 retas(classe Line), como pode ser observado no método draw()

### 4.1 - triangle.cpp
```C++
#include "triangle.h"
#include "pixel.h"
#include "line.h"

Triangle::Triangle(Pixel &v1, Pixel &v2, Pixel &v3) {
  this->v1 = v1;
  this->v2 = v2;
  this->v3 = v3;
}
Triangle::Triangle(Pixel &v1, Pixel &v2, Pixel &v3, unsigned char r, unsigned char g, unsigned char b, unsigned char a) {
  this->v1 = v1;
  this->v2 = v2;
  this->v3 = v3;

  this->r = r;
  this->g = g;
  this->b = b;
  this->a = a;
}

void Triangle::draw() {
  Line line1 (this->v1, this->v2, this->r, this->g, this->b, this->a);
  Line line2 (this->v1, this->v3, this->r, this->g, this->b, this->a);
  Line line3 (this->v2, this->v3, this->r, this->g, this->b, this->a);
  line1.draw();
  line2.draw();
  line3.draw();
}

```