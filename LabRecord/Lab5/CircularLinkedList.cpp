//Menu driven program for Circular linked list
#include <iostream>
#include <cstdlib>
using namespace std;

class CircularLinkedList {
    private:
        struct Node {
            int data;
            Node* prev;
            Node* next;
        };
        Node* head; 

    public:
        CircularLinkedList(){
            head=nullptr;
        }
        void insertBeginning(int value);
        void insertEnd(int value);
        void insertPosition(int pos, int value);
        int deleteBeginning();
        int deleteEnd();
        int deletePosition(int pos);
        int search(int value);
        void display();
};

int main() {
    CircularLinkedList list;
    int choice, value, position;
    do {
        cout << "\n1. Insert Beginning\n2. Insert End\n3. Insert Position\n4. Delete Beginning\n";
        cout << "5. Delete End\n6. Delete Position\n7. Search\n8. Display\n9. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter value: "; cin >> value;
                list.insertBeginning(value);
                break;
            case 2:
                cout << "Enter value: "; cin >> value;
                list.insertEnd(value);
                break;
            case 3:
                cout << "Enter position and value: "; cin >> position >> value;
                list.insertPosition(position, value);
                break;
            case 4:
                cout << "Deleted value: " << list.deleteBeginning() << endl;
                break;
            case 5:
                cout << "Deleted value: " << list.deleteEnd() << endl;
                break;
            case 6:
                cout << "Enter position: "; cin >> position;
                cout << "Deleted value: " << list.deletePosition(position) << endl;
                break;
            case 7:
                cout << "Enter value to search: "; cin >> value;
                position = list.search(value);
                if (position != -1)
                    cout << "Element found at position: " << position << endl;
                else
                    cout << "Element not found!" << endl;
                break;
            case 8:
                list.display();
                break;
            case 9:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice!" << endl;
        }
    } while (choice != 9);
    return 0;
}

// Inserting at the beginning
void CircularLinkedList::insertBeginning(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    if (!head) {
        newNode->next = newNode;
        newNode->prev = newNode;
        head = newNode;
    } 
    else {
        Node* tail = head->prev;
        newNode->next = head;
        newNode->prev = tail;
        tail->next = newNode;
        head->prev = newNode;
        head = newNode;
    }
}

// Inserting at the end
void CircularLinkedList::insertEnd(int value) {
    if (!head) {
        insertBeginning(value);
        return;
    }
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    Node* tail = head->prev;
    newNode->next = head;
    newNode->prev = tail;
    tail->next = newNode;
    head->prev = newNode;
}

// Inserting at position
void CircularLinkedList::insertPosition(int pos, int value) {
    if (pos <= 0) {
        cout << "Invalid position!" << endl;
        return;
    }
    if (pos == 1 || !head) {
        insertBeginning(value);
        return;
    }
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    Node* temp = head;
    for (int i = 1; temp->next != head && i < pos - 1; i++) {
        temp = temp->next;
    }
    newNode->next = temp->next;
    newNode->prev = temp;
    temp->next->prev = newNode;
    temp->next = newNode;
}

// Delete from the beginning
int CircularLinkedList::deleteBeginning() {
    if (!head) {
        cout << "List is empty!" << endl;
        return -1;
    }
    Node* temp = head;
    int value = temp->data;
    if (head->next == head) {
        head = nullptr;
    } else {
        Node* tail = head->prev;
        head = head->next;
        head->prev = tail;
        tail->next = head;
    }
    free(temp);
    return value;
}

// Delete from the end
int CircularLinkedList::deleteEnd() {
    if (!head) return -1;
    if (head->next == head) return deleteBeginning();
    Node* tail = head->prev;
    int value = tail->data;
    tail->prev->next = head;
    head->prev = tail->prev;
    free(tail);
    return value;
}

// Delete from position
int CircularLinkedList::deletePosition(int pos) {
    if (!head || pos <= 0) return -1;
    if (pos == 1) return deleteBeginning();
    Node* temp = head;
    for (int i = 1; temp->next != head && i < pos; i++) {
        temp = temp->next;
    }
    if (temp->next == head) return deleteEnd();
    int value = temp->data;
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    free(temp);
    return value;
}

// Search for an element in the list 
int CircularLinkedList::search(int value) {
    if (!head) return -1;
    Node* temp = head;
    int pos = 1;
    do {
        if (temp->data == value) return pos;
        temp = temp->next;
        pos++;
    } while (temp != head);
    return -1;
}

//Displaying the list
void CircularLinkedList::display() {
    if (!head) {
        cout << "List is empty!" << endl;
        return;
    }
    Node* temp = head;
    cout << "Circular DLL: ";
    do {
        cout << temp->data << " <-> ";
        temp = temp->next;
    } while (temp != head);
    cout << "(head)" << endl;
}
