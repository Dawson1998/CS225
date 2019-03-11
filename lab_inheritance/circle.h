/**
 * @file circle.h
 * Declaration of the Circle class.
 */

#pragma once

#include "shape.h"

/**
 * A subclass of Shape that represents a Circle in 2D space
 */
class Circle : public Shape
{
  private:
    int radius_;
    void drawPoints(cs225::PNG* canvas, int x, int y) const;

  public:
    /**
     * Constructs a new Circle with the given center, color, and radius
     *
     * @param center point of the new Circle
     * @param color of the new Circle
     * @param radius of the new Circle in pixels
     */
    Circle(const Vector2& center, const cs225::HSLAPixel& color, int radius);

    /**
     * Computes and returns the area of the Circle in pixels
     *
     * @return the area of the Circle in pixels
     */
    int area() const;

    /**
     * Computes and returns the perimeter of the Circle in pixels
     *
     * @return the perimeter of the Circle in pixels
     */
    int perimeter() const;

    /**
     * Checks to see if the given point is inside the Circle
     *
     * @param p
     *
     * @return true if p is inside the Circle
     */
    bool contains(const Vector2& p) const;

    /**
     * Draws the Circle to the canvas
     *
     * @param canvas
     */
    void draw(cs225::PNG* canvas) const;

    /**
     * Gets the radius of the Circle in pixels
     *
     * @return the radius of the Circle in pixels
     */
    int radius() const;

    /**
     * Sets the radius of the Circle in pixels
     *
     * @param radius the new radius of the Circle in pixels
     */
    void set_radius(int radius);
};
