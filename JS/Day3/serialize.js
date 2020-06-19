/*
Given the root to a binary tree, implement serialize(root), which serializes the tree into a string, and deserialize(s), which deserializes the string back into the tree.
*/

class Node{
    constructor(val, left=null, right=null){
        this.val = val;
        this.left = left;
        this.right = right;
    }
}

/**
 * Given a node, serializes node into inorder string.
 * @param {Node} node 
 * @return {string} s
 */

function serialize(node){
    var s = "";
    if(node == null){
        s+="null";
        s+=" ";
        return s;
    }
    s+=node.val;
    s+=" ";
    s+=serialize(node.left);
    s+=serialize(node.right);
    return s;
}

function deserialize(string){
    function decode(vals){
        if(vals.length >= 1){
            var val = vals.shift();
        }
        else{
            return null;
        }
        //console.log(val);
        if(val == 'null'){
            return null;
        }
        var root = new Node(val);
        //console.log(node.val);
        root.left = decode(vals);
        root.right = decode(vals);
        return root;
    }
    var stringArray = string.split(' ');
    return decode(stringArray);
}

var assert = require('assert');

node = new Node('root', new Node('left', new Node('left.left')), new Node('right'));
//console.log(serialize(node));
if(deserialize(serialize(node)).left.left.val == 'left.left'){
    console.log("test worked!");
}