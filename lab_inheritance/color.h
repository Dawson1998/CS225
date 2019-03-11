/**
 * @file color.h
 * Provides a variety of colors for convenience.
 */

#pragma once

#include "cs225/PNG.h"

namespace color
{
    /* Format in initialization is hue, saturation, luminance, alpha */
    const cs225::HSLAPixel WHITE(0, 0, 1);
    const cs225::HSLAPixel BLACK(0, 0, 0);
    const cs225::HSLAPixel GRAY(33, 4.1/100.0, 56.7/100.0);
    const cs225::HSLAPixel RED(0, 1, 0.5);
    const cs225::HSLAPixel ORANGE(30, 1, 0.5);
    const cs225::HSLAPixel YELLOW(60, 1, 0.5);
    const cs225::HSLAPixel GREEN(120, 1, 0.5);
    const cs225::HSLAPixel TURQUOISE(120, 1, 0.5);
    const cs225::HSLAPixel BLUE(240, 1, 0.5);
    const cs225::HSLAPixel PURPLE(270, 1, 0.5);
    const cs225::HSLAPixel PINK(299, 96.9/100.0, 74.3/100.0);

} // namespace color

