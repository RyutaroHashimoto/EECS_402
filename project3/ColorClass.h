#ifndef _COLORCLASS_H_
#define _COLORCLASS_H_

//library
#include <iostream>
#include "constants.h"
using namespace std;

//program header
//Name: Ryutaro Hashimoto
//Date: October 12, 2021
//purpose: This program will define color class. Colors are described by RGB 
//values.

//global Class
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

    // Set color values to specific value
    bool setTo(int inRed, int inGreen, int inBlue);

    // Set color values to specific class
    bool setTo(ColorClass &inColor);

    // add color value of another class with clipping if need
    bool addColor(ColorClass &rhs);

    // substract color value of another class with clipping if need
    bool subtractColor(ColorClass &rhs);

    // multiplies each color value by the adjustment factor with clipping
    bool adjustBrightness(const double adjFactor);

    // print each of current color values of class
    void printComponentValues();

private:
    // RGB color value
    int redValue;
    int greenValue;
    int blueValue;

    // do clip three color value and return whether clipped or not
    bool doClipValue(int &inRed, int &inGreen, int &inBlue);

    // clip value of color so that values is within the valid range
    int clipValue(int &colorValue);
};

#endif