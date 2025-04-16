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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        if(!root) return ans;
        bool ltordir = true;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int width = q.size();
            vector<int>onelevel(width);
            for(int i = 0 ; i <width ; ++i){
                TreeNode*front = q.front();
                q.pop();
                int index = ltordir ? i : width-i-1;
                onelevel[index] = front->val;
                /////////////////////////////////////////for java////////////
                //if (oneLevel.size() <= index) oneLevel.add(node.val);
                //else oneLevel.add(index, node.val);
                if(front->left)
                    q.push(front->left);
                if(front->right)
                    q.push(front->right);
            }

            ltordir = !ltordir;
            ans.push_back(onelevel);

        }
        return ans;
        
    }
};









////another method with same complexities



class Solution {
    public:
        vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
            vector<vector<int>> ans;
            if (!root) return ans;
    
            queue<TreeNode*> q;
            q.push(root);
            bool leftToRight = true;
    
            while (!q.empty()) {
                int size = q.size();
                deque<int> level;
    
                for (int i = 0; i < size; ++i) {
                    TreeNode* node = q.front();
                    q.pop();
                    
                    if (leftToRight)
                        level.push_back(node->val);
                    else
                        level.push_front(node->val);
    
                    if (node->left) q.push(node->left);
                    if (node->right) q.push(node->right);
                }
    
                ans.push_back(vector<int>(level.begin(), level.end()));
                leftToRight = !leftToRight;
            }
            return ans;
        }
    };
    







    class Solution {
        public:
            void dfs(TreeNode* node, int level, vector<vector<int>>& result) {
                if (!node) return;
                if (result.size() == level)
                    result.push_back({});
                
                if (level % 2 == 0)
                    result[level].push_back(node->val);
                else
                    result[level].insert(result[level].begin(), node->val); // insert at front
        
                dfs(node->left, level + 1, result);
                dfs(node->right, level + 1, result);
            }
        
            vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
                vector<vector<int>> result;
                dfs(root, 0, result);
                return result;
            }
        };
        



        // Comparison
        // Approach	Time Complexity	Space Complexity	Extra Data Structure
        // BFS (queue + vector)	O(N)	O(N)	queue<TreeNode*>, vector<int>
        // BFS (queue + deque)	O(N)	O(N)	queue<TreeNode*>, deque<int>
        // DFS (Recursion)	O(N)	O(H) (O(log N) for balanced trees)	None