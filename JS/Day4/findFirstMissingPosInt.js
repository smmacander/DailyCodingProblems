/*
Good morning! Here's your coding interview problem for today.

This problem was asked by Stripe.

Given an array of integers, find the first missing positive integer in 
linear time and constant space. In other words, find the lowest positive 
integer that does not exist in the array. The array can contain 
duplicates and negative numbers as well.

For example, the input [3, 4, -1, 1] should give 2. The input 
[1, 2, 0] should give 3.

You can modify the input array in-place.
*/

/**
 * Given an array of integers, returns the lowest positive integer that does not exist in the array.
 * @param {int[]} intArray 
 * @return {int}
 */
function findFirstMissingPosInt(intArray){
    var lowerInt = intArray[0] - 1;
    var higherInt = intArray[0] + 1;
    for(let i = 1; i < intArray.length; i++){
        if(intArray[i] <= 1){
            lowerInt = lowerInt;
        }
        else if(intArray[i] == higherInt){
            higherInt++;
        }
        else if(intArray[i] - 1 < lowerInt){
            lowerInt = intArray[i] - 1;
        }
        else if(intArray[i] == lowerInt){
            lowerInt = higherInt;
        }
    }
    if(lowerInt == 0){
        return higherInt;
    }
    return lowerInt;
}

var array1 = [3, 4, -1, 1];
console.log(findFirstMissingPosInt(array1));

var array2 = [1, 2, 0];
console.log(findFirstMissingPosInt(array2));