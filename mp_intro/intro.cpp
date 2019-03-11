#include "cs225/PNG.h"
#include "cs225/HSLAPixel.h"

#include <string>
#include <cmath>
#include <cstdlib>



void rotate(std::string inputFile, std::string outputFile) {
  // TODO: Part 2
  cs225::PNG png;

  png.readFromFile(inputFile);
  cs225::PNG png2(png.width(),png.height());

  for(unsigned int x=0;x<png2.width();x++)
  {
    for(unsigned int y=0;y<png2.height();y++)
    {
      cs225::HSLAPixel &pixel=png.getPixel(x,y);
      cs225::HSLAPixel &pixel2=png2.getPixel(png2.width()-x-1,png2.height()-y-1);
      pixel2=pixel;
    }
  }
  png2.writeToFile(outputFile);
}
cs225::PNG createSpotlight(cs225::PNG image, int centerX, int centerY) {
  for (unsigned x = 0; x < image.width(); x++) {
    for (unsigned y = 0; y < image.height(); y++) {
      cs225::HSLAPixel & pixel = image.getPixel(x, y);
      unsigned int d = sqrt((centerX-x)*(centerX-x)+(centerY-y)*(centerY-y));
        pixel.h=pixel.h*(1-.005*d);

      // `pixel` is a pointer to the memory stored inside of the PNG `image`,
      // which means you're changing the image directly.  No need to `set`
      // the pixel since you're directly changing the memory of the image.
      pixel.s = 0.5;
    }
  }
  return image;

}
cs225::PNG createSpotlight2(cs225::PNG image, int centerX, int centerY) {
  for (unsigned x = 0; x < image.width(); x++) {
    for (unsigned y = 0; y < image.height(); y++) {
      cs225::HSLAPixel & pixel = image.getPixel(x, y);
      unsigned int d = sqrt((centerX-x)*(centerX-x)+(centerY-y)*(centerY-y));
        pixel.h=pixel.h*(1-.0005*d);

      // `pixel` is a pointer to the memory stored inside of the PNG `image`,
      // which means you're changing the image directly.  No need to `set`
      // the pixel since you're directly changing the memory of the image.
    }
  }
  return image;

}

cs225::PNG myArt(unsigned int width, unsigned int height) {
  cs225::PNG png(width, height);
  // TODO: Part 3
  double hue=0;
  for(unsigned int x =0; x<width;x++)
  {
    for(unsigned int y=0;y<height;y++)
    {
      cs225::HSLAPixel p(hue, 1, .5);
      cs225::HSLAPixel &pixel=png.getPixel(x,y);
      pixel=p;
      if(hue==360)
      {
        hue=0;
      }
      else hue++;

    }
  }
  png=createSpotlight(png, 100,100);
  png=createSpotlight(png, 700,700);
  png=createSpotlight2(png, 0,800);
  png=createSpotlight2(png, 800,0);

  return png;
}
