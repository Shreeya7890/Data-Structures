// Header file- SinglyLinkedList.h
#include <iostream>
using namespace std;

class Node {
    public:
        int val;
        Node* next;
        Node(int v) {
            val = v;
            next = NULL;
        }
};

class SinglyLinkedList {
    private:
        Node* head;
        Node* gethead(); 

    public:
        SinglyLinkedList() {
            head = NULL;
        }

        void insert(int val);
        void merge(SinglyLinkedList& l2, SinglyLinkedList& merged);
        void display();
};
