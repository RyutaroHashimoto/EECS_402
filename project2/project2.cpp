//library
#include <iostream>
using namespace std;

//program header
//Name: Ryutaro Hashimoto
//Date: October 12, 2021
//purpose: This program will define color image class. Image is composed of a
//collection of pixels. Colors re described by RGB values.

//global constant
const int MAXIMUM_COLOR_VALUE = 1000;
const int MINIMUM_COLOR_VALUE = 0;
const int DEFAULT_ROW_VALUE = -99999;
const int DEFAULT_COL_VALUE = -99999;
const int DEFAULT_IMAGE_HEIGHT = 10;
const int DEFAULT_IMAGE_WIDTH = 18;

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

    // do clip three color value and eturn whether clipped or not
    bool doClipValue(int &inRed, int &inGreen, int &inBlue);

    // clip value of color so that values is within the valid range and
    int clipValue(int &colorValue);
};

class RowColumnClass
{
public:
    // Initiialy set to -99999 (-99999, -99999)
    RowColumnClass();

    // Initiialy set to specific value with input (inRow, inCol)
    RowColumnClass(int inRow, int inCol);

    // Set value values to specific value
    void setRowCol(int inRow, int inCol);

    // Set row values to specific value
    void setRow(int inRow);

    // Set columns values to specific value
    void setCol(int inCol);

    // Get row value
    int getRow();

    // Get columns value
    int getCol();

    // adds the index values in the input parameter to the objects
    void addRowColTo(RowColumnClass &inRowCol);

    // print current value
    void printRowCol();

private:
    // row and columns index value
    int rowValue;
    int colValue;
};

class ColorImageClass
{
public:
    // Initiialy set black image
    ColorImageClass();

    // Initiialy set all image pixel to the color provided
    void initializeTo(ColorClass &inColor);

    // pixel-wise addition (return true if at least one pixel clipped)
    bool addImageTo(ColorImageClass &rhsImg);

    // pixel values to be set to the sum of the corresponding pixels in
    // each image in the imagesToAdd
    bool addImages(int numImgsToAdd, ColorImageClass imagesToAdd[]);

    //  set the pixel at the location specified to the color provided
    bool setColorAtLocation(RowColumnClass &inRowCol, ColorClass &inColor);

    // get color at provided row/col index location if valid
    bool getColorAtLocation(RowColumnClass &inRowCol, ColorClass &outColor);

    // print contents of the image
    void printImage();

private:
    ColorClass imagePixelColor[DEFAULT_IMAGE_HEIGHT][DEFAULT_IMAGE_WIDTH];
};

#ifdef ANDREW_TEST
#include "andrewTest.h"
#else
int main()
{
    ColorClass testColor;
    RowColumnClass testRowCol;
    RowColumnClass testRowColOther(111, 222);
    ColorImageClass testImage;
    ColorImageClass testImages[3];

    //Test some basic ColorClass operations...
    cout << "Initial: ";
    testColor.printComponentValues();
    cout << endl;

    testColor.setToBlack();
    cout << "Black: ";
    testColor.printComponentValues();
    cout << endl;

    testColor.setToGreen();
    cout << "Green: ";
    testColor.printComponentValues();
    cout << endl;

    testColor.adjustBrightness(0.5);
    cout << "Dimmer Green: ";
    testColor.printComponentValues();
    cout << endl;

    //Test some basic RowColumnClass operations...
    cout << "Want defaults: ";
    testRowCol.printRowCol();
    cout << endl;

    testRowCol.setRowCol(2, 8);
    cout << "Want 2,8: ";
    testRowCol.printRowCol();
    cout << endl;

    cout << "Want 111, 222: ";
    testRowColOther.printRowCol();
    cout << endl;

    testRowColOther.setRowCol(4, 2);
    testRowCol.addRowColTo(testRowColOther);
    cout << "Want 6,10: ";
    testRowCol.printRowCol();
    cout << endl;

    //Test some basic ColorImageClass operations...
    testColor.setToRed();
    testImage.initializeTo(testColor);

    testRowCol.setRowCol(555, 5);
    cout << "Want: Color at [555,5]: Invalid Index!" << endl;
    cout << "Color at ";
    testRowCol.printRowCol();
    cout << ": ";
    if (testImage.getColorAtLocation(testRowCol, testColor))
    {
        testColor.printComponentValues();
    }
    else
    {
        cout << "Invalid Index!";
    }
    cout << endl;

    testRowCol.setRow(4);
    cout << "Want: Color at [4,5]: R: 1000 G: 0 B: 0" << endl;
    cout << "Color at ";
    testRowCol.printRowCol();
    cout << ": ";
    if (testImage.getColorAtLocation(testRowCol, testColor))
    {
        testColor.printComponentValues();
    }
    else
    {
        cout << "Invalid Index!";
    }
    cout << endl;

    //Set up an array of images of different colors
    testColor.setToRed();
    testColor.adjustBrightness(0.25);
    testImages[0].initializeTo(testColor);
    testColor.setToBlue();
    testColor.adjustBrightness(0.75);
    testImages[1].initializeTo(testColor);
    testColor.setToGreen();
    testImages[2].initializeTo(testColor);

    //Modify a few individual pixel colors
    testRowCol.setRowCol(4, 2);
    testColor.setToWhite();
    testImages[1].setColorAtLocation(testRowCol, testColor);

    testRowCol.setRowCol(2, 4);
    testColor.setToBlack();
    testImages[2].setColorAtLocation(testRowCol, testColor);

    //Add up all images in testImages array and assign result
    //to the testImage image
    testImage.addImages(3, testImages);

    //Check some certain values
    cout << "Added values:" << endl;
    for (int colInd = 0; colInd < 8; colInd += 2)
    {
        testRowCol.setRowCol(4, colInd);
        cout << "Color at ";
        testRowCol.printRowCol();
        cout << ": ";
        if (testImage.getColorAtLocation(testRowCol, testColor))
        {
            testColor.printComponentValues();
        }
        else
        {
            cout << "Invalid Index!";
        }
        cout << endl;
    }

    for (int rowInd = 0; rowInd < 8; rowInd += 2)
    {
        testRowCol.setRowCol(rowInd, 4);
        cout << "Color at ";
        testRowCol.printRowCol();
        cout << ": ";
        if (testImage.getColorAtLocation(testRowCol, testColor))
        {
            testColor.printComponentValues();
        }
        else
        {
            cout << "Invalid Index!";
        }
        cout << endl;
    }

    cout << "Printing entire test image:" << endl;
    testImage.printImage();

    return 0;
}
#endif

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

