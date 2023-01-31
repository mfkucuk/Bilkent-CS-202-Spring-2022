/*
* Title: Heaps, Priority Queues
* Author: Mehmet Feyyaz Küçük
* ID: 22003550
* Section: 2
* Assignment: 3
* Description: Header file for heap data structure
*/

#ifndef HEAP_H
#define HEAP_H

#include "Request.h"

class Heap {
    public:
        Heap();
        ~Heap();

        bool isEmpty() const;
        void insert(const Request& newItem);
        void remove(Request& rootItem);

    protected:
        void rebuild(int root);

    private:
        Request* items;
        int size;
};

#endif