#ifndef BOOKSTORE_H
#define BOOKSTORE_H

#include <fstream>
#include <cstring>
#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include "Book.cpp"

using std::ios;
using std::cout;
using std::endl;
using std::setw;
using std::left;
using std::ifstream;
using std::right;
using std::cin;
//*****************************************************************
// FILE:      BookStore.h
// AUTHOR:    Alex Boyle
 // LOGON ID:  your z-ID
// DUE DATE:  due date of assignment
// 
// PURPOSE:   Contains the declaration for the BookStore class.
//*****************************************************************/

class BookStore {
	// Data members and method prototypes for the Book class go here
	private:
		Book books[30];
		int numberBooks = 0;
	public:
		/****************
		*BookStore()
		*
		*defalt constructor
		*******************/
		BookStore();

		/****************
                *BookStore(const char*)
                *
                *Param: char* : name of input file
                *******************/
		BookStore(const char*);

		/****************
                *sortByISBN()
                *
                *this sorts all current books by isbn number
                *******************/
		void sortByISBN();

		/****************
                *searchForISBN(char[])
                *
                *Param: char[] : isbn that is being looked for
		*
		*return: index of isbn number if exists, else -1
                *******************/
		int searchForISBN(char[]);

		/****************
                *processOrders(const char*)
                *
                *Param: char* : name of file orders are in
                *******************/
		void processOrders(const char*);

		/****************
                *print()
                *
                *prints current objects status
                *******************/
		void print();
};

   #endif
