//
//  BinaryNode.h
//  EngineTest
//
//  Created by Chase Bradbury on 2/20/14.
//  Copyright (c) 2014 Chase Bradbury. All rights reserved.
//

#ifndef __EngineTest__BinaryNode__
#define __EngineTest__BinaryNode__

#include <iostream>

class BinaryNode {
    
private:
    long key;
    void* data;
    BinaryNode* left;
    BinaryNode* right;
    
    
public:
    
    /*** Constructor ***/
    
    BinaryNode(long key, void* data);
    // Constructs a new node with a key and data.
    
    
    /*** Access functions ***/
    
    long getKey();
    // Returns the key of the node.
    
    void* getData();
    // Returns the data of the node.
    
    BinaryNode* getLeft();
    // Returns a reference to the node to the left.
    // pre: hasLeft()
    
    BinaryNode* getRight();
    // Returns a reference to the node to the right.
    // pre: hasRight()
    
    bool hasLeft();
    // Returns true if there is a node to the left.
    
    bool hasRight();
    // Returns true if there is a node to the right.
    
    
    
    /*** Manipulation function ***/
    
    void setKey(long key);
    // Changes the key to a new key.
    
    void setData(void* data);
    // Changes the data to new data.
    
    void setLeft(BinaryNode*);
    // Changes the node to the left.
    
    void setRight(BinaryNode*);
    // Changes the node to the right.
    
    void detachLeft();
    // Makes left NULL.
    
    void detachRight();
    // Makes right NULL;
};

    

#endif /* defined(__EngineTest__BinaryNode__) */
