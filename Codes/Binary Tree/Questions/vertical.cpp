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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>>ans;
        queue<pair<TreeNode* , pair<int,int>>>q;
        q.push({root , {0,0}});
        map<int , map<int , multiset<int>>>mp;
        while(!q.empty()){
            auto front= q.front();
            q.pop();
            TreeNode*&node = front.first;
            auto coordinate = front.second;
            int& row = coordinate.first;
            int& col = coordinate.second;

            mp[col][row].insert(node->val);

            if(node->left){
                q.push({node->left , {row+1 , col-1} });
            }
            if(node->right){
                q.push({node->right, {row+1 ,col+1}});
            }
        }

        //stroing into ans vector
        for(auto it : mp){
            auto&colmap = it.second;
            vector<int>vline;
            for(auto colmapit:colmap){
                auto&mset = colmapit.second;
                vline.insert(vline.end() , mset.begin() , mset.end());
            }
            ans.push_back(vline);

        }
        return ans;


                
    }
};







// both are same complexities of Nlogn and n 






class Solution {
    public:
        map<int, map<int, vector<int>>> nodes; // Stores {col -> {row -> {values}}}
        
        void dfs(TreeNode* root, int row, int col) {
            if (!root) return;
            
            nodes[col][row].push_back(root->val); // Store value
            
            dfs(root->left, row + 1, col - 1);  // Left child: decrease column, increase row
            dfs(root->right, row + 1, col + 1); // Right child: increase column, increase row
        }
    
        vector<vector<int>> verticalTraversal(TreeNode* root) {
            vector<vector<int>> ans;
            dfs(root, 0, 0);
    
            for (auto& col : nodes) {
                vector<int> vertical;
                for (auto& row : col.second) {
                    sort(row.second.begin(), row.second.end()); // Sort values within same row
                    vertical.insert(vertical.end(), row.second.begin(), row.second.end());
                }
                ans.push_back(vertical);
            }
            return ans;
        }
    };
    

   



