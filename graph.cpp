#include "graph.h"

Graph::Graph() {
    maxNodes = 10;
    numNodes = 0;
    nodes = new int[maxNodes];

    adjMatrix = new int*[maxNodes];
    for (int i = 0; i < maxNodes; i++) {
        adjMatrix[i] = new int[maxNodes];
        for (int j = 0; j < maxNodes; j++)
            adjMatrix[i][j] = 0;
    }
}

Graph::~Graph() {
    for (int i = 0; i < maxNodes; i++)
        delete[] adjMatrix[i];
    delete[] adjMatrix;
    delete[] nodes;
}

void Graph::resize() {
    int newMax = maxNodes * 2;

    // New nodes array
    int* newNodes = new int[newMax];
    for (int i = 0; i < numNodes; i++)
        newNodes[i] = nodes[i];

    // New adjacency matrix
    int** newMatrix = new int*[newMax];
    for (int i = 0; i < newMax; i++) {
        newMatrix[i] = new int[newMax];
        for (int j = 0; j < newMax; j++)
            newMatrix[i][j] = 0;
    }

    // Copy old adjacency data
    for (int i = 0; i < numNodes; i++)
        for (int j = 0; j < numNodes; j++)
            newMatrix[i][j] = adjMatrix[i][j];

    // Free old memory
    for (int i = 0; i < maxNodes; i++)
        delete[] adjMatrix[i];
    delete[] adjMatrix;
    delete[] nodes;

    nodes = newNodes;
    adjMatrix = newMatrix;
    maxNodes = newMax;
}

int Graph::findNode(int node) {
    for (int i = 0; i < numNodes; i++)
        if (nodes[i] == node)
            return i;
    return -1;
}

int Graph::addNode(int node) {
    int idx = findNode(node);
    if (idx != -1) return idx; // Node already exists

    if (numNodes == maxNodes)
        resize();

    nodes[numNodes] = node;
    return numNodes++;
}

void Graph::buildGraph(string &filename) {
    ifstream fin(filename);
    if (fin.is_open()) {
        int u, v;
        while (fin >> u >> v)
            addEdge(u, v);
        fin.close();
    }
}

void Graph::addEdge(int u, int v) {
    int idxU = addNode(u);
    int idxV = addNode(v);
    adjMatrix[idxU][idxV] = 1;
    adjMatrix[idxV][idxU] = 1; // Undirected graph
}

string Graph::search(int node) {
    if (findNode(node) != -1)
        return "SUCCESS";
    return "FAILURE";
}

int Graph::getSize() {
    return numNodes;
}

string Graph::BFS(int startNode) {
    int startIdx = findNode(startNode);
    if (startIdx == -1) return "Node not found";

    bool* visited = new bool[numNodes];
    for (int i = 0; i < numNodes; i++)
        visited[i] = false;

    int* queue = new int[numNodes];
    int* order = new int[numNodes];
    int front = 0, back = 0, orderSize = 0;

    visited[startIdx] = true;
    queue[back++] = startIdx;

    while (front < back) {
        int curr = queue[front++];
        order[orderSize++] = nodes[curr];

        for (int i = 0; i < numNodes; i++) {
            if (adjMatrix[curr][i] == 1 && !visited[i]) {
                visited[i] = true;
                queue[back++] = i;
            }
        }
    }

    string result = "";
    for (int i = 0; i < orderSize; i++) {
        result += to_string(order[i]);
        if (i < orderSize - 1)
            result += " -> ";
    }

    delete[] visited;
    delete[] queue;
    delete[] order;
    return result;
}

void Graph::dfsHelper(int index, bool* visited, int* order, int &orderSize) {
    visited[index] = true;
    order[orderSize++] = nodes[index];

    for (int i = 0; i < numNodes; i++) {
        if (adjMatrix[index][i] == 1 && !visited[i])
            dfsHelper(i, visited, order, orderSize);
    }
}

string Graph::DFS(int startNode) {
    int startIdx = findNode(startNode);
    if (startIdx == -1) return "Node not found";

    bool* visited = new bool[numNodes];
    int* order = new int[numNodes];
    int orderSize = 0;

    for (int i = 0; i < numNodes; i++)
        visited[i] = false;

    dfsHelper(startIdx, visited, order, orderSize);

    string result = "";
    for (int i = 0; i < orderSize; i++) {
        result += to_string(order[i]);
        if (i < orderSize - 1)
            result += " -> ";
    }

    delete[] visited;
    delete[] order;
    return result;
}
