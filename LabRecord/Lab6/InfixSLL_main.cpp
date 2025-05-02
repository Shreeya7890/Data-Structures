//Main program file for infix using SLL

#include <iostream>
#include "InfixSLL.h"

using namespace std;

string infixToPostfix(string infix);
int evaluatePostfix(string postfix);
bool isBalanced(string expr);
int precedence(char op);
bool isOperator(char ch);

int main() {
    int choice;
    string infix, postfix;
    char expr[100];

    do {
        cout << "\nMenu:\n";
        cout << "1. Get Infix Expression\n";
        cout << "2. Convert Infix to Postfix\n";
        cout << "3. Evaluate Postfix Expression\n";
        cout << "4. Check Parentheses Balance\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter a valid infix expression (without spaces): ";
                cin >> infix;
                break;

            case 2:
                if (infix.empty()) {
                    cout << "Please enter an infix expression first!\n";
                } else {
                    postfix = infixToPostfix(infix);
                    cout << "Postfix Expression: " << postfix << endl;
                }
                break;

            case 3:
                if (postfix.empty()) {
                    cout << "Please convert an infix expression first!\n";
                } else {
                    cout << "Evaluation Result: " << evaluatePostfix(postfix) << endl;
                }
                break;

            case 4:
                cout << "Enter expression with only '(' and ')': ";
                cin >> expr;
                cout << (isBalanced(expr) ? "Balanced\n" : "Not Balanced\n");
                break;

            case 5:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 5);

    return 0;
}

// Function to get precedence of operators
int precedence(char op) {
    if (op == '=') return 1;
    if (op == '+' || op == '-') return 2;
    if (op == '*' || op == '/') return 3;
    if (op == '^') return 4;
    return 0;
}

// Check if character is an operator
bool isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^' || ch == '=');
}

// Function to convert infix to postfix
string infixToPostfix(string infix) {
    Stack stack;
    string postfix;
    
    for (int i = 0; i < infix.length(); i++) {
        char ch = infix[i];

        if (isdigit(ch)) {
            postfix += ch;
        } 
        else if (ch == '(') {
            stack.push(ch);
        } 
        else if (ch == ')') {
            while (!stack.isEmpty() && stack.peek() != '(') {
                postfix += stack.pop();
            }
            stack.pop();  // Remove '('
        } 
        else if (isOperator(ch)) {
            while (!stack.isEmpty() && precedence(stack.peek()) >= precedence(ch)) {
                postfix += stack.pop();
            }
            stack.push(ch);
        }
    }
    while (!stack.isEmpty()) {
        postfix += stack.pop();
    }
    return postfix;
}

// Function to evaluate a postfix expression
int evaluatePostfix(string postfix) {
    Stack stack;
    
    for (int i = 0; i < postfix.length(); i++) {
        char ch = postfix[i];

        if (isdigit(ch)) {
            stack.push(ch - '0');  // Convert char to int
        } 
        else {
            int val2 = stack.pop();
            int val1 = stack.pop();

            switch (ch) {
                case '+': stack.push(val1 + val2); break;
                case '-': stack.push(val1 - val2); break;
                case '*': stack.push(val1 * val2); break;
                case '/': stack.push(val1 / val2); break;
                case '^': stack.push(val1 ^ val2); break;
            }
        }
    }
    return stack.pop();
}

// Function to check balanced parentheses
bool isBalanced(string expr) {
    Stack stack;
    
    for (int i = 0; expr[i] != '\0'; i++) {
        char ch = expr[i];

        if (ch == '(') {
            stack.push(ch);
        } 
        else if (ch == ')') {
            if (stack.isEmpty()) return false;
            stack.pop();
        }
    }
    return stack.isEmpty();
}

//Time complexity:
// Complexity: O(n)
//Processing each character/operator once in a stack makes the complexity O(n)