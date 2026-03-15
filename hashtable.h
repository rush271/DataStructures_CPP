#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

class hashTable {
private:
    int size;
    int maxsize;
    int* htable;

public:
    hashTable(); // Constructor.
    ~hashTable(); // Deconstructor.
    
    void buildHash(string &filename); // Function that builds and initializes a hashhable.
    void insert(int num); // Function that inserts a value num into the hashtable.
    string search(int num); // Function that searches for num.
    int getSize(); // Function that returns the size of the hashtable.
    void doubleSize(); // Function that doubles the size of the hashtable.
    int hashFunc(int num); // Function that returns the index of the number in the hashtable.

};

#endif
