//
//  BinaryNode.cpp
//  EngineTest
//
//  Created by Chase Bradbury on 2/20/14.
//  Copyright (c) 2014 Chase Bradbury. All rights reserved.
//

#include "BinaryNode.h"

BinaryNode::BinaryNode(long new_key, void* new_data)
{
    key = new_key;
    data = new_data;
}
// Constructs a new node with a key and data.


/*** Access functions ***/

long BinaryNode::getKey()
{
    return key;
}
// Returns the key of the node.

void* BinaryNode::getData()
{
    return data;
}
// Returns the data of the node.

BinaryNode* BinaryNode::getLeft()
{
    return left;
}
// Returns a reference to the node to the left.
// pre: hasLeft()

BinaryNode* BinaryNode::getRight()
{
    return right;
}
// Returns a reference to the node to the right.
// pre: hasRight()

bool BinaryNode::hasLeft()
{
    return left != NULL;
}
// Returns true if there is a node to the left.

bool BinaryNode::hasRight()
{
    return right != NULL;
}
// Returns true if there is a node to the right.



/*** Manipulation function ***/

void BinaryNode::setKey(long new_key)
{
    key = new_key;
}
// Changes the key to a new key.

void BinaryNode::setData(void* new_data)
{
    data = new_data;
}
// Changes the data to new data.

void BinaryNode::setLeft(BinaryNode* node)
{
    left = node;
}
// Changes the node to the left.

void BinaryNode::setRight(BinaryNode* node)
{
    right = node;
}
// Changes the node to the right.

void BinaryNode::detachLeft()
{
    left = NULL;
}
// Makes left NULL.

void BinaryNode::detachRight()
{
    right = NULL;
}
// Makes right NULL;