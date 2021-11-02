#ifndef _PPMIMAGECLASS_H_
#define _PPMIMAGECLASS_H_

//library
#include <iostream>
#include "constants.h"
#include "ColorImageClass.h"
using namespace std;

//program header
//Name: Ryutaro Hashimoto
//Date: October 12, 2021
//purpose: This program will define color class. Colors are described by RGB
//values.

class PPMImageClass
{
public:
    // Initially set black 5 by 5image
    PPMImageClass();

    // Initially set black image with specified size
    PPMImageClass(int inHeight, int inWidth);

    void PrintImage()
    {
        ColorImage.printImage();
    }

    bool setColorAtLocation(int rowIdx, int colIdx, ColorClass &inColor)
    {
        ColorImage.setColorAtLocation(rowIdx, colIdx, inColor);
    }

private:
    // color image pixel value
    ColorImageClass ColorImage;
    int height;
    int width;
};

#endif