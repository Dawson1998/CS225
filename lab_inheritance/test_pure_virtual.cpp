/**
 * @file test_pure_virtual.cpp
 * A simple application that demonstrates a problem with Truck pure virtual methods.
 */

#include <iostream>

#include "truck.h"

using cs225::PNG;

int main()
{
    PNG canvas;
    canvas.resize(128, 128);

    const Vector2 truck_center(64, 64);

    /* TODO: Why can't I construct a new Truck?  Is should be a valid Drawable.
     * Could it be missing something that would prevent it from being
     * constructed?
     */
    Drawable* truck = new Truck(truck_center);

    truck->draw(&canvas);

    canvas.writeToFile("test_pure_virtual.png");

    delete truck;
    return 0;
}
