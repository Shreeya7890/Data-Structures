// Round Robin scheduling algorithm using the circular linked list
#include "Round Robin.h"

int main() {
    int timeSlice;
    cout << "Enter time slice: ";
    cin >> timeSlice;
    
    RoundRobinScheduler scheduler(timeSlice);
    int choice, time;
    
    do {
        cout << "\n1. Insert Process\n2. Execute\n3. Display\n4. Exit\nEnter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter process time: ";
                cin >> time;
                scheduler.insertProcess(time);
                break;
            case 2:
                scheduler.execute();
                break;
            case 3:
                scheduler.display();
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

RoundRobinScheduler::RoundRobinScheduler(int slice) : tail(nullptr), timeSlice(slice) {}

// Function for inserting 
void RoundRobinScheduler::insertProcess(int time) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->time = time;
    if (!tail) {
        newNode->next = newNode;
        tail = newNode;
    } else {
        newNode->next = tail->next;
        tail->next = newNode;
        tail = newNode;
    }
}

//Function for executing
void RoundRobinScheduler::execute() {
    if (!tail) {
        cout << "No processes to execute!\n";
        return;
    }
    
    Node* current = tail->next;
    int remainingTime = current->time - timeSlice;
    cout << "Executing process with time: " << current->time << "\n";
    
    if (remainingTime > 0) {
        cout << "Remaining time after execution: " << remainingTime << "\n";
        insertProcess(remainingTime);
    } else {
        cout << "Process completed.\n";
    }
    
    if (current == tail) {
        tail = nullptr;
    } else {
        tail->next = current->next;
    }
    free(current);
}

// Function for displaying
void RoundRobinScheduler::display() {
    if (!tail) {
        cout << "No processes in queue!\n";
        return;
    }
    
    cout << "Processes in queue: ";
    Node* temp = tail->next;
    do {
        cout << temp->time << " -> ";
        temp = temp->next;
    } while (temp != tail->next);
    cout << "(Back to start)\n";
}
