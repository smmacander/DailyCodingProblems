#include <iostream>
using namespace std;

/*
Given an array of integers, return a new array such that each element at index i of the new array is the product of all the numbers in the original array except the one at i.
For example, if our input was [1, 2, 3, 4, 5], the expected output would be [120, 60, 40, 30, 24]. If our input was [3, 2, 1], the expected output would be [2, 3, 6].
Follow-up: what if you can't use division?
*/

int main(){
    /*int originalArray[5] = {1, 2, 3, 4, 5};
    int outputArray[5] = {};
    for(int i = 0; i < 5; i++){
        int productDivIndex = 1; //product divided by index (all other numbers besides index multiplied)
        for(int j = 0; j < 5; j++){
            if(j != i){
                productDivIndex*=originalArray[j];
            }
        }
        outputArray[i] = productDivIndex;
    }
    for(int a = 0; a < 5; a++){
        cout << outputArray[a] << " ";
    }
    cout << endl;*/

    int originalArray[3] = {3, 2, 1};
    int outputArray[3] = {};
    for(int i = 0; i < 3; i++){
        int productDivIndex = 1; //product divided by index (all other numbers besides index multiplied)
        for(int j = 0; j < 3; j++){
            if(j != i){
                productDivIndex*=originalArray[j];
            }
        }
        outputArray[i] = productDivIndex;
    }
    for(int a = 0; a < 3; a++){
        cout << outputArray[a] << " ";
    }
    cout << endl;
}