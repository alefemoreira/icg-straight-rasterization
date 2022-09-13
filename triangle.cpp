#include "triangle.h"
#include "pixel.h"
#include "mygl.h"

Triangle::Triangle(Pixel &v1, Pixel &v2, Pixel &v3) {
    this->v1 = v1;
    this->v2 = v2;
    this->v3 = v3;
}

void Triangle::draw() {
    drawLine(v1, v2);
    drawLine(v1, v3);
    drawLine(v2, v3);
}
