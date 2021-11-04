#include "ColorImageClass.h"

//program header
//Name: Ryutaro Hashimoto
//Date: November 4, 2021
//purpose: This program will define "ColorImageClass" class and its method.

ColorImageClass::ColorImageClass()
{
    // default image size is defined as global variables
    height = DEFAULT_IMAGE_HEIGHT;
    width = DEFAULT_IMAGE_WIDTH;

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

ColorImageClass::ColorImageClass(int inHeight, int inWidth, int maxColorValue)
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

void ColorImageClass::ClearMemory()
{
    // Clear dynamic allocated memory
    for (int rowIdx = 0; rowIdx < height; rowIdx++)
    {
        delete[] imagePixelColor[rowIdx];
    }
    delete[] imagePixelColor;
}

bool ColorImageClass::setColorAtLocation(int rowIdx, int colIdx,
                                         ColorClass &inColor)
{
    if (height <= rowIdx || width <= colIdx)
    {
        // input location is out of range
        return false;
    }

    imagePixelColor[rowIdx][colIdx].setTo(inColor);
    return true;
}

bool ColorImageClass::getColorAtLocation(int rowIdx, int colIdx,
                                         ColorClass &outColor)
{
    if (height <= rowIdx || width <= colIdx)
    {
        // input location is out of range
        return false;
    }

    outColor.setTo(imagePixelColor[rowIdx][colIdx]);
    return true;
}

void ColorImageClass::setHeight(int inHeight)
{
    height = inHeight;
}

void ColorImageClass::setWidth(int inWidth)
{
    width = inWidth;
}

int ColorImageClass::getHeight()
{
    return height;
}

int ColorImageClass::getWidth()
{
    return width;
}
