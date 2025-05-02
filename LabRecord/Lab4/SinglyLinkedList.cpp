//Menu driven program for Linked list to perform some functions
#include <iostream>
using namespace std;

// Node structure
class Node {
    public:
        int data;
        Node* next;
        Node(int value){
            data = value;
            next = nullptr;
        }
};

// Singly Linked List Class
class SinglyLinkedList {
    private:
        Node* head;

    public:
        SinglyLinkedList(){
            head=nullptr;
        } 
        void insertbeginning(int value);
        void insertend(int value);
        void insertpos(int value, int position);
        int deletebeginning();
        int delete_end();
        int deletepos(int position);
        bool search(int value);
        void display();
        void displayReverse();
        void reverseList();
};

//Main program
int main() {
    SinglyLinkedList list;
    int choice, value, pos;

    do {
        cout << "\nMenu\n";
        cout << "1. Insert Beginning\n";
        cout << "2. Display\n";
        cout << "3. Insert End\n";
        cout << "4. Insert Position\n";
        cout << "5. Delete Beginning\n";
        cout << "6. Delete End\n";
        cout << "7. Delete Position\n";
        cout << "8. Search\n";
        cout << "9. Display Reverse\n";
        cout << "10. Reverse List\n";
        cout << "11. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                list.insertbeginning(value);
                break;
            case 2:
                list.display();
                break;
            case 3:
                cout << "Enter value: ";
                cin >> value;
                list.insertend(value);
                break;
            case 4:
                cout << "Enter value";
                cin >> value;
                cout<< "Enter position: ";
                cin >> pos;
                list.insertpos(value, pos);
                break;
            case 5:
                cout << "Deleted element: " << list.deletebeginning() << "\n";
                break;
            case 6:
                cout << "Deleted element: " << list.delete_end() << "\n";
                break;
            case 7:
                cout << "Enter position to delete: ";
                cin >> pos;
                cout << "Deleted element: " << list.deletepos(pos) << "\n";
                break;
            case 8:
                cout << "Enter value to search: ";
                cin >> value;
                if (list.search(value))
                    cout << "Element has been found.\n";
                else
                    cout << "Element was not found.\n";
                break;
            case 9:
                cout << "Displaying list in reverse: \n";
                list.displayReverse();
                break;
            case 10:
                cout << "List reversed. \n";
                list.reverseList();
                break;
            case 11:
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 11);
    return 0;
}

// Function for Inserting at beginning
void SinglyLinkedList::insertbeginning(int value) {
    Node* newNode = new Node(value);
    newNode->next = head;
    head = newNode;
}

// Function for displaying
void SinglyLinkedList::display() {
    Node* temp = head;
    while (temp) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

// Function for Inserting at end
void SinglyLinkedList::insertend(int value) {
    Node* newNode = new Node(value);
    if (!head) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function for Inserting at position
void SinglyLinkedList::insertpos(int value, int pos) {
    if (pos < 1) return;
    if (pos == 1) {
        insertbeginning(value);
        return;
    }
    Node* newNode = new Node(value);
    Node* temp = head;
    for (int i = 1; temp && i < pos - 1; i++) {
        temp = temp->next;
    }
    if (!temp) return;
    newNode->next = temp->next;
    temp->next = newNode;
}

// Function for deleting from beginning
int SinglyLinkedList::deletebeginning() {
    if (!head) return -1;
    int value = head->data;
    Node* temp = head;
    head = head->next;
    delete temp;
    return value;
}

// Function for deleting from end
int SinglyLinkedList::delete_end() {
    if (!head) return -1;
    if (!head->next) {
        int value = head->data;
        delete head;
        head = nullptr;
        return value;
    }
    Node* temp = head;
    while (temp->next->next) {
        temp = temp->next;
    }
    int value = temp->next->data;
    delete temp->next;
    temp->next = nullptr;
    return value;
}

// Function for deleting at position
int SinglyLinkedList::deletepos(int pos) {
    if (!head || pos < 1) return -1;
    if (pos == 1) return deletebeginning();
    Node* temp = head;
    for (int i = 1; temp->next && i < pos - 1; i++) {
        temp = temp->next;
    }
    if (!temp->next) return -1;
    Node* nodeToDelete = temp->next;
    int value = nodeToDelete->data;
    temp->next = temp->next->next;
    delete nodeToDelete;
    return value;
}

// Function for searching
bool SinglyLinkedList::search(int value) {
    Node* temp = head;
    while (temp) {
        if (temp->data == value) return true;
        temp = temp->next;
    }
    return false;
}

// Function for displaying reverse list
void displayReverseHelper(Node* node) {
    if (!node) return;
    displayReverseHelper(node->next);
    cout << node->data << " -> ";
}
void SinglyLinkedList::displayReverse() {
    displayReverseHelper(head);
    cout << "NULL\n";
}

// Function for reversing original list
void SinglyLinkedList::reverseList() {
    Node* prev = nullptr;
    Node* current = head;
    Node* next = nullptr;
    while (current) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
}


