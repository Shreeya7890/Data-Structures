//Implement stack ADT using a character singly linked list
#include <iostream>
using namespace std;

struct Node {
    char data;
    Node* next;
};

class Stack {
    private:
        Node* top;

    public:
        Stack() { top = nullptr; }   
                        
        void push(char element);
        char pop();
        char peek();
        bool isEmpty();
};

int main() {
    Stack s;
    int choice;
    char value;

    do {
        cout << "\nStack Operations:\n";
        cout << "1. Push\n2. Pop\n3. Peek\n4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter a character to push: ";
                cin >> value;
                s.push(value);
                break;
            case 2:
                value = s.pop();
                if (value != '\0')
                    cout << "Popped: " << value << endl;
                break;
            case 3:
                value = s.peek();
                if (value != '\0')
                    cout << "Top element: " << value << endl;
                break;
            case 4:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 4);

    return 0;
}

// Push operation
void Stack::push(char element) {
    Node* newNode = new Node();
    if (!newNode) {
        cout << "Heap Overflow! Cannot push '" << element << "'\n";
        return;
    }
    newNode->data = element;
    newNode->next = top;
    top = newNode;
    cout << "Pushed: " << element << endl;
}

// Pop operation
char Stack::pop() {
    if (top == nullptr) {
        cout << "Stack Underflow! Nothing to pop.\n";
        return '\0';
    }
    Node* temp = top;
    char popped = top->data;
    top = top->next;
    delete temp;
    return popped;
}

// Peek operation
char Stack::peek() {
    if (top == nullptr) {
        cout << "Stack is empty!\n";
        return '\0';
    }
    return top->data;
}

// Check if stack is empty
bool Stack::isEmpty() {
    return top == nullptr;
}


//Time complexity:
// Push, Pop and Peek in SLL: O(1)
//Operations on a SLL stack are constant time as insertion and deletion occur at the head. 
//No size limitation, but requires extra memory for pointers.