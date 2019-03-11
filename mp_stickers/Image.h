/**
 * @file Image.h
 * Contains your declaration of the interface for the Image class.
 */

#pragma once
#include "Image.h"
#include "cs225/PNG.h"
#include <iostream>
using namespace std;
class Image: public cs225::PNG
{
public:
  //void lighten(double amount);
  void lighten();
  void lighten(double amount);
  void darken();
  void darken(double amount);
  void grayScale();
  void illinify();
  void desaturate();
  void desaturate(double amount);
  void rotateColor(double degrees);
  void saturate();
  void saturate(double amount);
  void scale(double factor);
  void scale(unsigned w, unsigned h);

private:

};
