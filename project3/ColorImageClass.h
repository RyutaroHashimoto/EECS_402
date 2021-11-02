#ifndef _COLORIMAGECLASS_H_
#define _COLORIMAGECLASS_H_

//library
#include <iostream>
#include "constants.h"
#include "ColorClass.h"
#include "RowColumnClass.h"
using namespace std;

//program header
//Name: Ryutaro Hashimoto
//Date: October 12, 2021
//purpose: This program will define color class. Colors are described by RGB
//values.

class ColorImageClass
{
public:
    // Initiialy set black image
    ColorImageClass();

    // Initiialy set all image pixel to the color provided
    void initializeTo(ColorClass &inColor);

    // pixel-wise addition (return true if at least one pixel clipped)
    bool addImageTo(ColorImageClass &rhsImg);

    // pixel values to be set to the sum of the corresponding pixels in
    // each image in the imagesToAdd
    bool addImages(int numImgsToAdd, ColorImageClass imagesToAdd[]);

    //  set the pixel at the location specified to the color provided
    bool setColorAtLocation(RowColumnClass &inRowCol, ColorClass &inColor);

    // get color at provided row/col index location if valid
    bool getColorAtLocation(RowColumnClass &inRowCol, ColorClass &outColor);

    // print contents of the image
    void printImage();

private:
    // color image pixel value
    ColorClass **imagePixelColor;
    int height;
    int width;
};

#endif