#include "SortedListClass.h"

//program header
//Name: Ryutaro Hashimoto
//Date: November 18, 2021
//purpose: This program will define "SortedListClass" class and its method.

SortedListClass::SortedListClass()
{
    head = NULL;
    tail = NULL;
}

SortedListClass::SortedListClass(const SortedListClass &rhs)
{
    LinkedNodeClass *originalCurrentNodePtr;
    LinkedNodeClass *newCurrentNodePtr;
    LinkedNodeClass *newNodePtr;
    LinkedNodeClass *tempPre;
    int tempValue;

    if (rhs.head == NULL)
    {
        head = NULL;
        tail = NULL;
    }
    else{
        originalCurrentNodePtr = rhs.head;
        newCurrentNodePtr = new LinkedNodeClass(
                    originalCurrentNodePtr->getPrev(), 
                    originalCurrentNodePtr->getValue(), 
                    originalCurrentNodePtr->getNext());
        head = newCurrentNodePtr;
        tail = newCurrentNodePtr;
        originalCurrentNodePtr = originalCurrentNodePtr->getNext();
        while (originalCurrentNodePtr != NULL)
        {
            //Copy next node
            newNodePtr = new LinkedNodeClass(
                                    newCurrentNodePtr, 
                                    originalCurrentNodePtr->getValue(), 
                                    originalCurrentNodePtr->getNext());
            //Recreate current node to connect new next node
            tempPre = newCurrentNodePtr->getPrev();
            tempValue = newCurrentNodePtr->getValue();
            delete newCurrentNodePtr;
            newCurrentNodePtr = new LinkedNodeClass(
                                    tempPre, 
                                    tempValue, 
                                    newNodePtr);
            tail = newNodePtr;
            originalCurrentNodePtr = originalCurrentNodePtr->getNext();
            newCurrentNodePtr = newCurrentNodePtr->getNext();
        }
    }
}

SortedListClass::~SortedListClass()
{
    clear();
}

void SortedListClass::clear()
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

void SortedListClass::insertValue(const int &valToInsert)
{
    LinkedNodeClass *currentNodePtr;
    LinkedNodeClass *newNodePtr;
    LinkedNodeClass *tempNext;
    LinkedNodeClass *tempPre;
    int tempValue;

    if (head == NULL)  //for empty list
    {
        newNodePtr = new LinkedNodeClass(NULL, valToInsert, NULL);
        head = newNodePtr;
        tail = newNodePtr;
    }
    else if (head->getValue() > valToInsert) // insert to front
    {
        //Create new first node
        newNodePtr = new LinkedNodeClass(NULL, valToInsert, head);

        //Recreate old first node to follow new first node
        tempValue = head->getValue();
        tempNext = head->getNext();
        // delete head;
        head = new LinkedNodeClass(newNodePtr, tempValue, tempNext);
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
            newNodePtr = new LinkedNodeClass(
                        currentNodePtr, 
                        valToInsert, 
                        NULL);
            
            //Recreate old node to connect new node(left)
            tempValue = currentNodePtr->getValue();
            tempPre = currentNodePtr->getPrev();
            // delete currentNodePtr;
            currentNodePtr = new LinkedNodeClass(
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
            newNodePtr = new LinkedNodeClass(
                currentNodePtr,
                valToInsert,
                currentNodePtr->getNext());

            //Recreate old node to connect new node(right)
            currentNodePtr = currentNodePtr->getNext();
            tempValue = currentNodePtr->getValue();
            tempNext = currentNodePtr->getNext();
            // delete currentNodePtr;
            currentNodePtr = new LinkedNodeClass(
                newNodePtr,
                tempValue,
                tempNext);

            //Recreate old node to connect new node(left)
            currentNodePtr = newNodePtr->getPrev();
            tempValue = currentNodePtr->getValue();
            tempPre = currentNodePtr->getPrev();
            // delete currentNodePtr;
            currentNodePtr = new LinkedNodeClass(
                tempPre,
                tempValue,
                newNodePtr);
        }
    }
}

void SortedListClass::printForward() const
{
    LinkedNodeClass *currentNodePtr;

    cout << "Forward List Contents Follow:" << endl;
    currentNodePtr = head;
    while(currentNodePtr != NULL)
    {
        cout << currentNodePtr->getValue() << endl;
        currentNodePtr = currentNodePtr->getNext();
    }
    cout << "End Of List Contents" << endl;
}

void SortedListClass::printBackward() const
{
    LinkedNodeClass *currentNodePtr;

    cout << "Backward List Contents Follow:" << endl;
    if (head != NULL)
    {
        currentNodePtr = tail;
        while (currentNodePtr != NULL)
        {
            cout << currentNodePtr->getValue() << endl;
            currentNodePtr = currentNodePtr->getPrev();
        }
    }
    cout << "End Of List Contents" << endl;
}

bool SortedListClass::removeFront(int &theVal)
{
    LinkedNodeClass *newHeadNodePtr;

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

bool SortedListClass::removeLast(int &theVal)
{
    LinkedNodeClass *newTailNodePtr;

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

int SortedListClass::getNumElems() const
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

bool SortedListClass::getElemAtIndex(const int index, int &outVal) const
{
    LinkedNodeClass *currentNodePtr;
    int count = 0;
    currentNodePtr = head;

    while (currentNodePtr != NULL && count < index)
    {
        count++;
        currentNodePtr = currentNodePtr->getNext();
    }
    if (count == index)
    {
        outVal = currentNodePtr->getValue();
        return true;
    }
    return false;
}
