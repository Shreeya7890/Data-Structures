// Main program- SLL
#include "SinglyLinkedList.h"

int main() {
    SinglyLinkedList list1, list2, list3;
    int ch, val;

    do {
        cout << "\nMenu\n";
        cout << "1. Insert in List1\n";
        cout << "2. Insert in List2\n";
        cout << "3. Merge into List3\n";
        cout << "4. Display All\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> ch;

        switch (ch) {
            case 1:
                cout << "Enter value: ";
                cin >> val;
                list1.insert(val);
                break;
            case 2:
                cout << "Enter value: ";
                cin >> val;
                list2.insert(val);
                break;
            case 3:
                list3 = SinglyLinkedList(); // reset list3
                list1.merge(list2, list3);
                cout << "Lists merged.\n";
                break;
            case 4:
                cout << "List1: ";
                list1.display();
                cout << "List2: ";
                list2.display();
                cout << "List3: ";
                list3.display();
                break;
            case 5:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid!\n";
        }
    } while (ch != 5);

    return 0;
}

// Private head getter
Node* SinglyLinkedList::gethead() {
    return head;
}

// Insert in ascending order
void SinglyLinkedList::insert(int val) {
    Node* newNode = new Node(val);

    if (head == NULL || val <= head->val) {
        newNode->next = head;
        head = newNode;
        return;
    }

    Node* ptr = head;
    while (ptr->next && ptr->next->val < val)
        ptr = ptr->next;

    newNode->next = ptr->next;
    ptr->next = newNode;
}

// Merge two sorted lists into a third
void SinglyLinkedList::merge(SinglyLinkedList& l2, SinglyLinkedList& merged) {
    Node* p1 = this->gethead();
    Node* p2 = l2.gethead();

    while (p1) {
        merged.insert(p1->val);
        p1 = p1->next;
    }
    while (p2) {
        merged.insert(p2->val);
        p2 = p2->next;
    }
}

// Function to display list
void SinglyLinkedList::display() {
    if (!head) {
        cout << "List is empty.\n";
        return;
    }

    Node* ptr = head;
    while (ptr) {
        cout << ptr->val << " -> ";
        ptr = ptr->next;
    }
    cout << "NULL\n";
}
