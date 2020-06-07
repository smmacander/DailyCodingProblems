#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

string* getPrefixSubset(string* inputArray, string prefix, int size){
    //cout << size << endl;
    int prefixSize = prefix.length();
    sort(inputArray, inputArray+size);
    string* newArray = new string[size];
    for(int i = 0; i < size; i++){
        bool passed = false;
        //cout << inputArray[i] << endl;
        string currentString = inputArray[i].substr(0, prefixSize);
        //cout << currentString << endl;
        if(currentString == prefix){
            //cout << inputArray[i] << endl;
            newArray[i] = inputArray[i];
            passed = true;
        }
        else{
            if(passed == true){
                break;
            }
        }
    }
    return newArray;
}

int main(){
    string array[] = {"dog", "deer", "deal"};
    string *newArray = getPrefixSubset(array, "de", 3);
    cout << newArray[0] << endl;
    cout << newArray[1] << endl;
}