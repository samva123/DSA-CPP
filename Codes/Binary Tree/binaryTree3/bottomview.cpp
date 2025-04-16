#include <bits/stdc++.h>
using namespace std;

// Definition of Node structure
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    vector<int> bottomView(Node* root) {
        if (!root) return {};

        map<int, int> hdToNodemap; // {horizontal_distance -> node_value}
        queue<pair<Node*, int>> q; // {node, horizontal_distance}
        q.push({root, 0});

        while (!q.empty()) {
            auto front  = q.front();
            auto frontNode = front.first;
            auto hd  = front.second;
            q.pop();

            // Always update the map (to store the last node seen at this horizontal distance)
            hdToNodemap[hd] = frontNode->data;

            if (frontNode->left) q.push({frontNode->left, hd - 1});
            if (frontNode->right) q.push({frontNode->right, hd + 1});
        }

        vector<int> result;
        // for (auto& [hd, val] : hdToNodemap) {
        //     result.push_back(val);
        // }
        for (auto& pair : hdToNodemap) {
            result.push_back(pair.second);
        }
        
        return result;
    }
};

// Helper function to print vector
void printVector(const vector<int>& vec) {
    for (int num : vec) cout << num << " ";
    cout << endl;
}

// Main function to test the bottom view
int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    Solution sol;
    vector<int> result = sol.bottomView(root);

    cout << "Bottom View: ";
    printVector(result);

    return 0;
}










#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    void dfs(Node* root, int hd, int level, map<int, pair<int, int>>& hdMap) {
        if (!root) return;

        // Update if the current level is deeper or not present in the map
        if (hdMap.find(hd) == hdMap.end() || level >= hdMap[hd].second) {
            hdMap[hd] = {root->data, level};
        }

        dfs(root->left, hd - 1, level + 1, hdMap);
        dfs(root->right, hd + 1, level + 1, hdMap);
    }

    vector<int> bottomView(Node* root) {
        vector<int> ans;
        if (!root) return ans;

        map<int, pair<int, int>> hdMap; // {horizontal_distance -> {node_value, level}}
        
        // Perform DFS
        dfs(root, 0, 0, hdMap);

        // Collect results from map
        for (auto it : hdMap) {
            ans.push_back(it.second.first);
        }

        return ans;
    }
};

void printVector(const vector<int>& vec) {
    for (int num : vec) cout << num << " ";
    cout << endl;
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    Solution sol;
    vector<int> result = sol.bottomView(root);

    cout << "Bottom View: ";
    printVector(result);

    return 0;
}















#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    vector<int> bottomView(Node* root) {
        if (!root) return {};

        unordered_map<int, int> hdToNode;
        queue<pair<Node*, int>> q;
        q.push({root, 0});

        int minHd = 0, maxHd = 0;

        while (!q.empty()) {
            auto front  = q.front();
            auto frontNode = front.first;
            auto hd  = front.second;
            q.pop();

            hdToNode[hd] = frontNode->data;

            minHd = min(minHd, hd);
            maxHd = max(maxHd, hd);

            if (frontNode->left) q.push({frontNode->left, hd - 1});
            if (frontNode->right) q.push({frontNode->right, hd + 1});
        }

        vector<int> result;
        for (int i = minHd; i <= maxHd; i++) {
            result.push_back(hdToNode[i]);
        }
        return result;
    }
};

void printVector(const vector<int>& vec) {
    for (int num : vec) cout << num << " ";
    cout << endl;
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    Solution sol;
    vector<int> result = sol.bottomView(root);

    cout << "Bottom View: ";
    printVector(result);

    return 0;
}
