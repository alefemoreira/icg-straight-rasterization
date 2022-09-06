#include "main.h"

 class Pixel {
  private:
     int x;
     int y;
     unsigned char *r, *g, *b, *a;

  public:
    Pixel(int x, int y) {
      int offset = 4 * x + IMAGE_WIDTH * 4 * y;
      this->x = x;
      this->y = y;
      this->r = &FBptr[offset + 0];
      this->g = &FBptr[offset + 1];
      this->b = &FBptr[offset + 2];
      this->a = &FBptr[offset + 3];
      this->*r = 255;
      this->*g = 0;
      this->*b = 255;
      this->*a = 255;
    }

    setColor(unsigned char r, unsigned char g, unsigned char b, unsigned char a) {
      this->*r = r;
      this->*g = g;
      this->*b = b;
      this->*a = a;
    }

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
//-----------------------------------------------------------------------------
void MyGlDraw(void)
{
  //*************************************************************************
  DesenhaLinha();
  DesenhaPixels();
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

