/*
* Title: Heaps, Priority Queues
* Author: Mehmet Feyyaz Küçük
* ID: 22003550
* Section: 2
* Assignment: 3
* Description: Implementation of the virtual computer
*/

#include <iostream>
using namespace std;

#include "Computer.h"

Computer::Computer() {
    id = -1;
    timeTaken = 0;
    occupied = false;
}

Computer::Computer(int id) {
    this->id = id;
    timeTaken = 0;
    occupied = false;
}

bool Computer::isOccupied() {
    return occupied;
}

bool Computer::takeRequest(const Request& newRequest) {
    currentRequest = newRequest;
    occupied = true;
    return true;
}

bool Computer::finishRequest(int time) {
    if (currentRequest.processTime + timeTaken == time) {
        occupied = false;
        return true;
    }
    return false;
}