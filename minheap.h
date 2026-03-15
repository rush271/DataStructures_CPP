#ifndef MINHEAP_H
#define MINHEAP_H

#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

class minHeap {
private:
	int size;
	int maxsize;
	int* heap;

public:
	minHeap(); // Constructor.
	~minHeap(); // Deconstructor.

	void buildMin(string &filename); // Function that builds and initializes a minHeap.
	void deleteMin(); // Function that deletes the minimum element of the minHeap.
	void insert(int num); // Function that inserts a value num.
	int findMin(); // Function that returns the minimum element of the minHeap.
	int getSize(); // Function that returns the size of the minHeap.
	void reshape(); //Function that sorts the nodes of an unsorted Heap.
	void moveUp(int node); // Function that rearranges the inserted node
};

#endif