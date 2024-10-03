////////////simple /////////////////////////////
class Solution {
public:

    int solve (TreeNode*root){
        if(!root) return 0; 

        int rob = 0 ;
        int dont = 0 ;

        rob += root->val;
        if(root->left){
            rob += solve(root->left->left) + solve(root->left->right);

        }
        if(root->right){
            rob += solve(root->right->right) + solve(root->right->left);
        }

        dont  = solve(root->left) + solve(root->right);
        return max(rob , dont);

    }
    int rob(TreeNode* root) {
        return solve(root);
        
    }
};



//////////////another approach////////////////
class Solution {
public:

    int solve (TreeNode*root, unordered_map<TreeNode* , int>&dp){
        if(!root) return 0; 

        if(dp.find(root) != dp.end()) return dp[root];

        int rob = 0 ;
        int dont = 0 ;

        rob += root->val;
        if(root->left){
            rob += solve(root->left->left , dp) + solve(root->left->right ,dp);

        }
        if(root->right){
            rob += solve(root->right->right,dp) + solve(root->right->left,dp);
        }

        dont  = solve(root->left , dp) + solve(root->right ,dp);
        return dp[root] = max(rob , dont);

    }
    int rob(TreeNode* root) {
        unordered_map<TreeNode* , int>dp;
        return solve(root ,dp);
        
    }
};





