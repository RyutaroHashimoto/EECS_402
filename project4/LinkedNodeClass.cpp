#include "LinkedNodeClass.h"

//program header
//Name: Ryutaro Hashimoto
//Date: November 18, 2021
//purpose: This program will define "LinkedNodeClass" class and its method.

LinkedNodeClass::LinkedNodeClass(
    LinkedNodeClass *inPrev,
    const int &inVal,
    LinkedNodeClass *inNext
)
{
    prevNode = inPrev;
    nodeVal = inVal;
    nextNode = inNext;
}

int LinkedNodeClass::getValue() const
{
    return nodeVal;
}

LinkedNodeClass* LinkedNodeClass::getNext() const
{
    return nextNode;
}

LinkedNodeClass* LinkedNodeClass::getPrev() const
{
    return prevNode;
}

void LinkedNodeClass::setNextPointerToNull()
{
    nextNode = NULL;
}

void LinkedNodeClass::setPreviousPointerToNull()
{
    prevNode = NULL;
}

void LinkedNodeClass::setBeforeAndAfterPointers()
{
    LinkedNodeClass *oldPrev;
    LinkedNodeClass *oldNext;
    LinkedNodeClass *twoPrevious;
    LinkedNodeClass *twoNext;

    oldPrev = prevNode;
    oldNext = nextNode;

    //modify two previous node
    twoPrevious = prevNode->getPrev();
    twoPrevious->nextNode = nextNode;

    //modify the node next two nodes
    twoNext = nextNode->getPrev();
    twoNext->prevNode = prevNode;

    //modify the previous node
    oldPrev->prevNode = oldPrev->nextNode;
    oldPrev->nextNode = twoNext;

    //modify the next node
    oldNext->nextNode = oldNext->prevNode;
    oldNext->prevNode = twoPrevious;
    
    prevNode = oldNext;
    nextNode = oldPrev;
}