/*
This problem was recently asked by Google.

Given a list of numbers and a number k, return whether any two numbers from the list add up to k.

For example, given [10, 15, 3, 7] and k of 17, return true since 10 + 7 is 17.

Bonus: Can you do this in one pass?
*/

/**
 * Given a list of numbers and a number k, returns whether any two numbers from the list add up to k.
 * @param {number[]} numsList
 * @param {number} sum
 * @return {boolean}
 */

function hasSum(numsList, sum){
    const differences = new Set();
    for(let i = 0; i < numsList.length; i++){
        const num = numsList[i];
        const difference = sum - num;
        if(differences.has(difference)){
            return true;
        }
        differences.add(num);
    }
    return false;
}

var setA = [10, 15, 3, 7];
var k = 17;
console.log(hasSum(setA, k));

var setB = [5, 11, 4, 9];
var j = 3;
console.log(hasSum(setB, j));
