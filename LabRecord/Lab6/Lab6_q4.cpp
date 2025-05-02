//
#include <iostream>
#include <stack>
using namespace std;

class ParenthesisChecker {
public:
    
};

int main() {
    ParenthesisChecker checker;
    int choice;
    string input;

    do {
        cout << "\nMenu:\n1. Check Balance\n2. Exit\nEnter choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter parentheses string: ";
                cin >> input;
                if (checker.isBalanced(input))
                    cout << "Balanced\n";
                else
                    cout << "Not Balanced\n";
                break;
            case 2:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 2);

    return 0;
}

bool ParenthesisChecker::isBalanced(const string &expr) {
    stack<char> s;
    for (char ch : expr) {
        if (ch == '(') {
            s.push(ch);
        } else if (ch == ')') {
            if (s.empty()) return false; // Unmatched ')'
            s.pop(); // Matching '(' found
        }
    }
    return s.empty(); // If stack is empty, balanced
}

//Time complexity:
//Complexity: O(n) (Best and worst Cases)
// Each character is pushed or popped at most once. So O(n)
// Since each character is processed atleast once, its not O(1).
