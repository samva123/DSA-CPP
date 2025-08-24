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
    // void countnodes(TreeNode* root , int &count){
    //      if(root == NULL){
    //         return ;
    //     }
    //     count++;
    //     countnodes(root->left,totalnodes);
    //     countnodes(root->right,totalnodes);
        
    
    // }
    bool levelordertraversal(TreeNode* root ){
        queue<TreeNode*>q;
        q.push(root);
        bool nullfound = false;
        while(!q.empty()){
            TreeNode* front = q.front();
            q.pop();

            if(front == NULL){
                nullfound = true;
            }
            else{
                if(nullfound)
                    return false;
            
                q.push(front->left);
                
                
                
                q.push(front->right);
                
            


            }
            
        }
        return true;
    }
    bool isCompleteTree(TreeNode* root) {
    //    int totalnodes = 0;
    //    countnodes(root,totalnodes);
    //    int lastnode = 0;
        return levelordertraversal(root);
    //    if(lastnode > totalnode){
    //     return false;
    //    }
    //    else{
    //     return true;
    //    }
    }
    
};