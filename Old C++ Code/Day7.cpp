#include <assert.h>
#include <iostream>
#include <string>
using namespace std;

/*
Given the mapping a = 1, b = 2, ... z = 26, and an encoded message, count the number of ways it can be decoded.

For example, the message '111' would give 3, since it could be decoded as 'aaa', 'ka', and 'ak'.

You can assume that the messages are decodable. For example, '001' is not allowed.
*/

int is_char(string input){
    int intInput = stoi(input);
    if(intInput > 0 && intInput <= 26){
        return 1;
    }
    return 0;
}

int getNumberofWaysToDecode(string input){
    int count;
    if(input.length() == 1){
        count = 1;
    }
    else if(input.length() == 2){
        count = 1 + is_char(input);
    }
    else{
        count = getNumberofWaysToDecode(input.substr(1));
        if(is_char(input.substr(0,2)) == 1){
            count += getNumberofWaysToDecode(input.substr(2));
        }
    }
    return count;
}

int main(){
    assert(getNumberofWaysToDecode("81") == 1);
    assert(getNumberofWaysToDecode("11") == 2);
    assert(getNumberofWaysToDecode("111") == 3);
    assert(getNumberofWaysToDecode("1111") == 5);
    assert(getNumberofWaysToDecode("1311") == 4);
}