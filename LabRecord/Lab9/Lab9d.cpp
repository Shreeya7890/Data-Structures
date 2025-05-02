//Main file for expression tree
#include "Lab9dheader.h"

int main() {
    ExpressionTree et;
    string postfix;
    int choice;

    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Enter Postfix Expression\n2. Construct Expression Tree\n3. Preorder\n4. Inorder\n5. Postorder\n6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter a valid postfix expression: ";
                cin >> postfix;
                et.constructTree(postfix);
                break;
            case 2:
                cout << "Expression tree constructed.\n";
                break;
            case 3:
                cout << "Preorder Traversal: ";
                et.preorder();
                break;
            case 4:
                cout << "Inorder Traversal: ";
                et.inorder();
                break;
            case 5:
                cout << "Postorder Traversal: ";
                et.postorder();
                break;
            case 6:
                cout << "Exiting program.\n";
                return 0;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    }
}

