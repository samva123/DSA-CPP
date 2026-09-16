#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node(int x) : data(x), left(NULL), right(NULL) {}
};

class CountPairsBST {

public:

    /*--------------------------------------------------
      Approach 1 : Two BST Iterators (Best Space)
    --------------------------------------------------*/
    static int countPairsTwoStacks(Node* root1, Node* root2, int x) {
        stack<Node*> s1, s2;
        Node *a = root1, *b = root2;
        int ans = 0;

        while (true) {

            while (a) {
                s1.push(a);
                a = a->left;
            }

            while (b) {
                s2.push(b);
                b = b->right;
            }

            if (s1.empty() || s2.empty()) break;

            Node* atop = s1.top();
            Node* btop = s2.top();

            int sum = atop->data + btop->data;

            if (sum == x) {
                ans++;
                s1.pop();
                s2.pop();
                a = atop->right;
                b = btop->left;

            }
            else if (sum < x) {
                s1.pop();
                a = atop->right;
            }
            else {
                s2.pop();
                b = btop->left;
            }
        }
        return ans;
    }

    /*--------------------------------------------------
      Approach 2 : HashSet
    --------------------------------------------------*/
    static void store(Node* root, unordered_set<int>& s) {
        if (!root) return;
        store(root->left, s);
        s.insert(root->data);
        store(root->right, s);
    }

    static int countPairsHash(Node* root1, Node* root2, int x) {
        unordered_set<int> s;
        store(root1, s);

        int count = 0;
        stack<Node*> st;
        Node* curr = root2;

        while (curr || !st.empty()) {
            while (curr) {
                st.push(curr);
                curr = curr->left;
            }
            curr = st.top(); st.pop();
            if (s.count(x - curr->data)) count++;
            curr = curr->right;
        }
        return count;
    }

    /*--------------------------------------------------
      Approach 3 : Two Inorder Arrays
    --------------------------------------------------*/
    static void inorder(Node* root, vector<int>& v) {
        if (!root) return;
        inorder(root->left, v);
        v.push_back(root->data);
        inorder(root->right, v);
    }

    static int countPairsArray(Node* root1, Node* root2, int x) {
        vector<int> v1, v2;
        inorder(root1, v1);
        inorder(root2, v2);

        int i = 0, j = v2.size() - 1, count = 0;

        while (i < v1.size() && j >= 0) {
            int sum = v1[i] + v2[j];
            if (sum == x) {
                count++;
                i++; j--;
            }
            else if (sum < x) i++;
            else j--;
        }
        return count;
    }
};
