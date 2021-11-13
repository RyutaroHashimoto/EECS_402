#include "PPMImageClass.h"

//program header
//Name: Ryutaro Hashimoto
//Date: November 4, 2021
//purpose: This program will define "PPMImageClass" class and its method.

PPMImageClass::PPMImageClass()
{
    // default maximum color value is defined as global variables
    maxColorValue = MAXIMUM_COLOR_VALUE;

    ColorImage = ColorImageClass();
}

PPMImageClass::PPMImageClass(int inHeight, int inWidth)
{
    ColorImage.setHeight(inHeight);
    ColorImage.setHeight(inWidth);
    maxColorValue = MAXIMUM_COLOR_VALUE;

    ColorImage = ColorImageClass(ColorImage.getHeight(), ColorImage.getWidth());
}

bool PPMImageClass::readPPMFile(const string path)
{
    ifstream inFile;
    string imageType;
    int red;
    int green;
    int blue;
    int inHeight;
    int inWeight;

    inFile.open(path.c_str());

    // Check whether open input file or not.
    if (inFile.fail())
    {
        cout << "Unable to open input file!" << endl;
        cout << "File path may be wrong." << endl;
        cout << "Input file path: " << path << endl;
        return false;
    }

    // Read magic number of image file.
    if (readValue(imageType, inFile))
    {
        if (imageType != PPM_IMAGE_MAGIC_NUMBER)
        {
            cout << "Magic number of file is not " << PPM_IMAGE_MAGIC_NUMBER
                 << "!" << endl;
            cout << "Check magic number." << endl;
            cout << "Magic number of inout file: " << imageType << endl;
            inFile.close();
            return false;
        }
    }
    else
    {
        cout << "Program can't find Magic number! Check format of file."
             << endl;
        inFile.close();
        return false;
    }

    // Read height of image.
    if (!(readValue(inWeight, inFile) && readValue(inHeight, inFile)))
    {
        cout << "Program can't find size of image! Check format of file."
             << endl;
        inFile.close();
        return false;
    }

    // read the maximum value in the color descriptions.
    if (!(readValue(maxColorValue, inFile)))
    {
        {
            cout << "Program can't find maximum value in the color \
descriptions! Check format of file."
                 << endl;
            inFile.close();
            return false;
        }
    }

    // read contents of image
    ColorImage = ColorImageClass(inHeight, inWeight);
    ColorClass ColorValue;

    for (int rIdx = 0; rIdx < ColorImage.getHeight(); rIdx++)
    {
        for (int cIdx = 0; cIdx < ColorImage.getWidth(); cIdx++)
        {
            if (!(readValue(red, inFile) && readValue(green, inFile) &&
                  readValue(blue, inFile)))
            {
                inFile.close();
                return false;
            }

            if (!(MINIMUM_COLOR_VALUE <= red && red <= maxColorValue &&
                  MINIMUM_COLOR_VALUE <= green && green <= maxColorValue &&
                  MINIMUM_COLOR_VALUE <= blue && blue <= maxColorValue))
            {
                cout << "At least, one of RGB value is out of valid range."
                     << endl;
                cout << "Check the input value." << endl;
                inFile.close();
                return false;
            }

            ColorValue.setTo(red, green, blue);
            ColorImage.setColorAtLocation(rIdx, cIdx, ColorValue);
        }
    }
    inFile.close();
    return true;
}

bool PPMImageClass::writePPMFile(const string path)
{
    ColorClass currentColor;
    ofstream outFile;

    outFile.open(path.c_str());
    if (outFile.fail())
    {
        cout << "Unable to open output file" << endl;
        cout << "File path may be wrong." << endl;
        cout << "Input file path: " << path << endl;
        outFile.close();
        return false;
    }

    outFile << PPM_IMAGE_MAGIC_NUMBER << endl;
    outFile << ColorImage.getWidth() << " " << ColorImage.getHeight() << endl;
    outFile << maxColorValue << endl;

    for (int rIdx = 0; rIdx < ColorImage.getHeight(); rIdx++)
    {
        for (int cIdx = 0; cIdx < ColorImage.getWidth() - 1; cIdx++)
        {
            ColorImage.getColorAtLocation(rIdx, cIdx, currentColor);
            outFile << currentColor.getRedValue() << " ";
            outFile << currentColor.getGreenValue() << " ";
            outFile << currentColor.getBlueValue() << " ";
        }
        ColorImage.getColorAtLocation(rIdx, ColorImage.getWidth() - 1,
                                      currentColor);
        outFile << currentColor.getRedValue() << " ";
        outFile << currentColor.getGreenValue() << " ";
        outFile << currentColor.getBlueValue() << endl;
    }

    outFile.close();
    cout << "Output succeed!" << endl;
    return true;
}

int PPMImageClass::getHeight()
{
    return ColorImage.getHeight();
}

int PPMImageClass::getWidth()
{
    return ColorImage.getWidth();
}

int PPMImageClass::getMaxColorValue()
{
    return maxColorValue;
}

void PPMImageClass::getColorAtLocation(int rowIdx, int colIdx,
                                       ColorClass &outColor)
{
    ColorImage.getColorAtLocation(rowIdx, colIdx, outColor);
}

void PPMImageClass::setColorAtLocation(int rowIdx, int colIdx,
                                       ColorClass &inColor)
{
    ColorImage.setColorAtLocation(rowIdx, colIdx, inColor);
}

int PPMImageClass::getRed(int rowIdx, int colIdx)
{
    return ColorImage.getRed(rowIdx, colIdx);
}

int PPMImageClass::getGreen(int rowIdx, int colIdx)
{
    return ColorImage.getGreen(rowIdx, colIdx);
}

int PPMImageClass::getBlue(int rowIdx, int colIdx)
{
    return ColorImage.getBlue(rowIdx, colIdx);
}

void PPMImageClass::ClearMemory()
{
    ColorImage.ClearMemory();
}
