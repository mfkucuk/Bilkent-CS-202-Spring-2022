/*
* Title: Trees
* Author: Mehmet Feyyaz Küçük
* ID: 22003550
* Section: 2
* Assignment: 2
* Description: Binary node implementation class
*/

#include <iostream>
using namespace std;

#include "BinaryNode.h"

BinaryNode::BinaryNode() {
    value = 0;
    rightPtr = NULL;
    leftPtr = NULL;
    size = 0;
    parent = NULL;
}

BinaryNode::BinaryNode(const int& nodeItem, BinaryNode* left, BinaryNode* right) {
    rightPtr = new BinaryNode;
    leftPtr = new BinaryNode;

    rightPtr->value = right->value;
    leftPtr->value = left->value;
    this->value = nodeItem;
}