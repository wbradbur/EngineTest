//
//  LinkedList.h
//  EngineTest
//
//  Created by Chase Bradbury on 12/19/13.
//  Copyright (c) 2013 Chase Bradbury. All rights reserved.
//

#ifndef __EngineTest__LinkedList__
#define __EngineTest__LinkedList__

#include <iostream>
#include "BinaryNode.h"
using namespace std;

/* Node structure */
typedef struct node_t* noderef;

class LinkedList {
    
private:
    
    BinaryNode* first;
    BinaryNode* last;
    BinaryNode* current;
    
public:
    
    /*** Access functions ***/
    
    bool isEmpty();
	// returns true is list is empty else returns false.
    
    bool isInList(long key);
    // Returns true if the key is in the list.
    
    bool offEnd();
	// returns true is current == NULL
    
    bool atFirst();
	// returns true if current == first and !offEnd()
    
    bool atLast();
	// returns true if current == last and !offEnd()
    
    long firstKey();
	// return the first key
    // pre: !isEmpty()
    
    long lastKey();
	// return the last key
	// pre: !isEmpty()
    
    long currentKey();
	// return the current key
	// pre: !offEnd()
    
    void* firstData();
    // return the generic value of first data
    // pre: !isEmpty()
    
    void* lastData();
    // return the generic value of last data
    // pre: !isEmpty()
    
    void* currentData();
    // return the generic value of current data
    // pre: !offEnd()
    
    void* getData(long key);
    // Returns the data of the key in the list. Returns null if not found
    
    int getLength();
	// return the length of the list
    
    bool equalsKeys(LinkedList other);
	// return true iff the two lists have the same keys in the same order
    
    bool equalsExact(LinkedList other);
    // return true iff the two lists have the same key-data pairs in the same order
    
    
    
    /*** Manipulation procedures ***/
    
    void makeEmpty();
	// make the list empty.
	// Post: isEmpty()
    
    void moveFirst();
	// set current marker to the first element in the list
	// Pre: !isEmpty(); Post: !offEnd()
    
    void moveLast();
	// set current marker to the last element in the list
	// Pre: !isEmpty(); Post: !offEnd()
    
    void movePrev();
	// set current marker one step backward.
	// Pre: !offEnd(); Post: offEnd() only if atFirst() was true
    
    void moveNext();
	// set current marker one step forward.
	// Pre: !offEnd(); Post: offEnd() only if atLast() was true
    
    void insertBeforeFirst(long key, void* data);
	// Inserts new element before first
	// Post: !isEmpty()
    
    void insertAfterLast(long key, void* data);
	// Inserts new element after last one
	// Post: !isEmpty()
    
    void insertBeforeCurrent(long key, void* data);
	// Inserts new element before current one
	// Pre: !offEnd(); Post: !isEmpty(), !offEnd()
    
    void insertAfterCurrent(long key, void* data);
	// Inserts new element after current one
	// Pre: !offEnd(); Post: !isEmpty(), !offEnd()
    
    void insertSorted(long key, void* data);
    // Inserts new element in sorted order
    // Pre: !offEnd(); Post: !isEmpty()
    
    void setCurrData(void* data);
    // Replaces the data of the current node.
    // Pre: !offEnd()
    
    void setData(long key, void* data);
    // Replaces the data of the first instance of the key.
    
    void sortAscending();
    // Sorts the list with the smallest key at the head
    
    void sortDescending();
    // Sorts the list with the largest key at the head
    
    void deleteFirst();
	// delete the first element.
	// Pre: !isEmpty()
    
    void deleteLast();
	// delete the last element.
	// Pre: !isEmpty()
    
    void deleteCurrent();
	// delete the current element.
	// Pre: !isEmpty(), !offEnd(); Post: offEnd()
    
    void deleteKey(long key);
    // delete the first instance of the key.
    // Pre: !isEmpty()
    
    void forEach(void (*function)(void*));
    // iterate through the list and do the function for each data
    
    
    
    /*** Utility operations ***/
    
    void printList();
    
    LinkedList copyList();
    
    LinkedList operator +(LinkedList);
    
    LinkedList operator -(LinkedList);
    
    LinkedList operator ==(LinkedList);
    
    
    
    friend ostream& operator <<(ostream& stream, LinkedList& list);
};

ostream& operator <<(ostream& stream, LinkedList& list);

#endif /* defined(__EngineTest__LinkedList__) */
