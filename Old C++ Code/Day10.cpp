#include <iostream>
#include <chrono>
#include <thread>
using namespace std;

/*
Implement a job scheduler which takes in a function f and an integer n, and calls f after n milliseconds.
*/

void foobar(){
    cout << "ping" << endl;
}

void foobar1(){
    cout << "ping1" << endl;
}

template <class functiontype>
void schedular(functiontype function(), int milliseconds){
    std::this_thread::sleep_for(std::chrono::milliseconds(milliseconds));
    function();
}

int main(){
    schedular(foobar, 1000);
    schedular(foobar1, 1000);
}