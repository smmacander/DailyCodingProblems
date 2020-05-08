#include <iostream>
#include <sstream>
#include <string>
using namespace std;
#define MARKER "null"

/*
Given the root to a binary tree, implement serialize(root), which serializes the tree into a string, and deserialize(s), which deserializes the string back into the tree.
*/

class Node{
    public:
        string value;
        Node *left, *right;
        Node(string value, Node *left = nullptr, Node *right = nullptr){
            this->value = value;
            this->left = left;
            this->right = right;
        }
};

string serialize(Node *root){
    string s;
    if(root == NULL){
        s+=MARKER;
        s+=" ";
        return s;
    }
    s+=root->value;
    s+=" ";
    s += serialize(root->left);
    s += serialize(root->right);
    return s;
}

void deserializeHelper(Node *&root, stringstream &ss){
    string val;
    while(ss >> val){
        if(val == MARKER){
            return;
        }
        root = new Node(val);
        deserializeHelper(root->left, ss);
        deserializeHelper(root->right, ss);
    }
}

Node *deserialize(string s){
    Node *root;
    std::stringstream iss(s);
    deserializeHelper(root, iss);
    return root;
}

int main(){
    Node *node =  new Node("root",  new Node("left", new Node("left.left")), new Node("right"));
    /*string s = serialize(node);
    cout << s << endl;
    Node *newnode = deserialize(s);
    cout << newnode->left->left->value << endl;*/
    if(deserialize(serialize(node))->left->left->value == "left.left"){
        cout << "Success!" << endl;
    }
    else cout << "Failure!";
}