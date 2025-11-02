#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;      // stores ASCII of operator or digit itself
    Node* left;
    Node* right;
    Node(int val) : data(val), left(NULL), right(NULL) {}
};

int evaluate(Node* root) {
    if (!root) return 0;

    // If leaf → operand
    if (!root->left && !root->right)
        return root->data;  // already number (not ASCII of digit)

    // Evaluate subtrees
    int leftVal = evaluate(root->left);
    int rightVal = evaluate(root->right);

    // Convert ASCII to operator
    char op = (char)root->data;

    switch (op) {
        case '+': return leftVal + rightVal;
        case '-': return leftVal - rightVal;
        case '*': return leftVal * rightVal;
        case '/': return leftVal / rightVal;
    }
    return 0;
}

int main() {
    // Given tree:
    //        *
    //       / \
    //      +   *
    //     / \ / \
    //    2  3 4  5
    //
    // but * and + are ASCII values (42 and 43)

    Node* root = new Node(42);         // *
    root->left = new Node(43);         // +
    root->right = new Node(42);        // *
    root->left->left = new Node(2);
    root->left->right = new Node(3);
    root->right->left = new Node(4);
    root->right->right = new Node(5);

    cout << "Result = " << evaluate(root) << endl;
    return 0;
}
