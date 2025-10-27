#include <iostream>
#include <sstream>
#include <unordered_map>
#include <vector>
#include <queue>
#include <map>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    vector<int> getInorder(TreeNode* root) {
        vector<int> inorder;
        TreeNode* cur = root;
        
        while (cur != NULL) {
            ///if left is null visit it 
            if (cur->left == NULL) {
                inorder.push_back(cur->val);
                cur = cur->right;
            } else {
                ////finding predecessor
                TreeNode* prev = cur->left;
                while (prev->right && prev->right != cur) {
                    prev = prev->right;
                }
                
                ///if right is null , then go left 
                //after establishing link from predecessor to curr
                if (prev->right == NULL) {
                    prev->right = cur;
                    cur = cur->left;
                } else {
                    // left is already viisted , go right after 
                    //visiting curr and removing connection
                    prev->right = NULL;
                    inorder.push_back(cur->val);
                    cur = cur->right;
                }
            }
        }
        
        return inorder;
    }
};

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->left->right->right = new TreeNode(6);

    Solution sol;
    vector<int> inorder = sol.getInorder(root);

    cout << "Binary Tree Morris Inorder Traversal: ";
    for (int i = 0; i < inorder.size(); i++) {
        cout << inorder[i] << " ";
    }
    cout << endl;

    return 0;
}

    //         1
    //       /   \
    //      2     3
    //     / \   / \
    //    4   5 7   8
    //       /
    //      6
////best tree for explaining morris traversal












// class Solution {
//     public:
//         vector<int> getPreorder(TreeNode* root) {
//             vector<int> preorder;
//             TreeNode* cur = root;
    
//             while (cur != NULL) {
//                 if (cur->left == NULL) {
//                     preorder.push_back(cur->val);
//                     cur = cur->right;
//                 } else {
//                     TreeNode* prev = cur->left;
//                     while (prev->right && prev->right != cur) {
//                         prev = prev->right;
//                     }
                    
//                     if (prev->right == NULL) {
//                         preorder.push_back(cur->val); // Fix: Add value before going left
//                         prev->right = cur;
//                         cur = cur->left;
//                     } else {
//                         prev->right = NULL;
//                         cur = cur->right;
//                     }
//                 }
//             }
            
//             return preorder;
//         }
//     };
    










// #include <iostream>
// #include <vector>

// using namespace std;

// struct TreeNode {
//     int val;
//     TreeNode *left, *right;
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
// };

// class Solution {
// public:
//     vector<int> getPostorder(TreeNode* root) {
//         vector<int> postorder;
//         TreeNode* dummy = new TreeNode(0);
//         dummy->left = root;
//         TreeNode* cur = dummy;

//         while (cur) {
//             if (cur->left == NULL) {
//                 cur = cur->right;
//             } else {
//                 TreeNode* pred = cur->left;
//                 while (pred->right && pred->right != cur) {
//                     pred = pred->right;
//                 }

//                 if (pred->right == NULL) {
//                     pred->right = cur;
//                     cur = cur->left;
//                 } else {
//                     pred->right = NULL;
//                     addReversePath(cur->left, postorder);
//                     cur = cur->right;
//                 }
//             }
//         }

//         return postorder;
//     }

// private:
//     void addReversePath(TreeNode* node, vector<int>& postorder) {
//         vector<int> temp;
//         while (node) {
//             temp.push_back(node->val);
//             node = node->right;
//         }
//         reverse(temp.begin(), temp.end());
//         postorder.insert(postorder.end(), temp.begin(), temp.end());
//     }
// };

// int main() {
//     TreeNode* root = new TreeNode(1);
//     root->left = new TreeNode(2);
//     root->right = new TreeNode(3);
//     root->left->left = new TreeNode(4);
//     root->left->right = new TreeNode(5);
//     root->left->right->right = new TreeNode(6);

//     Solution sol;
//     vector<int> postorder = sol.getPostorder(root);

//     cout << "Binary Tree Morris Postorder Traversal: ";
//     for (int val : postorder) {
//         cout << val << " ";
//     }
//     cout << endl;

//     return 0;
// }
