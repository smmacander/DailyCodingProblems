#include <iostream>
using namespace std;

/*
cons(a, b) constructs a pair, and car(pair) and cdr(pair) returns the first and last element of that pair. For example, car(cons(3, 4)) returns 3, and cdr(cons(3, 4)) returns 4.

Given this implementation of cons:

def cons(a, b):
    def pair(f):
        return f(a, b)
    return pair

Implement car and cdr.
*/

class Pair{
    public:
        int a, b;
};

Pair *cons(int a, int b){
    Pair *pair = new Pair;
    pair->a = a;
    pair->b = b;
    return pair;
}

int car(Pair *a){
    if(a->a > a->b){
        return a->b;
    }
    return a->a;
}

int cdr(Pair *a){
    if(a->a < a->b){
        return a->b;
    }
    return a->a;
}

int main(){
    cout << car(cons(3, 4)) << endl;
    cout << cdr(cons(3, 4)) << endl;
}