#include <iostream>
#include "LUVAPixel.h"

namespace cs225 {
  std::ostream & operator<<(std::ostream & out, LUVAPixel const & pixel) {
    out << "(" << pixel.x << ", " << pixel.y << ", " << pixel.z << (pixel.a != 1 ? ", " + std::to_string(pixel.a) : "") << ")";

    return out;
  }
}