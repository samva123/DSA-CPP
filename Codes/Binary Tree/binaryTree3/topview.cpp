







// in this we are initialising answer array from start




#include <iostream>
#include <vector>
#include <queue>
#include <map>

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
    vector<int> topView(Node* root) {
        // Result vector
        vector<int> ans;

        if (root == NULL) 
            return ans; // Return empty vector instead of {}

        // Map to store the first node for each horizontal distance
        map<int, int> hdToNodemap;
        // Queue to perform level-order traversal with horizontal distance
        queue<pair<Node*, int>> q;

        q.push(make_pair(root, 0)); // Root has horizontal distance 0

        while (!q.empty()) {
            pair<Node*, int> temp = q.front();
            q.pop();

            Node* frontNode = temp.first;
            int hd = temp.second;

            // If no entry exists for the current horizontal distance
            if (hdToNodemap.find(hd) == hdToNodemap.end()) {
                hdToNodemap[hd] = frontNode->data;
            }

            // Check left child
            if (frontNode->left != NULL) {
                q.push(make_pair(frontNode->left, hd - 1));
            }

            // Check right child
            if (frontNode->right != NULL) {
                q.push(make_pair(frontNode->right, hd + 1));
            }
        }

        // Collect the results in `ans`
        for (auto i : hdToNodemap) {
            ans.push_back(i.second);
        }

        return ans;
    }
};

// Function to print vector
void printVector(const vector<int>& vec) {
    for (int num : vec) cout << num << " ";
    cout << endl;
}

// Main function
int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    Solution sol;
    vector<int> result = sol.topView(root);

    cout << "Top View: ";
    printVector(result);

    return 0;
}













#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    vector<int> topView(Node* root) {
        vector<int> ans;
        if (!root) return ans;

        unordered_map<int, int> hdToNode;
        queue<pair<Node*, int>> q;
        q.push({root, 0});

        int minHd = 0, maxHd = 0;

        while (!q.empty()) {
            //auto [frontNode, hd] = q.front();
            auto front  = q.front();
            auto frontNode = front.first;
            auto hd  = front.second;
            q.pop();

            if (hdToNode.find(hd) == hdToNode.end()) {
                hdToNode[hd] = frontNode->data;
            }

            minHd = min(minHd, hd);
            maxHd = max(maxHd, hd);

            if (frontNode->left) q.push({frontNode->left, hd - 1});
            if (frontNode->right) q.push({frontNode->right, hd + 1});
        }

        for (int i = minHd; i <= maxHd; i++) {
            ans.push_back(hdToNode[i]);
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
    vector<int> result = sol.topView(root);

    cout << "Top View: ";
    printVector(result);

    return 0;
}
