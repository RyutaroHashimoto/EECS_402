//library
#include <iostream>
#include "LinkedNodeClass.h"
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
  SortedListClass<int> testList;

  testList.printForward(); //
  testList.printBackward();

  testList.insertValue(1);
  testList.printForward(); // 1
  testList.printBackward();

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

  SortedListClass<int> testList2(testList);
  testList2.printForward();                // -50 -50 -10 1 1 2 3 3
  testList2.printBackward();               //3 3 2 1 1 -10 -50 -50
  cout << testList2.getNumElems() << endl; //8

  int value;
  testList2.removeFront(value);
  testList2.printForward(); // -50 -10 1 1 2 3 3
  cout << value << endl;    //-50

  testList2.removeLast(value);
  testList2.printForward(); // -50 -10 1 1 2 3
  cout << value << endl;    //3

  testList2.printBackward(); // 3 2 1 1 -10 -50

  testList2.removeLast(value);
  testList2.removeLast(value);
  testList2.removeLast(value);
  testList2.removeLast(value);
  testList2.removeLast(value);
  testList2.removeLast(value);
  testList2.printForward();  //
  testList2.printBackward(); //

  testList.printBackward(); //3 3 2 1 1 -10 -50 -50

  testList.getElemAtIndex(0, value);
  cout << value << endl; //-50

  testList.getElemAtIndex(2, value);
  cout << value << endl; //-10

  testList.getElemAtIndex(7, value);
  cout << value << endl; //3

  cout << testList.getElemAtIndex(20, value) << endl; //0

  testList2.clear();
  testList2.printForward();

  SortedListClass<char> testList3;
  char value_char = 'w';

  testList3.printForward(); //
  testList3.printBackward();

  testList3.insertValue('b');
  testList3.printForward(); // b
  testList3.printBackward();

  testList3.insertValue('a');
  testList3.printForward(); // a b
  testList3.printBackward(); // b a

  testList3.getElemAtIndex(-1, value_char);
  cout << value_char << endl; //w

  testList3.getElemAtIndex(2, value_char);
  cout << value_char << endl; //w

  testList3.getElemAtIndex(3, value_char);
  cout << value_char << endl; //w

  testList3.getElemAtIndex(0, value_char);
  cout << value_char << endl; //a

  testList3.getElemAtIndex(1, value_char);
  cout << value_char << endl; //b

  testList3.removeFront(value_char);
  testList3.printForward();  //b
  cout << value_char << endl; //a

  // test FIFOQueueClass
  cout << " test FIFOQueueClass" << endl;
  FIFOQueueClass<int> testFIFOQueueClass;
  int deque;

  testFIFOQueueClass.print(); //

  testFIFOQueueClass.enqueue(1);
  testFIFOQueueClass.print(); //1

  testFIFOQueueClass.enqueue(2);
  testFIFOQueueClass.enqueue(3);
  testFIFOQueueClass.print(); //3 2 1

  cout << testFIFOQueueClass.getNumElems() << endl; //3

  testFIFOQueueClass.dequeue(deque);
  testFIFOQueueClass.print(); //2 1
  cout << deque << endl;      //3

  testFIFOQueueClass.dequeue(deque);
  testFIFOQueueClass.print(); //1
  cout << deque << endl;      //2

  testFIFOQueueClass.dequeue(deque);
  testFIFOQueueClass.print(); //
  cout << deque << endl;      //1

  cout << testFIFOQueueClass.dequeue(deque) << endl; //0

  FIFOQueueClass<char> testFIFOQueueClass2;
  char deque_char;

  testFIFOQueueClass2.print(); //

  testFIFOQueueClass2.enqueue('a');
  testFIFOQueueClass2.print(); //a

  testFIFOQueueClass2.enqueue('b');
  testFIFOQueueClass2.enqueue('a');
  testFIFOQueueClass2.print(); //a b a

  cout << testFIFOQueueClass2.getNumElems() << endl; //3

  testFIFOQueueClass2.dequeue(deque_char);
  testFIFOQueueClass2.print(); //b a
  cout << deque_char << endl; //a

  return 0;
}

#endif
