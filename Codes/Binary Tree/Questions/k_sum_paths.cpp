// path sum 3 - leetcode 


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


























class Solution {
    unordered_map<long long,long long> mp;
    int ans = 0;
public:
    void getAns(TreeNode* root, int targetSum, long long current_sum) {
        if(root == NULL) {
            return;
        }
        long long val = current_sum + root->val;
        if(val == targetSum ) {
            ans += 1;
        }
        if(mp.find(val - targetSum) != mp.end() && mp[val-targetSum]) {
            ans += mp[val-targetSum];
        }
        mp[val] += 1;
        getAns(root->left, targetSum, current_sum + root->val);
        getAns(root->right, targetSum, current_sum + root->val);
        mp[val] -= 1; 
    }
    int pathSum(TreeNode* root, int targetSum) {
        long long current_sum = 0;
        getAns(root, targetSum, current_sum);
        return ans;
    }
};



















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


//////////////////JAVA//////////////////////////



/// https://chatgpt.com/c/67f3f6f0-74dc-8003-a278-e43fa8fd13b3












class Solution {
public:
    int get(TreeNode *root, int t, map<long long, int> &mp, long long pr = 0) {
        if (root == nullptr) return 0;
        pr += root->val;
        int ans = mp[pr - t];
        mp[pr]++;

        // Recursively calculate the count of paths for left and right subtrees
        ans += get(root->left, t, mp, pr);
        ans += get(root->right, t, mp, pr);

        // Decrement the frequency of the current prefix sum (backtrack)
        mp[pr]--;
        return ans;
    }

    int pathSum(TreeNode* root, int targetSum) {
        map<long long, int> mp;
        mp[0] = 1;
        return get(root, targetSum, mp);
    }
};