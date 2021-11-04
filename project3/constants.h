#ifndef _CONSTANTS_H_
#define _CONSTANTS_H_

#include <string>
using namespace std;

//program header
//Name: Ryutaro Hashimoto
//Date: November 4, 2021
//purpose: This program will define constants variables in this program.

const int MAXIMUM_COLOR_VALUE = 500;
const int MINIMUM_COLOR_VALUE = 0;
const int DEFAULT_IMAGE_HEIGHT = 5;
const int DEFAULT_IMAGE_WIDTH = 5;

const int NUM_OF_MAIN_MENU = 5;
const int CHOICE_OF_ANNOTATE_IMAGE_WITH_RECTANGLE = 1;
const int CHOICE_OF_ANNOTATE_IMAGE_WITH_PATTERN = 2;
const int CHOICE_OF_INSERT_ANOTHER = 3;
const int CHOICE_OF_WRITE_OUT_CURRENT_IMAGE = 4;
const int CHOICE_OF_EXIT_THE_PROGRAM = 5;

const int NUM_OF_RECTANGLE_SPECIFICATION_METHOD = 3;
const int CHOICE_OF_SPECIFY_UPPER_LEFT_LOWER_RIGHT_CORNERS = 1;
const int CHOICE_OF_SPECIFY_UP_LEFT_CORNER_DIMENSIONS = 2;
const int CHOICE_OF_SPECIFY_SPECIFY_EXTENT_FROM_CENTER = 3;

const int NUM_OF_DEFAULT_COLOR = 5;
const int CHOICE_OF_RED = 1;
const int CHOICE_OF_GREEN = 2;
const int CHOICE_OF_BLUE = 3;
const int CHOICE_OF_BLACK = 4;
const int CHOICE_OF_WHITE = 5;

const int NUM_OF_CHOICE_FILL = 2;
const int CHOICE_OF_NOT_FILL_IN = 1;
const int CHOICE_OF_FILL_IN = 2;

const string PPM_IMAGE_MAGIC_NUMBER = "P3";

#endif