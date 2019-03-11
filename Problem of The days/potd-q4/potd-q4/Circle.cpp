#include "Circle.h"

double Circle::getArea() {
  return 3.14 * r * r;
}

void Circle::setRadius(double val) {
  r = val;
}
