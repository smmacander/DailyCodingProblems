/*
Given an array of integers, return a new array such that each element at index i of the new array is the product of all the numbers in the original array except the one at i.

For example, if our input was [1, 2, 3, 4, 5], the expected output would be [120, 60, 40, 30, 24]. If our input was [3, 2, 1], the expected output would be [2, 3, 6].
Follow-up: what if you can't use division?

*/

/**
 * Given an array of integers, return a new array such that each element at index i of the new array is the product of all the numbers in the original array except the one at i.
 * @param {number[]} intArray
 * @return {number[]}
 */

function productOfAllOtherElements(intArray){
    var productsUntilCurrElement, newArray = Array(intArray.length);
    var productsUntilCurrElement = [intArray[0]];
    for(let i = 0; i < intArray.length; i++){
        if(i > 0){
            productsUntilCurrElement[i] = productsUntilCurrElement[i - 1]*intArray[i];
            var currentProduct = productsUntilCurrElement[i - 1]
        }
        else{
            var currentProduct = 1;
        }
        for(let j = i + 1; j < intArray.length; j++){
            currentProduct *= intArray[j];
        }
        newArray[i] = currentProduct;
    }
    return newArray;
}

var setA = [1, 2, 3, 4, 5];
var newSetA = productOfAllOtherElements(setA);

for(let i = 0; i < 5; i++){
    console.log(newSetA[i]);
}

console.log(' ');

var setB = [3, 2, 1];
var newSetB = productOfAllOtherElements(setB);

for(let i = 0; i < 3; i++){
    console.log(newSetB[i]);
}

console.log(' ');

var setC = [89, 57, 30, 37, 105];
var newSetC = productOfAllOtherElements(setC);

for(let i = 0; i < 5; i++){
    console.log(newSetC[i]);
}