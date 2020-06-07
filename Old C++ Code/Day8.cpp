#include <iostream>
using namespace std;

/*
A unival tree (which stands for "universal value") is a tree where all nodes under it have the same value.

Given the root to a binary tree, count the number of unival subtrees.

For example, the following tree has 5 unival subtrees:

   0
  / \
 1   0
    / \
   1   0
  / \
 1   1
*/

class Node{
    public:
        int value;
        Node *left, *right;
        Node(int value, Node *left = nullptr, Node *right = nullptr){
            this->value = value;
            this->left = left;
            this->right = right;
        }
};

bool isCurrentNodeUnivalTree(Node *root, int value){
    if(root == NULL){
        return true;
    }
    if(root->value == value){
        return(isCurrentNodeUnivalTree(root->left, value) && isCurrentNodeUnivalTree(root->right, value));
    }
    return false;
}

int numUnivalSubtrees(Node *root){
    int count = isCurrentNodeUnivalTree(root, root->value);
    if(root->left){
        count += numUnivalSubtrees(root->left);
    }
    if(root->right){
        count += numUnivalSubtrees(root->right);
    }
    return count;
}

int main(){
    Node *root = new Node(0);
    root->left = new Node(1);
    root->right = new Node(0);
    root->right->left = new Node(1);
    root->right->left->left = new Node(1);
    root->right->left->right = new Node(1);
    root->right->right = new Node(0);
    cout << numUnivalSubtrees(root) << endl;

}