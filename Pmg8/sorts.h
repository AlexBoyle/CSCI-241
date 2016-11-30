#ifndef SORTS_H
#define SORTS_H

#include<iostream>
#include<vector>
#include <fstream>
#include <stdlib.h>

using std::cout;
using std::setw;
using std::vector;
using std::ifstream;

/******************************
*void buildList(vector<T>&, const char*);
*
*param: vector: list to populate
*	char: file name to read
*
*******************************/
template <class T>
void buildList(vector<T>&, const char*);

/***************************
*void printList(const vector<T>&, int, int);
*
*param: vector: list to be printed
*	int: width of items
*	int: number of items per line
*
*****************************/
template <class T>
void printList(const vector<T>&, int, int);


/////////////////////////////////////
template <class T>
void buildList(vector<T>& set, const char* fileName){
	T item;
	ifstream inFile;
        inFile.open(fileName);
        if(inFile.fail()){
                cout << "File failed to open\n";
                exit(-1);
        }
        inFile >> item;
        int j = 0;
        while (!inFile.eof()){
                set.push_back(item);
		inFile >> item;
        }
        inFile.close();

}

template <class T>
void printList(const vector<T>& set, int itemWidth, int numPerLine){
	cout<< "\n" << itemWidth << '\n';
	for(int i = 0; i < set.size(); i ++){
		cout << setw(itemWidth + 1) << set[i];
		if((i +1) % numPerLine == 0){
			cout << '\n';
		}
	}
}
#endif
