#include "ColorClass.h"

//program header
//Name: Ryutaro Hashimoto
//Date: November 4, 2021
//purpose: This program will define "ColorClass" class and its method.

ColorClass::ColorClass()
{
    redValue = MAXIMUM_COLOR_VALUE;
    greenValue = MAXIMUM_COLOR_VALUE;
    blueValue = MAXIMUM_COLOR_VALUE;
}

ColorClass::ColorClass(int inRed, int inGreen, int inBlue)
{
    redValue = inRed;
    greenValue = inGreen;
    blueValue = inBlue;
}

void ColorClass::setToBlack()
{
    redValue = MINIMUM_COLOR_VALUE;
    greenValue = MINIMUM_COLOR_VALUE;
    blueValue = MINIMUM_COLOR_VALUE;
}

void ColorClass::setToRed()
{
    redValue = MAXIMUM_COLOR_VALUE;
    greenValue = MINIMUM_COLOR_VALUE;
    blueValue = MINIMUM_COLOR_VALUE;
}

void ColorClass::setToGreen()
{
    redValue = MINIMUM_COLOR_VALUE;
    greenValue = MAXIMUM_COLOR_VALUE;
    blueValue = MINIMUM_COLOR_VALUE;
}

void ColorClass::setToBlue()
{
    redValue = MINIMUM_COLOR_VALUE;
    greenValue = MINIMUM_COLOR_VALUE;
    blueValue = MAXIMUM_COLOR_VALUE;
}
void ColorClass::setToWhite()
{
    redValue = MAXIMUM_COLOR_VALUE;
    greenValue = MAXIMUM_COLOR_VALUE;
    blueValue = MAXIMUM_COLOR_VALUE;
}

void ColorClass::setToBlack(int maxColorValue)
{
    redValue = MINIMUM_COLOR_VALUE;
    greenValue = MINIMUM_COLOR_VALUE;
    blueValue = MINIMUM_COLOR_VALUE;
}

void ColorClass::setToRed(int maxColorValue)
{
    redValue = maxColorValue;
    greenValue = MINIMUM_COLOR_VALUE;
    blueValue = MINIMUM_COLOR_VALUE;
}

void ColorClass::setToGreen(int maxColorValue)
{
    redValue = MINIMUM_COLOR_VALUE;
    greenValue = maxColorValue;
    blueValue = MINIMUM_COLOR_VALUE;
}

void ColorClass::setToBlue(int maxColorValue)
{
    redValue = MINIMUM_COLOR_VALUE;
    greenValue = MINIMUM_COLOR_VALUE;
    blueValue = maxColorValue;
}
void ColorClass::setToWhite(int maxColorValue)
{
    redValue = maxColorValue;
    greenValue = maxColorValue;
    blueValue = maxColorValue;
}

void ColorClass::setTo(int inRed, int inGreen, int inBlue)
{
    redValue = inRed;
    greenValue = inGreen;
    blueValue = inBlue;
}

void ColorClass::setTo(ColorClass &inColor)
{
    redValue = inColor.redValue;
    greenValue = inColor.greenValue;
    blueValue = inColor.blueValue;
}

int ColorClass::getRedValue()
{
    return redValue;
}

int ColorClass::getGreenValue()
{
    return greenValue;
}

int ColorClass::getBlueValue()
{
    return blueValue;
}
