/**
 * @file test_virtual.cpp
 * A simple application that demonstrates a problem with Shape virtual methods.
 */

#include <iostream>

#include "color.h"
#include "rectangle.h"
#include "vector2.h"

using cs225::PNG;

int main()
{
    const int canvas_width = 128;
    const int canvas_height = 128;

    PNG canvas;
    canvas.resize(canvas_width, canvas_height);

    Vector2 rectangle_center(canvas_width / 2, canvas_height / 2);
    const int rectangle_width = canvas_width / 4;
    const int rectangle_height = canvas_height / 4;
    Rectangle* rectangle = new Rectangle(rectangle_center, color::BLUE,
                                         rectangle_width, rectangle_height);

    rectangle->draw(&canvas);

    const int rectangle_perimeter = rectangle->perimeter();
    std::cout << "Rectangle's Perimeter = " << rectangle_perimeter << std::endl;
    const int rectangle_area = rectangle->area();
    std::cout << "Rectangle's Area = " << rectangle_area << std::endl;

    /* But we can treat a Rectangle just like a Shape using a Shape pointer */
    Shape* shape = rectangle;
    const int shape_perimeter = shape->perimeter();
    std::cout << "Shape's Perimeter = " << shape_perimeter << std::endl;
    const int shape_area = shape->area();
    std::cout << "Shape' Area = " << shape_area << std::endl;

    /* TODO: For some reason the shape's area and perimeter is different from
     * rectangle's area and perimeter even though they are pointing to the same
     * object!  Can you this this so they are the same WITHOUT changing the
     * shape's type from a Shape pointer to a Rectangle pointer? */
    if (rectangle_perimeter == shape_perimeter) {
        std::cout << "The Perimeters are the same!" << std::endl;
    } else {
        std::cout << "The Perimeters are NOT the same." << std::endl;
    }

    if (rectangle_area == shape_area) {
        std::cout << "The Areas are the same!" << std::endl;
    } else {
        std::cout << "The Areas are NOT the same." << std::endl;
    }

    canvas.writeToFile("test_virtual.png");

    delete rectangle;

    return 0;
}
