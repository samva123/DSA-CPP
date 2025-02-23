#include<bits/stdc++.h>
using namespace std;
//   Definition for a binary tree node.
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
        vector<int> result; // Store traversal result
    
        vector<int> postorderTraversal(TreeNode* root) {
            if (!root) return result; // Base case
    
            postorderTraversal(root->left);  // Traverse left (L)
            postorderTraversal(root->right); // Traverse right (R)
            result.push_back(root->val);  // Process current node (N)
    
            return result;
        }
    };

    



    

  class Solution {
    public:
        vector<int> postorderTraversal(TreeNode* root) {
            if (!root) return {};  // Base case
    
            vector<int> left = postorderTraversal(root->left);  // Traverse left (L)
            vector<int> right = postorderTraversal(root->right); // Traverse right (R)
            left.insert(left.end(), right.begin(), right.end()); // Merge left and right
            left.push_back(root->val);  // Process current node (N)
    
            return left;
        }
    };
    