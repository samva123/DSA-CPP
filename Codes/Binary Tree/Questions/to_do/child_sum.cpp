class Solution {
public:
    bool solve(Node* root) {
        if (!root) return true;
        if (!root->left && !root->right) return true;

        int left = root->left ? root->left->data : 0;
        int right = root->right ? root->right->data : 0;

        if (root->data != left + right) return false;

        return solve(root->left) && solve(root->right);
    }

    bool isSumProperty(Node *root) {
        return solve(root);
    }
};


class Solution {
public:
    bool isSumProperty(Node *root) {
        if (!root) return true;

        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            Node* node = q.front();
            q.pop();

            // Skip leaf nodes
            if (!node->left && !node->right) continue;

            int left = node->left ? node->left->data : 0;
            int right = node->right ? node->right->data : 0;

            if (node->data != left + right) return false;

            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }

        return true;
    }
};