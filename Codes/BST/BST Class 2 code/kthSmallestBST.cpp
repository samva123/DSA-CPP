#include <bits/stdc++.h>
using namespace std;

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
    int kthSmallest(TreeNode* root, int &k) {
        if(root == NULL) {
            return -1;
        }
        //LNR
        //L
        int leftAns = kthSmallest(root->left, k );
        if(leftAns != -1) {
            return leftAns;
        }
        //N;
        k--;
        if( k == 0) {
            return root->val;
        }
        //R
        int rightAns = kthSmallest(root->right, k);
        return rightAns;
        
    }
};




#include <stack>

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        std::stack<TreeNode*> stack;
        TreeNode* current = root;
        
        while (current != nullptr || !stack.empty()) {
            // Reach the leftmost node of the current node
            while (current != nullptr) {
                stack.push(current);
                current = current->left;
            }
            
            // Current must be nullptr at this point
            current = stack.top();
            stack.pop();
            k--;
            
            // If the k-th smallest is found
            if (k == 0) {
                return current->val;
            }
            
            // Move to the right subtree
            current = current->right;
        }
        
        return -1; // k is out of bounds
    }
};