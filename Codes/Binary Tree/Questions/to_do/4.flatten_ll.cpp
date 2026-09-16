#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:

    // ===================== 1️⃣ Recursive (Reverse Preorder) =====================
    TreeNode* prev = NULL;

    void flattenRecursive(TreeNode* root) {
        if (root == NULL) return;

        flattenRecursive(root->right);
        flattenRecursive(root->left);

        root->right = prev;
        root->left = NULL;
        prev = root;
    }

   

    // ===================== 3️⃣ Morris Traversal (O(1) Space) =====================
    void flattenMorris(TreeNode* root) {
        TreeNode* curr = root;

        while (curr != NULL) {
            if (curr->left != NULL) {

                TreeNode* pre = curr->left;
                while (pre->right != NULL) {
                    pre = pre->right;
                }

                pre->right = curr->right;
                curr->right = curr->left;
                curr->left = NULL;
            }
            curr = curr->right;
        }
    }
};






















































































 // ===================== 2️⃣ Iterative (Stack) =====================
    void flattenIterative(TreeNode* root) {
        if (root == NULL) return;

        stack<TreeNode*> st;
        st.push(root);

        while (!st.empty()) {
            TreeNode* cur = st.top();
            st.pop();

            if (cur->right) st.push(cur->right);
            if (cur->left)  st.push(cur->left);

            if (!st.empty())
                cur->right = st.top();

            cur->left = NULL;
        }
    }
