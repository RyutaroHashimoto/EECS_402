//library
#include <iostream>
#include "constants.h"
#include "ColorClass.h"
#include "PPMImageClass.h"
#include "ModifyFunction.h"
using namespace std;

//program header
//Name: Ryutaro Hashimoto
//Date: October 12, 2021
//purpose: This program will define color class. Colors are described by RGB
//values.

bool loadPPMImage(PPMImageClass &Image)
{
    string path;

    getInputVale(path, "Enter string for PPM image file name to load: ");
    if (!(Image.readPPMFile(path)))
    {
        return false;
    }

    return true;
}

void annotateImageRectangle(PPMImageClass &Image)
{
    int commandChoice;
    int rowUpperLeft;
    int colUpperLeft;
    int rowLowerRight;
    int colLowerRight;
    bool doFillIn;

    int rowIdx;
    int colIdx;
    int nRow = 0;
    int nCol = 0;

    ColorClass rectangleColor;

    // input how to decide position and size
    cout << "1. Specify upper left and lower right corners of rectangle" << endl;
    cout << "2. Specify upper left corner and dimensions of rectangle" << endl;
    cout << "3. Specify extent from center of rectangle" << endl;

    getInputVale(commandChoice, "Enter int for rectangle specification method: ");
    while (commandChoice > 3 || commandChoice < 1)
    {
        cout << "Input value " << commandChoice << " is out of valid range. Choose from 1~3" << endl;
        getInputVale(commandChoice, "Try again - Enter int for rectangle specification method: ");
    }

    // Get information of rectangle
    if (commandChoice == 1)
    {
        getInputVale(rowIdx, colIdx, "Enter upper left corner row and column: ");
        while (rowIdx < 0 || colIdx < 0 || 
                    rowIdx > Image.getHeight() || colIdx > Image.getWidth())
        {
            cout << "Input value " << rowIdx << " " << colIdx << " is out of valid range.Try again " << endl;
            getInputVale(rowIdx, colIdx, "Enter upper left corner row and column: ");
        }

        rowUpperLeft = rowIdx;
        colUpperLeft = colIdx;

        getInputVale(rowIdx, colIdx, "Enter lower left corner row and column: ");
        while (rowIdx < 0 || colIdx < 0 ||
               rowIdx > Image.getHeight() || colIdx > Image.getWidth())
        {
            cout << "Input value " << rowIdx << " " << colIdx << " is out of valid range.Try again " << endl;
            getInputVale(rowIdx, colIdx, "Enter lower left corner row and column: ");
        }

        rowLowerRight = rowIdx;
        colLowerRight = colIdx;
    }
    else if (commandChoice == 2)
    {
        getInputVale(rowIdx, colIdx, "Enter upper left corner row and column: ");
        while (rowIdx < 0 || colIdx < 0 ||
               rowIdx > Image.getHeight() || colIdx > Image.getWidth())
        {
            cout << "Input value " << rowIdx << " " << colIdx << " is out of valid range.Try again " << endl;
            getInputVale(rowIdx, colIdx, "Enter upper left corner row and column: ");
        }

        getInputVale(nRow, "Enter int for number of rows: ");
        while (nRow < 0 || nRow > Image.getHeight())
        {
            cout << "Input value " << nRow << " is out of valid range. Try again" << endl;
            getInputVale(nRow, "Enter int for number of rows: ");
        }

        getInputVale(nCol, "Enter int for number of columns: ");
        while (nCol < 0 || nCol > Image.getHeight())
        {
            cout << "Input value " << nCol << " is out of valid range. Try again" << endl;
            getInputVale(nCol, "Enter int for number of columns: ");
        }

        rowUpperLeft = rowIdx;
        colUpperLeft = colIdx;
        rowLowerRight = rowIdx + nRow;
        colLowerRight = colIdx + nCol;
    }
    else
    {
        getInputVale(rowIdx, colIdx, "Enter rectangle center row and column: ");
        while (rowIdx < 0 || colIdx < 0 ||
               rowIdx > Image.getHeight() || colIdx > Image.getWidth())
        {
            cout << "Input value " << rowIdx << " " << colIdx << " is out of valid range.Try again " << endl;
            getInputVale(rowIdx, colIdx, "Enter rectangle center row and column: ");
        }

        getInputVale(nRow, "Enter int for half number of rows: ");
        while (nRow < 0 || nRow > Image.getHeight())
        {
            cout << "Input value " << nRow << " is out of valid range. Try again" << endl;
            getInputVale(nRow, "Enter int for half number of rows: ");
        }

        getInputVale(nCol, "Enter int for half number of columns: ");
        while (nCol < 0 || nCol > Image.getWidth())
        {
            cout << "Input value " << nCol << " is out of valid range. Try again" << endl;
            getInputVale(nCol, "Enter int for half number of columns: ");
        }

        rowUpperLeft = rowIdx - nRow;
        colUpperLeft = colIdx - nCol;
        rowLowerRight = rowIdx + nRow;
        colLowerRight = colIdx + nCol;
    }

    if (rowLowerRight > Image.getHeight() || colLowerRight > Image.getWidth())
    {
        cout << "Error. The size of rectangle is bigger than original Image." << endl;
        cout << "Nothing to be done." << endl;
        return;
    }

    // Get color of rectangle
    cout << "1. Red" << endl;
    cout << "2. Green" << endl;
    cout << "3. Blue" << endl;
    cout << "4. Black" << endl;
    cout << "5. White" << endl;

    getInputVale(commandChoice, "Enter int for rectangle color: ");
    while (commandChoice > 5 || commandChoice < 1)
    {
        cout << "Input value " << commandChoice << " is out of valid range. Choose from 1~5" << endl;
        getInputVale(commandChoice, "Try again - Enter int for rectangle color: ");
    }

    if (commandChoice == 1)
        rectangleColor.setToRed(Image.getMaxColorValue());
    else if (commandChoice == 2)
        rectangleColor.setToGreen(Image.getMaxColorValue());
    else if (commandChoice == 3)
        rectangleColor.setToBlue(Image.getMaxColorValue());
    else if (commandChoice == 4)
        rectangleColor.setToBlack(Image.getMaxColorValue());
    else if (commandChoice == 5)
        rectangleColor.setToWhite(Image.getMaxColorValue());

    // Get choice whether fill in or not.
    cout << "1. no" << endl;
    cout << "2. Yes" << endl;

    getInputVale(commandChoice, "Enter int for rectangle fill option: ");
    while (commandChoice > 2 || commandChoice < 1)
    {
        cout << "Input value " << commandChoice << " is out of valid range. Choose from 1~2" << endl;
        getInputVale(commandChoice, "Try again - Enter int for rectangle fill option: ");
    }

    if (commandChoice == 1)
        doFillIn = false;
    else
        doFillIn = true;

    // do annotation
    if (doFillIn)
    {
        for (int i = rowUpperLeft; i <= rowLowerRight; i++)
        {
            for (int j = colUpperLeft; j <= colLowerRight; j++)
            {
                Image.setColorAtLocation(i, j, rectangleColor);
            }
        }
    }
    else
    {
        // top line
        for (int j = colUpperLeft; j <= colLowerRight; j++)
        {
            Image.setColorAtLocation(rowUpperLeft, j, rectangleColor);
        }

        // left line
        for (int i = rowUpperLeft + 1; i < rowLowerRight; i++)
        {
            Image.setColorAtLocation(i, colUpperLeft, rectangleColor);
        }

        // right line
        for (int i = rowUpperLeft + 1; i < rowLowerRight; i++)
        {
            Image.setColorAtLocation(i, colLowerRight, rectangleColor);
        }

        // bottom line
        for (int j = colUpperLeft; j <= colLowerRight; j++)
        {
            Image.setColorAtLocation(rowLowerRight, j, rectangleColor);
        }
    }

    return;
}

