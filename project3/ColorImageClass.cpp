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

ColorImageClass::ColorImageClass(int inHeight, int inWidth)
{
    // default image size is defined as global variables
    height = inHeight;
    width = inWidth;

    // default color of image is black
    ColorClass defaultColor;
    defaultColor.setToBlack();

    // dynamic allocate row vectors
    imagePixelColor = new ColorClass *[height];

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

bool ColorImageClass::setColorAtLocation(int rowIdx, int colIdx, ColorClass &inColor)
{
    if (height < rowIdx || width < colIdx)
    {
        // input location is out of range
        return false;
    }

    imagePixelColor[rowIdx][colIdx].setTo(inColor);
    return true;
}

bool ColorImageClass::getColorAtLocation(int rowIdx, int colIdx, ColorClass &outColor)
{
    if (height < rowIdx || width < colIdx)
    {
        // input location is out of range
        return false;
    }

    outColor.setTo(imagePixelColor[rowIdx][colIdx]);
    return true;
}

void ColorImageClass::printImage()
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width - 1; j++)
        {
            imagePixelColor[i][j].printComponentValues();
            cout << "--";
        }
        // last pixel
        imagePixelColor[i][width - 1].printComponentValues();
        cout << endl;
    }
}
