// Array List ADT using class and menu
#include <stdio.h>
#include <stdlib.h>

#define size 5

class list {
    private:
        int arr[size]; 
        int count; 

    public:
    list() {
        count = -1; 
    }
    void insert_beginning(int value); 
    void insert_end(int value); 
    void insert_position(int pos, int value); 
    int delete_beginning(); 
    int delete_end(); 
    int delete_position(int pos); 
    void search(int value); 
    void display(); 
    void rotate(int k); 
};

int main() {
    list list1;
    int choice, value, pos, k;
    do {
        printf("\nMenu:\n");
        printf("1. Insert at beginning\n2. Insert at end\n3. Insert at a position\n");
        printf("4. Delete from beginning\n5. Delete from end\n6. Delete at a position\n");
        printf("7. Search\n8. Display\n9. Rotate\n10. Exit\n");
        printf("Enter a choice from 1 to 10: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to be inserted: ");
                scanf("%d", &value);
                list1.insert_beginning(value);
                break;
            case 2:
                printf("Enter value to be inserted: ");
                scanf("%d", &value);
                list1.insert_end(value);
                break;
            case 3:
                printf("Enter value to be inserted: ");
                scanf("%d", &value);
                printf("Enter position: ");
                scanf("%d", &pos);
                list1.insert_position(pos, value);
                break;
            case 4:
                printf("Deleted value: %d\n", list1.delete_beginning());
                break;
            case 5:
                printf("Deleted value: %d\n", list1.delete_end());
                break;
            case 6:
                printf("Enter position: ");
                scanf("%d", &pos);
                printf("Deleted value: %d\n", list1.delete_position(pos));
                break;
            case 7:
                printf("Enter value to be searched: ");
                scanf("%d", &value);
                list1.search(value);
                break;
            case 8:
                printf("Existing list: ");
                list1.display();
                break;
            case 9:
                printf("Enter the number of positions to rotate: ");
                scanf("%d", &k);
                list1.rotate(k);
                break;
            case 10:
                printf("Exiting..\n");
                break;
        }
    } while (choice != 10);
}

// Insert value at the beginning
void list::insert_beginning(int value) {
    if (count == size - 1) {
        printf("List is full\n");
        return;
    }
    for (int i = count + 1; i > 0; i--) {
        arr[i] = arr[i - 1];
    }
    arr[0] = value;
    count++;
}

// Insert value at the end
void list::insert_end(int value) {
    if (count == size - 1) {
        printf("List is full\n");
        return;
    }
    arr[++count] = value;
}

// Insert value at a specific position
void list::insert_position(int pos, int value) {
    if (count == size - 1 || pos < 1 || pos > count + 2) {
        printf("Invalid entry or List is full\n");
        return;
    }
    for (int i = count + 1; i >= pos; i--) {
        arr[i] = arr[i - 1];
    }
    arr[pos - 1] = value;
    count++;
}

// Delete value from the beginning and return deleted value
int list::delete_beginning() {
    if (count == -1) {
        printf("List is empty\n");
        return -1;
    }
    int deleted_value = arr[0];
    for (int i = 0; i < count; i++) {
        arr[i] = arr[i + 1];
    }
    count--;
    return deleted_value;
}

// Delete value from the end and return deleted value
int list::delete_end() {
    if (count == -1) {
        printf("List is empty\n");
        return -1;
    }
    return arr[count--];
}

// Delete value from a specific position and return deleted value
int list::delete_position(int pos) {
    if (count == -1 || pos < 1 || pos > count + 1) {
        printf("Cannot delete\n");
        return -1;
    }
    int deleted_value = arr[pos - 1];
    for (int i = pos - 1; i < count; i++) {
        arr[i] = arr[i + 1];
    }
    count--;
    return deleted_value;
}

// Search for an element in the list
void list::search(int value) {
    for (int i = 0; i <= count; i++) {
        if (arr[i] == value) {
            printf("Number was found at position %d", i + 1);
            return;
        }
    }
    printf("Number not found\n");
}

// Display the elements of the list
void list::display() {
    if (count == -1) { 
        printf("List is empty\n");
        return;
    }
    for (int i = 0; i <= count; i++) { 
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Rotate the list by k positions
void list::rotate(int k) {
    if (count == -1) { 
        printf("List is empty!\n");
        return;
    }

    k = k % (count + 1); 
    if (k == 0) return;

    int temp[size];
    for (int i = 0; i <= count; i++) { 
        temp[(i + k) % (count + 1)] = arr[i];
    }
    for (int i = 0; i <= count; i++) { 
        arr[i] = temp[i];
    }
    printf("Rotated list by %d positions.\n", k);
}
