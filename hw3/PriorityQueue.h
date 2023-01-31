/*
* Title: Heaps, Priority Queues
* Author: Mehmet Feyyaz Küçük
* ID: 22003550
* Section: 2
* Assignment: 3
* Description: Header file for priority queue data structure
*/

#include "Heap.h"

#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H

class PriorityQueue {
    public:
        PriorityQueue();
        ~PriorityQueue();

        bool pqIsEmpty() const;
        void pqInsert(const Request& newItem);
        void pqRemove(Request& rootItem);

    private:
        Heap h;
};

#endif