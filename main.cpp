#include "minheap.h"
#include "maxheap.h"
#include "hashtable.h"
#include "graph.h"

#include <iostream>
#include <cstring>
#include <fstream>
#include <chrono>

using namespace std;
using namespace std::chrono;
int main() {
	minHeap minheap;
	maxHeap maxheap;
	hashTable hashtable;
	Graph graph;

	ifstream fin("commands.txt");
	ofstream fout("output.txt");
	string line;
	string words[5];
	int pos_lastletter;

	if (fin.is_open()) {
		while (getline(fin, line)) {

			for (int i=0; i<5; i++)
				words[i]=""; // Initialize words array after every line

			int pos_firstletter=0; // Position of the first letter of each word
			int j=0; // Word index

			for (int i=0; i<line.length(); i++)
				if (line[i] == ' ') { // Scanning the line until i find the character ' '
					pos_lastletter=i; // The word stops right when i get the character ' '
					for (int k = pos_firstletter; k<pos_lastletter; k++)
						words[j]+=line[k]; // Adding the letters of the word to a new word array
					pos_firstletter = i+1;
					j++;
				}

			for (int k = pos_firstletter; k<line.length(); k++)
				words[j]+=line[k];  // Adding the last word of the line manually

			if (words[0] == "BUILD")
				if (words[1] == "MINHEAP") {
					auto arxi = high_resolution_clock::now();
					minheap.buildMin(words[2]);
					auto telos = high_resolution_clock::now();
					auto diarkeia = duration_cast<microseconds> (telos - arxi);
					fout << "Time it took to build Minheap: " << diarkeia.count() << " ms. " << endl;
				}
				else if (words[1] == "MAXHEAP") {
					auto arxi = high_resolution_clock::now();
					maxheap.buildMax(words[2]);
					auto telos = high_resolution_clock::now();
					auto diarkeia = duration_cast<microseconds> (telos - arxi);
					fout << "Time it took to build Maxheap: " << diarkeia.count() << " ms. " << endl;
				}
				else if (words[1] == "HASHTABLE") {
					auto arxi = high_resolution_clock::now();
					hashtable.buildHash(words[2]);
					auto telos = high_resolution_clock::now();
					auto diarkeia = duration_cast<microseconds> (telos - arxi);
					fout << "Time it took to build Hashtable: " << diarkeia.count() << " ms. " << endl;
				}
				else if (words[1] == "GRAPH") {
					auto arxi = high_resolution_clock::now();
					graph.buildGraph(words[2]);
					auto telos = high_resolution_clock::now();
					auto diarkeia = duration_cast<microseconds> (telos - arxi);
					fout << "Time it took to build Graph: " << diarkeia.count() << " ms. " << endl;
				}

			if (words[0] == "INSERT")
				if (words[1] == "MINHEAP") {
					auto arxi = high_resolution_clock::now();
					minheap.insert(stoi(words[2]));
					auto telos = high_resolution_clock::now();
					auto diarkeia = duration_cast<microseconds> (telos - arxi);
					fout << "Time it took to insert " << words[2] <<  " into the Minheap: " << diarkeia.count() << " ms. " << endl;
				}
				else if (words[1] == "MAXHEAP") {
					auto arxi = high_resolution_clock::now();
					maxheap.insert(stoi(words[2]));
					auto telos = high_resolution_clock::now();
					auto diarkeia = duration_cast<microseconds> (telos - arxi);
					fout << "Time it took to insert " << words[2] <<  " into the Maxheap: " << diarkeia.count() << " ms. " << endl;
				}
				else if (words[1] == "HASHTABLE") {
					auto arxi = high_resolution_clock::now();
					hashtable.insert(stoi(words[2]));
					auto telos = high_resolution_clock::now();
					auto diarkeia = duration_cast<microseconds> (telos - arxi);
					fout << "Time it took to insert " << words[2] <<  " into the Hashtable: " << diarkeia.count() << " ms. " << endl;
				}
				else if (words[1] == "GRAPH") {
					auto arxi = high_resolution_clock::now();
					graph.addEdge(stoi(words[2]), stoi(words[3]));
					auto telos = high_resolution_clock::now();
					auto diarkeia = duration_cast<microseconds> (telos - arxi);
					fout << "Time it took to insert edge (" << words[2] << ", " << words[3] << ") into the Graph: " << diarkeia.count() << " ms. " << endl;
				}

			if (words[0] == "GETSIZE")
				if (words[1] == "MINHEAP") {
					auto arxi = high_resolution_clock::now();
					int size = minheap.getSize();
					auto telos = high_resolution_clock::now();
					auto diarkeia = duration_cast<microseconds> (telos - arxi);
					fout << "Time it took to get the size (" << size <<  ") of the Minheap: " << diarkeia.count() << " ms. " << endl;
				}
				else if (words[1] == "MAXHEAP") {
					auto arxi = high_resolution_clock::now();
					int size = maxheap.getSize();
					auto telos = high_resolution_clock::now();
					auto diarkeia = duration_cast<microseconds> (telos - arxi);
					fout << "Time it took to get the size (" << size <<  ") of the Maxheap: " << diarkeia.count() << " ms. " << endl;
				}
				else if (words[1] == "HASHTABLE") {
					auto arxi = high_resolution_clock::now();
					int size = hashtable.getSize();
					auto telos = high_resolution_clock::now();
					auto diarkeia = duration_cast<microseconds> (telos - arxi);
					fout << "Time it took to get the size (" << size <<  ") of the Hashtable: " << diarkeia.count() << " ms. " << endl;
				}
				else if (words[1] == "GRAPH") {
					auto arxi = high_resolution_clock::now();
					int size = graph.getSize();
					auto telos = high_resolution_clock::now();
					auto diarkeia = duration_cast<microseconds> (telos - arxi);
					fout << "Time it took to get the size (" << size << ") of the Graph: " << diarkeia.count() << " ms. " << endl;
				}

			if (words[0] == "FINDMIN")
				if (words[1] == "MINHEAP") {
					auto arxi = high_resolution_clock::now();
					int min = minheap.findMin();
					auto telos = high_resolution_clock::now();
					auto diarkeia = duration_cast<microseconds> (telos - arxi);
					fout << "Time it took to find the min number (" << min <<  ") of the Minheap: " << diarkeia.count() << " ms. " << endl;
				}

			if (words[0] == "FINDMAX")
				if (words[1] == "MAXHEAP") {
					auto arxi = high_resolution_clock::now();
					int max = maxheap.findMax();
					auto telos = high_resolution_clock::now();
					auto diarkeia = duration_cast<microseconds> (telos - arxi);
					fout << "Time it took to find the max number (" << max <<  ") of the Maxheap: " << diarkeia.count() << " ms. " << endl;
				}

			if (words[0] == "DELETEMIN")
				if (words[1] == "MINHEAP") {
					auto arxi = high_resolution_clock::now();
					minheap.deleteMin();
					auto telos = high_resolution_clock::now();
					auto diarkeia = duration_cast<microseconds> (telos - arxi);
					fout << "Time it took to delete the min number of the Minheap: " << diarkeia.count() << " ms. " << endl;
				}

			if (words[0] == "DELETEMAX")
				if (words[1] == "MAXHEAP") {
					auto arxi = high_resolution_clock::now();
					maxheap.deleteMax();
					auto telos = high_resolution_clock::now();
					auto diarkeia = duration_cast<microseconds> (telos - arxi);
					fout << "Time it took to delete the max number of the Maxheap: " << diarkeia.count() << " ms. " << endl;
				}

			if (words[0] == "SEARCH")
				if (words[1] == "HASHTABLE") {
					auto arxi = high_resolution_clock::now();
					string search = hashtable.search(stoi(words[2]));
					auto telos = high_resolution_clock::now();
					auto diarkeia = duration_cast<microseconds> (telos - arxi);
					fout << "Time it took the search to be completed " << diarkeia.count() << " ms. The search was a " << search << "." << endl;
				}
				else if (words[1] == "GRAPH") {
					auto arxi = high_resolution_clock::now();
					string search = graph.search(stoi(words[2]));
					auto telos = high_resolution_clock::now();
					auto diarkeia = duration_cast<microseconds> (telos - arxi);
					fout << "Time it took the search to be completed " << diarkeia.count() << " ms. The search was a " << search << "." << endl;
				}

			if (words[0] == "BFS")
				if (words[1] == "GRAPH") {
					auto arxi = high_resolution_clock::now();
					string traversal = graph.BFS(stoi(words[2]));
					auto telos = high_resolution_clock::now();
					auto diarkeia = duration_cast<microseconds> (telos - arxi);
					fout << "BFS from node " << words[2] << ": " << traversal << ". Time: " << diarkeia.count() << " ms. " << endl;
				}

			if (words[0] == "DFS")
				if (words[1] == "GRAPH") {
					auto arxi = high_resolution_clock::now();
					string traversal = graph.DFS(stoi(words[2]));
					auto telos = high_resolution_clock::now();
					auto diarkeia = duration_cast<microseconds> (telos - arxi);
					fout << "DFS from node " << words[2] << ": " << traversal << ". Time: " << diarkeia.count() << " ms. " << endl;
				}
		}
	}
	return 0;
}
