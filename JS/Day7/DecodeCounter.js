/*
Good morning! Here's your coding interview problem for today.

This problem was asked by Facebook.

Given the mapping a = 1, b = 2, ... z = 26, and an encoded message,
count the number of ways it can be decoded.

For example, the message '111' would give 3, since it could be
decoded as 'aaa', 'ka', and 'ak'.

You can assume that the messages are decodable. For example, '001'
is not allowed.
*/

function isChar(input){
    var intInput = parseInt(input);
    if((intInput > 0) && (intInput <= 26)){
        //console.log("is char");
        return 1;
    }
    //console.log("is not char");
    return 0;
}

function DecodeCounter(message){
    var count;
    if(message.length == 1){
        //console.log("Length 1");
        count = 1;
    }
    else if(message.length == 2){
        //console.log("Length 2");
        count = 1 + isChar(message);
    }
    else{
        //console.log("Else");
        //console.log(message.substring(1));
        count = DecodeCounter(message.substring(1));
        //console.log(message.substring(0,2));
        if(isChar(message.substring(0,2)) == 1){
            //console.log("substr 2");
            //console.log(message.substring(2));
            count += DecodeCounter(message.substring(2));
        }
    }
    return count;
}

console.log(DecodeCounter('81'));
console.log(DecodeCounter('11'));
console.log(DecodeCounter('111'));
console.log(DecodeCounter('1111'));
console.log(DecodeCounter('1311'));