/**
 * @file rectangle.h
 * Declaration of the Rectangle class.
 */

#pragma once

#include "shape.h"

/**
 * A subclass of Shape that represents a rectangle in 2D space
 */
class Rectangle : public Shape
{
  private:
    int width_;
    int height_;

  public:
    /**
     * Constructs a new Rectangle with the given center, color, height,
     *  and width
     *
     * @param center the center of the Rectangle
     * @param color the color of the Rectangle
     * @param width the width of the Rectangle in pixels
     * @param height the height of the Rectangle in pixels
     */
    Rectangle(const Vector2& center, const cs225::HSLAPixel& color, int width,
              int height);

    /**
     * Computes and returns the area of the Rectangle in pixels
     *
     * @return the area of the Rectangle in pixels
     */
    int area() const;

    /**
     * Computes and returns the perimeter of the Rectangle in pixels
     *
     * @return the perimeter of the Rectangle in pixels
     */
    int perimeter() const;

    /**
     * Checks to see if the given Vector2 p is inside of the Rectangle
     *
     * @param p Vector2
     *
     * @return true if p is inside of the Rectangle
     */
    bool contains(const Vector2& p) const;

    /**
     * Draws the Rectangle onto the canvas
     *
     * @param canvas to draw onto
     */
    void draw(cs225::PNG* canvas) const;

    /**
     * Gets the width of the Rectangle in pixels
     *
     * @return the width of the Rectangle in pixels
     */
    int width() const;

    /**
     * Sets the width of the Rectangle in pixels
     *
     * @param width the new width of the Rectangle in pixels
     */
    void set_width(int width);

    /**
     * Gets the height of the Rectangle in pixels
     *
     * @return the height of the Rectangle in pixels
     */
    int height() const;

    /**
     * Sets the height of the Rectangle in pixels
     *
     * @param height the new height of the Rectangle in pixels
     */
    void set_height(int height);
};
