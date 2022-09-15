#ifndef _MYGL_H_
#define _MYGL_H_

#include "pixel.h"
#include "definitions.h"

//-----------------------------------------------------------------------------
void MyGlDraw(void);

//*****************************************************************************
void putPixel(int x, int y, unsigned char r, unsigned char g, unsigned char b, unsigned char a);
void drawLine(Pixel &start, Pixel &end, unsigned char r, unsigned char g, unsigned char b, unsigned char a);
void drawTriange(Pixel &v1, Pixel &v2, Pixel &v3, unsigned char r, unsigned char g, unsigned char b, unsigned char a);
//*****************************************************************************


#endif // _MYGL_H_