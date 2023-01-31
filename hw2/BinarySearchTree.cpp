/*
* Title: Trees
* Author: Mehmet Feyyaz Küçük
* ID: 22003550
* Section: 2
* Assignment: 2
* Description: Binary search tree implementation class
*/

#include <iostream>
using namespace std;

#include "BinarySearchTree.h"

BinarySearchTree::BinarySearchTree() {
    root = NULL;
}

BinarySearchTree::~BinarySearchTree() {
    while (root != NULL) {
        remove(root->value);
    }
}

bool BinarySearchTree::isEmpty() {
    return root == NULL;
}

int BinarySearchTree::getHeight() {
    return getHeight(root);
}

int BinarySearchTree::getHeight(BinaryNode* treeNode) {
    if (treeNode == NULL) {
        return 0;
    }

    int lHeight = getHeight(treeNode->leftPtr);
    int rHeight = getHeight(treeNode->rightPtr);

    if (lHeight > rHeight) {
        return lHeight + 1;
    }

    return rHeight + 1;
}

int BinarySearchTree::getNumberOfNodes() {
    return root == NULL ? 0 : root->size + 1;
}

bool BinarySearchTree::add(int newEntry) {

    return add(root, newEntry);
} 

bool BinarySearchTree::add(BinaryNode* treeNode, int newEntry) {

    if (newEntry <= 0 || contains(newEntry)) {
        return false;
    }

    if (root == NULL) {
        BinaryNode* newNode = new BinaryNode;
        newNode->value = newEntry;
        newNode->parent = treeNode;
        root = newNode;
        return true;
    }

    while (treeNode != NULL) {
        treeNode->size++;
        if (treeNode->value < newEntry) {
            if (treeNode->rightPtr != NULL) {
                treeNode = treeNode->rightPtr;
            }
            else {
                BinaryNode* newNode = new BinaryNode;
                newNode->value = newEntry;
                newNode->parent = treeNode;
                treeNode->rightPtr = newNode;
                return true;
            }
        }
        else {
            if (treeNode->leftPtr != NULL) {
                treeNode = treeNode->leftPtr;
            }
            else {
                BinaryNode* newNode = new BinaryNode;
                newNode->value = newEntry;
                newNode->parent = treeNode;
                treeNode->leftPtr = newNode;
                return true;
            }
        }
    }

    return false;
}

bool BinarySearchTree::remove(int anEntry) {
    return remove(root, anEntry);
}

bool BinarySearchTree::remove(BinaryNode*& treeNode, int anEntry) {

    if (!contains(anEntry)) {
        return false;
    }

    treeNode->size--;

    // if the value is equal to the given entry, we are the node the be deleted.
    if (treeNode->value == anEntry) {
        return removeNode(treeNode);
    }

    else if (treeNode->value < anEntry) {
        return remove(treeNode->rightPtr, anEntry);
    }
    else {
        return remove(treeNode->leftPtr, anEntry);
    }

}

bool BinarySearchTree::removeNode(BinaryNode*& treeNode) {

    int repValue;
    BinaryNode* tempNode;


    // test for leaf node
    if (treeNode->leftPtr == NULL && treeNode->rightPtr == NULL) {
        delete treeNode;
        treeNode = NULL;
        return true;
    }

    // test for node with only right child
    else if (treeNode->leftPtr == NULL) {
        tempNode = treeNode;
        treeNode = treeNode->rightPtr;
        delete tempNode;
        return true;
    }

    // test for node with only left child
    else if (treeNode->rightPtr == NULL) {
        tempNode = treeNode;
        treeNode = treeNode->leftPtr;
        delete tempNode;
        return true;
    }

    // test for node with both children
    else {
        processInorderSuccessor(treeNode->rightPtr, repValue);
        treeNode->value = repValue;
        return true;
    }

    return false;
}

void BinarySearchTree::processInorderSuccessor(BinaryNode*& treeNode, int& repValue) {
    if (treeNode->leftPtr == NULL) {
        repValue = treeNode->value;
        BinaryNode* temp = treeNode;
        treeNode = treeNode->rightPtr;
        delete temp;
    }
    else {
        processInorderSuccessor(treeNode->leftPtr, repValue);
    }
}

bool BinarySearchTree::contains(int anEntry) {
    BinaryNode* cur = root;

    while (cur != NULL) {
        if (cur->value == anEntry) {
            return true;
        }
        else if (cur->value < anEntry) {
            cur = cur->rightPtr;
        }
        else {
            cur = cur->leftPtr;
        }
    }

    return false;
}

void BinarySearchTree::inorderTraverse() {
    inorderTraverse(root);
    cout << endl;
}

void BinarySearchTree::inorderTraverse(BinaryNode* treeNode) {

    if (treeNode == NULL) {
        return;
    }
        
    // Visit the left subtrees first.
    inorderTraverse(treeNode->leftPtr);

    // Visit the node in the middle.
    cout << treeNode->value << " ";

    // Visit the right subtrees
    inorderTraverse(treeNode->rightPtr);

}

int BinarySearchTree::getWidth() {
    return getWidth(root);
}

int BinarySearchTree::getWidth(BinaryNode* treeNode) {
    int maxWidth = 0;

    for (int i = 1; i <= getHeight(); i++) {
        int width = getWidth(treeNode, i);
        if (width > maxWidth) {
            maxWidth = width;
        }
    }

    return maxWidth;
}

int BinarySearchTree::getWidth(BinaryNode* treeNode, int height) {
    if (treeNode == NULL) {
        return 0;
    }
    else if (height == 1) {
        return 1;
    }

    return getWidth(treeNode->leftPtr, height - 1) + getWidth(treeNode->rightPtr, height - 1);
}

int BinarySearchTree::count(int a, int b) {
    int counter = 0;
    countNode(root, a, b, counter);
    return counter;
}

void BinarySearchTree::countNode(BinaryNode* treeNode, int a, int b, int& counter) {

    if (treeNode == NULL) {
        return;
    }

    // Visit the left subtrees first.
    if (treeNode->value >= a) {
        countNode(treeNode->leftPtr, a, b, counter);
    }

    // Visit the node in the middle.
    if (treeNode->value >= a && treeNode->value <= b) {
        counter++;
    }

    // Visit the right subtrees
    if (treeNode->value <= b) {
        countNode(treeNode->rightPtr, a, b, counter);
    }
}

int BinarySearchTree::select(int anEntry) {
    int index = 0;
    bool found = false;
    incrementIndex(root, anEntry, index, found);

    if (getNumberOfNodes() <= index) {
        return -1;
    }
    else {
        return index;
    }
}

void BinarySearchTree::incrementIndex(BinaryNode* treeNode, int anEntry, int& index, bool& found) {
    if (treeNode == NULL || found) {
        return;
    }

    // Visit the left subtrees first.
    incrementIndex(treeNode->leftPtr, anEntry, index, found);

    // Visit the node in the middle.
    if (treeNode->value == anEntry) {
        found = true;
        return;
    }
    else if (!found) {
        index++;
    }

    // Visit the right subtrees
    incrementIndex(treeNode->rightPtr, anEntry, index, found);

}

int BinarySearchTree::successor(int anEntry) {
    if (!contains(anEntry)) {
        return -1;
    }

    if (getNumberOfNodes() == select(anEntry) + 1) {
        return -2;
    }

    BinaryNode* cur = root;

    while (root != NULL) {
        if (select(cur->value) == select(anEntry) + 1) {
            return cur->value;
        }

        if (select(cur->value) > select(anEntry) + 1) {
            cur = cur->leftPtr;
        }
        else {
            cur = cur->rightPtr;
        }
    }

    return -1;
}
