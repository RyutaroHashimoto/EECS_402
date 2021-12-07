#include "FIFOQueueClass.h"

//program header
//Name: Ryutaro Hashimoto
//Date: December 6, 2021
//purpose: This program will template "FIFOQueueClass" class and its method.
// Update: December 6 by Ryutaro Hashimoto
//         Template FIFOQueueClass

template <class T>
FIFOQueueClass<T>::FIFOQueueClass()
{
    head = NULL;
    tail = NULL;
}

template <class T>
FIFOQueueClass<T>::~FIFOQueueClass()
{
    clear();
}

template <class T>
void FIFOQueueClass<T>::enqueue(const T &newItem)
{
    LinkedNodeClass<T> *newNodePtr = NULL;
    LinkedNodeClass<T> *tempNext;
    T tempValue;

    if (head == NULL)
    {
        newNodePtr = new LinkedNodeClass<T>(NULL, newItem, NULL);
        head = newNodePtr;
        tail = newNodePtr;
    }
    else{
        newNodePtr = new LinkedNodeClass<T>(NULL, newItem, head);
        tempNext = head->getNext();
        tempValue = head->getValue();
        *head = LinkedNodeClass<T>(
            newNodePtr,
            tempValue,
            tempNext);
        head = newNodePtr;
    }
}

template <class T>
bool FIFOQueueClass<T>::dequeue(T &outItem)
{
    LinkedNodeClass<T> *newTailNodePtr;
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
        outItem = tail->getValue();
        newTailNodePtr = tail->getPrev();
        newTailNodePtr->setNextPointerToNull();
        delete tail;
        tail = newTailNodePtr;
    }
    return true;
}

template <class T>
void FIFOQueueClass<T>::print() const
{
    LinkedNodeClass<T> *currentNodePtr;
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

template <class T>
int FIFOQueueClass<T>::getNumElems() const
{
    LinkedNodeClass<T> *currentNodePtr;
    int count = 0;
    currentNodePtr = head;
    while (currentNodePtr != NULL)
    {
        count++;
        currentNodePtr = currentNodePtr->getNext();
    }
    return count;
}

template <class T>
void FIFOQueueClass<T>::clear()
{
    LinkedNodeClass<T> *currentNodePtr;
    LinkedNodeClass<T> *nextNodePtr;
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
