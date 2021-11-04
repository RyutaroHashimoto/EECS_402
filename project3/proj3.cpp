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
//purpose: This program will read/write PPM format image and modify it.
//If base image can't be read correctly, program will exit with error 1.
//Then, program will continue until users input the exit command, 
//then program will exit with .0  

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

    // get command and execute
    while (isProgramContinue)
    {
        cout << "1. Annotate image with rectangle" << endl;
        cout << "2. Annotate image with pattern from file" << endl;
        cout << "3. Insert another " << endl;
        cout << "4. Write out current image" << endl;
        cout << "5. Exit the program" << endl;

        getInputVale(commandChoice, "Enter int for main menu choice: ");

        if (commandChoice == CHOICE_OF_ANNOTATE_IMAGE_WITH_RECTANGLE)
        {
            annotateImageRectangle(Image);
        }
        else if (commandChoice == CHOICE_OF_ANNOTATE_IMAGE_WITH_PATTERN)
        {
            annotateImagePattern(Image);
        }
        else if (commandChoice == CHOICE_OF_INSERT_ANOTHER)
        {
            insertAnotherImage(Image);
        }
        else if (commandChoice == CHOICE_OF_WRITE_OUT_CURRENT_IMAGE)
        {
            outputPPMImage(Image);
        }
        else if (commandChoice == CHOICE_OF_EXIT_THE_PROGRAM)
        {
            isProgramContinue = false;
        }
        else{
            cout << "Input value " 
                << commandChoice 
                << " is out of valid range. Choose from menu" << endl;
            getInputVale(commandChoice, 
                "Try again - Enter int for main menu choice: ");
        }
    }
    
    cout << "Thank you for using this program " << endl;
    return 0;
}
