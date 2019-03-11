#include "Image.h"
#include "cs225/PNG.h"
#include "cs225/HSLAPixel.h"
#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;

void Image::lighten()
{
  int width = this->width();
  int height = this->height();
  for(int x =0;x<width;x++)
  {
    for(int y=0; y<height; y++)
    {
      if(this->getPixel(x,y).l+.1>=1.0)
      {
        this->getPixel(x,y).l=1.0;
        continue;
      }
      else
        this->getPixel(x,y).l=this->getPixel(x,y).l+.1;
    }
  }
}
void Image::lighten(double amount)
{
  int width = this->width();
  int height = this->height();
  for(int x =0;x<width;x++)
  {
    for(int y=0; y<height; y++)
    {
      if(this->getPixel(x,y).l+amount>=1.0)
      {
        this->getPixel(x,y).l=1;
        continue;
      }
      else
        this->getPixel(x,y).l=this->getPixel(x,y).l+amount;
    }
  }
}
void Image::darken()
{
  int width = this->width();
  int height = this->height();
  for(int x =0;x<width;x++)
  {
    for(int y=0; y<height; y++)
    {
      if(this->getPixel(x,y).l-.1<=0.0)
      {
        this->getPixel(x,y).l=0;
      }
      else
        this->getPixel(x,y).l=this->getPixel(x,y).l-.1;
    }
  }
}
void Image::darken(double amount)
{
  int width = this->width();
  int height = this->height();
  for(int x =0;x<width;x++)
  {
    for(int y=0; y<height; y++)
    {
      if(this->getPixel(x,y).l-amount<=0.0)
      {
        this->getPixel(x,y).l=0;
      }
      else this->getPixel(x,y).l=this->getPixel(x,y).l-amount;
    }
  }
}
void Image::grayScale()
{
  int width = this->width();
  int height = this->height();
  for(int x =0;x<width;x++)
  {
    for(int y=0; y<height; y++)
    {
      this->getPixel(x,y).s=0;
    }
  }
}
void Image::illinify()
{
  for (unsigned x = 0; x < this->width(); x++) {
    for (unsigned y = 0; y < this->height(); y++) {
      cs225::HSLAPixel & pixel = this->getPixel(x, y);
      double od, bd;
      if(pixel.h>=191)
      {
         od = 371-pixel.h;
      }
      else
      {
        od=sqrt((pixel.h-11)*(pixel.h-11));
      }

      if(pixel.h>=36&&pixel.h<=216)
      {
        bd=216-pixel.h;
        bd=sqrt(bd*bd);
      }
      else
      {
        bd=pixel.h-216;
        bd=sqrt(bd*bd);
      }

      if(od>=bd)
      {
        pixel.h=216;
      }
      else
      {
        pixel.h=11;
      }
      // `pixel` is a pointer to the memory stored inside of the PNG `image`,
      // which means you're changing the image directly.  No need to `set`
      // the pixel since you're directly changing the memory of the image.
      //pixel.s=0;
    }
  }
}
void Image::desaturate()
{
  int width = this->width();
  int height = this->height();
  for(int x =0;x<width;x++)
  {
    for(int y=0; y<height; y++)
    {
      this->getPixel(x,y).s=this->getPixel(x,y).s-.1;
    }
  }
}
void Image::desaturate(double amount)
{
  int width = this->width();
  int height = this->height();
  for(int x =0;x<width;x++)
  {
    for(int y=0; y<height; y++)
    {
      this->getPixel(x,y).s=this->getPixel(x,y).s-amount;
    }
  }
}
void Image::rotateColor(double degrees)
{
  int width = this->width();
  int height = this->height();
  for(int x =0;x<width;x++)
  {
    for(int y=0; y<height; y++)
    {
      if(this->getPixel(x,y).h+degrees>360)
      {
        this->getPixel(x,y).h=this->getPixel(x,y).h+degrees-360;
      }
      else if(this->getPixel(x,y).h+degrees<0)
      {
        this->getPixel(x,y).h=this->getPixel(x,y).h+degrees+360;
      }
      else
        this->getPixel(x,y).h=this->getPixel(x,y).h+degrees;
    }
  }
}
void Image::saturate()
{
  int width = this->width();
  int height = this->height();
  for(int x =0;x<width;x++)
  {
    for(int y=0; y<height; y++)
    {
      this->getPixel(x,y).s=this->getPixel(x,y).s+.1;
    }
  }
}
void Image::saturate(double amount)
{
  int width = this->width();
  int height = this->height();
  for(int x =0;x<width;x++)
  {
    for(int y=0; y<height; y++)
    {
      this->getPixel(x,y).s=this->getPixel(x,y).s+amount;
    }
  }
}
void Image::scale(double factor)
{
  unsigned int newwidth=this->width()*factor;
  unsigned int newheight=this->height()*factor;
  double xr=this->width()/(double)newwidth;
  double yr=this->height()/(double)newheight;
  if(xr>yr)
  {
    xr=yr;
  }
  else
  {
    yr=xr;
  }
  cs225::PNG si(*this);
    this->resize(ceil(newwidth),ceil(newheight));
    for(unsigned int x = 0; x<newwidth;x++)
    {
      for(unsigned int y=0; y<newheight;y++)
      {
        int ox = x*xr;
        int oy = y*yr;
        this->getPixel(x,y)=si.getPixel(ox,oy);
      }
    }

    //this->scale(newwidth,newheight);
}
void Image::scale(unsigned w, unsigned h)
{
  unsigned newwidth=w;
  unsigned newheight=h;
  double xr=(double)newwidth/(this->width());

  double yr=(double)newheight/(this->height());
  if(yr>xr)
  {
    scale(xr);
  }
  else{
    scale(yr);
  }
  /*cs225::PNG si(*this);
  this->resize(newwidth,newheight);
    for(unsigned int x = 0; x<newwidth;x++)
    {
      for(unsigned int y=0; y<newheight;y++)
      {
        int ox = x*xr;
        int oy = y*yr;
        this->getPixel(x,y)=si.getPixel(ox,oy);
      }
    }*/
}
