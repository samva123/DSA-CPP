#include <bits/stdc++.h>
using namespace std;
//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    void storeInorder(TreeNode* root, vector<int> &inorder) {
        //base case
        if(root == NULL) {
            return;
        }
        //LNR
        storeInorder(root->left, inorder);
        //N
        inorder.push_back(root->val);
        //R
        storeInorder(root->right, inorder);
    }

    bool findTarget(TreeNode* root, int k) {
        vector<int> inorder;
        storeInorder(root, inorder);

        ///find targetnusing 2 pointer approach
        int start = 0;
        int end = inorder.size()-1;

        while(start < end) {
            int sum = inorder[start] + inorder[end];
            if(sum == k) {
                return true;
            }
            else if(sum > k) {
                end--;
            }
            else if(sum < k) {
                start++;
            }
        }
        return false;
    }
};





//try to find one more approach other than below one 









// class Solution {
// public:
//     bool findTarget(TreeNode* root, int k) {
//         if (!root) return false;

//         stack<TreeNode*> leftStack, rightStack;
//         TreeNode* left = root, *right = root;

//         // Initialize the left stack for in-order traversal
//         while (left) {
//             leftStack.push(left);
//             left = left->left;
//         }

//         // Initialize the right stack for reverse in-order traversal
//         while (right) {
//             rightStack.push(right);
//             right = right->right;
//         }

//         while (!leftStack.empty() && !rightStack.empty()) {
//             TreeNode* leftNode = leftStack.top();
//             TreeNode* rightNode = rightStack.top();

//             // If the two pointers meet, break the loop
//             if (leftNode == rightNode) break;

//             int sum = leftNode->val + rightNode->val;

//             if (sum == k) {
//                 return true;
//             } else if (sum < k) {
//                 // Move the left pointer to the next higher value
//                 leftStack.pop();
//                 TreeNode* node = leftNode->right;
//                 while (node) {
//                     leftStack.push(node);
//                     node = node->left;
//                 }
//             } else {
//                 // Move the right pointer to the next lower value
//                 rightStack.pop();
//                 TreeNode* node = rightNode->left;
//                 while (node) {
//                     rightStack.push(node);
//                     node = node->right;
//                 }
//             }
//         }

//         return false;
//     }
// };