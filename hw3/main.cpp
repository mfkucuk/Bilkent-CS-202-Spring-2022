/*
* Title: Heaps, Priority Queues
* Author: Mehmet Feyyaz Küçük
* ID: 22003550
* Section: 2
* Assignment: 3
* Description: Main program for reading the log file to determine number of min. computers
*/

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

#include "PriorityQueue.h"
#include "Computer.h"

// Helper function for splitting the lines of the log file to strings
string* split(string str, char ch) {
    string* list = new string[10];
    int index = 0;
    string curStr = "";

    for (int i = 0; i < str.length() + 1; i++) {
        if (str[i] != ch) {
            curStr += str[i];
        }
        else {
            list[index++] = curStr;
            curStr = "";
        }
    }

    list[index] = curStr;

    return list;
}

int main(int argc, char* argv[]) {
    fstream logfile;
    int numOfRequests;
    Request* requests;
    PriorityQueue pq;

    // Read the log file
    logfile.open(argv[1], ios::in);
    if (logfile.is_open()) {
        string line;
        int index = 0;
        while (getline(logfile, line)) {

            // Read the number of requests
            if (line.find(" ") == -1) {
                stringstream ss;
                ss << line;
                ss >> numOfRequests;
                requests = new Request[numOfRequests];
            }

            // Read the requests and store them in an array.
            else {
                int id, priority, requestTime, processTime;
                stringstream ss1, ss2, ss3, ss4;

                string* list = split(line, ' ');

                ss1 << list[0];
                ss1 >> id;

                ss2 << list[1];
                ss2 >> priority;

                ss3 << list[2];
                ss3 >> requestTime;

                ss4 << list[3];
                ss4 >> processTime;

                Request newRequest(id, priority, requestTime, processTime);
                requests[index++] = newRequest;

                delete [] list;
            }
        }
    }
    logfile.close();

    Computer* comps;
    int numOfComputers = 0;
    double avgWaitingTime = 0;
    int index = 0;
    int totalWaitingTime = 0;
    bool areAllFree = true;
    stringstream ss;
    ss << argv[2];
    ss >> avgWaitingTime;

    double calculatedAvg;

    // Simulate until minimum number of computers satisfying maximum average waiting time is found
    do {
        numOfComputers++;

        // initalize computers
        comps = new Computer[numOfComputers];
        for (int i = 0; i < numOfComputers; i++) {
            comps[i].id = i;
        }

        calculatedAvg = 0;
        index = 0;
        totalWaitingTime = 0;
        for (int i = 0;; i++) {
            if (index < numOfRequests) {
                while (requests[index].requestTime == (i+1)) {
                    pq.pqInsert(requests[index++]);
                    if (index == numOfRequests) {
                        break;
                    }
                }
            }

            for (int j = 0; j < numOfComputers; j++) {
                if (comps[j].isOccupied()) {
                    comps[j].finishRequest(i+1);
                }

                if (!(comps[j].isOccupied())) {
                    if (!(pq.pqIsEmpty())) {
                        Request newRequest;
                        pq.pqRemove(newRequest);
                        comps[j].takeRequest(newRequest);
                        areAllFree = false;
                        comps[j].timeTaken = i + 1;
                        totalWaitingTime += i + 1 - newRequest.requestTime;
                    }
                }
            }

            if (index >= numOfRequests) {
                areAllFree = true;
                for (int j = 0; j < numOfComputers; j++) {
                    if (comps[j].isOccupied()) {
                        areAllFree = false;
                    }
                }
                if (areAllFree) {
                    break;
                }
            }
        }

        calculatedAvg = (double)totalWaitingTime / numOfRequests;

        delete [] comps;

    } while (calculatedAvg > avgWaitingTime);

    // Simulate with min number of computers
    cout << "Minimum number of computer required: " << numOfComputers << endl;
    cout << endl;

    cout << "Simulation with " << numOfComputers << " computers:" << endl;
    cout << endl;

    // initalize computers
    comps = new Computer[numOfComputers];
    for (int i = 0; i < numOfComputers; i++) {
        comps[i].id = i;
    }

    index = 0;
    for (int i = 0;; i++) {
        if (index < numOfRequests) {
            while (requests[index].requestTime == (i+1)) {
                pq.pqInsert(requests[index++]);
                if (index == numOfRequests) {
                    break;
                }
            }
        }

        for (int j = 0; j < numOfComputers; j++) {
            if (comps[j].isOccupied()) {
                comps[j].finishRequest(i+1);
            }

            if (!(comps[j].isOccupied())) {
                if (!(pq.pqIsEmpty())) {
                    Request newRequest;
                    pq.pqRemove(newRequest);
                    comps[j].takeRequest(newRequest);
                    comps[j].timeTaken = i + 1;
                    totalWaitingTime += i + 1 - newRequest.requestTime;
                    cout << "Computer " << comps[j].id << " takes request " << newRequest.id << " at ms " << (i+1) << " (wait: " << i + 1 - newRequest.requestTime << " ms)" << endl;
                }
            }
        }

        if (index >= numOfRequests) {
            areAllFree = true;
            for (int j = 0; j < numOfComputers; j++) {
                if (comps[j].isOccupied()) {
                    areAllFree = false;
                }
            }
            if (areAllFree) {
                break;
            }
        }
    }

    cout << endl;
    cout << "Average waiting time: " << calculatedAvg << " ms" << endl;

    delete [] comps;
    delete [] requests;

    return 0;
}