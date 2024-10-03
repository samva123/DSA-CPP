///////////simple///////////////

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
    vector<TreeNode*>all(int start  , int end){

        if(start>end) return {0};
        if(start == end) return {new TreeNode(start)};


        vector<TreeNode*>ans;
        for(int i = start ; i <= end ; i++){

            vector<TreeNode*>left =  all(start , i-1);
            vector<TreeNode*>right = all(i+1 , end);
            for(int j = 0 ; j < left.size(); j++){
                for(int k = 0 ; k <right.size() ; k++){
                    TreeNode*root = new TreeNode(i);
                    root->left = left[j];
                    root->right  = right[k];
                    ans.push_back(root);
                }
            }

        }
        return ans;
    }
    vector<TreeNode*> generateTrees(int n) {
        if(n == 0) return {};
        return all(1 , n);
        
    }
};







////////////////////another approach//////////

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
    // vector<vector<vector<TreeNode*>>>dp(n+1 , vector<vector<TreeNode*>>(n+1 , vector<TreeNode*>(0)));
    map<pair<int , int > , vector<TreeNode*>>dp;
    vector<TreeNode*>all(int start  , int end){

        if(start>end) return {0};
        if(start == end) return {new TreeNode(start)};

        // if(dp[start][end] != 0) return dp[start][end];
        if(dp.find({start , end}) != dp.end()) return dp[{start , end}];


        vector<TreeNode*>ans;
        for(int i = start ; i <= end ; i++){

            vector<TreeNode*>left =  all(start , i-1);
            vector<TreeNode*>right = all(i+1 , end);
            for(int j = 0 ; j < left.size(); j++){
                for(int k = 0 ; k <right.size() ; k++){
                    TreeNode*root = new TreeNode(i);
                    root->left = left[j];
                    root->right  = right[k];
                    ans.push_back(root);
                }
            }

        } 
        return dp[{start , end}] = ans;
    }
    vector<TreeNode*> generateTrees(int n) {
        if(n == 0) return {};

        
        return all(1 , n);
        
    }
};