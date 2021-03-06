//library
#include <iostream>
#include "LinkedNodeClass.h"
#include "LIFOStackClass.h"
#include "FIFOQueueClass.h"
#include "SortedListClass.h"

using namespace std;

//program header
//Name: Ryutaro Hashimoto
//Date: November 18, 2021
//purpose: This program will test SortedListClass, LIFOStackClass
//and FIFOQueueClass

//Do NOT remove any of the preprocessor directives in this file.
//They should not affect your ability to write test code in your
//main function below, and they must be in your submitted main
//file exactly as provided to you with the project.
#ifdef ANDREW_TEST
#include "andrewTest.h"
#else

int main()
{
  //This is just a placeholder main function - it does exceptionally
  //little actual testing, so you'll want to add your own tests here.
  //Feel free to leave your tests in the version of this file you
  //submit, but we will not be running your main function, so the
  //output, etc., of your main doesn't need to match anything from
  //a sample output, etc.

  //test SortedListClass
  cout << " test SortedListClass" << endl;
  SortedListClass testList;
  int output= -999;
  testList.printForward(); //
  testList.printBackward();

  testList.getElemAtIndex(1, output);
  cout << "output: " << output << endl;
  testList.getElemAtIndex(0, output);
  cout << "output: " << output << endl;
  testList.insertValue(1);
  testList.printForward(); // 1
  testList.printBackward();

  testList.getElemAtIndex(0, output);
  cout << "output: " << output << endl;

  testList.getElemAtIndex(-10, output);
  cout << "output: " << output << endl;

  testList.insertValue(2);
  testList.printForward(); // 1 2

  testList.insertValue(3);
  testList.printForward(); // 1 2 3

  testList.insertValue(-50);
  testList.printForward(); // -50 1 2 3

  testList.insertValue(1);
  testList.printForward(); // -50 1 1 2 3

  testList.insertValue(-50);
  testList.printForward(); // -50 -50 1 1 2 3

  testList.insertValue(3);
  testList.printForward(); // -50 -50 1 1 2 3 3

  testList.insertValue(-10);
  testList.printForward();  // -50 -50 -10 1 1 2 3 3
  testList.printBackward(); //3 3 2 1 1 -10 -50 -50

  

  return 0;
}

#endif
