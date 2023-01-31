/*
* Title: CS202 Spring 2022
* Author: Mehmet Feyyaz Küçük
* ID: 22003550
* Section: 2
* Assignment: 4
* Description: Header file for graph data-structure.
*/

#include <iostream>
using namespace std;

#ifndef GRAPH_H
#define GRAPH_H

struct Node {
    int val;
    int cost;
    Node* next;
};

struct Edge {
    int v1, v2, weight;
};

class FlightMapGraph {

    public:
        FlightMapGraph();
        FlightMapGraph(int numOfVertices);
        ~FlightMapGraph();

        Node* addAdjListNode(Node*& head, int vertexNo, int weight);
        void initGraph(int numOfVertices);
        bool insertFlight(int v1, int v2, int weight);
        void listFlights(int u);
        bool findShortestPath(int v1, int v2);
        void minimizeCost();

        Node** head;
        int numOfVertices;
};

#endif