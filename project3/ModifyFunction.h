#ifndef _MODIFYFUNCTION_H_
#define _MODIFYFUNCTION_H_

//library
#include <iostream>
#include "constants.h"
#include "PPMImageClass.h"
#include "commonFunc.h"
using namespace std;

//program header
//Name: Ryutaro Hashimoto
//Date: November 4, 2021
//purpose: This program will prototyped functions to handle ppm image.

// function to load image data from PPM file
bool loadPPMImage(PPMImageClass &Image);

// function to allow rectangles to be drawn on original image
void annotateImageRectangle(PPMImageClass &Image);

// function to annotate image with a “pattern”.
void annotateImagePattern(PPMImageClass &Image);

// function to insert another image
void insertAnotherImage(PPMImageClass &Image);

// function to write out current image data into PPM file
void outputPPMImage(PPMImageClass Image);

#endif