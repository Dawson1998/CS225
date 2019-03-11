/**
 * @file test_destructor.cpp
 * A simple application that demonstrates a problem with the Triangle destructor.
 */

#include <iostream>

#include "cs225/PNG.h"
#include "color.h"
#include "shape.h"
#include "triangle.h"
#include "vector2.h"

using cs225::PNG;
using cs225::HSLAPixel;

int main()
{
    const int canvas_width = 128;
    const int canvas_height = 128;

    PNG canvas;
    canvas.resize(canvas_width, canvas_height);

    const HSLAPixel triangle_color = color::ORANGE;
    Shape* triangle = new Triangle(triangle_color, Vector2(32, 32),
                                   Vector2(64, 64), Vector2(32, 64));

    triangle->draw(&canvas);

    canvas.writeToFile("test_destructor.png");

    /* TODO: Why is this leaking memory?  Triangle does have a valid
     * destructor!?
     * Can you stop it from leaking WITHOUT changing triangle's type from a
     * Shape pointer to a Triangle pointer type? */
    delete triangle;
    triangle = NULL;

    return 0;
}
