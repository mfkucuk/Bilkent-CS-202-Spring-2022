/*
* Title: Heaps, Priority Queues
* Author: Mehmet Feyyaz Küçük
* ID: 22003550
* Section: 2
* Assignment: 3
* Description: Header file for a virtual computer
*/

#ifndef COMPUTER_H
#define COMPUTER_H

#include "Request.h"

class Computer {
    public:
        int id;
        int timeTaken;
        bool occupied;
        Request currentRequest;

        Computer();
        Computer(int id);

        bool isOccupied();
        bool takeRequest(const Request& newRequest);
        bool finishRequest(int time);        
};

#endif