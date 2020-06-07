#include <iostream>
using namespace std;

int numWaysToClimb(int stairs){
    int numWays = 1; //First, accounts for when you walk up one step at a time.
    int multipleOfTwo = 2; //Starting at 2, while loop goes through and sees if theres room to make a multipleOfTwo step
    while(multipleOfTwo <= stairs){
        int numOnes = stairs - multipleOfTwo; //in between the steps of two, there are numOne steps of one
        int numTotalSpots = numOnes + (multipleOfTwo/2); //the number of total 
        int numTwoSpots = numWays += numOnes + 1; //the number of orders is the amount of 1s + 1
        multipleOfTwo += 2; //go to next multiple of two
    }
    return numWays;
}

int numWaysToClimbWithArray(int stairs, int array[], int arrayLength){

}

int main(){
    int stairLength = 4;
    int array[3] = {1, 3, 5};
    int arrayLength = 3;
    cout << numWaysToClimb(stairLength) << endl;
    cout << numWaysToClimbWithArray(stairLength, array, arrayLength) << endl;
}