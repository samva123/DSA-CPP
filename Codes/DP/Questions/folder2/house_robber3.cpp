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



// 🥇 Approach 1 — Simple Recursion (No Memoization)
// int solve(TreeNode* root);

// ⏱ Time Complexity: O(2^n)

// Each node makes two recursive choices — rob or not rob — leading to exponential growth.

// Essentially, you recompute subproblems multiple times.

// 💾 Space Complexity: O(n)

// The recursion stack depth can go up to n (for a skewed tree).

// No extra data structure used.

// 🥈 Approach 2 — Recursion + Memoization (Using unordered_map)
// int solve(TreeNode* root, unordered_map<TreeNode*, int>& dp);

// ⏱ Time Complexity: O(n)

// Each node is computed only once and stored in the hash map.

// Hence, the number of computations = number of nodes.

// 💾 Space Complexity: O(n)

// O(n) for the recursion stack (worst case: skewed tree).

// O(n) for the hash map storing results of each node.

// Overall still O(n).

// 🥉 Approach 3 — Pair Return (Optimized Space)
// pair<int, int> solve(TreeNode* root);


// Returns two values for each node: {rob, dont}.

// Avoids using extra hash map.

// ⏱ Time Complexity: O(n)

// Each node is visited exactly once.

// 💾 Space Complexity:

// Recursion stack only → O(h), where h = height of the tree.

// For a balanced tree, h = O(log n)

// For a skewed tree, h = O(n)
// ✅ So average/balanced case: O(log n)
// ✅ Worst case: O(n)

// 🔍 Final Summary Table
// Approach	Technique	Time Complexity	Space Complexity	Notes
// 1	Simple Recursion	O(2^n)	O(n)	Exponential, brute-force
// 2	Memoization (DP)	O(n)	O(n)	Optimal in time, not in space
// 3	Pair Return	O(n)	O(log n) avg / O(n) worst	Optimal in both time & space
