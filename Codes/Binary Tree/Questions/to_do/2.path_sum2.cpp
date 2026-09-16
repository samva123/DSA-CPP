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
    void solve(TreeNode* root , int targetSum , vector<vector<int>>&ans , vector<int>&temp){
        if(root == NULL) return;

        temp.push_back(root->val);

        if(root->left == NULL && root->right == NULL && targetSum == root->val){
            ans.push_back(temp);
        }
        solve(root->left , targetSum-root->val , ans , temp );
        solve(root->right , targetSum-root->val , ans , temp);

        temp.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(root ==  NULL) return {};
        vector<vector<int>>ans;
        vector<int>temp;
        solve(root , targetSum , ans , temp);
        return ans;
        
    }
};



class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        if (!root) return ans;

        queue<pair<TreeNode*, pair<int, vector<int>>>> q;
        q.push({root, {root->val, {root->val}}});

        while (!q.empty()) {
            auto cur = q.front();
            q.pop();

            TreeNode* node = cur.first;
            int sum = cur.second.first;
            vector<int> path = cur.second.second;

            if (!node->left && !node->right && sum == targetSum) {
                ans.push_back(path);
            }

            if (node->left) {
                auto newPath = path;
                newPath.push_back(node->left->val);
                q.push({node->left, {sum + node->left->val, newPath}});
            }

            if (node->right) {
                auto newPath = path;
                newPath.push_back(node->right->val);
                q.push({node->right, {sum + node->right->val, newPath}});
            }
        }
        return ans;
    }
};























////single path 
class Solution {
public:
    bool solve(TreeNode* root, int targetSum, vector<int>& path) {
        if (!root) return false;

        path.push_back(root->val);

        if (!root->left && !root->right && targetSum == root->val) {
            return true;
        }

        if (solve(root->left, targetSum - root->val, path) ||
            solve(root->right, targetSum - root->val, path)) {
            return true;
        }

        path.pop_back();
        return false;
    }

    vector<int> pathSum(TreeNode* root, int targetSum) {
        vector<int> path;
        solve(root, targetSum, path);
        return path;
    }
};