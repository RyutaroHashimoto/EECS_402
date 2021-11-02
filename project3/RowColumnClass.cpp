//library
#include <iostream>
#include "RowColumnClass.h"
using namespace std;

RowColumnClass::RowColumnClass()
{
    rowValue = DEFAULT_ROW_VALUE;
    colValue = DEFAULT_COL_VALUE;
}

RowColumnClass::RowColumnClass(int inRow, int inCol)
{
    rowValue = inRow;
    colValue = inCol;
}

void RowColumnClass::setRowCol(int inRow, int inCol)
{
    rowValue = inRow;
    colValue = inCol;
}

void RowColumnClass::setRow(int inRow)
{
    rowValue = inRow;
}

void RowColumnClass::setCol(int inCol)
{
    colValue = inCol;
}

int RowColumnClass::getRow()
{
    return rowValue;
}

int RowColumnClass::getCol()
{
    return colValue;
}

void RowColumnClass::addRowColTo(RowColumnClass &inRowCol)
{
    rowValue += inRowCol.rowValue;
    colValue += inRowCol.colValue;
}

void RowColumnClass::printRowCol()
{
    cout << "[" << rowValue << "," << colValue << "]";
}