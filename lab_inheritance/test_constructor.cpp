/**
 * @file test_constructor.cpp
 * A simple application that demonstrates a problem with the Circle constructor.
 */

#include <iostream>

#include "cs225/PNG.h"
#include "color.h"
#include "shape.h"
#include "circle.h"
#include "vector2.h"

using cs225::PNG;
using cs225::HSLAPixel;

int main()
{
    const int canvas_width = 128;
    const int canvas_height = 128;

    PNG canvas;
    canvas.resize(canvas_width, canvas_height);

    const HSLAPixel circle_color = color::ORANGE;
    const Vector2 circle_center(32, 32);
    const int circle_radius = 16;
    Circle* circle = new Circle(circle_center, circle_color, circle_radius);

    circle->draw(&canvas);

    canvas.writeToFile("test_constructor.png");

    /* TODO: For some reason the circle is NOT constructed with the proper color
     * and center position.
     * Can you make it so the circle is constructed with the proper color and
     * center position WITH OUT using set_center() or set_color()? */
    const bool correct_color = (circle->color() == circle_color);

    if (correct_color) {
        std::cout << "Circle's color is correct!" << std::endl;
    } else {
        std::cout << "Circle's color is NOT correct!" << std::endl;
    }

    const bool correct_center = circle->center() == circle_center;
    if (correct_center) {
        std::cout << "Circle's center is correct!" << std::endl;
    } else {
        std::cout << "Circle's center is NOT correct!" << std::endl;
    }

    delete circle;
    circle = NULL;

    return 0;
}
