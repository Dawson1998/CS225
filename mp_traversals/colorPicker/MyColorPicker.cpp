#include "../cs225/HSLAPixel.h"
#include "../Point.h"
#include "../cs225/PNG.h"
#include "ColorPicker.h"
#include "MyColorPicker.h"
#include "GridColorPicker.h"
#include <math.h>

using namespace cs225;

/**
 * Picks the color for pixel (x, y).
 * Using your own algorithm
 */
 MyColorPicker::MyColorPicker(
   HSLAPixel gridColor, PNG back, unsigned spacing
 ) : gridColor(gridColor), backgroundColor(back), spacing(spacing) { }
HSLAPixel MyColorPicker::getColor(unsigned x, unsigned y) {
  /* @todo [Part 3] */
  if (x + y == spacing) {
      return gridColor;
  }
  double hue = 0;
  HSLAPixel pixel(hue, 1, 0.5);
  hue += spacing;
  if (hue >= 360) { hue -= 360; }
  return pixel;

  // `pixel` is a pointer to the memory stored inside of the PNG `image`,
  // which means you're changing the image directly.  No need to `set`
  // the pixel since you're directly changing the memory of the image.
  //pixel.s = 0.5;
  return backgroundColor.getPixel(x,y);
}
