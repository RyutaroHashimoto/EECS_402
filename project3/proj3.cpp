//library
#include <iostream>
#include <fstream>
#include <string>
#include "constants.h"
#include "PPMImageClass.h"
#include "UtilsFunction.h"
using namespace std;

//program header
//Name: Ryutaro Hashimoto
//Date: October 12, 2021
//purpose: This program will define color image class. Image is composed of a
//collection of pixels. Colors are described by RGB values.

bool readPPMFile(const string path);

int main()
{
    int numRow = 3;
    int numCol = 3;

    ColorImageClass temp_img;

    temp_img = ColorImageClass(numRow, numCol);

    temp_img.printImage();

    cout << PPM_IMAGE_MAGIC_NUMBER << endl;

    PPMImageClass sample_img;
    sample_img = PPMImageClass(2, 3);

    readPPMFile("sample/small.ppm");
}

bool readPPMFile(const string path)
{
    ifstream inFile;
    string imageType;
    int height;
    int width;
    int red;
    int green;
    int blue;
    int maxColorValue;

    inFile.open(path);

    // Check file path is right or not
    if (inFile.fail())
    {
        cout << "Unable to open input file!" << endl;
        exit(1);
    }

    inFile >> imageType;
    inFile >> height;
    inFile >> width;
    inFile >> maxColorValue;

    cout << width << endl;


    PPMImageClass Image;
    Image = PPMImageClass(height, width);

    ColorClass ColorValue;

    for (int i = 0; i < height; i++)
    {
        for (int j=0; j < width; j++)
        {
            inFile >> red;
            inFile >> green;
            inFile >> blue;
            ColorValue.setTo(red, green, blue);
            Image.setColorAtLocation(i, j, ColorValue);
        }
    }

    Image.PrintImage();
    return true;
    }