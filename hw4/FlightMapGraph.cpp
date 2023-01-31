/*
* Title: CS202 Spring 2022
* Author: Mehmet Feyyaz Küçük
* ID: 22003550
* Section: 2
* Assignment: 4
* Description: Implementation of graph data-structure.
*/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#include "FlightMapGraph.h"

FlightMapGraph::FlightMapGraph() {

}

FlightMapGraph::FlightMapGraph(int numOfVertices) {
    this->numOfVertices = numOfVertices;
    head = new Node*[numOfVertices];

    for (int i = 0; i < numOfVertices; i++) {
        head[i] = NULL;
    }
};

FlightMapGraph::~FlightMapGraph() {
    for (int i = 0; i < numOfVertices; i++) {
        delete[] head[i];
    }

    delete[] head;
}

Node* FlightMapGraph::addAdjListNode(Node*& head, int vertexNo, int weight) {
    
    // Allocate memory for a new node.
    Node* newNode = new Node;

    // Define the node.
    newNode->val = vertexNo;
    newNode->cost = weight;

    // Insert the node at the beginning
    newNode->next = head;
    head = newNode;

    return newNode;
}

void FlightMapGraph::initGraph(int numOfVertices) {
    this->numOfVertices = numOfVertices;
    head = new Node*[numOfVertices]();

    for (int i = 0; i < numOfVertices; i++) {
        head[i] = NULL;
    }
}

bool FlightMapGraph::insertFlight(int v1, int v2, int weight) {

    int count = 0;  // Number of flights from v1.

    // Add both vertices to each other's linked list.
    addAdjListNode(head[v1], v2, weight);
    addAdjListNode(head[v2], v1, weight);

    for (Node* cur = head[v1]; cur != NULL; cur = cur->next) {
        count++;
    }

    cout << "Inserted a new flight between " << v1 << " and " << v2 << "." << endl;
    cout << "\tThe number of flights from " << v1 << " is " << count << "." << endl;

    return true;
}

void FlightMapGraph::listFlights(int u) {

    int count = 0;  // Number of flights from u.

    cout << "List of flights from " << u << ":" << endl;

    for (Node* cur = head[u]; cur != NULL; cur = cur->next) {
        cout << "\t" << u << " to " << cur->val << " with a duration of " << cur->cost << "." << endl;
        count++;
    }

    cout << "\tThe number of flights is " << count << "." << endl;
}

bool FlightMapGraph::findShortestPath(int v1, int v2) {

    // Shortest past
    int path[numOfVertices] = {-1};
    int pathIndex = 0;

    // We need an array to show us which vertices are visited.
    bool visited[numOfVertices] = {false};

    // First vertex in the shortest path is v1.
    path[pathIndex++] = v1;

    int u = v1; // current vertex

    int weight[numOfVertices] = {INT_MAX};
    for (Node* cur = head[u]; cur != NULL; cur = cur->next) {
        weight[cur->val] = cur->cost;
    }

    // Mark v1 as visited.
    visited[v1] = true;

    while (u != v2) {

        // Find the vertex with minimum weight which is not visited.
        int minW = -1;
        for (Node* cur = head[u]; cur != NULL; cur = cur->next) {
            if (minW > cur->cost && !visited[cur->val]) {
                minW = cur->cost;
                u = cur->val;
            }
        }

        // Mark the vertex with minimum weight as visited.
        visited[u] = true;

        // Update the weight array.
        for (Node* cur = head[u]; cur != NULL; cur = cur->next) {
            if (weight[cur->val] > weight[u] + cur->cost && !visited[cur->val]) {
                weight[cur->val] = weight[u] + cur->cost;
            }
        }



    }


    
    return true;
}

void FlightMapGraph::minimizeCost() {
    
}