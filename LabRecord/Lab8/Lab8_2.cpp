#include <stdio.h>
#include <stdlib.h>

class BinaryTree {
    private:
        struct Node {
            char data;
            struct Node* left;
            struct Node* right;
        };

        Node* root;

        Node* createNode(char data);
        Node* insert(Node* node, char data);
        void preorder(Node* node);
        void inorder(Node* node);
        void postorder(Node* node);
        int search(Node* node, char key);

    public:
        BinaryTree();
        void insert(char data);
        void preorder();
        void inorder();
        void postorder();
        void search(char key);
};

int main() {
    BinaryTree tree;
    int choice;
    char data;

    while (1) {
        printf("\n1. Insert\n2. Preorder\n3. Inorder\n4. Postorder\n5. Search\n6. Exit\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter character to insert: ");
                scanf(" %c", &data);
                tree.insert(data);
                break;
            case 2:
                tree.preorder();
                break;
            case 3:
                tree.inorder();
                break;
            case 4:
                tree.postorder();
                break;
            case 5:
                printf("Enter character to search: ");
                scanf(" %c", &data);
                tree.search(data);
                break;
            case 6:
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
}

BinaryTree::BinaryTree() {
    root = NULL;
}

BinaryTree::Node* BinaryTree::createNode(char data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation failed\n");
        return NULL;
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void BinaryTree::insert(char data) {
    root = insert(root, data);
}

BinaryTree::Node* BinaryTree::insert(Node* node, char data) {
    if (node == NULL) return createNode(data);
    
    char direction;
    printf("Insert %c to (L)eft or (R)ight of %c? ", data, node->data);
    scanf(" %c", &direction);

    if (direction == 'L' || direction == 'l')
        node->left = insert(node->left, data);
    else
        node->right = insert(node->right, data);

    return node;
}

void BinaryTree::preorder() {
    printf("Preorder: ");
    preorder(root);
    printf("\n");
}

void BinaryTree::preorder(Node* node) {
    if (node == NULL) return;
    printf("%c ", node->data);
    preorder(node->left);
    preorder(node->right);
}

void BinaryTree::inorder() {
    printf("Inorder: ");
    inorder(root);
    printf("\n");
}

void BinaryTree::inorder(Node* node) {
    if (node == NULL) return;
    inorder(node->left);
    printf("%c ", node->data);
    inorder(node->right);
}

void BinaryTree::postorder() {
    printf("Postorder: ");
    postorder(root);
    printf("\n");
}

void BinaryTree::postorder(Node* node) {
    if (node == NULL) return;
    postorder(node->left);
    postorder(node->right);
    printf("%c ", node->data);
}

void BinaryTree::search(char key) {
    if (search(root, key))
        printf("Element %c found in the tree\n", key);
    else
        printf("Element %c not found in the tree\n", key);
}

int BinaryTree::search(Node* node, char key) {
    if (node == NULL) return 0;
    if (node->data == key) return 1;
    return search(node->left, key) || search(node->right, key);
}
