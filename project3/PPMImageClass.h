#ifndef _PPMIMAGECLASS_H_
#define _PPMIMAGECLASS_H_

//library
#include <iostream>
#include <fstream>
#include <string>
#include "constants.h"
#include "ColorImageClass.h"
using namespace std;

//program header
//Name: Ryutaro Hashimoto
//Date: October 12, 2021
//purpose: This program will define PPMImageClass class. 

class PPMImageClass
{
public:
    // Initially set black 5 by 5image
    PPMImageClass();

    // Initially set black image with specified size
    PPMImageClass(int inHeight, int inWidth);

    // read image from .ppm file
    bool readPPMFile(const string path);

    // output current colorimage into .ppm file
    bool writePPMFile(const string path);

    // edit color value of specific point
    bool setColorAtLocation(int rowIdx, int colIdx, ColorClass &inColor)
    {
        ColorImage.setColorAtLocation(rowIdx, colIdx, inColor);
    }

    void PrintImage()
    {
        ColorImage.printImage();
    }


private :
    ColorImageClass ColorImage;
    int height;
    int width;
    int maxColorValue;

    // get and check data in input file stream
    bool readValue(int &value, ifstream &inFile);
    bool readValue(string &value, ifstream &inFile);
};

#endif