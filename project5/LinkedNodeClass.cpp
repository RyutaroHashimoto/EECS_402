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
    LinkedNodeClass *original;

    oldPrev = prevNode;
    oldNext = nextNode;
    original = prevNode->getNext();

    if (oldPrev == NULL || oldNext == NULL)
    {
        cout << "This node is first or last node!" << endl;
    }
    else
    {

        //modify the two previous node
        twoPrevious = prevNode->getPrev();
        if (twoPrevious != NULL)
        {
            twoPrevious->nextNode = oldNext;
            oldNext->prevNode = twoPrevious;
        } else
        {
            oldNext->prevNode = NULL;
        }

        //modify the node next two nodes
        twoNext = nextNode->getNext();
        if (twoNext != NULL)
        {
            twoNext->prevNode = oldPrev;
            oldPrev->nextNode = twoNext;
        }
        else
        {
            oldPrev->nextNode = NULL;
        }

        //modify the previous node
        oldPrev->prevNode = original;

        // //modify the next node
        oldNext->nextNode = original;

        prevNode = oldNext;
        nextNode = oldPrev;
    }
}