#ifndef _COLORCLASS_H_
#define _COLORCLASS_H_

//library
#include <iostream>
#include "constants.h"
using namespace std;

//program header
//Name: Ryutaro Hashimoto
//Date: November 4, 2021
//purpose: This program will prototyped "ColorClass" class and its method.

class ColorClass
{
public:
    // Initiialy set to white without input (all value is MAXIMUM_COLOR_VALUE)
    ColorClass();

    // Initiialy set to specific value with input
    ColorClass(int inRed, int inGreen, int inBlue);

    // Set color values to black (min, min, min)
    void setToBlack();

    // Set color values to red (max, min, min)
    void setToRed();

    // Set color values to green (min, max, min)
    void setToGreen();

    // Set color values to blue (min, min, max)
    void setToBlue();

    // Set color values to white (max, max, max)
    void setToWhite();

    // Set color values to black (min, min, min) with specified max
    void setToBlack(int maxColorValue);

    // Set color values to red (max, min, min) with specified max
    void setToRed(int maxColorValue);

    // Set color values to green (min, max, min) with specified max
    void setToGreen(int maxColorValue);

    // Set color values to blue (min, min, max) with specified max
    void setToBlue(int maxColorValue);

    // Set color values to white (max, max, max) with specified max
    void setToWhite(int maxColorValue);

    // Set color values to specific value
    void setTo(int inRed, int inGreen, int inBlue);

    // Set color values to specific class
    void setTo(ColorClass &inColor);

    // get value of red
    int getRedValue();

    // get value of green
    int getGreenValue();

    // get value of blue
    int getBlueValue();

private:
    // RGB color value
    int redValue;
    int greenValue;
    int blueValue;
};

#endif
