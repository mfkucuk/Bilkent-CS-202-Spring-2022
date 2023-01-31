/*
* Title: Heaps, Priority Queues
* Author: Mehmet Feyyaz Küçük
* ID: 22003550
* Section: 2
* Assignment: 3
* Description: Header file for HTTP requests
*/

#ifndef REQUEST_H
#define REQUEST_H

class Request {
    public:
        Request();
        Request(int id, int priority, int requestTime, int processTime);

        double actualPriority();

        int id;
        int priority;
        int requestTime;
        int processTime;
};

#endif