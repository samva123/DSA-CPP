#include <bits/stdc++.h>
using namespace std;



class Solution {
public:
    void convertBSTtoDLL(Node* root, Node* &head) {
        if (root == NULL) return;

        // R
        convertBSTtoDLL(root->right, head);

        // N
        root->right = head;
        if (head != NULL)
            head->left = root;
        head = root;

        // L
        convertBSTtoDLL(root->left, head);
    }

    Node* flattenBST(Node* root) {
        Node* head = NULL;

        // step 1: convert BST to sorted DLL
        convertBSTtoDLL(root, head);

        // step 2: make it right-skewed (left = NULL)
        Node* curr = head;
        while (curr != NULL) {
            curr->left = NULL;
            curr = curr->right;
        }

        return head;
    }
};



class Solution {
public:
    void inorder(Node* root, Node* &prev, Node* &head){
        if(root == NULL) return;

        inorder(root->left, prev, head);

        if(prev == NULL){
            head = root;
        } else {
            prev->right = root;
        }

        root->left = NULL;
        prev = root;

        inorder(root->right, prev, head);
    }

    Node* flattenBST(Node* root) {
        Node* prev = NULL;
        Node* head = NULL;

        inorder(root, prev, head);

        return head;
    }
};