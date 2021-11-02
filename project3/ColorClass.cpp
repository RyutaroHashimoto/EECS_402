//library
#include <iostream>
#include "ColorClass.h"
using namespace std;

ColorClass::ColorClass()
{
    redValue = MAXIMUM_COLOR_VALUE;
    greenValue = MAXIMUM_COLOR_VALUE;
    blueValue = MAXIMUM_COLOR_VALUE;
}

ColorClass::ColorClass(int inRed, int inGreen, int inBlue)
{
    doClipValue(inRed, inGreen, inBlue);

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

bool ColorClass::setTo(int inRed, int inGreen, int inBlue)
{
    bool doClipp = false;

    doClipp = doClipValue(inRed, inGreen, inBlue);

    redValue = inRed;
    greenValue = inGreen;
    blueValue = inBlue;

    return doClipp;
}

bool ColorClass::setTo(ColorClass &inColor)
{
    redValue = inColor.redValue;
    greenValue = inColor.greenValue;
    blueValue = inColor.blueValue;

    return false;
}

bool ColorClass::addColor(ColorClass &rhs)
{
    bool doClipp = false;

    redValue += rhs.redValue;
    greenValue += rhs.greenValue;
    blueValue += rhs.blueValue;

    doClipp = doClipValue(redValue, greenValue, blueValue);

    return doClipp;
}

bool ColorClass::subtractColor(ColorClass &rhs)
{
    bool doClipp = false;

    redValue -= rhs.redValue;
    greenValue -= rhs.greenValue;
    blueValue -= rhs.blueValue;

    doClipp = doClipValue(redValue, greenValue, blueValue);

    return doClipp;
}

bool ColorClass::adjustBrightness(const double adjFactor)
{
    bool doClipp = false;

    redValue = int(redValue * adjFactor);
    greenValue = int(greenValue * adjFactor);
    blueValue = int(blueValue * adjFactor);

    doClipp = doClipValue(redValue, greenValue, blueValue);

    return doClipp;
}

void ColorClass::printComponentValues()
{
    cout << "R: " << redValue << " G: " << greenValue << " B: "
         << blueValue;
}

bool ColorClass::doClipValue(int &inRed, int &inGreen, int &inBlue)
{
    bool doClipp = false;

    doClipp = (clipValue(inRed) || doClipp);
    doClipp = (clipValue(inGreen) || doClipp);
    doClipp = (clipValue(inBlue) || doClipp);

    return doClipp;
}

int ColorClass::clipValue(int &colorValue)
{
    if (colorValue > MAXIMUM_COLOR_VALUE)
    {
        // clip color values higher than the allowed maximum
        colorValue = MAXIMUM_COLOR_VALUE;
        return true;
    }
    if (colorValue < MINIMUM_COLOR_VALUE)
    {
        // clip color values lower than the allowed minimum
        colorValue = MINIMUM_COLOR_VALUE;
        return true;
    }
    return false;
}