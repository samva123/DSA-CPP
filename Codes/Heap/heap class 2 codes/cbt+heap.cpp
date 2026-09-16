// Structure of node
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

class Solution
{
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
    pair<bool, int> solve(Node *root)
    {
        if (root == NULL)
            return {true, INT_MIN};

        if (root->left == NULL && root->right == NULL)
            return {true, root->data};

        auto left = solve(root->left);
        auto right = solve(root->right);

        if (left.first && right.first &&
            root->data > left.second &&
            root->data > right.second)
        {
            return {true, root->data};
        }

        return {false, root->data};
    }
    bool isHeap(struct Node *tree)
    {
        int n = nodecount(tree);
        int i = 0;
        return isCBT(tree, i, n) && solve(tree).first;

        // code here
    }
};

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class Solution {
public:
    bool isHeap(Node* root) {

        queue<Node*> q;
        q.push(root);

        bool nullSeen = false;

        while(!q.empty()) {

            Node* temp = q.front();
            q.pop();

            // left child
            if(temp->left) {

                if(nullSeen)
                    return false;

                if(temp->data < temp->left->data)
                    return false;

                q.push(temp->left);

            } else {
                nullSeen = true;
            }

            // right child
            if(temp->right) {

                if(nullSeen)
                    return false;

                if(temp->data < temp->right->data)
                    return false;

                q.push(temp->right);

            } else {
                nullSeen = true;
            }
        }

        return true;
    }
};