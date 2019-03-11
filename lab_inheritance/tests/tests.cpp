/**
 * @file: tests.cpp
 * Contains tests for lab functionality.
 */

#include "../cs225/catch/catch.hpp"

#include "../cs225/PNG.h"
#include "../cs225/HSLAPixel.h"

#include "../drawable.h"
#include "../color.h"
#include "../vector2.h"
#include "../shape.h"
#include "../circle.h"
#include "../triangle.h"
#include "../rectangle.h"
#include "../truck.h"
#include "../flower.h"

#include <unistd.h>

using cs225::PNG;
using cs225::HSLAPixel;

/**
 * Helper function to ompare two PNGs, reporting the (x, y) of the first
 * offending pixel
 * 
 * @param test the PNG to compare to the solution
 * @param sol the solution PNG
 */
void compare_and_report(const cs225::PNG & test, const cs225::PNG & sol)
{
    if(test.width() != sol.width() || test.height() != sol.height())
    {
        std::stringstream s;
        s << "Sizes differ! Sol: (" << sol.width() << ", " << sol.height() << ") != Actual: (" ;
        s <<  test.width() << ", " << test.height() << ")";
        FAIL(s.str());
    }

    for(size_t y = 0, n = test.height(); y < n; y++)
    {
        for(size_t x = 0, m = test.width(); x < m; x++)
        {
            if(test.getPixel(x, y) != sol.getPixel(x, y))
            {
                std::stringstream s;
                s << "Pixels differ at (" << x << ", " << y << ")!" << std::endl;
                s << "Sol: " << sol.getPixel(x, y) << ";  actual: " << test.getPixel(x, y) << std::endl;

                FAIL(s.str());
            }
        }
    }

    // If we get here, we're good
    SUCCEED("PNG matches the solution");
}

TEST_CASE("test_virtual_perim", "[weight=10]")
{
    Vector2 rectangle_center(4,5);
    Rectangle * rectangle = new Rectangle(rectangle_center, color::BLUE, 32, 32);

    Shape * shape = rectangle;

    int rect_perim = rectangle->perimeter();
    int shape_perim = shape->perimeter();

    delete rectangle;

    REQUIRE(rect_perim == shape_perim);
}

TEST_CASE("test_virtual_area", "[weight=10]")
{
    Vector2 rectangle_center(4,5);
    Rectangle * rectangle = new Rectangle(rectangle_center, color::GREEN, 47, 47);

    Shape * shape = rectangle;

    int rect_area = rectangle->area();
    int shape_area = shape->area();

    delete rectangle;

    REQUIRE(rect_area == shape_area);
}

TEST_CASE("test_destructor", "[weight=20][valgrind]") {
    Shape * triangle = new Triangle(color::ORANGE, Vector2(8,7), Vector2(5,5), Vector2(9,9));
    delete triangle;

    SUCCEED();
}

TEST_CASE("test_constructor", "[weight=20]")
{
    Circle circle(Vector2(26,26), color::ORANGE, 3);

    REQUIRE(circle.color().h == color::ORANGE.h);
    REQUIRE(circle.color().s == color::ORANGE.s);
    REQUIRE(circle.color().l == color::ORANGE.l);
}

TEST_CASE("test_pure_virtual", "[weight=10][valgrind]")
{
    PNG canvas;
    canvas.resize(128, 128);

    PNG soln;

    Drawable * truck = new Truck(Vector2(64, 64));
    truck->draw(&canvas);

    soln.readFromFile("tests/soln_truck.png");

    delete truck;

    compare_and_report(canvas, soln);
}

TEST_CASE("test_slicing", "[weight=20][valgrind]")
{
    PNG canvas;
    canvas.resize(128,128);

    PNG soln;
    PNG soln_old;
    soln.readFromFile("tests/soln_flower.png");

    Drawable * flower = new Flower(Vector2(64,64));

    flower->draw(&canvas);

    delete flower;

    compare_and_report(canvas, soln);
}
