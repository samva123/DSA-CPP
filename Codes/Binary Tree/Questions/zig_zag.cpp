/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
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