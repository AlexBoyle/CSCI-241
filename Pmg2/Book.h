#ifndef BOOK_H
#define BOOK_H

#include <cstring>
#include <iostream>
#include <iomanip>

using std::cout;
using std::endl;
using std::setw;
using std::left;
using std::right;

//*****************************************************************
// FILE:      Book.h
// AUTHOR:    Alex Boyle
// LOGON ID:  your z-ID
// DUE DATE:  due date of assignment
// 
// PURPOSE:   Contains the declaration for the Book class.
//*****************************************************************/

class Book {
	// Data members and method prototypes for the Book class go here
	private:
		char isbn [11]{};
		char title [41]{};
		double price = 0;
		int quantity = 0;
	public:
		/****************
		*Book()
		*
		*the default constructor
		****************/
		Book();

		/****************
                *Book(char[] , char[], double, int)
                *
		*Params:char[] : isbn
		*       char[] : name
		*       double : price
		*       int    : number of books
                *the default constructor
                ****************/
		Book(char[] , char[], double, int);

		/****************
                *getISBN();
                *
                *return: books isbn number
                ****************/
		char* getISBN();

		/****************
                *getTitle();
                *
                *return: books title
                ****************/
		char* getTitle();

		/****************
                *getPrice();
                *
                *return: books price
                ****************/
		double getPrice();

		/****************
                *getQuantity();
                *
                *return: number of books
                ****************/
		int getQuantity();
 		/****************
                *setPrice(double);
                *
                *param: double : new book price
                ****************/
		void setPrice(double);

		/****************
                *setQuantity(int);
                *
                *param: int : new quantity of books
                ****************/
		void setQuantity(int);
 
		/****************
                *fulfillOrder(int);
                *
                *param: int : number of books being ordered
                ****************/
		int fulfillOrder(int);

		/****************
                *print
                *
                *prints objects info
                ****************/
		void print();
};

   #endif
