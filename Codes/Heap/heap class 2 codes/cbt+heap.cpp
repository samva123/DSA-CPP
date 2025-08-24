// Structure of node
#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


class Solution {
  public:
    int nodecount(struct Node *root)
    {
        if (!root)
            return 0;
        int l = nodecount(root->left);
        int r = nodecount(root->right);
        return 1 + l + r;
    }
    bool isCBT(struct Node *root, int i, int &n)
    {
        if (!root)
            return true;
        if (i >= n)
            return false;
        return isCBT(root->left, 2 * i + 1, n) && isCBT(root->right, 2 * i + 2, n);
    }
   pair<bool, int> solve(Node* root) {
        //base case
        if(root == NULL) {
                pair<bool,int> p = make_pair(true, INT_MIN);
                return p;
        }
        if(root->left == NULL && root->right == NULL)
        {
                //leaf node
                pair<bool,int> p = make_pair(true, root->data);
                return p;
        }

        pair<bool, int> leftAns = solve(root->left);
        pair<bool, int> rightAns = solve(root->right);

        if(leftAns.first == true &&
          rightAns.first == true &&
          root->data > leftAns.second &&
          root->data > rightAns.second) {
                  pair<bool, int> p =  make_pair(true, root->data);
                  return p;
          }
         
          else {
                  pair<bool, int> p =  make_pair(false, root->data);
                  return p;
          }
}
    bool isHeap(struct Node* tree) {
        int n = nodecount(tree);
        int i = 0;
        return isCBT(tree, i, n) && solve(tree).first;
        
        // code here
    }
};