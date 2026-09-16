//User function Template for C++

#include <bits/stdc++.h>
using namespace std;

//Node Structure

struct Node
{
    int data;
    Node* left;
    Node* right;
};


//https://www.geeksforgeeks.org/problems/maximum-sum-of-non-adjacent-nodes/1

class Solution{
  public:
    pair<int , int> maxsum(Node* root){
        if(!root) return{0,0};   
        
        auto left = maxsum(root->left);
        auto right = maxsum(root->right);
        
        int a =  root->data + left.second + right.second;
        
        int b = max(left.first , left.second) + max(right.first , right.second);
        return {a,b};
        
    }
    //Function to return the maximum sum of non-adjacent nodes.
    int getMaxSum(Node *root) 
    {
        // Add your code here
        auto ans = maxsum(root);
        return max(ans.first , ans.second);
    }
};
// Problem	Pair meaning
// Non-adjacent sum	{include, exclude}

class Solution {
public:
    unordered_map<Node*, int> dp;

    int solve(Node* root) {
        if (!root) return 0;
        if (dp.count(root)) return dp[root];

        int include = root->data;
        if (root->left) {
            include += solve(root->left->left) + solve(root->left->right);
        }
        if (root->right) {
            include += solve(root->right->left) + solve(root->right->right);
        }

        int exclude = solve(root->left) + solve(root->right);

        return dp[root] = max(include, exclude);
    }

    int getMaxSum(Node* root) {
        return solve(root);
    }
};




int solve(Node* root) {
    if (!root) return 0;

    int include = root->data;
    if (root->left)
        include += solve(root->left->left) + solve(root->left->right);
    if (root->right)
        include += solve(root->right->left) + solve(root->right->right);

    int exclude = solve(root->left) + solve(root->right);

    return max(include, exclude);
}
// class TreeNode {
//     int data;
//     TreeNode left, right;

//     TreeNode(int val) {
//         data = val;
//         left = right = null;
//     }
// }

// class Pair {
//     int first, second;
//     Pair(int a, int b) {
//         first = a;
//         second = b;
//     }
// }

// class Solution {

//     Pair maxsum(TreeNode root) {
//         if (root == null) return new Pair(0, 0);

//         Pair left = maxsum(root.left);
//         Pair right = maxsum(root.right);

//         int a = root.data + left.second + right.second;
//         int b = Math.max(left.first, left.second) + Math.max(right.first, right.second);

//         return new Pair(a, b);
//     }

//     public int getMaxSum(TreeNode root) {
//         Pair ans = maxsum(root);
//         return Math.max(ans.first, ans.second);
//     }
// }
