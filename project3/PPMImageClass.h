#ifndef _PPMIMAGECLASS_H_
#define _PPMIMAGECLASS_H_

//library
#include <iostream>
#include <fstream>
#include <string>
#include "constants.h"
#include "commonFunc.h"
#include "ColorImageClass.h"
using namespace std;

//program header
//Name: Ryutaro Hashimoto
//Date: November 4, 2021
//purpose: This program will prototyped "PPMImageClass" class and its method.
class PPMImageClass
{
public:
    // Initially set black 5 by 5image
    PPMImageClass();

    // Initially set black image with specified size
    PPMImageClass(int inHeight, int inWidth);

    // read image from .ppm file
    bool readPPMFile(const string path);

    // output current colorimage into .ppm file
    bool writePPMFile(const string path);

    // edit color value of specific point
    void getColorAtLocation(int rowIdx, int colIdx, ColorClass &outColor);

    // edit color value of specific point
    void setColorAtLocation(int rowIdx, int colIdx, ColorClass &inColor);

    // get height of image
    int getHeight();

    // get width of image
    int getWidth();

    // get max color value of image
    int getMaxColorValue();

private:
    ColorImageClass ColorImage;
    int maxColorValue;
};

#endif
