#include "LinkedNodeClass.h"
//program header
//Name: Ryutaro Hashimoto
//Date: December 6, 2021
//purpose: This program will define template of "LinkedNodeClass" class
//         and its method.

template <class T>
LinkedNodeClass<T>::LinkedNodeClass(
    LinkedNodeClass<T> *inPrev,
    const T &inVal,
    LinkedNodeClass<T> *inNext)
{
    prevNode = inPrev;
    nodeVal = inVal;
    nextNode = inNext;
}

template <class T>
T LinkedNodeClass<T>::getValue() const
{
    return nodeVal;
}

template <class T>
LinkedNodeClass<T>* LinkedNodeClass<T>::getNext() const
{
    return nextNode;
}

template <class T>
LinkedNodeClass<T>* LinkedNodeClass<T>::getPrev() const
{
    return prevNode;
}

template <class T>
void LinkedNodeClass<T>::setNextPointerToNull()
{
    nextNode = NULL;
}

template <class T>
void LinkedNodeClass<T>::setPreviousPointerToNull()
{
    prevNode = NULL;
}

template <class T>
void LinkedNodeClass<T>::setBeforeAndAfterPointers()
{
    LinkedNodeClass<T> *oldPrev;
    LinkedNodeClass<T> *oldNext;
    LinkedNodeClass<T> *twoPrevious;
    LinkedNodeClass<T> *twoNext;
    LinkedNodeClass<T> *original;

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
        }
        else
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