void annotateImagePattern(PPMImageClass &Image)
{
    ColorClass patternColor;
    string path;
    ifstream inFile;
    int heightPattern;  
    int widthPattern;
    int value;
    int rowIdx;
    int colIdx;
    int commandChoice;

    getInputVale(path, "Enter string for file name containing pattern: ");

    // read pattern from text file
    inFile.open(path.c_str());

    // Check whether open input file or not .
    if (inFile.fail())
    {
        cout << "Unable to open input file!" << endl;
        cout << "File path may be wrong." << endl;
        cout << "Input file path: " << path << endl;
        return;
    }

    // Read height of image.
    if (!(readValue(widthPattern, inFile) && readValue(heightPattern, inFile)))
    {
        cout << "Program can't find size of image! Check format of file." << endl;
        inFile.close();
        return;
    } 

    // Check size of pattern
    if (heightPattern > Image.getHeight() || widthPattern > Image.getWidth())
    {
        cout << "Error. Size of pattern is bigger than original image." << endl;
        inFile.close();
        return;
    }

    // Read the pattern
    // Dynamic memory allocation
    int **pattern;
    pattern = new int *[heightPattern];
    for (int rIdx = 0; rIdx < heightPattern; rIdx++)
    {
        pattern[rIdx] = new int[widthPattern];
    }

    for (int rIdx = 0; rIdx < heightPattern; rIdx++)
    {
        for (int cIdx = 0; cIdx < widthPattern; cIdx++)
        {
            if (!readValue(value, inFile))
            {
                inFile.close();
                return;
            }
            pattern[rIdx][cIdx] = value;
        }
    }

    // Get annotated position
    getInputVale(rowIdx, colIdx, "Enter upper left corner to pattern row and column: ");
    while (rowIdx < 0 || colIdx < 0 ||
           rowIdx + heightPattern > Image.getHeight() || colIdx + widthPattern > Image.getWidth())
    {
        cout << "Input value " << rowIdx << " " << colIdx << " is out of valid range.Try again " << endl;
        getInputVale(rowIdx, colIdx, "Enter upper left corner to insert image row and column: ");
    }

    // Get annotated color
    cout << "1. Red" << endl;
    cout << "2. Green" << endl;
    cout << "3. Blue" << endl;
    cout << "4. Black" << endl;
    cout << "5. White" << endl;

    getInputVale(commandChoice, "Enter int for transparecy color: ");
    while (commandChoice > 5 || commandChoice < 1)
    {
        cout << "Input value " << commandChoice << " is out of valid range. Choose from 1~5" << endl;
        getInputVale(commandChoice, "Try again - Enter int for transparecy color: ");
    }

    if (commandChoice == 1)
        patternColor.setToRed(Image.getMaxColorValue());
    else if (commandChoice == 2)
        patternColor.setToGreen(Image.getMaxColorValue());
    else if (commandChoice == 3)
        patternColor.setToBlue(Image.getMaxColorValue());
    else if (commandChoice == 4)
        patternColor.setToBlack(Image.getMaxColorValue());
    else if (commandChoice == 5)
        patternColor.setToWhite(Image.getMaxColorValue());

    // Execute annotate pattern
    for (int i = 0; i < heightPattern; i++)
    {
        for (int j = 0; j < widthPattern; j++)
        {
            //check whether current pixel is annotated or not
            if (pattern[i][j] == 1)
            {
                Image.setColorAtLocation(i + rowIdx, j + colIdx, patternColor);
            }
        }
    }

    return;
}

