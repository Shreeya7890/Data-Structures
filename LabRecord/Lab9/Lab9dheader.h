//Code for expression tree
#include <iostream>
#include <stack>
using namespace std;

//Node structure for Expression Tree
struct ExpNode {
    char data;
    ExpNode* left;
    ExpNode* right;
};

class ExpressionTree {
    private:
        ExpNode* root;
        ExpNode* createNode(char value);
        ExpNode* constructTreeHelper(string postfix);
        void inorder(ExpNode* root);
        void preorder(ExpNode* root);
        void postorder(ExpNode* root);
    public:
        ExpressionTree();
        void constructTree(string postfix);
        void inorder();
        void preorder();
        void postorder();
};


//Constructor 
ExpressionTree::ExpressionTree() {
    root = nullptr;
}

//Create a new node
ExpNode* ExpressionTree::createNode(char value) {
    return new ExpNode{value, nullptr, nullptr};
}

//Construct the Expression Tree from a postfix expression 
ExpNode* ExpressionTree::constructTreeHelper(string postfix) {
    stack<ExpNode*> st;
    for (char ch : postfix) {
        ExpNode* node = createNode(ch);
        if (isalnum(ch)) { 
            st.push(node);
        } else { 
            node->right = st.top(); st.pop();
            node->left = st.top(); st.pop();
            st.push(node);
        }
    }
    return st.top();
}

//Public method to construct the tree
void ExpressionTree::constructTree(string postfix) {
    root = constructTreeHelper(postfix);
}

//Inorder traversal 
void ExpressionTree::inorder(ExpNode* root) {
    if (root) {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

void ExpressionTree::inorder() {
    inorder(root);
    cout << endl;
}

//Preorder traversal
void ExpressionTree::preorder(ExpNode* root) {
    if (root) {
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
}

void ExpressionTree::preorder() {
    preorder(root);
    cout << endl;
}

//Postorder traversal 
void ExpressionTree::postorder(ExpNode* root) {
    if (root) {
        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
    }
}

void ExpressionTree::postorder() {
    postorder(root);
    cout << endl;
}

