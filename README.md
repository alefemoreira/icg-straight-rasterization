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

Para o pixel foi criada uma classe chamada Pixel, assim que o objeto do tipo Pixel é instânciado ele é desenhado na tela

### Pixel.cpp
```C++
#include "Pixel.h"
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

int Pixel::getX() { return this->x; }
int Pixel::getY() { return this->y; }
```
## 3 -  Reta

## 4 -   Triangulo
