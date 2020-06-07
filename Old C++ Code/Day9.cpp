#include <assert.h>
#include <iostream>
using namespace std;

/*
Given a list of integers, write a function that returns the largest sum of non-adjacent numbers. Numbers can be 0 or negative.

For example, [2, 4, 6, 2, 5] should return 13, since we pick 2, 6, and 5. [5, 1, 1, 5] should return 10, since we pick 5 and 5.

Follow-up: Can you do this in O(N) time and constant space?
*/

int largestNonadjacentSum(int arr[], int size){
    int i = 0;
    int largestSum = 0;
    for (int i = 0; i < size; i++){
        cout << "i: " << i << endl;
        int iLargestSum = arr[i];
        for(int j = i + 2; j < size; j++){
            cout << "j: " << j << endl;
            int currentLoopSum = arr[i] + arr[j];
            for(int k = j + 2; k < size; k+=2){
                cout << "k: " << k << endl;
                currentLoopSum+=arr[k];
            }
            if(currentLoopSum > iLargestSum){
                    iLargestSum = currentLoopSum;
            }
        }
        if(iLargestSum > largestSum){
            largestSum = iLargestSum;
        }
    }
    return largestSum;
}

int main(){
    int arr1[] = {2, 4, 6, 2, 5};
    int arr2[] = {5, 1, 1, 5};
    cout << largestNonadjacentSum(arr1, 5) << endl;
    cout << largestNonadjacentSum(arr2, 4) << endl;
}