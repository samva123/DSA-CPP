// void printLeftView(Node *root, int level, vector<int> &leftView)
// {
// 	if (root == NULL)
// 		return;

// 	if (level == leftView.size())
// 	{
// 		// iska matlab left view ki node milgyi h , store karlo
// 		leftView.push_back(root->data);
// 	}
// 	printLeftView(root->left, level + 1, leftView);
// 	printLeftView(root->right, level + 1, leftView);
// }

// void printRightView(Node *root, int level, vector<int> &rightView)
// {
// 	if (root == NULL)
// 		return;

// 	if (level == rightView.size())
// 	{
// 		// iska matlab left view ki node milgyi h , store karlo
// 		rightView.push_back(root->data);
// 	}
// 	printRightView(root->right, level + 1, rightView);
// 	printRightView(root->left, level + 1, rightView);
// }














// vector<int> getLeftView(Node* root) {
//     vector<int> leftView;
//     if (!root) return leftView;

//     queue<Node*> q;
//     q.push(root);

//     while (!q.empty()) {
//         int size = q.size();
//         for (int i = 0; i < size; i++) {
//             Node* curr = q.front();
//             q.pop();

//             // First element of each level is part of the left view
//             if (i == 0) leftView.push_back(curr->data);

//             if (curr->left) q.push(curr->left);
//             if (curr->right) q.push(curr->right);
//         }
//     }
//     return leftView;
// }




// vector<int> getRightView(Node* root) {
//     vector<int> rightView;
//     if (!root) return rightView;

//     queue<Node*> q;
//     q.push(root);

//     while (!q.empty()) {
//         int size = q.size();
//         for (int i = 0; i < size; i++) {
//             Node* curr = q.front();
//             q.pop();

//             // Last element of each level is part of the right view
//             if (i == size - 1) rightView.push_back(curr->data);

//             if (curr->left) q.push(curr->left);
//             if (curr->right) q.push(curr->right);
//         }
//     }
//     return rightView;
// }
