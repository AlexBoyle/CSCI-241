/***********************************************************
CSCI 241 - Assignment 1 - Fall 2016

Progammer: Alex Boyle
Z-ID: z1759628

Purpose: This program keeps track of books
************************************************************/


#include "BookStore.cpp"

int main(){
	BookStore bookStore ("bookdata");
	bookStore.print();
	bookStore.processOrders("orders.txt");
	bookStore.print();
}
