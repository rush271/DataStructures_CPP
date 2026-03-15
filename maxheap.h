#ifndef MAXHEAP_H
#define MAXHEAP_H

#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

class maxHeap {
private:
	int size;
	int maxsize;
	int* heap;

public:
	maxHeap(); // Constructor.
	~maxHeap(); // Deconstructor.

	void buildMax(string &filename); // Function that builds and initializes a maxHeap.
	void deleteMax(); // Function that deletes the maximum element of the maxHeap.
	void insert(int num); // Function that inserts a value num.
	int findMax(); // Function that returns the maximum element of the maxHeap.
	int getSize(); // Function that returns the size of the maxHeap.
	void reshape(); //Function that sorts the nodes of an unsorted Heap.
	void moveUp(int node); // Function that rearranges the inserted node

};

#endif