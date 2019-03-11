/**
 * @file vector2.h
 * Declaration of the Vector2 class.
 */

#pragma once

/**
 * Represents a 2 dimensional vector
 */
class Vector2
{
  private:
    double x_; /**< The X coordinate of this vector */
    double y_; /**< The Y coordinate of this vector */

  public:
    /**
     * Constructs a new Vector2 at (0, 0)
     */
    Vector2();

    /**
     * Constructs a new Vector2 at (x, y)
     *
     * @param x
     * @param y
     */
    Vector2(double x, double y);

    /**
     * Subtracts two Vector2s and returns the value
     *
     * @param other Vector2 to subtract by
     *
     * @return a new Vector2 that equals *this - other
     */
    Vector2 operator-(const Vector2& other) const;

    /**
     * Adds two Vector2s together and returns the value
     *
     * @param other Vector2 to add
     *
     * @return a new Vector2 that equals *this + other
     */
    Vector2 operator+(const Vector2& other) const;

    /**
     * Multiples the current Vector2 by a scalar and returns a new
     * Vector2 with its value
     *
     * @param constant to multiply by
     *
     * @return a new Vector2 that equals (x * constant, y * constant)
     */
    Vector2 operator*(int constant);

    /**
     * Divides the current Vector2 by a scalar and returns a new Vector2
     * with its value
     *
     * @param constant to divide by
     *
     * @return a new Vector2 that equals (x / constant, y / constant)
     */
    Vector2 operator/(int constant);

    /**
     * Checks to see if the current Vector2 equals the other Vector2
     *
     * @param other Vector2 to check
     *
     * @return true if the current Vector2 equals the other Vector2
     */
    bool operator==(const Vector2& other) const;

    /**
     * Gets the x coordinate of the Vector2
     *
     * @return the x coordinate of the Vector2
     */
    double x() const;

    /**
     * Sets the x coordinate of the Vector2
     *
     * @param x the new x coordinate of the Vector2
     */
    void setX(double x);

    /**
     * Gets the y coordinate of the Vector2
     *
     * @return the y coordinate of the Vector2
     */
    double y() const;

    /**
     * Sets the y coordinate of the Vector2
     *
     * @param y the new y coordinate of the Vector2
     */
    void setY(double y);

    /**
     * Computes and returns the distance from the current Vector2 to the
     * other Vector2
     *
     * @param other
     *
     * @return sqrt((this->x - other.x)^2 + (this-y - other.y)^2)
     */
    double distanceTo(const Vector2& other) const;

    /**
     * Checks if the current Vector2 is north of the other Vector2
     *
     * @param other
     *
     * @return true if the current Vector2 is north of the other Vector2
     */
    bool isNorthOf(const Vector2& other) const;

    /**
     * Checks if the current Vector2 is north west of the other Vector2
     *
     * @param other
     *
     * @return true if the current Vector2 is north west of the other Vector2
     */
    bool isNorthWestOf(const Vector2& other) const;

    /**
     * Checks if the current Vector2 is north east of the other Vector2
     *
     * @param other
     *
     * @return true if the current Vector2 is north east of the other Vector2
     */
    bool isNorthEastOf(const Vector2& other) const;

    /**
     * Checks if the current Vector2 is south of the other Vector2
     *
     * @param other
     *
     * @return true if the current Vector2 is south of the other Vector2
     */
    bool isSouthOf(const Vector2& other) const;

    /**
     * Checks if the current Vector2 is south west of the other Vector2
     *
     * @param other
     *
     * @return true if the current Vector2 is south west of the other Vector2
     */
    bool isSouthWestOf(const Vector2& other) const;

    /**
     * Checks if the current Vector2 is south east of the other Vector2
     *
     * @param other
     *
     * @return true if the current Vector2 is south east of the other Vector2
     */
    bool isSouthEastOf(const Vector2& other) const;

    /**
     * Checks if the current Vector2 is west of the other Vector2
     *
     * @param other
     *
     * @return true if the current Vector2 is west of the other Vector2
     */
    bool isWestOf(const Vector2& other) const;

    /**
     * Checks if the current Vector2 is east of the other Vector2
     *
     * @param other
     *
     * @return true if the current Vector2 is east of the other Vector2
     */
    bool isEastOf(const Vector2& other) const;

    /**
     * Computes and returns the dot product of the current Vector2 and
     * other Vector2
     *
     * @param other
     *
     * @return the dot product of the current Vector2 and the other Vector2
     */
    double dotProduct(const Vector2& other) const;

    /**
     * Computes and returns the cross product of the current Vector2 and
     * the other Vector2
     *
     * @param other
     *
     * @return the cross product of the current Vector2 and the other Vector2
     */
    double crossProduct(const Vector2& other) const;

    /**
     * Computes and returns the projection of the current Vector2 onto b
     *
     * @param b Vector2 to project onto
     *
     * @return the Vector2 representing the projection of the current Vector2
     * onto b
     */
    Vector2 projectionOn(const Vector2& b) const;

    /**
     * Computes and returns the length of the Vector2 from the origin
     *
     * @return the length of the Vector2 from the origin
     */
    double length() const;

    /**
     * Computes and returns the length^2 of the Vector2 from the origin
     *
     * @return the length^2 of the Vector2 from the origin
     */
    double length2() const;

    /**
     * Computes and returns the magnitude of the Vector2.
     * Note this is the same as length
     *
     * @return the magnitude of the Vector2
     */
    double magnitude() const;

    /**
     * Computes and returns the normalized form of the current Vector2
     *
     * @return the normalized form of the current Vector2
     */
    Vector2 normalize() const;

    /**
     * Computes and returns the left hand normal of the current Vector2
     *
     * @return the left hand normal of the current Vector2
     */
    Vector2 leftHandNormal() const;

    /**
     * Computes and returns the right hand normal of the current Vector2
     *
     * @return the right hand normal of the current Vector2
     */
    Vector2 rightHandNormal() const;
};
