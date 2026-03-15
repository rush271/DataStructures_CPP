#include "hashtable.h"

hashTable :: hashTable () {
    htable = nullptr; // Initialize hashtable
    size=0;
    maxsize=0;
}

hashTable :: ~hashTable() {
    delete[] htable; // Delete hashtable
}

int hashTable :: hashFunc(int number){
    return number % maxsize; // Returns the index of the number in the hashntable
}

void hashTable :: buildHash (string &filename) {
	ifstream fin(filename);
	
    maxsize = 10;
	htable = new int[maxsize];
	
	for (int i=0; i<maxsize; i++)
	    htable[i] = -1; // -1 Shows that the cell is empty

    if (fin.is_open()) {
		int num;
		while(fin>>num)
			insert(num);
	}
	
	fin.close();
}

int hashTable :: getSize(){
    return size; // Returns the size of the hashTable
}

void hashTable :: insert(int num){
    if (size == maxsize){ // If the size reaches its limit double the size
        doubleSize();
    }
    int i;
    i=hashFunc(num);
    while (htable[i] != -1){ // As long as the cell is full keep searching
        i = (i+1) % maxsize; // Go to the next cell
    }
    htable[i]=num;
    size++;
}   

void hashTable :: doubleSize(){
    int proig_maxsize = maxsize;
    maxsize*=2;
    
    int* proig_htable = htable;
    htable = new int[maxsize];
    
    for (int i=0; i<maxsize; i++){
        htable[i] = -1;
    }
    
    for (int i=0; i<proig_maxsize; i++){
        if (proig_htable[i] != -1){
            insert(proig_htable[i]);
        }
    }
    delete[] proig_htable;
}



string hashTable :: search(int num){
    int afetiria = hashFunc(num);

    string str = "FAILURE";

    int i = afetiria;
    int loops = 0;
    while (htable[i] != num){
        i = (i + 1) % maxsize;
        loops++;
        if (loops == maxsize)
            break;
    }     
    if (htable[i] == num)
        str = "SUCCESS";
    
    return str;
}
