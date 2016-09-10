/***********************************************************
CSCI 241 - Assignment 1 - Fall 2016

Progammer: Alex Boyle
Z-ID: z1759628

Purpose: This program accepts a name and give back a fourtune
************************************************************/


#include <iostream>
#include <string>

using std::cin; using std::cout; using std::endl;using std::string;using std::getline;
//numbers corisponding to the output strings
int num [] = {0,1,2,3,4,5,6,7,8,9,11,12,22};
//output strings
string output [] = {
        "emptiness, nothingness, blank",
        "independence, loneliness, creativity, originality, dominance, leadership, impatience",
        "quiet, passive, diplomatic, co-operation, comforting, soothing, intuitive, compromising, patient",
        "charming, outgoing, self expressive, extroverted, abundance, active, energetic, proud",
        "harmony, truth, justice, order discipline, practicality",
        "new directions, excitement, change, adventure",
        "love, harmony, perfection, marriage, tolerance, public service",
        "spirituality, completeness, isolation, introspection",
        "organization, business, commerce, new beginnings",
        "romantic, rebellious, determined, passionate, compassionate",
        "idealism, visionary, inspirational",
        "perfectionist, discriminating",
        "builder, leader, humanitarian, practical, honest"
};


/*************
*intArrayContains
*
*Use: to find the index of a number in an int array
*
*Params: int[]: array to ckeck if value exists in
*       int: size of input array
*       int: value to check array for
*
* return:  index of number if found, else -1
*************/
int intArrayContains(int[], int, int);

/*****************************
*nameSum
*
*Use:  to evaluate a string
*
*Param: string: the string to be evaluated into an int
*
*return: the value of the input string
*****************************/
int nameSum(string);


int main(){
        //the var that holds the falue to repeat
        string cont;

        //main program loop
        do{
                string name;
                cout << "name: ";
                std::getline(std::cin, name);
                cout <<"That name has the traits "<<output[intArrayContains(num ,sizeof(num)/sizeof(num[0]), nameSum(name))] << endl;
                cout<< "\nAnother? (y/n) ";
                getline(cin, cont);
        } while(cont[0] == 'y' || cont[0] == 'Y');
        return 0;
}

int nameSum(string input) {
        int lenght = input.length();
        int sum = 0;
        // calculate inital sum
        for(int i = 0; i < lenght; i ++){
                //check for 1-9
                if((int)input[i] >= 48 && (int)input[i] <= 57 ){
                        sum += (int)input[i] - 48;
                }
                //check for A-Z
                else if((int)input[i] >= 65 && (int)input[i] <= 90){
                        sum += (int)input[i] - 64;
                }
				//check for a-z
                 else if((int)input[i] >= 97 && (int)input[i] <= 122){
                        sum += (int)input[i] - 96;
                }
        }

        //if the calculated number does not fit, recalculate
        while (intArrayContains(num, sizeof(num)/sizeof(num[0]), sum) == -1){
                int tempSum= 0;
                while (sum > 0) {
                        int digit = sum % 10;
                        sum /= 10;
                        tempSum += digit;
                }
                sum = tempSum;
        }
        //return the number that the input text fits
        return sum;
}

int intArrayContains(int arr[], int len, int check){
        for(int i = 0; i < len; i ++){
                if(arr[i] == check){
                        return i;
                }
        }

        return -1;
}
