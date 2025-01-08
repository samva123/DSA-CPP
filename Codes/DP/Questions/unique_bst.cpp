#include <bits/stdc++.h>
using namespace std;
///////////simple///////////////


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





// Yes, this is one of the most optimized solutions for generating all unique binary search trees (BSTs) for a given number nnn.
// Why is this the best solution?
// 1.	Time Complexity of O(n^3):
// o	The recursive approach explores all possible ranges [start, end] and computes the result for each using dynamic programming (memoization).
// o	The time complexity is dominated by the recursive structure, where for each subproblem (start, end), we explore all possible roots and combine the results for the left and right subtrees.
// o	This OO(n^3) complexity is the best we can achieve for this problem due to the combinatorial nature of the task (i.e., generating all unique BSTs).
// 2.	Space Complexity of O(n^2⋅Cn):
// o	The memoization approach saves recomputation, but it still needs to store results for each subproblem (start, end) and the corresponding tree structures. This is why the space complexity depends on both the number of subproblems and the number of trees generated.
// o	The space complexity is primarily determined by the Catalan number growth, which is a combinatorial characteristic of the problem.
// Is there any possibility for further improvement?
// •	In terms of time complexity: Given that the problem involves generating all unique BSTs, which is a combinatorial problem (related to the Catalan numbers), it's unlikely that we can improve beyond O(n3)O(n^3)O(n3). The generation of the trees themselves involves a combinatorial explosion, and this time complexity is the best known for this problem.
// •	In terms of space complexity: The space used by the memoization and the tree structures is inevitable because each tree structure must be stored, and each subproblem must be computed at least once. However, the use of memoization ensures that we're not recomputing the same subproblems multiple times, which is the most efficient way to handle the problem.
// Conclusion:
// This solution is already optimal in terms of time and space complexity for generating all unique BSTs. While there may be other ways to tweak the implementation or improve its constant factors, there is no known algorithm that would significantly improve the overall complexity.
// 4o mini