void insertAnotherImage(PPMImageClass &Image)
{
    PPMImageClass anotherImage;
    ColorClass transparancyColor;
    ColorClass currentColor;
    string path;

    int rowIdx;
    int colIdx;

    int commandChoice;

    // read annotate Image from ppm file
    getInputVale(path, "Enter string for PPM file name to output:");
    if (!(anotherImage.readPPMFile(path)))
    {
        getInputVale(commandChoice, "Try again - Enter string for PPM file name to output: ");
    }

    // get annotated position
    getInputVale(rowIdx, colIdx, "Enter upper left corner to insert image row and column: ");
    while (rowIdx < 0 || colIdx < 0 ||
           rowIdx > Image.getHeight() || colIdx > Image.getWidth())
    {
        cout << "Input value " << rowIdx << " " << colIdx << " is out of valid range.Try again " << endl;
        getInputVale(rowIdx, colIdx, "Enter upper left corner to insert image row and column: ");
    }

    // check size of another image and position
    if (rowIdx + anotherImage.getHeight() > Image.getHeight() || colIdx + anotherImage.getWidth() > Image.getWidth())
    {
        cout << "Error. Inserting image is too big to insert at specified position." << endl;
        return;
    }

    // get transparecy color
    cout << "1. Red" << endl;
    cout << "2. Green" << endl;
    cout << "3. Blue" << endl;
    cout << "4. Black" << endl;
    cout << "5. White" << endl;

    getInputVale(commandChoice, "Enter int for transparecy color: ");
    while (commandChoice > 5 || commandChoice < 1)
    {
        cout << "Input value " << commandChoice << " is out of valid range. Choose from 1~5" << endl;
        getInputVale(commandChoice, "Try again - Enter int for transparecy color: ");
    }

    if (commandChoice == 1)
        transparancyColor.setToRed(Image.getMaxColorValue());
    else if (commandChoice == 2)
        transparancyColor.setToGreen(Image.getMaxColorValue());
    else if (commandChoice == 3)
        transparancyColor.setToBlue(Image.getMaxColorValue());
    else if (commandChoice == 4)
        transparancyColor.setToBlack(Image.getMaxColorValue());
    else if (commandChoice == 5)
        transparancyColor.setToWhite(Image.getMaxColorValue());

    // Do insert another image
    for (int i = 0; i < anotherImage.getHeight(); i++)
    {
        for (int j = 0; j < anotherImage.getWidth(); j++)
        {
            //check whether current pixel is transparancy or not
            anotherImage.getColorAtLocation(i, j, currentColor);
            if (currentColor.getRedValue() == transparancyColor.getRedValue() ||
                currentColor.getBlueValue() == transparancyColor.getBlueValue() ||
                currentColor.getGreenValue() == transparancyColor.getGreenValue())
            {
                continue;
            }
            else{
                Image.setColorAtLocation(i + rowIdx, j + colIdx, currentColor);
            }
        }
    }

    return;
}

void outputPPMImage(PPMImageClass Image)
{
    string path;

    getInputVale(path, "Enter string for PPM file name to output: ");
    if (!(Image.writePPMFile(path)))
    {
        getInputVale(path, "Enter string for PPM file name to output: ");
    }
}
