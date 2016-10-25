#include "Verifier.h"

void Verifier::readGrid(const char* file){
	char temp[50];
	ifstream inFile;
	inFile.open(file);
	if(inFile.fail()){
		cout << "File failed to open\n";
		exit(-1);
	}
        inFile.getline(temp, 50);
	int j = 0;
        while (!inFile.eof()){
		for(int i = 0; i < SIZE; i ++){
			grid[j][i] = ((int)temp[(i*2)]) - 48;
		}
		inFile.getline(temp, 50);
		j ++;
	}
	inFile.close();
}

const bool Verifier::verifySolution(){
	for(int i = 0; i < SIZE; i ++){
		if(!(verifyRow(i) && verifyCol(i) && verifyBox(i))){
			return false;
		}
	}
	return true;
}

const bool Verifier::verifyRow(const int& a){
	bool check[9];
	for(int i = 0; i < SIZE; i ++){check[i] = false;}
	for(int i = 0; i < SIZE; i ++){check[grid[a][i] - 1] = true;}
	for(int i = 0; i < SIZE; i ++){if(!check[i]){ return false;}}
	return true;
}
const bool Verifier::verifyCol(const int& a){
	bool check[9];
	for(int i = 0; i < SIZE; i ++){check[i] = false;}
	for(int i = 0; i < SIZE; i ++){check[grid[i][a] - 1] = true;}
	for(int i = 0; i < SIZE; i ++){if(!check[i]){ return false;}}
	return true;
}
const bool Verifier::verifyBox(const int& a){
	bool check[9];
        for(int i = 0; i < SIZE; i ++){check[i] = false;}
        for(int i = 0; i < SIZE; i ++){check[grid[((a%3)*3)+(i%3)][(i/3) + ((a/3)* 3)] - 1] = true;}
        for(int i = 0; i < SIZE; i ++){if(!check[i]){ return false;}}
        return true;
}
const void Verifier::printGrid(){
	cout << "+-----------------------+\n";
	for(int i = 0; i < 9; i ++) {
		if(i == 3 || i == 6)
			cout << "|-------+-------+-------|\n";
		for(int j = 0; j < 9; j ++) {
			if(j == 0 || j == 3 || j == 6)
				cout << "| ";
			cout << grid[i][j] << " ";
		}
		cout << "|\n";
	}
	cout << "+-----------------------+\n";
}

