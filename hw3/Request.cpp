/*
* Title: Heaps, Priority Queues
* Author: Mehmet Feyyaz Küçük
* ID: 22003550
* Section: 2
* Assignment: 3
* Description: Implementation of HTTP requests
*/

#include "Request.h"

Request::Request() {
    id = -1;
    priority = -1;
    requestTime = -1;
    processTime = -1;
}

Request::Request(int id, int priority, int requestTime, int processTime) {
    this->id = id;
    this->priority = priority;
    this->requestTime = requestTime;
    this->processTime = processTime;
}


double Request::actualPriority() {
    return priority + (1 / ((double) requestTime));
}