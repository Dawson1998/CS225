/**
 * @file circle.cpp
 * Implementation of the Circle class.
 */

#include "circle.h"
#include "line.h"
#include <cassert>
#include <cstdio>
#include <cmath>

using cs225::HSLAPixel;
using cs225::PNG;

const double PI = 3.141592;

Circle::Circle(const Vector2& pcenter, const HSLAPixel& pcolor, int pradius)
    : Shape(pcenter,pcolor), radius_(pradius)
{
    /* Nothing.  See initialization list. */

}

int Circle::area() const
{
    const int tarea = static_cast<int>(PI * radius_ * radius_);
    return tarea;
}

int Circle::perimeter() const
{
    const int tperimeter = static_cast<int>(PI * 2 * radius_);
    return tperimeter;
}

bool Circle::contains(const Vector2& p) const
{
    const double distance = this->center().distanceTo(p);
    return distance <= this->radius_;
}

void Circle::drawPoints(PNG* canvas, int x, int y) const
{
    HSLAPixel* pixel;
    int i;
    int j;
    while (y > 0) {
        i = static_cast<int>(this->center().x() + x);
        j = static_cast<int>(this->center().y() + y);
        pixel = &(canvas->getPixel(i, j));
        *pixel = this->color();

        i = static_cast<int>(this->center().x() + x);
        j = static_cast<int>(this->center().y() - y);
        pixel = &(canvas->getPixel(i, j));
        *pixel = this->color();


        i = static_cast<int>(this->center().x() - x);
        j = static_cast<int>(this->center().y() + y);
        pixel = &(canvas->getPixel(i, j));
        *pixel = this->color();


        i = static_cast<int>(this->center().x() - x);
        j = static_cast<int>(this->center().y() - y);
        pixel = &(canvas->getPixel(i, j));
        *pixel = this->color();


        i = static_cast<int>(this->center().x() + y);
        j = static_cast<int>(this->center().y() + x);
        pixel = &(canvas->getPixel(i, j));
        *pixel = this->color();


        i = static_cast<int>(this->center().x() + y);
        j = static_cast<int>(this->center().y() - x);
        pixel = &(canvas->getPixel(i, j));
        *pixel = this->color();


        i = static_cast<int>(this->center().x() - y);
        j = static_cast<int>(this->center().y() + x);
        pixel = &(canvas->getPixel(i, j));
        *pixel = this->color();


        i = static_cast<int>(this->center().x() - y);
        j = static_cast<int>(this->center().y() - x);
        pixel = &(canvas->getPixel(i, j));
        *pixel = this->color();


        y -= 1;
    }
}

void Circle::draw(PNG* canvas) const
{
    HSLAPixel& pixel = canvas->getPixel(static_cast<int>(this->center().x()),
                                 static_cast<int>(this->center().y()));
    pixel = this->color();

    int x = 0;
    int y = this->radius_;
    int p = 1 - this->radius_;
    this->drawPoints(canvas, x, y);

    while (x < y) {
        x++;
        if (p < 0) {
            p += 2 * x + 1;
        } else {
            y--;
            p += 2 * (x - y + 1);
        }
        this->drawPoints(canvas, x, y);
    }
}

int Circle::radius() const
{
    return this->radius_;
}

void Circle::set_radius(int pradius)
{
    this->radius_ = pradius;
}
