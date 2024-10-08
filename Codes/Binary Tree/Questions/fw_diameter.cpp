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
int d = 0;
int height(TreeNode* root) {
	//base case
    
	if(root == NULL ) {
		return 0;
	}
	int leftheight = height(root->left);
	int rightheight = height(root->right);
    int currd = leftheight+rightheight;
    d = max(d,currd);
	int height = max(leftheight, rightheight) + 1;
	return height;
}
  int diameterOfBinaryTree(TreeNode* root) {
	//base case
    height(root);
    return d;}

};