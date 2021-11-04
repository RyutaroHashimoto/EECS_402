#ifndef _COMMONFUNC_H_
#define _COMMONFUNC_H_
//library
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

//program header
//Name: Ryutaro Hashimoto
//Date: October 12, 2021
//purpose: This program will define color class. Colors are described by RGB
//values.

// get and check data in input file stream (int)
bool readValue(int &value, ifstream &inFile);

// get and check data in input file stream (string)
bool readValue(string &value, ifstream &inFile);

// function to get int value from command prompt
void getInputVale(int &value, string errorMessage);

// function to get two int value from command prompt
void getInputVale(int &value1, int &value2, string errorMessage);

// function to get string value from command prompt
void getInputVale(string &value, string promptMessage);

#endif