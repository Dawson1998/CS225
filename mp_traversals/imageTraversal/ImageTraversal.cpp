#include <cmath>
#include <iterator>
#include <iostream>

#include "../cs225/HSLAPixel.h"
#include "../cs225/PNG.h"
#include "../Point.h"

#include "ImageTraversal.h"

/**
 * Calculates a metric for the difference between two pixels, used to
 * calculate if a pixel is within a tolerance.
 *
 * @param p1 First pixel
 * @param p2 Second pixel
 * @return the difference between two HSLAPixels
 */
double ImageTraversal::calculateDelta(const HSLAPixel & p1, const HSLAPixel & p2) {
  double h = fabs(p1.h - p2.h);
  double s = p1.s - p2.s;
  double l = p1.l - p2.l;

  // Handle the case where we found the bigger angle between two hues:
  if (h > 180) { h = 360 - h; }
  h /= 360;

  return sqrt( (h*h) + (s*s) + (l*l) );
}

/**
 * Default iterator constructor.
 */
ImageTraversal::Iterator::Iterator() {
  /** @todo [Part 1] */
  t=NULL;
  //start_=NULL;
  //pos_=NULL;
  //base_=NULL;
  //tol_=0;
  //pointsV=NULL;
  //path_=NULL;
  unsigned int width = 0;
  unsigned int height = 0;
  unsigned int aw= base_.width();
  unsigned int ah = base_.height();
  //std::cout<<"hi";
  pointsV.resize(aw,std::vector<bool>(ah));
  while(width<aw)
  {
    while(height<ah)
    {
      pointsV[width][height]=false;
      height++;
    }
    width++;
  }
}


bool ImageTraversal::Iterator::isAllowed(Point p)
{
  Point temp  = p;
  if(temp.y>=base_.height() || temp.x>=base_.width()) return false;
  if(temp.y<base_.height() && temp.x<base_.width())
  {
    HSLAPixel & begin = base_.getPixel(start_.x,start_.y);
    HSLAPixel & position = base_.getPixel(temp.x,temp.y);
    if(calculateDelta(begin,position)<tol_)
    {
      if(pointsV[temp.x][temp.y]==false)
      {
        return true;
      }
    }
  }
  return false;
  /*HSLAPixel & begin = base_.getPixel(start_.x,start_.y);
  HSLAPixel & position = base_.getPixel(pos_.x,pos_.y);
  if(calculateDelta(begin,position)<tol_)
  {
    if(pointsV[temp.x][temp.y]==false)
    {
      return true;
    }
  }
  return false*/
}

ImageTraversal::Iterator::Iterator(ImageTraversal* imaget,PNG png, Point p, double d)
{//std::cout<<"hi";
  t = imaget;
  base_ = png;
  start_=p;
  pos_= p;
  tol_ = d;
  unsigned int width = 0;
  unsigned int height = 0;
  unsigned int aw= base_.width();
  unsigned int ah = base_.height();
  //std::cout<<"hi";
  pointsV.resize(aw,std::vector<bool>(ah));
  while(width<aw)
  {
    height = 0;
    while(height<ah)
    {
      pointsV[width][height]=false;
      height++;
    }
    width++;
  }
  //std::cout<<"hi";

  if(!isAllowed(pos_)==false)
  {
    //pointsV[base_.widht()*pos_.y+pos_.x]=true;
    pointsV[pos_.x][pos_.y]=true;
  }

}
/**
 * Iterator increment opreator.
 *
 * Advances the traversal of the image.
 */
ImageTraversal::Iterator & ImageTraversal::Iterator::operator++() {
  /** @todo [Part 1] */
  pointsV[pos_.x][pos_.y]=true;
  //int increment = 1;
  Point right, left, above, below;
  right = Point(pos_.x+1,pos_.y);
  left = Point(pos_.x-1,pos_.y);
  above = Point(pos_.x,pos_.y-1);
  below = Point(pos_.x,pos_.y+1);
  if(isAllowed(right)){ t->add(right);}
  if(isAllowed(below)){ t->add(below);}
  if(isAllowed(left)) {t->add(left);}
  if(isAllowed(above)) {t->add(above);}
  while(t->empty()!=true && isAllowed(t->peek())!=true)
  {
    t->pop();
    if(t->empty())
    {
      return *this;
    }
  }
  if(t->empty()==false)
  {
    pos_ = t->peek();
    return *this;
  }
  else
  {
    t = NULL;
    return *this;
  }
  return *this;
}


/**
 * Iterator accessor opreator.
 *
 * Accesses the current Point in the ImageTraversal.
 */
Point ImageTraversal::Iterator::operator*() {
  /** @todo [Part 1] */
  return pos_;
}

/**
 * Iterator inequality operator.
 *
 * Determines if two iterators are not equal.
 */
bool ImageTraversal::Iterator::operator!=(const ImageTraversal::Iterator &other) {
  /** @todo [Part 1] */

  //return false;
  /*if(t==NULL && other.t==NULL)
  {
    return false;
  }
  else if(t!=NULL && other.t!=NULL)
  {
    if(t->empty()!=true && other.t->empty()!=true)
    {
      return (t!=other.t);
    }
  }
  else if(t->e)
  return true;*/
  //TAKEN DIRECTLY FROM Lab_trees/TreeTraversals
  bool thisEmpty = false;
  bool otherEmpty = false;

  if (t == NULL) { thisEmpty = true; }
  if (other.t == NULL) { otherEmpty = true; }

  if (!thisEmpty)  { thisEmpty = t->empty(); }
  if (!otherEmpty) { otherEmpty = other.t->empty(); }

  if (thisEmpty && otherEmpty) return false; // both empty then the ts are equal, return true
  else if ((!thisEmpty)&&(!otherEmpty)) return (t != other.t); //both not empty then compare the traversals
  else return true; // one is empty while the other is not, return true
}
