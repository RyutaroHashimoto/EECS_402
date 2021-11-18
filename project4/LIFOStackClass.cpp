#include "LIFOStackClass.h"

//program header
//Name: Ryutaro Hashimoto
//Date: November 18, 2021
//purpose: This program will define "LIFOStackClass" class and its method.

LIFOStackClass::LIFOStackClass()
{
    head = NULL;
    tail = NULL;
}

LIFOStackClass::~LIFOStackClass()
{
    clear();
}

void LIFOStackClass::push(const int &newItem)
{
    LinkedNodeClass *newNodePtr;
    LinkedNodeClass *currentNodePtr;
    LinkedNodeClass *tempPre;
    int tempValue;

    if (head == NULL)
    {
        newNodePtr = new LinkedNodeClass(NULL, newItem, NULL);
        head = newNodePtr;
        tail = newNodePtr;
    }
    else
    {
        newNodePtr = new LinkedNodeClass(tail, newItem, NULL);
        currentNodePtr = tail;
        tempPre = currentNodePtr->getPrev();
        tempValue = currentNodePtr->getValue();
        *currentNodePtr = LinkedNodeClass(
            tempPre,
            tempValue,
            newNodePtr);
        tail = newNodePtr;
    }
}

bool LIFOStackClass::pop(int &outItem)
{
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
}

void LIFOStackClass::print() const
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

int LIFOStackClass::getNumElems() const
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

void LIFOStackClass::clear()
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