/**
 * @file line.h
 * Declaration of the Line class.
 */

#pragma once

#include <vector>

#include "drawable.h"
#include "vector2.h"

/**
 * A subclass of Drawable that represents a line in 2D space
 */
class Line : public Drawable
{
  private:
    Vector2 a_;
    Vector2 b_;
    cs225::HSLAPixel color_;

  public:
    /**
     * Constructs a new Line going from Point a to Point b
     *
     * @param a
     * @param b
     * @param color of the new Line
     */
    Line(const Vector2& a, const Vector2& b, const cs225::HSLAPixel& color);

    /**
     * Draws the Line onto the canvas
     *
     * @param canvas
     */
    void draw(cs225::PNG* canvas) const;

    /**
     * Gets starting point of the Line
     *
     * @return the starting point of the Line
     */
    Vector2 a() const;

    /**
     * Sets the starting point of the Line
     *
     * @param a the new starting point of the Line
     */
    void set_a(const Vector2& a);

    /**
     * Gets the ending point of the Line
     *
     * @return the ending point of the Line
     */
    Vector2 b() const;

    /**
     * Sets the ending point of the Line
     *
     * @param b the new ending point of the Line
     */
    void set_b(const Vector2& b);

    /**
     * Gets the color of the Line
     *
     * @return the color of the Line
     */
    cs225::HSLAPixel color() const;

    /**
     * Sets the color of the Line
     *
     * @param color the new color of the Line
     */
    void set_color(const cs225::HSLAPixel& color);

    static std::vector<double> linearInterpolation(const Vector2& a,
                                                   const Vector2& b);
};
