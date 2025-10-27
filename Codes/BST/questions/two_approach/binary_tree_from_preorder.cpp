#include<bits/stdc++.h>
using namespace std;


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
    TreeNode*build(int &i , int min , int max , vector<int>&preorder){
        if(i >= preorder.size()){
            return nullptr;
        }
        TreeNode*root = nullptr;
        if(preorder[i] > min && preorder[i]  < max){
            root = new TreeNode(preorder[i++]);
            root->left = build(i , min , root->val , preorder);
            root->right = build(i , root->val , max , preorder);
        }
        return root;

    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int min = INT_MIN , max = INT_MAX;
        int i = 0;
        return build(i , min , max , preorder);

        
    }
};






//////brute force in java 

// public TreeNode bstFromPreorder(int[] preorder) {
//     TreeNode root = null;
//     for (int val : preorder) {
//         root = insert(root, val);
//     }
//     return root;
// }

// private TreeNode insert(TreeNode root, int val) {
//     if (root == null) return new TreeNode(val);
//     if (val < root.val) root.left = insert(root.left, val);
//     else root.right = insert(root.right, val);
//     return root;
// }
