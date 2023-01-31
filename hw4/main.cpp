#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

#include "FlightMapGraph.h"

// Helper function for splitting the lines of the log file to strings
string* split(string str, char ch) {
    string* list = new string[10];
    int j = 0;
    string cur = "";

    for (int i = 0; i < str.length() + 1; i++) {
        if (str[i] != ch) {
            cur += str[i];
        }
        else {
            list[j++] = cur;
            cur = "";
        }
    }

    list[j] = cur;

    return list;
}

int main(int argc, char** argv) {

    // Create the graph for flight map

    FlightMapGraph fmg;

    string filename = argv[argc - 1];
    fstream flightFile;

    int numOfAirports;
    int numOfInstructions;

    flightFile.open(filename, ios::in);
    if (flightFile.is_open()) {
        string line;
        int fileIndex = 0;

        while (getline(flightFile, line)) {
            if (fileIndex == 0) {
                stringstream ssAirports;
                ssAirports << line;
                ssAirports >> numOfAirports;

                fmg.initGraph(numOfAirports);
            }
            else if (fileIndex == 1) {
                stringstream ssInstructions;
                ssInstructions << line;
                ssInstructions >> numOfInstructions;
            }
            else {
                string* list;
                list = split(line, ' ');

                // Flight Insertion
                if (line[0] == 'I') {
                    stringstream ss1, ss2, ss3;
                    int v1, v2, w;

                    ss1 << list[1];
                    ss1 >> v1;

                    ss2 << list[2];
                    ss2 >> v2;

                    ss3 << list[3];
                    ss3 >> w;

                    fmg.insertFlight(v1, v2, w);
                }

                // List flights
                else if (line[0] == 'L') {
                    stringstream ss1;
                    int u;

                    ss1 << list[1];
                    ss1 >> u;

                    fmg.listFlights(u); 
                }

                // Find shortest path
                else if (line[0] == 'S') {

                }

                // Minimize cost
                else {

                }

                delete[] list;
            }

            fileIndex++;
        }
    }
    flightFile.close();

    return 0;
}