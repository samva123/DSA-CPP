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
        void preorder(TreeNode* root, vector<int>& result) {
            if (root == nullptr) {
                return;
            }
    
            // Process the current node (N)
            result.push_back(root->val);
    
            // Traverse the left subtree (L)
            preorder(root->left, result);
    
            // Traverse the right subtree (R)
            preorder(root->right, result);
        }
    
        vector<int> preorderTraversal(TreeNode* root) {
            vector<int> result;
            preorder(root, result);
            return result;
        }
    };
    













    class Solution {
        public:
            vector<int> preorderTraversal(TreeNode* root) {
                if (!root) return {};  // Base case
        
                vector<int> result = {root->val};   // Process current node (N)
                vector<int> left = preorderTraversal(root->left);  // Traverse left (L)
                vector<int> right = preorderTraversal(root->right); // Traverse right (R)
        
                result.insert(result.end(), left.begin(), left.end());
                result.insert(result.end(), right.begin(), right.end());
        
                return result;
            }
        };
        
















        class Solution {
            public:
                vector<int> result; // Store traversal result
            
                vector<int> preorderTraversal(TreeNode* root) {
                    if (!root) return result; // Base case
            
                    result.push_back(root->val); // Process current node (N)
                    preorderTraversal(root->left); // Traverse left (L)
                    preorderTraversal(root->right); // Traverse right (R)
            
                    return result;
                }
            };
            