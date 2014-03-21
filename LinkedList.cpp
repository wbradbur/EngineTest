//
//  LinkedList.cpp
//  EngineTest
//
//  Created by Chase Bradbury on 12/19/13.
//  Copyright (c) 2013 Chase Bradbury. All rights reserved.
//

#include "LinkedList.h"

/*** Node structure ***/
struct node_t {
    long key;
    void* data;
    noderef left;
    noderef right;
};



/*** Access functions ***/

bool LinkedList::isEmpty()
{
    return first == NULL;
}
// returns true is list is empty else returns false.

bool LinkedList::isInList(long key)
{
    moveFirst();
    while (!offEnd())
    {
        if (current->getKey() == key)
        {
            return true;
        }
        moveNext();
    }
    return false;
}
// Returns true if the key is in the list.

bool LinkedList::offEnd()
{
    return current == NULL;
}
// returns true is current == NULL

bool LinkedList::atFirst()
{
    return current == first && !offEnd();
}
// returns true if current == first and !offEnd()

bool LinkedList::atLast()
{
    return current == last && !offEnd();
}
// returns true if current == last and !offEnd()

long LinkedList::firstKey()
{
    if (!isEmpty())
    {
        return first->getKey();
    }
    return -1;
}
// return the first key
// pre: !isEmpty()

long LinkedList::lastKey()
{
    if (!isEmpty())
    {
        return last->getKey();
    }
    return -1;
}
// return the last key
// pre: !isEmpty()

long LinkedList::currentKey()
{
    if (!offEnd())
    {
        return current->getKey();
    }
    return -1;
}
// return the current key
// pre: !offEnd()

void* LinkedList::firstData()
{
    if (!isEmpty())
    {
        return first->getData();
    }
    return NULL;
}
// return the generic value of first data
// pre: !isEmpty()

void* LinkedList::lastData()
{
    if (!isEmpty())
    {
        return last->getData();
    }
    return NULL;
}
// return the generic value of last data
// pre: !isEmpty()

void* LinkedList::currentData()
{
    if (!offEnd())
    {
        return current->getData();
    }
    return NULL;
}
// return the generic value of current data
// pre: !offEnd()

void* LinkedList::getData(long key)
{
    if (isInList(key))
    {
        return current->getData();
    }
    return NULL;
}
// Returns the data of the first instance of the key in the list. Returns null if not found

int LinkedList::getLength()
{
    int length = 0;
    moveFirst();
    while (!offEnd())
    {
        ++length;
    }
    return length;
}
// return the length of the list

bool LinkedList::equalsKeys(LinkedList other)
{
    moveFirst();
    while (!offEnd() && !other.offEnd())
    {
        if (!offEnd() || !other.offEnd())
        {
            return false;
        }
        if (current->getKey() != other.current->getKey())
        {
            return false;
        }
    }
    return true;
}
// return true iff the two lists have the same keys in the same order

bool LinkedList::equalsExact(LinkedList other)
{
    moveFirst();
    while (!offEnd() && !other.offEnd())
    {
        if (!offEnd() || !other.offEnd())
        {
            return false;
        }
        if (current->getKey() != other.current->getKey() || current->getData() != other.current->getData())
        {
            return false;
        }
    }
    return true;
}
// return true iff the two lists have the same key-data pairs in the same order



/*** Manipulation procedures ***/

void LinkedList::makeEmpty()
{
    moveFirst();
    while (!offEnd())
    {
        delete current;
        moveNext();
    }
}
// make the list empty.
// Post: isEmpty()

void LinkedList::moveFirst()
{
    current = first;
}
// set current marker to the first element in the list
// Pre: !isEmpty(); Post: !offEnd()

void LinkedList::moveLast()
{
    current = last;
}
// set current marker to the last element in the list
// Pre: !isEmpty(); Post: !offEnd()

void LinkedList::movePrev()
{
    if (!offEnd())
    {
        current = current->getLeft();
    }
}
// set current marker one step backward.
// Pre: !offEnd(); Post: offEnd() only if atFirst() was true

void LinkedList::moveNext()
{
    if (!offEnd())
    {
        current = current->getRight();
    }
}
// set current marker one step forward.
// Pre: !offEnd(); Post: offEnd() only if atLast() was true

