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
        void func(TreeNode* root , vector<int>&result){
            if(root == nullptr){
                return;
            }
            func(root->left, result);
            result.push_back(root->val);
            func(root->right , result);
    
        }
        vector<int> inorderTraversal(TreeNode* root) {
            vector<int>result;
            func(root , result);
            return result;
            
        }
    };



















    class Solution {
        public:
            vector<int> inorderTraversal(TreeNode* root) {
                if (!root) return {};  // Base case
        
                vector<int> left = inorderTraversal(root->left);  // Traverse left (L)
                left.push_back(root->val);  // Process current node (N)
                vector<int> right = inorderTraversal(root->right); // Traverse right (R)
        
                left.insert(left.end(), right.begin(), right.end());
        
                return left;
            }
        };















        class Solution {
            public:
                vector<int> result; // Store traversal result
            
                vector<int> inorderTraversal(TreeNode* root) {
                    if (!root) return result; // Base case
            
                    inorderTraversal(root->left); // Traverse left (L)
                    result.push_back(root->val); // Process current node (N)
                    inorderTraversal(root->right); // Traverse right (R)
            
                    return result;
                }
            };
            
        