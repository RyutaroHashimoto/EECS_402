#include "SortedListClass.h"

//program header
//Name: Ryutaro Hashimoto
//Date: November 18, 2021
//purpose: This program will define "SortedListClass" class and its method.
//Update: Nov 21, printed element indented two spaces (176, 192)
//Update: Nov 21, change flow for pempty list (273)

template <class T>
SortedListClass<T>::SortedListClass()
{
    head = NULL;
    tail = NULL;
}

template <class T>
SortedListClass<T>::SortedListClass(const SortedListClass<T> &rhs)
{
    LinkedNodeClass<T> *originalCurrentNodePtr;
    LinkedNodeClass<T> *newCurrentNodePtr;
    LinkedNodeClass<T> *newNodePtr;
    LinkedNodeClass<T> *tempPre;
    int tempValue;

    if (rhs.head == NULL)
    {
        head = NULL;
        tail = NULL;
    }
    else{
        originalCurrentNodePtr = rhs.head;
        newCurrentNodePtr = new LinkedNodeClass<T>(
            originalCurrentNodePtr->getPrev(),
            originalCurrentNodePtr->getValue(),
            originalCurrentNodePtr->getNext());
        head = newCurrentNodePtr;
        tail = newCurrentNodePtr;
        originalCurrentNodePtr = originalCurrentNodePtr->getNext();
        while (originalCurrentNodePtr != NULL)
        {
            //Copy next node
            newNodePtr = new LinkedNodeClass<T>(
                newCurrentNodePtr,
                originalCurrentNodePtr->getValue(),
                originalCurrentNodePtr->getNext());
            //Recreate current node to connect new next node
            tempPre = newCurrentNodePtr->getPrev();
            tempValue = newCurrentNodePtr->getValue();
            *newCurrentNodePtr = LinkedNodeClass<T>(
                tempPre,
                tempValue,
                newNodePtr);
            tail = newNodePtr;
            originalCurrentNodePtr = originalCurrentNodePtr->getNext();
            newCurrentNodePtr = newCurrentNodePtr->getNext();
        }
    }
}

template <class T>
SortedListClass<T>::~SortedListClass()
{
    clear();
}

template <class T>
void SortedListClass<T>::clear()
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

template <class T>
void SortedListClass<T>::insertValue(const T &valToInsert)
{
    LinkedNodeClass<T> *currentNodePtr;
    LinkedNodeClass<T> *newNodePtr;
    LinkedNodeClass<T> *tempNext;
    LinkedNodeClass<T> *tempPre;
    T tempValue;

    if (head == NULL)  //for empty list
    {
        newNodePtr = new LinkedNodeClass<T>(NULL, valToInsert, NULL);
        head = newNodePtr;
        tail = newNodePtr;
    }
    else if (head->getValue() > valToInsert) // insert to front
    {
        //Create new first node
        newNodePtr = new LinkedNodeClass<T>(NULL, valToInsert, head);

        //Recreate old first node to follow new first node
        tempValue = head->getValue();
        tempNext = head->getNext();
        *head = LinkedNodeClass<T>(newNodePtr, tempValue, tempNext);
        head = newNodePtr;
    }
    else
    {
        currentNodePtr = head;
        // find the node after which the new node
        // is to be inserted
        while (currentNodePtr->getNext() != NULL &&
               currentNodePtr->getNext()->getValue() <= valToInsert)
            currentNodePtr = currentNodePtr->getNext();

        if (currentNodePtr->getNext() == NULL)  //new node is inserted to last
        {
            //Create new node
            newNodePtr = new LinkedNodeClass<T>(
                currentNodePtr,
                valToInsert,
                NULL);

            //Recreate old node to connect new node(left)
            tempValue = currentNodePtr->getValue();
            tempPre = currentNodePtr->getPrev();
            // delete currentNodePtr;
            *currentNodePtr = LinkedNodeClass<T>(
                tempPre,
                tempValue,
                newNodePtr);

            if (currentNodePtr->getPrev() == NULL)
            {
                head = currentNodePtr;
            }
            tail = newNodePtr;
        }
        else {
            //Create new node
            newNodePtr = new LinkedNodeClass<T>(
                currentNodePtr,
                valToInsert,
                currentNodePtr->getNext());

            //Recreate old node to connect new node(right)
            currentNodePtr = currentNodePtr->getNext();
            tempValue = currentNodePtr->getValue();
            tempNext = currentNodePtr->getNext();
            // delete currentNodePtr;
            *currentNodePtr = LinkedNodeClass<T>(
                newNodePtr,
                tempValue,
                tempNext);

            //Recreate old node to connect new node(left)
            currentNodePtr = newNodePtr->getPrev();
            tempValue = currentNodePtr->getValue();
            tempPre = currentNodePtr->getPrev();
            // delete currentNodePtr;
            *currentNodePtr = LinkedNodeClass<T>(
                tempPre,
                tempValue,
                newNodePtr);
        }
    }
}

template <class T>
void SortedListClass<T>::printForward() const
{
    LinkedNodeClass<T> *currentNodePtr;

    cout << "Forward List Contents Follow:" << endl;
    currentNodePtr = head;
    while(currentNodePtr != NULL)
    {
        cout << "  " << currentNodePtr->getValue() << endl;
        currentNodePtr = currentNodePtr->getNext();
    }
    cout << "End Of List Contents" << endl;
}

template <class T>
void SortedListClass<T>::printBackward() const
{
    LinkedNodeClass<T> *currentNodePtr;

    cout << "Backward List Contents Follow:" << endl;
    if (head != NULL)
    {
        currentNodePtr = tail;
        while (currentNodePtr != NULL)
        {
            cout << "  " << currentNodePtr->getValue() << endl;
            currentNodePtr = currentNodePtr->getPrev();
        }
    }
    cout << "End Of List Contents" << endl;
}

template <class T>
bool SortedListClass<T>::removeFront(T &theVal)
{
    LinkedNodeClass<T> *newHeadNodePtr;

    if (head == NULL) //for empty list
    {
        return false;
    }
    else if (head->getNext() == NULL) //for single node list
    {
        theVal = head->getValue();
        delete head;
        head = NULL;
        tail = NULL;
    }
    else {
        theVal = head->getValue();

        newHeadNodePtr = head->getNext();
        newHeadNodePtr->setPreviousPointerToNull();

        delete head;
        head = newHeadNodePtr;
    }
    return true;
}

template <class T>
bool SortedListClass<T>::removeLast(T &theVal)
{
    LinkedNodeClass<T> *newTailNodePtr;

    if (head == NULL) //for empty list
    {
        return false;
    }
    else if (head->getNext() == NULL)  //for single node list
    {
        theVal = head->getValue();
        delete head;
        head = NULL;
        tail = NULL;
    }
    else
    {
        theVal = tail->getValue();
        newTailNodePtr = tail->getPrev();
        newTailNodePtr->setNextPointerToNull();

        delete tail;
        tail = newTailNodePtr;
    }
    return true;
}

template <class T>
int SortedListClass<T>::getNumElems() const
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
bool SortedListClass<T>::getElemAtIndex(const int index, T &outVal) const
{
    LinkedNodeClass<T> *currentNodePtr;
    int count = 0;
    currentNodePtr = head;

    if (head == NULL)  // for empty list
    {
        return false;
    }

    while (currentNodePtr != NULL && count < index)
    {
        count++;
        currentNodePtr = currentNodePtr->getNext();
    }

    if (count == index && currentNodePtr != NULL)
    {
        outVal = currentNodePtr->getValue();
        return true;
    }
    return false;
}
