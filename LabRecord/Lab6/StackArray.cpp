// Implement stack ADT using a character array of size 5
#include <iostream>
using namespace std;

#define SIZE 5  

class Stack {
private:
    char arr[SIZE]; 
    int top;

public:
    Stack() { top = -1; } 

    void push(char element);
    char pop();
    char peek();
    bool isEmpty();
};

int main() {
    Stack stack1;
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
                stack1.push(value);
                break;
            case 2:
                value = stack1.pop();
                if (value != '\0')
                    cout << "Popped: " << value << endl;
                break;
            case 3:
                value = stack1.peek();
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
    if (top >= SIZE - 1) {
        cout << "Stack Overflow! Cannot push '" << element << "'\n";
        return;
    }
    arr[++top] = element;
    cout << "Pushed: " << element << endl;
}

// Pop operation
char Stack::pop() {
    if (top < 0) {
        cout << "Stack Underflow! Nothing to pop.\n";
        return '\0'; 
    }
    return arr[top--];
}

// Peek operation
char Stack::peek() {
    if (top < 0) {
        cout << "Stack is empty!\n";
        return '\0';
    }
    return arr[top];
}

// Check if stack is empty
bool Stack::isEmpty() {
    return top < 0;
}


//Time complexity: 
// Push, Pop and Peek in array: O(1)
//Each operation in an array-based stack is performed in constant time. 
//But the fixed size can cause stack overflow.