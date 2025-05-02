//Hash ADT-Quadratic Probing
#include <iostream>
using namespace std;

#define TABLE_SIZE 10

class HashTable {
    private:
        int table[TABLE_SIZE];
        bool occupied[TABLE_SIZE];

    public:
        HashTable(){
            for (int i = 0; i < TABLE_SIZE; i++) {
                table[i] = -1;
                occupied[i] = false;
            }
        }
        void insert(int key);
        int remove(int key);
        int search(int key);
        void display();
};

int main() {
    HashTable ht;
    int choice, key, result;

    do {
        cout << "\nMENU:\n";
        cout << "1. Insert\n2. Remove\n3. Search\n4. Display\n5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter key to insert: ";
            cin >> key;
            ht.insert(key);
            break;
        case 2:
            cout << "Enter key to remove: ";
            cin >> key;
            result = ht.remove(key);
            if (result == -1)
                cout << "Key not found.\n";
            else
                cout << "Removed key: " << result << "\n";
            break;
        case 3:
            cout << "Enter key to search: ";
            cin >> key;
            result = ht.search(key);
            if (result == -1)
                cout << "Key not found.\n";
            else
                cout << "Key found at index: " << result << "\n";
            break;
        case 4:
            ht.display();
            break;
        case 5:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 5);

    return 0;
}


// Insert using Quadratic Probing
void HashTable::insert(int key) {
    int index = key % TABLE_SIZE;
    int i = 0;

    while (i < TABLE_SIZE) {
        int newIndex = (index + i * i) % TABLE_SIZE;
        if (!occupied[newIndex]) {
            table[newIndex] = key;
            occupied[newIndex] = true;
            cout << "Inserted at index " << newIndex << "\n";
            return;
        }
        i++;
    }

    cout << "Hash table is full!\n";
}

// Remove function
int HashTable::remove(int key) {
    int index = key % TABLE_SIZE;
    int i = 0;

    while (i < TABLE_SIZE) {
        int newIndex = (index + i * i) % TABLE_SIZE;
        if (occupied[newIndex] && table[newIndex] == key) {
            int removedValue = table[newIndex];
            table[newIndex] = -1;
            occupied[newIndex] = false;
            return removedValue;
        }
        i++;
    }

    return -1;
}

// Search function
int HashTable::search(int key) {
    int index = key % TABLE_SIZE;
    int i = 0;

    while (i < TABLE_SIZE) {
        int newIndex = (index + i * i) % TABLE_SIZE;
        if (!occupied[newIndex])
            return -1;
        if (table[newIndex] == key)
            return newIndex;
        i++;
    }

    return -1;
}

// Display function
void HashTable::display() {
    cout << "\nHash Table:\n";
    for (int i = 0; i < TABLE_SIZE; i++) {
        cout << i << ": ";
        if (occupied[i])
            cout << table[i];
        else
            cout << "Empty";
        cout << "\n";
    }
}
