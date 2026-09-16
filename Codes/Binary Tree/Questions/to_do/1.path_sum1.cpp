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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root == NULL){
            return false;
        }

        if(root->left == NULL && root->right == NULL){
            return root->val == targetSum;
        }
        int remain = targetSum - root->val;

        return hasPathSum(root->left , remain) || hasPathSum(root->right , remain);
        
    }
};


class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (!root) return false;

        queue<pair<TreeNode*, int>> q;
        q.push({root, root->val});

        while (!q.empty()) {
            //auto [node, sum] = q.front();
            auto temp = q.front();
            auto node = temp.first;
            auto sum  =  temp.second;
            q.pop();

            if (!node->left && !node->right && sum == targetSum)
                return true;

            if (node->left)
                q.push({node->left, sum + node->left->val});

            if (node->right)
                q.push({node->right, sum + node->right->val});
        }

        return false;
    }
};
