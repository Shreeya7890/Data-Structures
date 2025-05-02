// Circular queue using array

#include <iostream>
using namespace std;

#define SIZE 5

class CircularQueue {
    private:
        int arr[SIZE];
        int front, rear;

    public:
        CircularQueue() {
            front = -1;
            rear = -1;
        }
        bool isFull();
        bool isEmpty();
        void enqueue(int value);
        void dequeue();
        void peek();
};

int main() {
    CircularQueue cq;
    int choice, value;

    do {
        cout << "\n1. Enqueue\n2. Dequeue\n3. Peek\n4. Exit\nEnter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1: 
                cout << "Enter value: ";
                cin >> value;
                cq.enqueue(value);
                break;
            case 2: 
                cq.dequeue();
                break;
            case 3: 
                cq.peek();
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

// Check if the queue is full
bool CircularQueue::isFull() {
    return (rear + 1) % SIZE == front;
}

// Check if the queue is empty
bool CircularQueue::isEmpty() {
    return front == -1;
}

// Insert an element in the circular queue
void CircularQueue::enqueue(int value) {
    if (isFull()) {
        cout << "Queue is full!\n";
        return;
    }
    if (front == -1) front = 0; 
    rear = (rear + 1) % SIZE;
    arr[rear] = value;
    cout << value << " enqueued into the circular queue.\n";
}

// Remove an element from the circular queue
void CircularQueue::dequeue() {
    if (isEmpty()) {
        cout << "Queue is empty!\n";
        return;
    }
    cout << arr[front] << " dequeued from the circular queue.\n";
    if (front == rear) 
        front = rear = -1; 
    else 
        front = (front + 1) % SIZE;
}

// Display the front element of the queue
void CircularQueue::peek() {
    if (isEmpty()) {
        cout << "Queue is empty!\n";
        return;
    }
    cout << "Front element: " << arr[front] << endl;
}
