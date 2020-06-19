/*
Good morning! Here's your coding interview problem for today.

This problem was asked by Jane Street.

cons(a, b) constructs a pair, and car(pair) and 
cdr(pair) returns the first and last element of that pair. For 
example, car(cons(3, 4)) returns 3, and 
cdr(cons(3, 4)) returns 4.

Implement car and cdr.
*/

/**
 * Constructs a pair and then returns function that is called upon it
 * @param {int} a 
 * @param {int} b 
 * @return returns callback to different function
 */
function cons(a, b){
    function pair(f){
        return f(a, b);
    }
    return pair;
}

/**
 * Returns the first element in pair.
 * @param {function} pair 
 * @return {int}
 */
function car(pair){
    function returnFirst(a, b){
        return a;
    }
    return pair(returnFirst);
}

/**
 * Returns the last element in pair.
 * @param {function} pair 
 */
function cdr(pair){
    function returnLast(a, b){
        return b;
    }
    return pair(returnLast);
}

console.log(car(cons(3, 4)));
console.log(cdr(cons(3, 4)));