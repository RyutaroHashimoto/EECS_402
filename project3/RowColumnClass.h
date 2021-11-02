#ifndef _ROWCOLUMNCLASS_H_
#define _ROWCOLUMNCLASS_H_

//library
#include <iostream>
#include "constants.h"
#include "ColorClass.h"
using namespace std;

//program header
//Name: Ryutaro Hashimoto
//Date: October 12, 2021
//purpose: This program will define color class. Colors are described by RGB
//values.

class RowColumnClass
{
public:
    // Initiialy set to default value (DEFAULT_ROW_VALUE, DEFAULT_COL_VALUE)
    RowColumnClass();

    // Initiialy set to specific value with input (inRow, inCol)
    RowColumnClass(int inRow, int inCol);

    // Set value values to specific value
    void setRowCol(int inRow, int inCol);

    // Set row values to specific value
    void setRow(int inRow);

    // Set columns values to specific value
    void setCol(int inCol);

    // Get row value
    int getRow();

    // Get columns value
    int getCol();

    // adds the index values in the input parameter to the objects
    void addRowColTo(RowColumnClass &inRowCol);

    // print current value
    void printRowCol();

private:
    // row and columns index value
    int rowValue;
    int colValue;
};

#endif