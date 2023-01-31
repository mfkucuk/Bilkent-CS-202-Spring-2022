/*
* Title: Heaps, Priority Queues
* Author: Mehmet Feyyaz Küçük
* ID: 22003550
* Section: 2
* Assignment: 3
* Description: Implementation file for priority queue data structure
*/

#include "PriorityQueue.h"

PriorityQueue::PriorityQueue() {

}

PriorityQueue::~PriorityQueue() {
    
}


bool PriorityQueue::pqIsEmpty() const {
    return h.isEmpty();
}

void PriorityQueue::pqInsert(const Request& newItem) {
    h.insert(newItem);
}

void PriorityQueue::pqRemove(Request& rootItem) {
    h.remove(rootItem);
}