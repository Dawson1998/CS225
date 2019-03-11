/**
 * @file sketchify.cpp
 * Implementation of the sketchify function.
 */

#include <cstdlib>
#include <cmath>

#include "cs225/PNG.h"
#include "cs225/HSLAPixel.h"
using namespace cs225;

/**
 * Creates a new output image.

 * @param w width of the image
 * @param h height of the image

 * @return a pointer to the newly-created image
 */
PNG* setupOutput(unsigned w, unsigned h) {
    PNG* image = new PNG(w, h);
    /*for(int x = 0; x<w;x++)
    {
      for(int y=0;y<h;y++)
      {
        HSLAPixel a = new HSLAPixel();
        image.
      }
    }*/
    return image;
}

/**
 * Used to customize the color of the sketchified image.

 * @return a pointer to the color to use when sketchifying
 */
HSLAPixel* myFavoriteColor() {
    HSLAPixel *p=new HSLAPixel(207, 0.8, 0.5,1);
    return p;
}

void sketchify(std::string inputFile, std::string outputFile) {
    // Load in.png
    PNG* original = new PNG();
    original->readFromFile(inputFile);
    unsigned width = original->width();
    //std::cout<<width<<std::endl;
    unsigned height = original->height();
    //std::cout<<height<<std::endl;
    // Create out.png
    PNG* output=setupOutput(width, height);
    //setupOutput(width, height);

    // Load our favorite color to color the outline
    HSLAPixel* myPixel = myFavoriteColor();

    // Go over the whole image, and if a pixel differs from that to its upper
    // left, color it my favorite color in the output
    for (unsigned y = 1;y < height; y++) {
        for (unsigned x = 1;x < width; x++) {
            // Calculate the pixel difference
            //std::cout<<"hi"<<std::endl;
            HSLAPixel& prev = original->getPixel(x - 1, y - 1);
            //std::cout<<"hi"<<std::endl;
            HSLAPixel& curr = original->getPixel(x, y);
            //std::cout<<"hi"<<std::endl;
            double diff = std::fabs(curr.h - prev.h);
            //std::cout<<"hi"<<std::endl;
            // If the pixel is an edge pixel,
            // color the output pixel with my favorite color
            HSLAPixel &currOutPixel = (*output).getPixel(x, y);
            //std::cout<<"hi"<<std::endl;
            if (diff > 20) {
                currOutPixel = *myPixel;
                //std::cout<<"hi"<<std::endl;
            }
        }
    }

    // Save the output file
    output->writeToFile(outputFile);

    // Clean up memory
    delete myPixel;
    //delete output;
    delete original;
}
