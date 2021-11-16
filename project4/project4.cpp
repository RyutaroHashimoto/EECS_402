//library
#include <iostream>
#include "LinkedNodeClass.h"
#include "LIFOStackClass.h"
#include "FIFOQueueClass.h"
#include "SortedListClass.h"

using namespace std;

//program header
//Name: Ryutaro Hashimoto
//Date: November 4, 2021
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


  // SortedListClass testList;

  // testList.printForward();
  // testList.insertValue(42);
  // testList.printForward();

  // testList.insertValue(10);
  // testList.printForward();

  // testList.insertValue(5);
  // testList.printForward();

  // testList.insertValue(50);
  // testList.printForward();

  // testList.insertValue(-50);
  // testList.printForward();

  // testList.insertValue(20);
  // testList.printForward();

  // testList.insertValue(20);
  // testList.printForward();

  // testList.insertValue(50);
  // testList.printForward();

  // SortedListClass testList2(testList);
  // testList2.printForward();


  int value;
  // testList2.removeFront(value);
  // testList2.printForward();
  // cout << value << endl;

  // testList2.removeLast(value);
  // testList2.printForward();
  // cout << value << endl;

  // testList2.printBackward();

  // testList.printForward();

  SortedListClass testList3;
  // testList3.insertValue(42);
  // testList3.printForward();
  // testList3.removeFront(value);
  // testList3.printForward();
  // testList3.printBackward();
  // cout << value << endl;

  // testList3.insertValue(24);
  // testList3.printForward();
  // testList3.removeLast(value);
  // testList3.printForward();
  // testList3.printBackward();
  // cout << value << endl;

  // cout << testList2.getNumElems() << endl;

  testList3.insertValue(1);
  testList3.insertValue(2);
  testList3.insertValue(3);
  testList3.insertValue(4);
  testList3.printForward();
  testList3.getElemAtIndex(0, value);
  cout << value << endl;
  testList3.getElemAtIndex(1, value);
  cout << value << endl;
  testList3.getElemAtIndex(2, value);
  cout << value << endl;
  testList3.getElemAtIndex(3, value);
  cout << value << endl;
  testList3.getElemAtIndex(4, value);
  cout << value << endl;
  return 0;
}

#endif