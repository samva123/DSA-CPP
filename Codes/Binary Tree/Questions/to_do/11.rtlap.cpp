#include <bits/stdc++.h>
using namespace std;



//Definition for Binary Tree Node
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};



class Solution {
  public:
    void solve(Node* root, vector<int>& temp, vector<vector<int>>& ans) {
        if (root == NULL) return;

        temp.push_back(root->data);

        if (root->left == NULL && root->right == NULL) {
            ans.push_back(temp);
        } else {
            solve(root->left, temp, ans);
            solve(root->right, temp, ans);
        }

        temp.pop_back();
    }

    vector<vector<int>> Paths(Node* root) {
        vector<vector<int>> ans;
        vector<int> temp;
        solve(root, temp, ans);
        return ans;
    }
};


class Solution {
public:
    vector<vector<int>> Paths(Node* root) {
        vector<vector<int>> ans;
        if (root == NULL) return ans;

        queue<pair<Node*, vector<int>>> q;
        q.push({root, {root->data}});

        while (!q.empty()) {
            auto cur = q.front();
            q.pop();

            Node* node = cur.first;
            vector<int> path = cur.second;

            if (node->left == NULL && node->right == NULL) {
                ans.push_back(path);
            }

            if (node->left) {
                vector<int> leftPath = path;
                leftPath.push_back(node->left->data);
                q.push({node->left, leftPath});
            }

            if (node->right) {
                vector<int> rightPath = path;
                rightPath.push_back(node->right->data);
                q.push({node->right, rightPath});
            }
        }

        return ans;
    }
};
