//  https://www.geeksforgeeks.org/problems/transform-to-sum-tree--170645/1

#include <bits/stdc++.h>
using namespace std;
//User function template for C++


struct Node
{
    int data;
    Node* left, * right;
}; 

class Solution {
public:

    int solve(Node* root) {

        if(root == NULL) {
            return 0;
        }

        int oldValue = root->data;

        int leftSum = solve(root->left);
        int rightSum = solve(root->right);

        root->data = leftSum + rightSum;

        return oldValue + leftSum + rightSum;
    }

    void toSumTree(Node *node) {
        solve(node);
    }
};
