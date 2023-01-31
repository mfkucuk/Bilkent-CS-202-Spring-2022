/*
* Title: Heaps, Priority Queues
* Author: Mehmet Feyyaz Küçük
* ID: 22003550
* Section: 2
* Assignment: 3
* Description: Implementation of heap data structure
*/

#include <iostream>
using namespace std;

#include "Heap.h"

Heap::Heap() {
    items = new Request[100000];
    size = 0;
}

Heap::~Heap() {
    delete [] items;
}

bool Heap::isEmpty() const {
    return size == 0;
}

void Heap::insert(const Request& newItem) {
    int place = size;
    int parent = (place - 1) / 2;
    Request temp;

    items[size] = newItem;

    while ((place > 0) && (items[parent].actualPriority() < items[place].actualPriority())) {
        temp = items[place];
        items[place] = items[parent];
        items[parent] = temp;

        place = parent;
        parent = (place - 1) / 2;
    }
    size++;
}

void Heap::remove(Request& rootItem) {
    if (isEmpty()) {
        return;
    }
    else {
        rootItem = items[0];
        items[0] = items[--size];
        rebuild(0);
    }
}

void Heap::rebuild(int root) {
    int child;
    int leftChild = 2 * root + 1;
    Request temp;
    if (leftChild < size) {
        int rightChild = leftChild + 1;

        if (rightChild < size) {
            if (items[rightChild].actualPriority() > items[leftChild].actualPriority()) {
                child = rightChild;
            }
            else {
                child = leftChild;
            }
        }

        if (items[root].actualPriority() < items[child].actualPriority()) {
            temp = items[root];
            items[root] = items[child];
            items[child] = temp;

            rebuild(child);
        }
    }
}