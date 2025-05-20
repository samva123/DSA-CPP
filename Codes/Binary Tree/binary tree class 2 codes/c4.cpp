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
    void solve(TreeNode* root, int targetSum, vector<vector<int>> &ans, vector<int> temp, int sum) {
        //base case
        if(root == NULL) {
            return;
        }
        //1 casE SOLVE KRNA H 
        sum += root->val;
        temp.push_back(root->val);

        //extra case
        if(root->left == NULL && root->right == NULL) {
            //verify
            if(sum == targetSum) {
                //store temp path in final ans array
                ans.push_back(temp);
            }
            else {
                return;
            }
        }

        //baaki recursion sambhal lega
        solve(root->left, targetSum, ans, temp, sum);
        solve(root->right, targetSum, ans, temp, sum);
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> temp;
        int sum = 0;
        solve(root, targetSum, ans, temp, sum);
        return ans;
    }
};










// class Solution {
//     public void func(TreeNode root, int targetSum, List<List<Integer>> result, List<Integer> temp, int sum) {
//         if (root == null) return;

//         temp.add(root.val);
//         sum += root.val;

//         if (root.left == null && root.right == null) {
//             if (sum == targetSum) {
//                 result.add(temp); // Safe, because it's already a new list
//             }
//             return;
//         }

//         func(root.left, targetSum, result, new ArrayList<>(temp), sum);
//         func(root.right, targetSum, result, new ArrayList<>(temp), sum);
//     }

//     public List<List<Integer>> pathSum(TreeNode root, int targetSum) {
//         List<List<Integer>> result = new ArrayList<>();
//         func(root, targetSum, result, new ArrayList<>(), 0);
//         return result;
//     }
// }

