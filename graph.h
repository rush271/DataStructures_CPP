#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

class Graph {
private:
    int* nodes;       // Array of node values
    int** adjMatrix;  // Adjacency matrix
    int numNodes;     // Current number of nodes
    int maxNodes;     // Max capacity

    int findNode(int node);                                          // Returns index of node, -1 if not found
    int addNode(int node);                                           // Adds node if not exists, returns index
    void resize();                                                   // Doubles capacity
    void dfsHelper(int index, bool* visited, int* order, int &orderSize); // Recursive DFS helper

public:
    Graph();   // Constructor
    ~Graph();  // Destructor

    void buildGraph(string &filename); // Builds graph from file (each line: u v)
    void addEdge(int u, int v);        // Adds undirected edge between u and v
    string search(int node);           // Returns SUCCESS if node exists, FAILURE otherwise
    int getSize();                     // Returns number of nodes
    string BFS(int startNode);         // Breadth-First Search traversal from startNode
    string DFS(int startNode);         // Depth-First Search traversal from startNode
};

#endif
