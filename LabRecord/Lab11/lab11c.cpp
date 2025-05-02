//Hash ADT-Separate chaining using linked list
#include <iostream>
using namespace std;

#define size 10

struct node{
    int key;
    int data;
    node* next;
};

class chain{
    private:
        node* arr[size];

    public:
        chain(){
            for (int i=0; i<size; i++){
                arr[i]=nullptr;
            }
        }
        void insert(int key, int value);
        int remove(int key);
        void display();
        int search(int key);
};

int main() {
    chain h;
    int choice, key, value;

    while (true) {
        cout << "\n--- Hash Table Menu ---\n";
        cout << "1. Insert\n";
        cout << "2. Remove\n";
        cout << "3. Search\n";
        cout << "4. Display\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter key: ";
                cin >> key;
                cout << "Enter value: ";
                cin >> value;
                h.insert(key, value);
                cout << "Inserted successfully.\n";
                break;

            case 2:
                cout << "Enter key to remove: ";
                cin >> key;
                value = h.remove(key);
                if (value == -1)
                    cout << "Key not found.\n";
                else
                    cout << "Removed key with value: " << value << endl;
                break;

            case 3:
                cout << "Enter key to search: ";
                cin >> key;
                value = h.search(key);
                if (value == -1)
                    cout << "Key not found.\n";
                else
                    cout << "Value found: " << value << endl;
                break;

            case 4:
                h.display();
                break;

            case 5:
                cout << "Exiting...\n";
                return 0;

            default:
                cout << "Invalid choice. Try again.\n";
        }
    }
}

//Insert function
void chain::insert(int key,int value){
    int index= key%size;
    node* newnode= (struct node*)malloc(sizeof(node));
    newnode->key=key;
    newnode->data=value;
    newnode->next=arr[index];
    arr[index]=newnode;

}

//Remove function
int chain::remove(int key){
    int index= key%size;
    node* temp=arr[index];
    while (temp!=NULL){
        if (temp->key==key){
            int val=temp->data;
            arr[index]=temp->next;
            free(temp);
            return val;
        }
        else if(temp->next!=NULL && temp->next->key==key){
            node* del=temp->next;
            temp->next=temp->next->next;
            int val=del->data;
            free(del);
            return val;
        }         
        temp=temp->next;
    }
    return -1;
}

//Search function
int chain::search(int key){
    int index= key%size;
    node* temp=arr[index];
    while (temp!=NULL){
        if(temp->key==key){
            int val=temp->data;
            return val;
        }         
        temp=temp->next;
    }
    return -1;
}

//Display function
void chain::display(){
    for (int i=0;i<size;i++){
        node* temp=arr[i];
        cout<<"Index "<<i<<endl;
        if (temp==NULL){
            cout<<"Empty"<<endl;
        }
        else{
            while(temp!=NULL){
                cout<<"("<<temp->key<<" : "<<temp->data<<")->";
                temp=temp->next;
            }
            cout<<"NULL"<<endl;
        }
    }
    return;
}