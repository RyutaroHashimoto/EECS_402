//library
#include <iostream>
#include "ColorImageClass.h"
using namespace std;

//program header
//Name: Ryutaro Hashimoto
//Date: October 12, 2021
//purpose: This program will define color class. Colors are described by RGB
//values.


ColorImageClass::ColorImageClass()
{
    // default image size is defined as global variables
    height = DEFAULT_IMAGE_HEIGHT;
    width = DEFAULT_IMAGE_WIDTH;

    // default color of image is black
    ColorClass defaultColor;
    defaultColor.setToBlack();

    // dynamic allocate row vectors
    imagePixelColor = new ColorClass*[height];

    // dynamic allocate each column values
    for (int rowIdx = 0; rowIdx < height; rowIdx++)
    {
        imagePixelColor[rowIdx] = new ColorClass[width];
    }

    // set black for each value
    for (int rowIdx = 0; rowIdx < height; rowIdx++)
    {
        for (int colIdx = 0; colIdx < width; colIdx++)
        {
            imagePixelColor[rowIdx][colIdx] = defaultColor;
        }
    }
}
