#include "maxheap.h"

maxHeap :: maxHeap () {
	size=0;
	maxsize=10;
	heap=new int[maxsize];
}

maxHeap :: ~maxHeap() {
	delete[] heap;
}

void maxHeap :: buildMax(string &filename) {
	ifstream fin(filename);
	if (fin.is_open()) {
		int num;
		while(fin>>num) {
			insert(num);
		}
	}
	fin.close();
}

void maxHeap :: insert(int num) {
	int* neoheap;
	if (size == maxsize) {
		maxsize*=2;
		neoheap=new int[maxsize]; // Make enough space for a new heap

		for (int i=0; i<size; i++) {
			neoheap[i]=heap[i]; // Transfer all data from the old heap to the new heap
		}

		delete[] heap; // Delete old heap
		heap = neoheap; // Rename new heap
	}

	heap[size] = num; // Insert num
	int lastnode = size; //Define the index of the inserted value
	moveUp(lastnode); // Rearrange the inserted node
	size++;
}

void maxHeap :: moveUp(int node) {
	int parent = (node - 1) /2; //Defining the parent of the inserted node
	if (heap[node] > heap[parent]) {
		swap(heap[parent],heap[node]); // Swapping values if the heap is unsorted
		moveUp(parent); // Calling this function again so it repeats for the rest of the heap's parents
	}
}

int maxHeap :: findMax() {
    reshape();
	return heap[0]; // Returns the maximum value of the maxHeap
}

int maxHeap :: getSize() {
	return size; // Returns the size of the maxHeap
}

void maxHeap :: reshape() {
	for (int i=(size-1)/2; i>=0; i--) {
		int parent = i ; // Redifine parent's node as forLoop continues

		while(true) {
			int left = (2 * parent) + 1; // Parent's left child
			int right = (2 * parent) + 2; // Parent's right child
			int largest = parent;

			if (left < size && heap[left] > heap[largest]) {
				largest = left;
			}

			if (right < size && heap[right] > heap[largest]) {
				largest = right;
			}

			if (parent != largest) {
				swap(heap[parent], heap[largest]);
				parent = largest;
			} else
				break;
		}
	}
}

void maxHeap :: deleteMax() {
    if (size == 0){ // In case the heap is empty
        return;
    }
    heap[0]=heap[size-1];
    size--;
    reshape();
}

