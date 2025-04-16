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
    bool solve(TreeNode* root, int targetSum, int sum ){
        //base case
        if(root == NULL) {
            return false;
        }
        sum += root->val;
        if(root->left == NULL && root->right==NULL) {
            //i m currently standing on a leaf node
            //verify
            if(sum == targetSum) 
                return true;
            else
                return false;
        }
        bool leftAns = solve(root->left, targetSum, sum);
        bool rightAns = solve(root->right,targetSum, sum);
        return leftAns||rightAns;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        int sum = 0;
        bool ans = solve(root, targetSum, sum);
        return ans;  
    }
};



//////////JAVA///////////////////

// class Solution {
//     public boolean help(TreeNode root , int targetSum , int sum){
//         if(root ==  null){
//             return false;
//         }

//         sum = sum + root.val;
//         if(root.right == null && root.left == null){
//             if(sum == targetSum){
//                 return true;
//             }else{
//                 return false;
//             }
//         }

//         Boolean left = help(root.left , targetSum , sum);
//         Boolean right  = help(root.right , targetSum , sum);
//         return left||right;
//     }
//     public boolean hasPathSum(TreeNode root, int targetSum) {

//         int sum  = 0;
//         boolean ans =  help(root , targetSum , sum);
//         return ans;
        
//     }
// }