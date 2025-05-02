// Priority queue implementation
#include <iostream>
#include <vector>
using namespace std;

class MaxHeap {
    private:
        vector<int> heap;
        void heapifyUp(int index);
        void heapifyDown(int index);
    public:
        void insert(int value);
        void deleteMax();
        void display();
        bool search(int value);
        void heapSort();
};

//Main program
int main() {
    MaxHeap heap;
    int choice, value;
    do {
        cout << "\nMenu:\n1. Insert\n2. Delete Max\n3. Display\n4. Search\n5. Heap Sort\n6. Exit\nEnter choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                heap.insert(value);
                break;
            case 2:
                heap.deleteMax();
                break;
            case 3:
                heap.display();
                break;
            case 4:
                cout << "Enter value to search: ";
                cin >> value;
                if (heap.search(value)) {
                    cout << "Found" << endl;
                } 
                else {
                    cout << "Not Found" << endl;
                }
                break;
            case 5:
                heap.heapSort();
                break;
            case 6:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice!" << endl;
        }
    } 
    while (choice != 6);
    return 0;
}

// Maintain heap order from bottom to top after insertion
void MaxHeap::heapifyUp(int index) {
    while (index > 0 && heap[index] > heap[(index - 1) / 2]) {
        swap(heap[index], heap[(index - 1) / 2]);
        index = (index - 1) / 2;
    }
}

// Maintain heap order from top to bottom after deletion
void MaxHeap::heapifyDown(int index) {
    int size = heap.size();
    int largest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < size && heap[left] > heap[largest])
        largest = left;
    if (right < size && heap[right] > heap[largest])
        largest = right;
    if (largest != index) {
        swap(heap[index], heap[largest]);
        heapifyDown(largest);
    }
}

// Insert a new value into the heap and fix the heap
void MaxHeap::insert(int value) {
    heap.push_back(value);
    heapifyUp(heap.size() - 1);
}

// Delete the root element (maximum) and re-heapify
void MaxHeap::deleteMax() {
    if (heap.empty()) {
        cout << "Heap is empty!" << endl;
        return;
    }
    heap[0] = heap.back();
    heap.pop_back();
    heapifyDown(0);
}

// Display all elements of the heap
void MaxHeap::display() {
    for (int val : heap) cout << val << " ";
    cout << endl;
}

// Search for a specific value in the heap
bool MaxHeap::search(int value) {
    for (int val : heap) {
        if (val == value) return true;
    }
    return false;
}

// Perform heap sort and print the sorted elements
void MaxHeap::heapSort() {
    vector<int> sortedHeap = heap; 
    vector<int> sorted;

    while (!sortedHeap.empty()) {
        sorted.push_back(sortedHeap.front());
        swap(sortedHeap.front(), sortedHeap.back());
        sortedHeap.pop_back();

        int index = 0, size = sortedHeap.size();
        while (true) {
            int left = 2 * index + 1;
            int right = 2 * index + 2;
            int largest = index;

            if (left < size && sortedHeap[left] > sortedHeap[largest]) largest = left;
            if (right < size && sortedHeap[right] > sortedHeap[largest]) largest = right;
            if (largest == index) break;

            swap(sortedHeap[index], sortedHeap[largest]);
            index = largest;
        }
    }

    for (int val : sorted) cout << val << " ";
    cout << endl;
}