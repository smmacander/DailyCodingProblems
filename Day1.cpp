#include <iostream>
using namespace std;

/*
Given a list of numbers and a number k, return whether any two numbers from the list add up to k.

For example, given [10, 15, 3, 7] and k of 17, return true since 10 + 7 is 17.

Bonus: Can you do this in one pass?
*/

bool function(int array[4], int k){
    //cout << "k: " << k << endl;
    int passedArray[4] = {0, 0, 0, 0};
    for(int i = 0; i < 4; i++){
        //cout << "Array[" << i << "]: " << array[i] << endl;
        if(array[i] == k){
            return true;
        }
        else{
            for(int j = 0; j < i; j++){
                if(array[i] + passedArray[j] == k){
                    return true;
                }
            }
            passedArray[i] = array[i];
        }
    }
    return false;
}
int main(){
    int array[4] = {9, 11, 9, 4};
    int k = 13;
    if(function(array, k)){
        cout << "True" << endl;
    }
    else{cout << "False" << endl;}
}
