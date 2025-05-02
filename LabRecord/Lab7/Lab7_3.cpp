//Queue ADT using LinkedList
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class Queue {
    private:
        Node *front, *rear;

    public:
        Queue() {
            front = rear = nullptr;
        }
        bool isEmpty();
        void enqueue(int value);
        void dequeue();
        void peek();
};

int main() {
    Queue q;
    int choice, value;

    do {
        cout << "\n1. Enqueue\n2. Dequeue\n3. Peek\n4. Exit\nEnter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1: 
                cout << "Enter value: ";
                cin >> value;
                q.enqueue(value);
                break;
            case 2: 
                q.dequeue();
                break;
            case 3: 
                q.peek();
                break;
            case 4: 
                cout << "Exiting...\n";
                break;
            default: 
                cout << "Invalid choice!\n";
        }
    } while (choice != 4);

    return 0;
}

// Check if the queue is empty
bool Queue::isEmpty() {
    return front == nullptr;
}

// Insert an element into the queue
void Queue::enqueue(int value) {
    Node* temp = new Node;
    temp->data = value;
    temp->next = nullptr;

    if (rear == nullptr) {
        front = rear = temp;
    } else {
        rear->next = temp;
        rear = temp;
    }
    cout << value << " enqueued into the queue.\n";
}

// Remove an element from the queue
void Queue::dequeue() {
    if (isEmpty()) {
        cout << "Queue is empty!\n";
        return;
    }
    Node* temp = front;
    cout << front->data << " dequeued from the queue.\n";
    front = front->next;
    delete temp;

    if (front == nullptr) {
        rear = nullptr; 
    }
}

// Display the front element of the queue
void Queue::peek() {
    if (isEmpty()) {
        cout << "Queue is empty!\n";
        return;
    }
    cout << "Front element: " << front->data << endl;
}