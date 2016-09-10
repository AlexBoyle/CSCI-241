/***********************************************************
CSCI 241 - Assignment 1 - Fall 2016

Progammer: Alex Boyle
Z-ID: z1759628

Purpose: This program accepts a a name and give back a fourtune
************************************************************/

#include <iostream>
#include <cstring>

using std::cin; using std::cout; using std::endl;


/************8
*intArrayContains
*
*Use: to find the index of a number in an int array
*
*Params: int[]: array to ckeck if value exists in
        int: lenght of array
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
*Param: char[]: the cstring to be evaluated into an int
*
*return: the value of the input cstring
*****************************/
int nameSum(char[]);

//value that is required for each index of text
int num [] = {0,1,2,3,4,5,6,7,8,9,11,12,22};

//text that is shown after a name is evaluated
char output [][128] = {
                {"emptiness, nothingness, blank"},
                {"independence, loneliness, creativity, originality, dominance, leadership, impatience"},
                {"quiet, passive, diplomatic, co-operation, comforting, soothing, intuitive, compromising, patient"},
                {"charming, outgoing, self expressive, extroverted, abundance, active, energetic, proud"},
                {"harmony, truth, justice, order discipline, practicality"},
                {"new directions, excitement, change, adventure"},
                {"love, harmony, perfection, marriage, tolerance, public service"},
                {"spirituality, completeness, isolation, introspection"},
                {"organization, business, commerce, new beginnings"},
                {"romantic, rebellious, determined, passionate, compassionate"},
                {"idealism, visionary, inspirational"},
                {"perfectionist, discriminating"},
                {"builder, leader, humanitarian, practical, honest"}
        };

int main(){
        char cont[64];
        //the main loop that askes for a name and then checks it
        do{
                char name[64];
                cout << "name: ";
                cin.getline(name,63);
                cout <<"That name has the traits "<<output[intArrayContains(num ,sizeof(num)/sizeof(num[0]), nameSum(name))] << endl;
                cout<< "\nAnother? (y/n) ";
                cin.getline(cont, 63);
        } while(cont[0] == 'y' || cont[0] == 'Y');
        return 0;
}
int nameSum(char a[]){
        int lenght = strlen(a);
        int sum = 0;
        //evaluate input string
        for(int i = 0; i < lenght; i ++){
                if((int)a[i] >= 48 && (int)a[i] <= 57 ){
                        sum += (int)a[i] - 48;
                }
                else if((int)a[i] >= 65 && (int)a[i] <= 90){
                        sum += (int)a[i] - 64;
                }
                 else if((int)a[i] >= 97 && (int)a[i] <= 122){
                        sum += (int)a[i] - 96;
                }
        }
        //recalculate sum untill it fits an index
        while (intArrayContains(num,sizeof(num)/sizeof(num[0]), sum) == -1){
                int tempSum= 0;
                while (sum > 0) {
                        int digit = sum % 10;
                        sum /= 10;
                        tempSum += digit;
                }
                sum = tempSum;
        }
        return sum;
}
int intArrayContains(int arr[],int len, int check){
        for(int i = 0; i < len; i ++){
                if(arr[i] == check){
                        return i;
                }
        }
        return -1;
}
