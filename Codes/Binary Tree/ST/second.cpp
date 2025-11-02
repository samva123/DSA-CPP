#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(NULL), right(NULL) {}
};

// Function to create mirror
void mirror(Node* root) {
    if (!root) return;

    // Step 1: swap left and right
    swap(root->left, root->right);

    // Step 2: recursively mirror subtrees
    mirror(root->left);
    mirror(root->right);
}

// For checking: inorder traversal
void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    // Example tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);

    cout << "Original inorder: ";
    inorder(root);
    cout << endl;

    mirror(root);

    cout << "Mirror inorder:   ";
    inorder(root);
    cout << endl;
}
