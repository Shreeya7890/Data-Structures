//Header file for infix with SLL
#include <iostream>
using namespace std;

class Node {
    public:
        char data;
        Node* next;
        Node(char val) {
            data = val;
            next = nullptr;
        }
};

class Stack {
    private:
        Node* top;
    public:
        Stack() { top = nullptr; }
        
        void push(char val);
        char pop();
        char peek();
        bool isEmpty();   
};

void Stack::push(char val) {
    Node* newNode = new Node(val);
    newNode->next = top;
    top = newNode;
}

char Stack:: pop() {
    if (isEmpty()) {
        return '\0';  
    }
    char val = top->data;
    Node* temp = top;
    top = top->next;
    delete temp;
    return val;
}

char Stack:: peek() {
    return (top != nullptr) ? top->data : '\0';
}

bool Stack:: isEmpty() {
    return top == nullptr;
}