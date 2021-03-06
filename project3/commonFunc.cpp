#include "commonFunc.h"

//program header
//Name: Ryutaro Hashimoto
//Date: November 4, 2021
//purpose: This program will define common functions to read value from command
//prompt or file.

bool readValue(string &value, ifstream &inFile)
{
    bool validInputFound = false;
    bool isContinuingReading = true;

    while (isContinuingReading)
    {
        inFile >> value;
        if (inFile.eof())
        {
            cout << "EOF before reading value" << endl;
            cout << "There are some missing values." << endl;
            validInputFound = false;
            isContinuingReading = false;
        }
        else if (inFile.fail())
        {
            cout << "At least, one of input values is invalid." << endl;
            cout << "Check the input value." << endl;
            validInputFound = false;
            isContinuingReading = false;
        }
        else
        {
            validInputFound = true;
            isContinuingReading = false;
        }
    }
    return validInputFound;
}

bool readValue(int &value, ifstream &inFile)
{
    bool validInputFound = false;
    bool isContinuingReading = true;

    while (isContinuingReading)
    {
        inFile >> value;
        if (inFile.eof())
        {
            cout << "EOF before reading value." << endl;
            cout << "There are some missing values." << endl;
            validInputFound = false;
            isContinuingReading = false;
        }
        else if (inFile.fail())
        {
            cout << "At least, one of input values is invalid." << endl;
            cout << "Check the input value." << endl;
            validInputFound = false;
            isContinuingReading = false;
        }
        else
        {
            validInputFound = true;
            isContinuingReading = false;
        }
    }
    return validInputFound;
}

void getInputVale(int &value, string promptMessage)
{
    bool validInputFound = false;

    cout << promptMessage;

    while (!validInputFound)
    {
        cin >> value;
        if (cin.fail())
        {
            cout << "Fail to input." << endl;
            cout << "Try again - " << promptMessage;
            cin.clear();
            cin.ignore(200, '\n');
        }
        else
        {
            validInputFound = true;
        }
    }
}

void getInputVale(int &value1, int &value2, string promptMessage)
{
    bool validInputFound = false;

    cout << promptMessage;

    while (!validInputFound)
    {
        cin >> value1;
        cin >> value2;
        if (cin.fail())
        {
            cout << "Fail to input." << endl;
            cout << "Try again - " << promptMessage;
            cin.clear();
            cin.ignore(200, '\n');
        }
        else
        {
            validInputFound = true;
        }
    }
}

void getInputVale(string &value, string promptMessage)
{
    bool validInputFound = false;

    cout << promptMessage;

    while (!validInputFound)
    {
        cin >> value;
        if (cin.fail())
        {
            cout << "Fail to input." << endl;
            cout << "Try again - " << promptMessage;
            cin.clear();
            cin.ignore(200, '\n');
        }
        else
        {
            validInputFound = true;
        }
    }
}
