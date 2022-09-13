#include "main.h"
#include "mygl.h"
#include <cmath>
#include <iostream>
// #include "definitions.h"

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

