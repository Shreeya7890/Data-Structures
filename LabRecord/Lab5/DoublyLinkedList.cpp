// Menu driven program for doubly linked list
#include <iostream>
#include <cstdlib>
using namespace std;

class DoublyLinkedList {
    private:
        struct Node {
            int data;
            Node* prev;
            Node* next;
        };

        Node* head; 
        Node* tail; 

    public:
        DoublyLinkedList(){
            head=nullptr;
            tail=nullptr;
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
    DoublyLinkedList list;
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
void DoublyLinkedList::insertBeginning(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->prev = nullptr;
    newNode->next = head;
    if (head) head->prev = newNode;
    head = newNode;
    if (!tail) tail = newNode;
}

// Inserting at the end 
void DoublyLinkedList::insertEnd(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = nullptr;
    newNode->prev = tail;
    if (tail) tail->next = newNode;
    tail = newNode;
    if (!head) head = newNode;
}

// Inserting at position
void DoublyLinkedList::insertPosition(int pos, int value) {
    if (pos <= 0) {
        cout << "Invalid position!" << endl;
        return;
    }
    if (pos == 1) {
        insertBeginning(value);
        return;
    }
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    Node* temp = head;
    for (int i = 1; temp && i < pos - 1; i++) {
        temp = temp->next;
    }
    if (!temp) {
        cout << "Position out of range!" << endl;
        free(newNode);
        return;
    }
    newNode->next = temp->next;
    newNode->prev = temp;
    if (temp->next) temp->next->prev = newNode;
    temp->next = newNode;
    if (!newNode->next) tail = newNode;
}

// Delete from the beginning 
int DoublyLinkedList::deleteBeginning() {
    if (!head) {
        cout << "List is empty!" << endl;
        return -1;
    }
    Node* temp = head;
    int value = temp->data;
    head = head->next;
    if (head) head->prev = nullptr;
    else tail = nullptr;
    free(temp);
    return value;
}

// Delete from the end 
int DoublyLinkedList::deleteEnd() {
    if (!tail) {
        cout << "List is empty!" << endl;
        return -1;
    }
    Node* temp = tail;
    int value = temp->data;
    tail = tail->prev;
    if (tail) tail->next = nullptr;
    else head = nullptr;
    free(temp);
    return value;
}

// Delete from position
int DoublyLinkedList::deletePosition(int pos) {
    if (!head) {
        cout << "List is empty!" << endl;
        return -1;
    }
    
    if (pos <= 0) {
        cout << "Invalid position!" << endl;
        return -1;
    }

    Node* temp = head;
    if (pos == 1) {
        return deleteBeginning(); 
    }

    for (int i = 1; temp && i < pos; i++) {
        temp = temp->next;
    }

    if (!temp) {
        cout << "Position out of range!" << endl;
        return -1;
    }

    int value = temp->data; 

    if (temp == tail) {
        return deleteEnd(); 
    }

    temp->prev->next = temp->next; 
    temp->next->prev = temp->prev; 

    free(temp); 

    return value; 
}

// Search for an element in the list 
int DoublyLinkedList::search(int value) {
    Node* temp = head;
    int pos = 1;
    while (temp) {
        if (temp->data == value) {
            return pos;
        }
        temp = temp->next;
        pos++;
    }
    return -1;
}

//Displaying the list
void DoublyLinkedList::display() {
    if (!head) {
        cout << "List is empty!" << endl;
        return;
    }

    cout << "Forward: ";
    Node* temp = head;
    while (temp) {
        cout << temp->data << " <-> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;

    cout << "Reverse: ";
    temp = tail;
    while (temp) {
        cout << temp->data << " <-> ";
        temp = temp->prev;
    }
    cout << "NULL" << endl;
}

