/**
 * @file shape.h
 * Declaration of the Shape class.
 */

#pragma once

#include "drawable.h"
#include "vector2.h"

/**
 * An abstract base class that represents a Shape which has an area,
 * perimeter, color, and can contain Vector2s. Shapes are also drawable, so
 * they are expected to know how to draw themselves to a PNG.
 */
class Shape : public Drawable
{
  protected:
    Vector2 center_;

  private:
    cs225::HSLAPixel color_;

  public:
    /**
     * Constructs a new Shape with a default color and center
     */
    Shape();

    /**
     * Constructs a new Shape with the given center and color
     *
     * @param center Vector2 of the new Shape
     * @param color of the new Shape
     */
    Shape(const Vector2& center, const cs225::HSLAPixel& color);

    virtual ~Shape()
    { /* Nothing */
    }

    /**
     * Computes and returns the area of the Shape in pixels
     *
     * @return the area (in pixels) of the Shape
     */
    virtual int area() const;

    /**
     * Computes and returns the perimeter of the Shape in pixels
     *
     * @return the perimeter (in pixels) of the Shape
     */
    virtual int perimeter() const;

    /**
     * Checks to see if the Vector2 p is contained inside of the Shape
     *
     * @param p Vector2 to check if it is contained inside the Shape or not
     *
     * @return true if Vector2 p is inside of the Shape
     */
    bool contains(const Vector2& p) const;

    /**
     * Gets the center Vector2 of the Shape
     *
     * @return the center Vector2 of the Shape
     */
    Vector2 center() const;

    /**
     * Sets the center Vector2 of the Shape
     *
     * @param center the new center Vector2 of the Shape
     */
    virtual void set_center(const Vector2& center);

    /**
     * Gets the color of the Shape
     *
     * @return the HSLAPixel representing the color of the Shape
     */
    cs225::HSLAPixel color() const;

    void draw(cs225::PNG* canvas) const;
};
