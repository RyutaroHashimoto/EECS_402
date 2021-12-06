#include "FIFOQueueClass.h"

//program header
//Name: Ryutaro Hashimoto
//Date: November 18, 2021
//purpose: This program will define "FIFOQueueClass" class and its method.

FIFOQueueClass::FIFOQueueClass()
{
    head = NULL;
    tail = NULL;
}

FIFOQueueClass::~FIFOQueueClass()
{
    clear();
}

void FIFOQueueClass::enqueue(const int &newItem)
{
    LinkedNodeClass *newNodePtr=NULL;
    LinkedNodeClass *tempNext;
    int tempValue;

    if (head == NULL)
    {
        newNodePtr = new LinkedNodeClass(NULL, newItem, NULL);
        head = newNodePtr;
        tail = newNodePtr;
    }
    else{
        newNodePtr = new LinkedNodeClass(NULL, newItem, head);
        tempNext = head->getNext();
        tempValue = head->getValue();
        *head = LinkedNodeClass(
            newNodePtr,
            tempValue,
            tempNext);
        head = newNodePtr;
    }
}

bool FIFOQueueClass::dequeue(int &outItem)
{
    LinkedNodeClass *newHeadNodePtr;
    if (head == NULL) //queue is empty
    {
        return false;
    }
    else if (head->getNext() == NULL) //for single node list
    {
        outItem = head->getValue();
        clear();
    }
    else
    {
        outItem = head->getValue();
        newHeadNodePtr = head->getNext();
        newHeadNodePtr->setPreviousPointerToNull();
        delete head;
        head = newHeadNodePtr;
    }
    return true;
}

void FIFOQueueClass::print() const
{
    LinkedNodeClass *currentNodePtr;
    if (head != NULL)
    {
        currentNodePtr = head;
        while (currentNodePtr->getNext() != NULL)
        {
            cout << currentNodePtr->getValue() << " ";
            currentNodePtr = currentNodePtr->getNext();
        }
        cout << currentNodePtr->getValue();
    }
    cout << endl;
}

int FIFOQueueClass::getNumElems() const
{
    LinkedNodeClass *currentNodePtr;
    int count = 0;
    currentNodePtr = head;
    while (currentNodePtr != NULL)
    {
        count++;
        currentNodePtr = currentNodePtr->getNext();
    }
    return count;
}

void FIFOQueueClass::clear()
{
    LinkedNodeClass *currentNodePtr;
    LinkedNodeClass *nextNodePtr;
    currentNodePtr = head;
    while (currentNodePtr != NULL)
    {
        nextNodePtr = currentNodePtr->getNext();
        delete currentNodePtr;
        currentNodePtr = nextNodePtr;
    }
    head = NULL;
    tail = NULL;
}