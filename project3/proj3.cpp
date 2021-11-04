//library
#include <iostream>
#include <fstream>
#include <string>
#include "constants.h"
#include "PPMImageClass.h"
#include "ModifyFunction.h"
using namespace std;

//program header
//Name: Ryutaro Hashimoto
//Date: October 12, 2021
//purpose: This program will define color image class. Image is composed of a
//collection of pixels. Colors are described by RGB values.


int main()
{
    bool isProgramContinue = true;
    int commandChoice;
    PPMImageClass Image;
    string path;

    // Firstly, read original image from PPM file
    if (!(loadPPMImage(Image)))
    {
        return 1;
    }

    // read command and execute
    while (isProgramContinue)
    {
        cout << "1. Annotate image with rectangle" << endl;
        cout << "2. Annotate image with pattern from file" << endl;
        cout << "3. Insert another " << endl;
        cout << "4. Write out current image" << endl;
        cout << "5. Exit the program" << endl;

        getInputVale(commandChoice, "Enter int for main menu choice: ");
        while (commandChoice > 5 || commandChoice < 1)
        {
            cout << "Input value " << commandChoice << " is out of valid range. Choose from 1~5" << endl;
            getInputVale(commandChoice, "Try again - Enter int for main menu choice: ");
        }

        if (commandChoice == 1)
        {
            annotateImageRectangle(Image);
        }
        else if (commandChoice == 2)
        {
            annotateImagePattern(Image);
        }
        else if (commandChoice == 3)
        {
            insertAnotherImage(Image);
        }
        else if (commandChoice == 4)
        {
            outputPPMImage(Image);
        }
        else if (commandChoice == 5)
        {
            isProgramContinue = false;
        }
    }
    




    cout << "Thank you for using this program " << endl;
    return 0;
}
