/*
* Title: Trees
* Author: Mehmet Feyyaz Küçük
* ID: 22003550
* Section: 2
* Assignment: 2
* Description: Binary node header class
*/

#ifndef BINARYNODE_H
#define BINARYNODE_H

class BinaryNode {
    public:
        BinaryNode();
        BinaryNode(const int& nodeItem, BinaryNode* left, BinaryNode* right);

        int value;
        BinaryNode* rightPtr;
        BinaryNode* leftPtr;
        int size;
        BinaryNode* parent;
};

#endif