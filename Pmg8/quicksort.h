#ifndef QUICKSORTS_H
#define QUICKSORTS_H

#include<iostream>
#include<vector>
#include <fstream>
#include <stdlib.h>

using std::cout;
using std::setw;
using std::vector;
using std::ifstream;

/****************************
*bool lessThan(const T&, const T&);
*
*param: two vars being compaired
*
****************************/
template <class T>
bool lessThan(const T&, const T&);

/****************************
*bool greaterThan(const T&, const T&);
*
*param: two vars being compaired
*
****************************/
template <class T>
bool greaterThan(const T&, const T&);

/****************************
*void quickSort(vector<T>&, bool (*)(const T&, const T&));
*
*param:	vector: list being sorted
*	function: comparison function
*
****************************/
template <class T>
void quickSort(vector<T>&, bool (*)(const T&, const T&));

/****************************
*void quickSort(vector<T>&, int, int, bool (*)(const T&, const T&));
*
*param: vector: list being sorted
*	int: first index
*	int: last index
*	function: compair function
*
****************************/
template <class T>
void quickSort(vector<T>&, int, int, bool (*)(const T&, const T&));

/****************************
*int partition(vector<T>&, int, int, bool (*)(const T&, const T&));
*
*param: vector: list being sorted:
*	int: first index
*	int: last index
*	function: compair function
*
****************************/
template <class T>
int partition(vector<T>&, int, int, bool (*)(const T&, const T&));
/////////////////////////////////////
template <class T>
void quickSort(vector<T>& set, bool (*compare)(const T&, const T&)){
	quickSort(set, 0, set.size()-1, compare);
}
template <class T>
void quickSort(vector<T>& set, int start, int end, bool (*compare)(const T&, const T&)){
	int pivotPoint;

   	if (start < end)
   	{
      		pivotPoint = partition(set, start, end, compare);     // Get the pivot point
      		quickSort(set, start, pivotPoint - 1, compare);       // Sort first sublist
      		quickSort(set, pivotPoint + 1, end, compare);         // Sort second sublist
      	}
}
template <class T>
int partition(vector<T>& set, int start, int end, bool (*compare)(const T&, const T&)){
	int pivotIndex, mid;
   	T pivotValue;

   	mid = (start + end) / 2;

	T temp = set[start];
   	set[start] = set[mid];
	set[mid] = temp;

   	pivotIndex = start;
	pivotValue = set[start];

   	for (int scan = start + 1; scan <= end; scan++)
      	{
      		if (compare(set[scan], pivotValue))
         	{
         		pivotIndex++;
         		temp = set[pivotIndex];
			set[pivotIndex] = set[scan];
			set[scan] = temp;
         	}
      	}
	temp = set[start];
	set[start] = set[pivotIndex];
	set[pivotIndex] = temp;
   	return pivotIndex;
}
template <class T>
bool greaterThan(const T& item1, const T& item2){
	return item1 > item2;
}
template <class T>
bool lessThan(const T& item1, const T& item2){
	return item1 < item2;
}
#endif
