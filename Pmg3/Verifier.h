#ifndef VERIFIER_H
#define VERIFIER_H

#include <fstream>
#include <iostream>

using std::cout;
using std::ifstream;

class Verifier{
	private:
		const int SIZE = 9;
		int grid[9][9];
	public:
		/**********************
		*void readGrid(const char*)
		*
		*Params: const char*: file to be read in as a sudoku puzzle
		**********************/
		void readGrid(const char*);

		/**********************
		*const bool verifySolution()
		*
		*Return: true if sudoku puzzle is correct, false otherwise
		**********************/
		const bool verifySolution();

		/**********************
		*const bool verifyRow(const int&)
		*
		*Params: const int&: row number to check
		*
		*Return: true if the row has the numbers 1-9 in it, false otherwise
		***********************/
		const bool verifyRow(const int&);

		/**********************
                *const bool verifyCol(const int&)
                *
                *Params: const int&: column number to check
                *
                *Return: true if the column has the numbers 1-9 in it, false otherwise
                ***********************/
		const bool verifyCol(const int&);

		/**********************
                *const bool verifyBox(const int&)
                *
                *Params: const int&: 3x3 box number to check
                *
                *Return: true if the box has the numbers 1-9 in it, false otherwise
                ***********************/
		const bool verifyBox(const int&);

		/**********************
                *const void printGrid()
                *
                *This function prints the puzzle to console
                **********************/
		const void printGrid();
};

#endif
