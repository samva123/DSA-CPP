#include <bits/stdc++.h>
using namespace std;
////////////simple /////////////////////////////
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


// First Approach (Simple Recursive)
// Time Complexity: (O(2^n))
// The recursion explores all possible subsets of nodes to rob, leading to an exponential time complexity.
// Space Complexity: (O(n))
// The recursion depth can go up to (n), where (n) is the number of nodes in the tree.
// Second Approach (Recursive with Memoization)
// Time Complexity: (O(n))
// Each node is processed once, and the results are stored in a hash map to avoid redundant calculations.
// Space Complexity: (O(n))
// The hash map stores the results for each node, and the recursion depth can go up to (n).
// the time and space complexity of the above code is O(n) where n is the number of nodes in the tree
// but we can optimise upto O(logn) space complexity by using pair<int , int> as return type of the function


class Solution {
public:
    pair<int, int> solve(TreeNode* root) {
        if (!root) return {0, 0};

        // Get the result for left and right children
        auto left = solve(root->left);
        auto right = solve(root->right);

        // If we rob this node, we cannot rob its immediate children
        int rob = root->val + left.second + right.second;

        // If we do not rob this node, we take the maximum of robbing or not robbing its children
        int dont = max(left.first, left.second) + max(right.first, right.second);

        return {rob, dont};
    }

    int rob(TreeNode* root) {
        auto result = solve(root);
        return max(result.first, result.second); // Max of robbing or not robbing the root
    }
};




