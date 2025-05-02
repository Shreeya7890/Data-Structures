//Binary Search Tree (BST) ADT Implementation
#include <iostream>
using namespace std;
 
struct Node {
    int data;
    Node* left;
    Node* right;
};

class BST {
    private:
        Node* root;
        Node* createNode(int value);       
        Node* insert(Node* root, int value); 
        bool search(Node* root, int key);  
        void inorder(Node* root);          
        void preorder(Node* root);         
        void postorder(Node* root); 

    public:
        BST();                  
        void insert(int value); 
        bool search(int key);   
        void inorder();         
        void preorder();        
        void postorder();                 
};

//Main function 
int main() {
    BST tree;
    int choice, value;

    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Insert\n2. Preorder\n3. Inorder\n4. Postorder\n5. Search\n6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                tree.insert(value);
                break;
            case 2:
                cout << "Preorder Traversal: ";
                tree.preorder();
                break;
            case 3:
                cout << "Inorder Traversal: ";
                tree.inorder();
                break;
            case 4:
                cout << "Postorder Traversal: ";
                tree.postorder();
                break;
            case 5:
                cout << "Enter value to search: ";
                cin >> value;
                if (tree.search(value)) {
                    cout << "Element found.\n";
                } else {
                    cout << "Element not found.\n";
                }
                break;
            case 6:
                cout << "Exiting program.\n";
                return 0;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    }
}

//Constructor
BST::BST() {
    root = nullptr;
}

//Create a new node 
Node* BST::createNode(int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->left = newNode->right = nullptr;
    return newNode;
}

//Insert a new value into the BST 
Node* BST::insert(Node* root, int value) {
    if (root == nullptr) {
        return createNode(value);
    }
    if (value < root->data) {
        root->left = insert(root->left, value);
    } else {
        root->right = insert(root->right, value);
    }
    return root;
}

void BST::insert(int value) {
    root = insert(root, value);
}

//Search for a value in the BST 
bool BST::search(Node* root, int key) {
    if (root == nullptr) {
        return false;
    }
    if (root->data == key) {
        return true;
    }
    if (key < root->data) {
        return search(root->left, key);
    }
    return search(root->right, key);
}

bool BST::search(int key) {
    return search(root, key);
}

//Inorder Traversal
void BST::inorder(Node* root) {
    if (root) {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

void BST::inorder() {
    inorder(root);
    cout << endl;
}

//Preorder Traversal 
void BST::preorder(Node* root) {
    if (root) {
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
}

void BST::preorder() {
    preorder(root);
    cout << endl;
}

//Postorder Traversal 
void BST::postorder(Node* root) {
    if (root) {
        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
    }
}

void BST::postorder() {
    postorder(root);
    cout << endl;
}
