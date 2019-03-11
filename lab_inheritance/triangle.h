/**
 * @file triangle.h
 * Declaration of the Triangle class.
 */

#pragma once

#include "shape.h"

/**
 * A subclass of a Shape that represents a triangle in 2D space
 */
class Triangle : public Shape
{
  private:
    Vector2** vertices_;

  public:
    /**
     * Constructs a new Triangle out of the 3 give Vector2s
     *
     * @param color of the new Triangle
     * @param vertex1 first Vector2 of the Triangle
     * @param vertex2 second Vector2 of the Triangle
     * @param vertex3 third Vector2 of the Triangle
     */
    Triangle(const cs225::HSLAPixel& color, const Vector2& vertex1,
             const Vector2& vertex2, const Vector2& vertex3);

    Triangle(const Triangle& other);

    ~Triangle();

    Triangle& operator=(const Triangle& rhs);

    /**
     * Computes and returns the area of the Triangle
     *
     * @return the area of the Triangle in pixels
     */
    int area() const;

    /**
     * Computes and returns the perimeter of the Triangle
     *
     * @return the perimeter of the Triangle in pixels
     */
    int perimeter() const;

    /**
     * Checks to see if the Vector2 p is contained inside of the Triangle
     *
     * @param p Vector2
     *
     * @return true if the Vector2 p is inside of the Triangle
     */
    bool contains(const Vector2& p) const;

    /**
     * Draws the Triangle to the canvas
     *
     * @param canvas PNG to draw onto
     */
    void draw(cs225::PNG* canvas) const;

    /**
     * Overridden set_center method that sets the center Vector2 of the
     * Triangle
     *
     * @param center the new center Vector2
     */
    void set_center(const Vector2& center);

    /**
     * Gets one of the Triangle's vertices.  Crashes if an invalid vertex
     * index is given (i.e. i < 0 or i > 2)
     *
     * @param i Vertex to get.  Either 0, 1, or 2
     *
     * @return The Triangle's i'th vertex
     */
    Vector2 vertex(int i) const;

    /**
     * Sets one of the Triangle's vertices.  Crashes if an invalid vertex
     * index is given (i.e. i < 0 or i > 2)
     *
     * @param i the vertex to change
     * @param value the new vertex
     */
    void set_vertex(int i, const Vector2& value);
};