RowColumnClass::RowColumnClass()
{
    rowValue = DEFAULT_ROW_VALUE;
    colValue = DEFAULT_COL_VALUE;
}

RowColumnClass::RowColumnClass(int inRow, int inCol)
{
    rowValue = inRow;
    colValue = inCol;
}

void RowColumnClass::setRowCol(int inRow, int inCol)
{
    rowValue = inRow;
    colValue = inCol;
}

void RowColumnClass::setRow(int inRow)
{
    rowValue = inRow;
}

void RowColumnClass::setCol(int inCol)
{
    colValue = inCol;
}

int RowColumnClass::getRow()
{
    return rowValue;
}

int RowColumnClass::getCol()
{
    return colValue;
}

void RowColumnClass::addRowColTo(RowColumnClass &inRowCol)
{
    rowValue += inRowCol.rowValue;
    colValue += inRowCol.colValue;
}

void RowColumnClass::printRowCol()
{
    cout << "[" << rowValue << "," << colValue << "]";
}

ColorImageClass::ColorImageClass()
{
    ColorClass defaultColor;
    // default color of imgae is black
    defaultColor.setToBlack();

    // make all pixel black
    for (int i = 0; i < DEFAULT_IMAGE_HEIGHT; i++)
    {
        for (int j = 0; j < DEFAULT_IMAGE_WIDTH; j++)
        {
            imagePixelColor[i][j] = defaultColor;
        }
    }
}

void ColorImageClass::initializeTo(ColorClass &inColor)
{
    for (int i = 0; i < DEFAULT_IMAGE_HEIGHT; i++)
    {
        for (int j = 0; j < DEFAULT_IMAGE_WIDTH; j++)
        {
            imagePixelColor[i][j].setTo(inColor);
        }
    }
}

bool ColorImageClass::addImageTo(ColorImageClass &rhsImg)
{
    bool doClip = false;
    for (int i = 0; i < DEFAULT_IMAGE_HEIGHT; i++)
    {
        for (int j = 0; j < DEFAULT_IMAGE_WIDTH; j++)
        {
            doClip = (imagePixelColor[i][j].addColor(
                          rhsImg.imagePixelColor[i][j]) ||
                      doClip);
        }
    }
    return doClip;
}

bool ColorImageClass::addImages(int numImgsToAdd,
                                ColorImageClass imagesToAdd[])
{
    bool doClip = false;
    for (int i = 0; i < DEFAULT_IMAGE_HEIGHT; i++)
    {
        for (int j = 0; j < DEFAULT_IMAGE_WIDTH; j++)
        {
            // At first, reset current color value
            imagePixelColor[i][j].setToBlack();

            for (int k = 0; k < numImgsToAdd; k++)
            {
                // add color value of each imagesToAdd
                doClip = (imagePixelColor[i][j].addColor(
                              imagesToAdd[k].imagePixelColor[i][j]) ||
                          doClip);
            }
        }
    }
    return doClip;
}

bool ColorImageClass::setColorAtLocation(RowColumnClass &inRowCol,
                                         ColorClass &inColor)
{
    if (DEFAULT_IMAGE_HEIGHT < inRowCol.getRow() ||
        DEFAULT_IMAGE_WIDTH < inRowCol.getCol())
    {
        // input location is out of range
        return false;
    }

    imagePixelColor[inRowCol.getRow()][inRowCol.getCol()].setTo(inColor);
    return true;
}

bool ColorImageClass::getColorAtLocation(RowColumnClass &inRowCol,
                                         ColorClass &outColor)
{
    if (DEFAULT_IMAGE_HEIGHT < inRowCol.getRow() ||
        DEFAULT_IMAGE_WIDTH < inRowCol.getCol())
    {
        // input location is out of range
        return false;
    }

    outColor.setTo(imagePixelColor[inRowCol.getRow()][inRowCol.getCol()]);
    return true;
}

void ColorImageClass::printImage()
{
    for (int i = 0; i < DEFAULT_IMAGE_HEIGHT; i++)
    {
        for (int j = 0; j < DEFAULT_IMAGE_WIDTH - 1; j++)
        {
            imagePixelColor[i][j].printComponentValues();
            cout << "--";
        }
        // last pixel
        imagePixelColor[i][DEFAULT_IMAGE_WIDTH - 1].printComponentValues();
        cout << endl;
    }
}