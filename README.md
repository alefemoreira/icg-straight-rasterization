# Rasterização de Retas

Professor: Maelso B. Pacheco
Disciplina: Introdução à Computação Gráfica

Grupo:

- Álefe de Lima Moreira
- José Alisson
- Weverton Vitor

## 1 Introdução 

O presente trabalho tem como tema a rasterização de retas pelo algoritmo de Bresenham, usado para rasterizar retas com baixo custo computacional. Neste trabalho serão implementadas classes e funções para desenhar os seguintes objetos gráficos: ponto, reta e triangulo.

## 2 Pixel

Para o pixel foi criada uma classe chamada Pixel. Ao instanciar um objeto do tipo Pixel, um pixel é plotado na tela. O pixel é a unidade mais básica que vamos trabalhar, com ele acessamos o frame buffer para setar as coordenadas e as cores do pixel, a partir dele construiremos retas e o triângulo. No código abaixo é possível perceber que há 2 construtores para a classe, um deles só é necessário as coordenadas e a cor padrão é branca, já no segundo construtor além das coordenadas é preciso informar as cores em rgba(*red*, *green*, *blue*, *alpha*). Com isso, podemos desenhar pontos na tela como é mostrado na imagem abaixo.

![image](https://user-images.githubusercontent.com/72952273/190861954-5fd1de19-fa43-4180-b20a-db2eb31e359b.png)

Figura 1: Pixels desenhados a partir da função pixel

```C++
// pixel.cpp
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

## 3 Reta

O algoritmo procura selecionar as localizações raster ideais que representam uma linha reta. O algoritmo incrementa em uma unidade em x ou y dependendo da inclinação da linha. O incremento na outra variável é zero ou um e é determinado examinando a distância entre a linha real e a localização da grade mais próxima. 

Com a técnica foi possível desenhar em todos o quadrantes. Baseada nas diferenças de deltaX e deltaY, é possivel calcular o coeficiente angular da reta (m) como podemos ver logo abaixo:

![image](https://user-images.githubusercontent.com/72952273/190861671-d8e63a17-6150-455c-ba35-0cad1b5a5040.png)

Figura 2: Demonstração dos quadrantes e inclinação 


Sabemos que o algoritmo de Bresenham encontra as coordenadas inteiras mais próximas da linha real, usando apenas matemática inteira. No entanto, pode haver valores de inclinação (m) para quando: 

### 3.1 `0 < m < 1`
Quando 0 < m < 1 a inclinação da linha é positiva, mas menor que 45 graus, assim o pixel imediatamente acima da linha real é o mais próximo

```C++
// line.cpp
void Line::draw() {
  float deltay = (this->destiny.getY() - this->origin.getY());
  float deltax = (this->destiny.getX() - this->origin.getX());

  float m =  deltay / deltax; // Coeficiente angular
  float d = this->origin.getY() - m * this->origin.getX(); // Coeficiente linear

  // Coordenadas x e y iniciais do pixel
  int x = this->origin.getX();
  int y = round(this->origin.getX() * m + d); // y0 = x0.m + d
  float e = m * x + d - y; // calcula erro
  
  if (deltax == 0) {// Reta horientada na vertical
    for (int i = this->origin.getY(); i < this->destiny.getY(); i++) {
      new Pixel(this->origin.getX(), i, this->r, this->g, this->b, this->a);
    }
  } else if (deltay == 0) {// Reta orientada na horizontal
    for (int i = this->origin.getX(); i < this->destiny.getX(); i++) {
      new Pixel(i, this->origin.getY(), this->r, this->g, this->b, this->a);
    }
  } else if (m > 0 && m < 1) {
    while (x <= this->destiny.getX()) {
      new Pixel(x, y, this->r, this->g, this->b, this->a);
      x++;
      e += m;
      if (e >= 0.5) {
        y++;
        e--;
      }
    }
  } ...
````
### 3.2 `m => 1` 

Quando m > 1 a inclinação é maior ou igual a 45 graus. Nesse caso, ao invés de considerar a linha como uma função no eixo `x`, foi considerada que a linha é uma função no eixo `y`, portanto substituir `y` onde era `x` e vice-versa.

```C++
else if (m >= 1) {
    m = deltax / deltay;
    d = this->origin.getX() - m * this->origin.getY();
    x = round(this->origin.getY() * m + d);
    y = this->origin.getY();
    e = m * y + d - x; // mudança no calculo do erro(inversão entre x e y)

    while (y <= this->destiny.getY()) {
      new Pixel(x, y, this->r, this->g, this->b, this->a);
      y++;
      e += m;
      if (e >= 0.5) {
        x++;
        e--;
      }
    }
  }
```

Observe que o calculo do `m`, ao invés de ser `deltaY / deltaX`, agora é `deltaX / deltaY`. Nos outros cálculos, a relação entre x e y também está invertida em comparação aos cálculos feitos para `0 < m < 1`.

### 3.3 `0 > m > -1`, 

Quando `0 > m > -1`, o pixel mais próximo no raster será o pixel abaixo da linha verdadeira.

```C++
else if(m < 0 && m > -1) {
    x = this->origin.getX();
    y = round(x * m + d);
    e = (m * x + d - y ); // mudança no calculo do erro(inversão do sinal de y)

    while (x <= this->destiny.getX() && y >= this->destiny.getY()) {
      new Pixel(x, y, this->r, this->g, this->b, this->a);
      x++;
      e -= m;
      if (e >= 0.5) {
        y--;
        e--;
      }
    }
  }
```

Observe que para `0 > m > -1` os sinais da operação está invertida em relação aos cálculos de `0 < m < 1`. Isso acontece porque nesse caso `deltaY` é negativo.

### 3.4 `m <= -1`

Para `m <= -1`, as mudanças feitas foram as mesmas feitas em [3.2](#32-m--1), conduto considerando os cálculos de `0 > m > -1`.

```c++
else { // m <= -1
  m = deltax / deltay;

  d = this->origin.getX() - m * this->origin.getY();
  x = round(this->origin.getY() * m + d);
  y = this->origin.getY();
  e = m * y + d - x; // mudança no calculo do erro(inversão entre x e y)

  while (y >= this->destiny.getY()) {
    new Pixel(x, y, this->r, this->g, this->b, this->a);
    y--;
    e -= m;
    if (e >= 0.5) {
      x++;
      e--;
    }
  }
}
```

### 3.5 `m = 0`

Para `m = 0`, foi fixado a componente da reta que não sofria variação, e variado a componente da reta que tinha variação:

```c++
if (deltax == 0) {// Reta horientada na vertical
  for (int i = this->origin.getY(); i < this->destiny.getY(); i++) {
    new Pixel(this->origin.getX(), i, this->r, this->g, this->b, this->a);
  }
} else if (deltay == 0) {// Reta orientada na horizontal
  for (int i = this->origin.getX(); i < this->destiny.getX(); i++) {
    new Pixel(i, this->origin.getY(), this->r, this->g, this->b, this->a);
  }
}
```

## 4 Triangulo

A abordagem que utilizamos no triangulo foi renderiza-lo a partir de 3 pixeis, o triangulo só será plotado na tela quando o método draw() for chamado, há um construtor padrão com 3 objetos da classe Pixel e outro com 3 pixeis e as cores em rgba, com 3 instâncias de Pixel é possível formar 3 retas(classe Line), como pode ser observado no método draw()

```C++
// triangle.cpp
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

![Vertices do triangulo e o triangulo.]()

## 5 Resultados e dificuldades encontradas

A aplicação ocorreu como esperado, sendo capaz de desenhar pixels, linhas e a formúlas geométricas. Nesse caso foi pedido para o que programa pudesse esboçar um triângulo atráves de um conjunto de pixels e retas, e assim foi realizado com êxito.
Compreender o algoritmo de Bresenham e em si foi o primeiro desafio apresentado durante a realização da atividade, seguido de conseguir desenhar em todos o quadrantes.
Utilizando o algoritmo de Bresenham, o programa foi capaz apenas de desenhar linhas básicas. Para desenhar linhas suaves, deve-se utilizar um algoritmo diferente.

## 6 Referências

- https://www.javatpoint.com/computer-graphics-bresenhams-line-algorithm
- https://medium.com/@thiagoluiz.nunes/rasterization-algorithms-computer-graphics-b9c3600a7587
- http://www.univasf.edu.br/~jorge.cavalcanti/comput_graf04_prim_graficas2.pdf



