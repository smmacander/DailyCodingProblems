#include <iostream>
using namespace std;

/*Given an array of integers, find the first missing positive integer in linear time and constant space. In other words, find the lowest positive integer that does not exist in the array. The array can contain duplicates and negative numbers as well.

For example, the input [3, 4, -1, 1] should give 2. The input [1, 2, 0] should give 3.

You can modify the input array in-place.
*/

int getLowestPositiveMissingInt(int array[], int size){
    int *newArray = new int[size]; //Creates a new array of the same size of the 
    for(int i = 0; i < size; i++){
        newArray[i] = 0;
    }
    for(int j = 0; j < size; j++){
        if(array[j] > 0 && array[j] <= size){
            newArray[array[j] - 1] = 1;
        }
    }
    int a = 0;
    while(newArray[a] == 1 && a != size){
        a++;
    }
    return a + 1;
}

int main(){
    int input[4] = {3, 4, -1, 1};
    int size = 4;
    cout << getLowestPositiveMissingInt(input, size) << endl;
    int input2[3] = {1, 2, 0};
    int size2 = 3;
    cout << getLowestPositiveMissingInt(input2, size2) << endl;
    int input3[4] = {-1, -1, -1, -1};
    int size3 = 4;
    cout << getLowestPositiveMissingInt(input3, size3) << endl;
    int input4[4] = {1, 2, 3, 4};
    int size4 = 4;
    cout << getLowestPositiveMissingInt(input4, size4) << endl;
}