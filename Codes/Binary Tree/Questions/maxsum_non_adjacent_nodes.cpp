//User function Template for C++

//Node Structure
/*
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/

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