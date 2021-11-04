#include "commonFunc.h"

bool readValue(string &value, ifstream &inFile)
{
    bool validInputFound = false;
    while (!validInputFound)
    {
        inFile >> value;
        if (inFile.eof())
        {
            cout << "EOF before reading value" << endl;
            cout << "There are some missing values." << endl;
            break;
        }
        else if (inFile.fail())
        {
            cout << "At least, one of input values is invalid." << endl;
            cout << "Check the input value." << endl;
            break;
        }
        else
        {
            validInputFound = true;
        }
    }
    return validInputFound;
}

bool readValue(int &value, ifstream &inFile)
{
    bool validInputFound = false;
    while (!validInputFound)
    {
        inFile >> value;
        if (inFile.eof())
        {
            cout << "EOF before reading value." << endl;
            cout << "There are some missing values." << endl;
            break;
        }
        else if (inFile.fail())
        {
            cout << "At least, one of input values is invalid." << endl;
            cout << "Check the input value." << endl;
            break;
        }
        else
        {
            validInputFound = true;
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
