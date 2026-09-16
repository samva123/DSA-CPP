#include <bits/stdc++.h>
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
    int kthSmallest(TreeNode* root, int &k) {
        if(root == NULL) {
            return -1;
        }
        //LNR
        //L
        int leftAns = kthSmallest(root->left, k );
        if(leftAns != -1) {
            return leftAns;
        }
        //N;
        k--;
        if( k == 0) {
            return root->val; 
        }
        //R
        int rightAns = kthSmallest(root->right, k);
        return rightAns;
        
    }
};


class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        TreeNode* curr = root;

        while(curr != NULL) {

            if(curr->left == NULL) {
                k--;
                if(k == 0) return curr->val;
                curr = curr->right;
            }
            else {
                TreeNode* pred = curr->left;

                // find inorder predecessor
                while(pred->right != NULL && pred->right != curr) {
                    pred = pred->right;
                }

                if(pred->right == NULL) {
                    pred->right = curr;      // create thread
                    curr = curr->left;
                }
                else {
                    pred->right = NULL;      // remove thread
                    k--;
                    if(k == 0) return curr->val;
                    curr = curr->right;
                }
            }
        }
        return -1;
    }
};
