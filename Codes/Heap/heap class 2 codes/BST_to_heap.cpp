#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

// Step 1: Inorder traversal to get sorted values
void storeInorder(Node* root, vector<int>& inorder) {
    if (root == nullptr) return;
    storeInorder(root->left, inorder);
    inorder.push_back(root->data);
    storeInorder(root->right, inorder);
}

// Step 2: Postorder traversal to assign values
void replaceWithInorder(Node* root, vector<int>& inorder, int& index) {
    if (root == nullptr) return;
    replaceWithInorder(root->left, inorder, index);
    replaceWithInorder(root->right, inorder, index);
    root->data = inorder[index++];
}

// Utility: Level Order Print for verification
void printLevelOrder(Node* root) {
    if (root == nullptr) return;
    vector<Node*> q = {root};
    int i = 0;
    while (i < q.size()) {
        Node* curr = q[i++];
        cout << curr->data << " ";
        if (curr->left) q.push_back(curr->left);
        if (curr->right) q.push_back(curr->right);
    }
    cout << endl;
}

// Main function to convert BST to Min Heap
void convertBSTToMinHeap(Node* root) {
    vector<int> inorder;
    storeInorder(root, inorder);  // Step 1
    int index = 0;
    replaceWithInorder(root, inorder, index);  // Step 2
}

int main() {
    /*
           BST:
               4
             /   \
            2     6
           / \   / \
          1   3 5   7
    */
    Node* root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(6);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    root->right->left = new Node(5);
    root->right->right = new Node(7);

    convertBSTToMinHeap(root);

    cout << "Level Order of Converted Min Heap:\n";
    printLevelOrder(root);

    return 0;
}
