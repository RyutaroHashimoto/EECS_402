//library
#include <iostream>
#include "PPMImageClass.h"
using namespace std;

PPMImageClass::PPMImageClass()
{
    // default image size is defined as global variables
    height = DEFAULT_IMAGE_HEIGHT;
    width = DEFAULT_IMAGE_WIDTH;

    ColorImage = ColorImageClass(height, width);
}

PPMImageClass::PPMImageClass(int inHeight, int inWidth)
{
    // default image size is defined as global variables
    height = inHeight;
    width = inWidth;

    ColorImage = ColorImageClass(height, width);
}
