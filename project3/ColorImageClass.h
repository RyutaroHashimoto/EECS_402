#ifndef _COLORIMAGECLASS_H_
#define _COLORIMAGECLASS_H_

//library
#include <iostream>
#include "constants.h"
#include "ColorClass.h"
using namespace std;

//program header
//Name: Ryutaro Hashimoto
//Date: November 4, 2021
//purpose: This program will prototyped "ColorImageClass" class and its method.

class ColorImageClass
{
public:
    // Initiialy, set black image
    ColorImageClass();

    // Initiialy, set black image with specified size
    ColorImageClass(int inHeight, int inWidth);

    // Initiialy, set black image with specified size and maximum color value
    ColorImageClass(int inHeight, int inWidth, int maxColorValue);

    //  set the pixel at the location specified to the color provided
    bool setColorAtLocation(int rowIdx, int colIdx, ColorClass &inColor);

    // get color at provided row/col index location if valid
    bool getColorAtLocation(int rowIdx, int colIdx, ColorClass &outColor);

    // Set height of image
    void setHeight(int inHeight);

    // Set width of image
    void setWidth(int inWidth);

    // Get height of image
    int getHeight();

    // Get width of image
    int getWidth();

private:
    // color image pixel value
    ColorClass **imagePixelColor;
    int height;
    int width;
};

#endif
