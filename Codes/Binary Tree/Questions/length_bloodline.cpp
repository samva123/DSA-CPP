//User function Template for C++

/*
structure of the node of the binary tree is as
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};
*/
// https://www.geeksforgeeks.org/problems/sum-of-the-longest-bloodline-of-a-tree/1

class Solution
{
public:

    pair<int , int>height(Node* root){
        if(!root) return{0,0};
        auto lh = height(root->left);
        auto rh = height(root->right);
        
        int sum = root->data;
        if(lh.first == rh.first){
            sum += lh.second > rh.second ? lh.second : rh.second;
        }
        else if(lh.first > rh.first){
            sum += lh.second;
        }
        else{
            sum += rh.second;
        }
        return {max(lh.first , rh.first) + 1,sum};
            
    }
    
    int sumOfLongRootToLeafPath(Node *root)
    {
        //code here
        auto h =  height(root);
        return h.second;
    }
};



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

//     Pair height(TreeNode root) {
//         if (root == null) return new Pair(0, 0);

//         Pair lh = height(root.left);
//         Pair rh = height(root.right);

//         int sum = root.data;
//         if (lh.first == rh.first) {
//             sum += Math.max(lh.second, rh.second);
//         } else if (lh.first > rh.first) {
//             sum += lh.second;
//         } else {
//             sum += rh.second;
//         }

//         return new Pair(Math.max(lh.first, rh.first) + 1, sum);
//     }

//     public int sumOfLongRootToLeafPath(TreeNode root) {
//         Pair h = height(root);
//         return h.second;
//     }
// }
