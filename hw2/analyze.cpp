/*
* Title: Trees
* Author: Mehmet Feyyaz Küçük
* ID: 22003550
* Section: 2
* Assignment: 2
* Description: A file containing functions for analyzing binary search trees
*/

#include <iostream>
#include <cstdlib>
using namespace std;

#include "BinarySearchTree.h"

void analyzeBST() {
    srand (time(NULL));

    BinarySearchTree bst;
    int* arr = new int[10000];

    // Create array while simultenously adding to the binary search tree.
    cout << "Random BST size vs. height (Insertion)" << endl;
    cout << "---------------------------------------" << endl;

    for (int i = 0; i < 10000; i++) {
        arr[i] = rand() % 100000 + 1;

        bst.add(arr[i]);

        if ((i+1) % 100 == 0) {
            cout << bst.getNumberOfNodes() << "\t" << bst.getHeight() << endl;
        }
    }

    cout << endl;

    // Shuffle the array
    for (int i = 0; i < 10000; i++) {
        int i1 = rand() % 10000;
        int i2 = rand() % 10000;
        int temp;

        temp = arr[i1];
        arr[i1] = arr[i2];
        arr[i2] = temp;
    }

    // Delete elements from binary search tree in a shuffled order.
    cout << "Random BST size vs. height (Deletion)" << endl;
    cout << "---------------------------------------" << endl;

    for (int i = 0; i < 10000; i++) {
        bst.remove(arr[i]);

        if ((i+1) % 100 == 0) {
            cout << bst.getNumberOfNodes() << "\t" << bst.getHeight() << endl;
        }
    }

    delete arr;
}