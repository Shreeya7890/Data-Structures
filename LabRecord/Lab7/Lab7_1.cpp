//Queue ADT Using Array
#include <iostream>
using namespace std;
#define size 5

class queue{
    int arr[size];
    int front, rear;

    public:
        queue(){
            front= -1;
            rear= -1;
        }
        bool isEmpty();
        bool isFull();
        void enqueue(int value);
        void dequeue();
        void peek();
};

int main() {
    queue q;
    int choice, value;

    do {
        cout << "\n1. Enqueue\n2. Dequeue\n3. Peek\n4. Exit\nEnter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1: 
                cout << "Enter value to be inserted: ";
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

//To check if queue is empty
bool queue::isEmpty()
{
    return front==-1 || front>rear;
}

//To check if queue is full
bool queue::isFull()
{
    return rear==size-1;
}

//Function to add into queue
void queue::enqueue(int value)
{
    if (isFull())
    {
        cout<< "Array is full. Cannot insert value\n";
        return;
    }
    if (front==-1) front=0;
    arr[++rear]= value;
    cout<< value <<" has been enqueued.\n";
}

//Function to remove from a queue
void queue::dequeue()
{
    if (isEmpty())
    {
        cout<< "Empty array. Cannot dequeue.\n";
        return;
    }
    cout<< arr[front++] <<" has been dequeued.\n";
    if (front>rear) front=rear=-1;
}

//function to peek at top element
void queue::peek()
{
    if (isEmpty())
    {
        cout<< "Empty array. No top element.\n";
        return;
    }
    cout << arr[front]<< endl;
}
