/*
* Title: Trees
* Author: Mehmet Feyyaz Küçük
* ID: 22003550
* Section: 2
* Assignment: 2
* Description: Binary search tree header class
*/

#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include "BinaryNode.h"

class BinarySearchTree {
    public:
        BinarySearchTree();
        ~BinarySearchTree();

        bool isEmpty();
        int getHeight();
        int getNumberOfNodes();
        bool add(int newEntry);
        bool remove(int anEntry);
        bool contains(int anEntry);
        void inorderTraverse();
        int getWidth();
        int count(int a, int b);
        int select(int anEntry);
        int successor(int anEntry);

    private:
        BinaryNode* root;

        bool add(BinaryNode* treeNode, int newEntry);
        bool remove(BinaryNode*& treeNode, int anEntry);
        bool removeNode(BinaryNode*& treeNode);
        void processInorderSuccessor(BinaryNode*& treeNode, int& repValue);
        void inorderTraverse(BinaryNode* treeNode);
        void countNode(BinaryNode* treeNode, int a, int b, int& counter);
        void incrementIndex(BinaryNode* treeNode, int anEntry, int& index, bool& found);
        int getHeight(BinaryNode* treeNode);
        int getWidth(BinaryNode* treeNode, int height);
        int getWidth(BinaryNode* treeNode);
};

#endif