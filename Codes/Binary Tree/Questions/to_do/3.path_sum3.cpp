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
    // Logic - Like subarray sum equal to K
    // keep on storing psum in map and check if psum - target exists in map for some node
    // TC = SC = O(N)

    // // Without BT
    // void solve(TreeNode *root, int target, unordered_map<long long,int> m, long long pSum, int &ans){
    //     if(root == NULL){
    //         return ;
    //     }

    //     // x + target = psum ==> x = psum - target
    //     pSum += root -> val;

    //     if(m.find((pSum - target)) != m.end()){
    //         ans = ans + m[(pSum - target)];
    //     }
    //     m[pSum]++;

    //     solve(root -> left, target, m, pSum, ans);
    //     solve(root -> right, target, m, pSum, ans);
    // }


    // With BT -> faster
    void solve(TreeNode *root, int target, unordered_map<long long,int> &m, long long &pSum, int &ans){
        if(root == NULL){
            return ;
        }

        // x + target = psum ==> x = psum - target
        pSum += root -> val;

        if(m.find((pSum - target)) != m.end()){
            ans = ans + m[(pSum - target)];
        }
        m[pSum]++;

        solve(root -> left, target, m, pSum, ans);
        solve(root -> right, target, m, pSum, ans);

        //BT
        m[pSum]--;
        pSum -= root -> val;
    }


    int pathSum(TreeNode* root, int target) {
        int ans = 0;
        long long pSum = 0;
        unordered_map<long long,int> m;
        m[0] = 1; // when root can also be included then psum - target = 0, so there should be 0 in map
        solve(root, target, m, pSum, ans);
        return ans;
    }
};




///////////naive solution////////
class Solution {
public:
    int ans = 0;
    void pathfromoneroot(TreeNode*root , long long sum){
        if(!root) return;

        if(sum == root->val){
            ++ans;
        }
        pathfromoneroot(root->left , sum-root->val);
        pathfromoneroot(root->right , sum-root->val);

    }
    int pathSum(TreeNode* root, int targetSum) {
        if(root){
            pathfromoneroot(root, targetSum);
            pathSum(root->left , targetSum);
            pathSum(root->right , targetSum);

        }
        return ans;
        
        
    }
};