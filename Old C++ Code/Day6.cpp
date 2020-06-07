#include <iostream>
using namespace std;

/*
An XOR linked list is a more memory efficient doubly linked list. Instead of each node holding next and prev fields, it holds a field named both, which is an XOR of the next node and the previous node. Implement an XOR linked list; it has an add(element) which adds the element to the end, and a get(index) which returns the node at index.
*/

class Node{
    public:
        Node(int value){
            this->value = value;
            this->both = nullptr;
            size = 1;
        }
        void add(int value){
            addHelper(this, value);
            size++;
        }
        Node *get(int index){
            Node *curr = this;
            Node *prev = NULL;
            Node *next;
            int iterator = 0;
            while(iterator != index){
                next = XOR(prev, curr->both);
                prev = curr;
                curr = next;
                iterator++;
            }
            return curr;
        }
        int value;
    private:
        int size;
        Node *both;
        void addHelper(Node *head, int value){
            Node *newNode = new Node(value);
            Node *curr = get(size-1);
            newNode->both = XOR(curr, NULL);
            Node *prev = XOR(curr->both, NULL);
            Node *next = nullptr;
            curr->both = XOR(newNode, XOR(curr->both,  NULL));
        }
        Node *XOR(Node *x, Node *y){
            return (Node *)((uintptr_t)(x) ^ (uintptr_t)(y));
        }
};

int main(){
    Node *head = new Node(0);
    for(int i = 1; i < 10; i++){
        head->add(i);
    }
    for(int i = 0; i < 10; i++){
        cout << head->get(i)->value << endl;
    }
}