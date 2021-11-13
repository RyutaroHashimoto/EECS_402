#include "ModifyFunction.h"

//program header
//Name: Ryutaro Hashimoto
//Date: November 4, 2021
//purpose: This program will define functions to handle ppm image.

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
    int rowIdx;
    int colIdx;
    int nRow = 0;
    int nCol = 0;
    bool doFillIn;
    bool isValidInput = false;

    ColorClass rectangleColor;

    // input how to decide position and size
    cout << "1. Specify upper left and lower right corners of rectangle"
         << endl;
    cout << "2. Specify upper left corner and dimensions of rectangle" << endl;
    cout << "3. Specify extent from center of rectangle" << endl;

    getInputVale(commandChoice,
                 "Enter int for rectangle specification method: ");
    while (!(isValidInput))
    {
        // Get information of rectangle
        if (commandChoice == CHOICE_OF_SPECIFY_UPPER_LEFT_LOWER_RIGHT_CORNERS)
        {
            isValidInput = true;
            getInputVale(rowIdx, colIdx,
                         "Enter upper left corner row and column: ");
            while (rowIdx < 0 || colIdx < 0 ||
                   rowIdx >= Image.getHeight() || colIdx >= Image.getWidth())
            {
                cout << "Input value " << rowIdx << " " << colIdx
                     << " is out of valid range.Try again " << endl;
                getInputVale(rowIdx, colIdx,
                             "Enter upper left corner row and column: ");
            }

            rowUpperLeft = rowIdx;
            colUpperLeft = colIdx;

            getInputVale(rowIdx, colIdx,
                         "Enter lower left corner row and column: ");
            while (rowIdx < 0 || colIdx < 0 ||
                   rowIdx >= Image.getHeight() || colIdx >= Image.getWidth())
            {
                cout << "Input value " << rowIdx << " " << colIdx
                     << " is out of valid range.Try again " << endl;
                getInputVale(rowIdx, colIdx,
                             "Enter lower left corner row and column: ");
            }

            rowLowerRight = rowIdx;
            colLowerRight = colIdx;

            // Check whether two input points can create rectangle or not.
            if (rowUpperLeft > rowLowerRight || colUpperLeft > colLowerRight)
                {
                    cout << "Error. Input points can't create rectangle" 
                        << endl;
                    return;
                }
        }
        else if (commandChoice == CHOICE_OF_SPECIFY_UP_LEFT_CORNER_DIMENSIONS)
        {
            isValidInput = true;
            getInputVale(rowIdx, colIdx,
                         "Enter upper left corner row and column: ");
            while (rowIdx < 0 || colIdx < 0 ||
                   rowIdx >= Image.getHeight() || colIdx >= Image.getWidth())
            {
                cout << "Input value " << rowIdx << " " << colIdx
                     << " is out of valid range.Try again " << endl;
                getInputVale(rowIdx, colIdx,
                             "Enter upper left corner row and column: ");
            }

            getInputVale(nRow, "Enter int for number of rows: ");
            while (nRow < 1 || nRow > Image.getHeight())
            {
                cout << "Input value " << nRow
                     << " is out of valid range. Try again" << endl;
                getInputVale(nRow, "Enter int for number of rows: ");
            }

            getInputVale(nCol, "Enter int for number of columns: ");
            while (nCol < 1 || nCol > Image.getHeight())
            {
                cout << "Input value " << nCol
                     << " is out of valid range. Try again" << endl;
                getInputVale(nCol, "Enter int for number of columns: ");
            }

            rowUpperLeft = rowIdx;
            colUpperLeft = colIdx;
            rowLowerRight = rowIdx + nRow;
            colLowerRight = colIdx + nCol;
        }
        else if (commandChoice == CHOICE_OF_SPECIFY_SPECIFY_EXTENT_FROM_CENTER)
        {
            isValidInput = true;
            getInputVale(rowIdx, colIdx,
                         "Enter rectangle center row and column: ");
            while (rowIdx < 0 || colIdx < 0 ||
                   rowIdx >= Image.getHeight() || colIdx >= Image.getWidth())
            {
                cout << "Input value " << rowIdx << " "
                     << colIdx << " is out of valid range.Try again " << endl;
                getInputVale(rowIdx, colIdx,
                             "Enter rectangle center row and column: ");
            }

            getInputVale(nRow, "Enter int for half number of rows: ");
            while (nRow < 1 || nRow > Image.getHeight())
            {
                cout << "Input value " << nRow
                     << " is out of valid range. Try again" << endl;
                getInputVale(nRow, "Enter int for half number of rows: ");
            }

            getInputVale(nCol, "Enter int for half number of columns: ");
            while (nCol < 1 || nCol > Image.getWidth())
            {
                cout << "Input value " << nCol
                     << " is out of valid range. Try again" << endl;
                getInputVale(nCol, "Enter int for half number of columns: ");
            }

            rowUpperLeft = rowIdx - nRow;
            colUpperLeft = colIdx - nCol;
            rowLowerRight = rowIdx + nRow;
            colLowerRight = colIdx + nCol;
        }
        else
        {
            cout << "Input value " << commandChoice
                 << " is out of valid range. Choose from menu" << endl;
            getInputVale(commandChoice, "Try again - \
Enter int for rectangle specification method: ");
        }
    }

    // Check the size of rectangle
    if (rowLowerRight >= Image.getHeight() ||
        colLowerRight >= Image.getWidth() ||
        rowUpperLeft < 0 ||
        colUpperLeft < 0)
    {
        cout << "Error. The size of rectangle is bigger than original Image."
             << endl;
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
    isValidInput = false;
    while (!(isValidInput))
    {
        if (commandChoice == CHOICE_OF_RED)
        {
            isValidInput = true;
            rectangleColor.setToRed(Image.getMaxColorValue());
        }
        else if (commandChoice == CHOICE_OF_GREEN)
        {
            isValidInput = true;
            rectangleColor.setToGreen(Image.getMaxColorValue());
        }
        else if (commandChoice == CHOICE_OF_BLUE)
        {
            isValidInput = true;
            rectangleColor.setToBlue(Image.getMaxColorValue());
        }
        else if (commandChoice == CHOICE_OF_BLACK)
        {
            isValidInput = true;
            rectangleColor.setToBlack(Image.getMaxColorValue());
        }
        else if (commandChoice == CHOICE_OF_WHITE)
        {
            isValidInput = true;
            rectangleColor.setToWhite(Image.getMaxColorValue());
        }
        else
        {
            cout << "Input value " << commandChoice
                << " is out of valid range. Choose from menu" << endl;
            getInputVale(commandChoice, "Try again - \
 Enter int for rectangle color: ");
        }
    }


    // Get choice whether fill in or not.
    cout << "1. no" << endl;
    cout << "2. Yes" << endl;

    getInputVale(commandChoice, "Enter int for rectangle fill option: ");
    isValidInput = false;
    while (!(isValidInput))
    {
        if (commandChoice == CHOICE_OF_NOT_FILL_IN)
        {
            doFillIn = false;
            isValidInput = true;
        }
        else if (commandChoice == CHOICE_OF_FILL_IN)
        {
            doFillIn = true;
            isValidInput = true;
        }
        else
        {
            cout << "Input value " << commandChoice
                << " is out of valid range. Choose from 1~2" << endl;
            getInputVale(commandChoice, "Try again -\
    Enter int for rectangle fill option: ");
        }
    }

    // do annotation
    if (doFillIn)
    {
        for (int rIdx = rowUpperLeft; rIdx <= rowLowerRight; rIdx++)
        {
            for (int cIdx = colUpperLeft; cIdx <= colLowerRight; cIdx++)
            {
                Image.setColorAtLocation(rIdx, cIdx, rectangleColor);
            }
        }
    }
    else
    {
        // top line
        for (int cIdx = colUpperLeft; cIdx <= colLowerRight; cIdx++)
        {
            Image.setColorAtLocation(rowUpperLeft, cIdx, rectangleColor);
        }

        // left line
        for (int rIdx = rowUpperLeft + 1; rIdx <= rowLowerRight; rIdx++)
        {
            Image.setColorAtLocation(rIdx, colUpperLeft, rectangleColor);
        }

        // right line
        for (int rIdx = rowUpperLeft + 1; rIdx <= rowLowerRight; rIdx++)
        {
            Image.setColorAtLocation(rIdx, colLowerRight, rectangleColor);
        }

        // bottom line
        for (int cIdx = colUpperLeft; cIdx <= colLowerRight; cIdx++)
        {
            Image.setColorAtLocation(rowLowerRight, cIdx, rectangleColor);
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
    bool isValidInput = false;

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
        cout << "Program can't find size of image! Check format of file."
             << endl;
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
    getInputVale(rowIdx, colIdx,
                 "Enter upper left corner to pattern row and column: ");
    while (rowIdx < 0 || colIdx < 0 ||
           rowIdx + heightPattern >= Image.getHeight() ||
           colIdx + widthPattern >= Image.getWidth())
    {
        cout << "Input value " << rowIdx << " " << colIdx
             << " is out of valid range.Try again " << endl;
        getInputVale(rowIdx, colIdx,
            "Enter upper left corner to insert image row and column: ");
    }

    // Get color of pattern
    cout << "1. Red" << endl;
    cout << "2. Green" << endl;
    cout << "3. Blue" << endl;
    cout << "4. Black" << endl;
    cout << "5. White" << endl;

    getInputVale(commandChoice, "Enter int for pattern color: ");
    isValidInput = false;
    while (!(isValidInput))
    {
        if (commandChoice == CHOICE_OF_RED)
        {
            isValidInput = true;
            patternColor.setToRed(Image.getMaxColorValue());
        }
        else if (commandChoice == CHOICE_OF_GREEN)
        {
            isValidInput = true;
            patternColor.setToGreen(Image.getMaxColorValue());
        }
        else if (commandChoice == CHOICE_OF_BLUE)
        {
            isValidInput = true;
            patternColor.setToBlue(Image.getMaxColorValue());
        }
        else if (commandChoice == CHOICE_OF_BLACK)
        {
            isValidInput = true;
            patternColor.setToBlack(Image.getMaxColorValue());
        }
        else if (commandChoice == CHOICE_OF_WHITE)
        {
            isValidInput = true;
            patternColor.setToWhite(Image.getMaxColorValue());
        }
        else
        {
            cout << "Input value " << commandChoice
                 << " is out of valid range. Choose from menu" << endl;
            getInputVale(commandChoice, "Try again - \
Enter int for pattern color: ");
        }
    }

    // Execute annotate pattern
    for (int rIdx = 0; rIdx < heightPattern; rIdx++)
    {
        for (int cIdx = 0; cIdx < widthPattern; cIdx++)
        {
            //check whether current pixel is annotated or not
            if (pattern[rIdx][cIdx] == 1)
            {
                Image.setColorAtLocation(
                    rIdx + rowIdx, cIdx + colIdx, 
                    patternColor);
            }
        }
    }

    // Clear dynamic allocate memory
    for (int rInd = 0; rInd < heightPattern; rInd++)
    {
        delete[] pattern[rInd];
    }
    delete[] pattern;

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
    bool isValidInput = false;

    // read annotate Image from ppm file
    getInputVale(path, "Enter string for PPM file name to output:");
    if (!(anotherImage.readPPMFile(path)))
    {
        getInputVale(commandChoice,
                     "Try again - Enter string for PPM file name to output: ");
    }

    // get annotated position
    getInputVale(rowIdx, colIdx,
                 "Enter upper left corner to insert image row and column: ");
    while (rowIdx < 0 || colIdx < 0 ||
           rowIdx >= Image.getHeight() || colIdx >= Image.getWidth())
    {
        cout << "Input value " << rowIdx << " " << colIdx
             << " is out of valid range.Try again " << endl;
        getInputVale(rowIdx, colIdx,
            "Enter upper left corner to insert image row and column: ");
    }

    // check size of another image and position
    if (rowIdx + anotherImage.getHeight() > Image.getHeight() ||
        colIdx + anotherImage.getWidth() > Image.getWidth())
    {
        cout << "Error. Inserting image is too big to insert\
 at specified position."
             << endl;
        return;
    }

    // get transparecy color
    cout << "1. Red" << endl;
    cout << "2. Green" << endl;
    cout << "3. Blue" << endl;
    cout << "4. Black" << endl;
    cout << "5. White" << endl;

    getInputVale(commandChoice, "Enter int for transparecy color: ");
    isValidInput = false;
    while (!(isValidInput))
    {
        if (commandChoice == CHOICE_OF_RED)
        {
            isValidInput = true;
            transparancyColor.setToRed(Image.getMaxColorValue());
        }
        else if (commandChoice == CHOICE_OF_GREEN)
        {
            isValidInput = true;
            transparancyColor.setToGreen(Image.getMaxColorValue());
        }
        else if (commandChoice == CHOICE_OF_BLUE)
        {
            isValidInput = true;
            transparancyColor.setToBlue(Image.getMaxColorValue());
        }
        else if (commandChoice == CHOICE_OF_BLACK)
        {
            isValidInput = true;
            transparancyColor.setToBlack(Image.getMaxColorValue());
        }
        else if (commandChoice == CHOICE_OF_WHITE)
        {
            isValidInput = true;
            transparancyColor.setToWhite(Image.getMaxColorValue());
        }
        else
        {
            cout << "Input value " << commandChoice
                 << " is out of valid range. Choose from menu" << endl;
            getInputVale(commandChoice, "Try again - \
Enter int for transparecy color: ");
        }
    }

    // Do insert another image
    for (int rIdx = 0; rIdx < anotherImage.getHeight(); rIdx++)
    {
        for (int cIdx = 0; cIdx < anotherImage.getWidth(); cIdx++)
        {
            //check whether current pixel is transparancy or not
            anotherImage.getColorAtLocation(rIdx, cIdx, currentColor);
            if (currentColor.getRedValue() ==
                    transparancyColor.getRedValue() ||
                currentColor.getBlueValue() ==
                    transparancyColor.getBlueValue() ||
                currentColor.getGreenValue() ==
                    transparancyColor.getGreenValue())
            {
            }
            else
            {
                Image.setColorAtLocation(
                    rIdx + rowIdx, cIdx + colIdx, 
                    currentColor);
            }
        }
    }
    anotherImage.ClearMemory();
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