void LinkedList::insertBeforeFirst(long key, void* data)
{
    BinaryNode* temp = new BinaryNode(key, data);
    if (!isEmpty())
    {
        first->setLeft(temp);
    } else
    {
        last = temp;
    }
    temp->setRight(first);
    first = temp;
}
// Inserts new element before first
// Post: !isEmpty()

void LinkedList::insertAfterLast(long key, void* data)
{
    BinaryNode* temp = new BinaryNode(key, data);
    if (!isEmpty())
    {
        last->setRight(temp);
    } else
    {
        first = temp;
    }
    temp->setLeft(last);
    last = temp;
}
// Inserts new element after last one
// Post: !isEmpty()

void LinkedList::insertBeforeCurrent(long key, void* data)
{
    if (!offEnd())
    {
        BinaryNode* temp = new BinaryNode(key, data);
        if (current == first)
        {
            first = temp;
        } else
        {
            current->getLeft()->setRight(temp);
        }
        temp->setLeft(current->getLeft());
        current->setLeft(temp);
        temp->setRight(current);
        current = temp;
    } else {
        insertAfterLast(key, data);
    }
}
// Inserts new element before current one
// Pre: !offEnd(); Post: !isEmpty(), !offEnd()

void LinkedList::insertAfterCurrent(long key, void* data)
{
    if (!offEnd())
    {
        BinaryNode* temp = new BinaryNode(key, data);
        if (current == last)
        {
            last = temp;
        } else
        {
            current->getRight()->setLeft(temp);
        }
        temp->setRight(current->getRight());
        current->setRight(temp);
        temp->setLeft(current);
        current = temp;
    } else {
        insertAfterLast(key, data);
    }
}
// Inserts new element after current one
// Pre: !offEnd(); Post: !isEmpty(), !offEnd()

void LinkedList::insertSorted(long key, void* data)
{
    moveFirst();
    if (!isEmpty())
    {
        while (!offEnd())
        {
            if (current->getKey() > key) {
                insertBeforeCurrent(key, data);
                return;
            }
            moveNext();
        }
    } else
    {
        insertAfterLast(key, data);
    }
}
// Inserts new element in sorted order
// Pre: !offEnd(); Post: !isEmpty()

void LinkedList::setCurrData(void* data)
{
    current->setData(data);
}
// Replaces the data of the current node.
// Pre: !offEnd()

void LinkedList::setData(long key, void* data)
{
    if (isInList(key))
    {
        setCurrData(data);
    }
    
}
// Replaces the data of the first instance of the key.

void LinkedList::sortAscending()
{
    
}
// Sorts the list with the smallest key at the head

void LinkedList::sortDescending()
{
    
}
// Sorts the list with the largest key at the head

void LinkedList::deleteFirst()
{
    if (!isEmpty())
    {
        BinaryNode* temp = first;
        first = first->getRight();
        delete temp;
    }
}
// delete the first element.
// Pre: !isEmpty()

void LinkedList::deleteLast()
{
    if (!isEmpty())
    {
        BinaryNode* temp = last;
        last = last->getLeft();
        delete temp;
    }
}
// delete the last element.
// Pre: !isEmpty()

void LinkedList::deleteCurrent()
{
    if (!offEnd())
    {
        BinaryNode* temp = current;
        if (current == first) {
            first = first->getRight();
        } else
        {
            current->getLeft()->setRight(current->getRight());
        }
        if (current == last) {
            last = last->getLeft();
        } else
        {
            current->getRight()->setLeft(current->getLeft());
        }
        current = current->getRight();
        delete temp;
    }
}
// delete the current element.
// Pre: !isEmpty(), !offEnd(); Post: offEnd()

void LinkedList::deleteKey(long key)
{
    if (isInList(key))
    {
        deleteCurrent();
    }
}
// delete the first instance of the key.
// Pre: !isEmpty()

void LinkedList::forEach(void (*function)(void*))
{
    moveFirst();
    while (!offEnd())
    {
        function(current->getData());
        moveNext();
    }
}
// iterate through the list and do the function for each data



/*** Other operations ***/

void LinkedList::printList()
{
    cout << *this;
}

LinkedList LinkedList::copyList()
{
    return *this;
}

ostream& operator <<(ostream& stream, LinkedList& list) {
    list.moveFirst();
    while (!list.offEnd())
    {
        
        stream << list.current->getKey() << ":\t" << list.current->getData() << endl;
        list.moveNext();
    }
    return stream;
}
