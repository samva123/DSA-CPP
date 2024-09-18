#include <iostream>
#include <map>
using namespace std;

struct Node {
    char data;   // Use char instead of int
    Node* left;
    Node* right;
    Node(char d) : data(d), left(NULL), right(NULL) {}
};

void createMapping(char inorder[], int size, map<char, int>& valueToIndexMap) {
    for (int i = 0; i < size; i++) {
        char element = inorder[i];
        valueToIndexMap[element] = i;
    }
}

Node* constructTreeFromPreAndInorderTraversal(map<char, int>& valueToIndexMap, char preOrder[], char inOrder[], int& preIndex, int inOrderStart, int inOrderEnd, int size) {
    // Base case
    if (preIndex >= size || inOrderStart > inOrderEnd) {
        return NULL;
    }

    // Pick the current element from preOrder and create a node
    char element = preOrder[preIndex];
    preIndex++;
    Node* root = new Node(element);

    // Find the position of this element in inorder
    int position = valueToIndexMap[element];

    // Recursively build the left and right subtrees
    root->left = constructTreeFromPreAndInorderTraversal(valueToIndexMap, preOrder, inOrder, preIndex, inOrderStart, position - 1, size);
    root->right = constructTreeFromPreAndInorderTraversal(valueToIndexMap, preOrder, inOrder, preIndex, position + 1, inOrderEnd, size);

    return root;
}

// Helper function to print the tree in inorder
void printInorder(Node* root) {
    if (root == NULL) return;
    printInorder(root->left);
    cout << root->data << " ";
    printInorder(root->right);
}

int main() {
    char inOrder[] = { 'B', 'A', 'D', 'C', 'F', 'E', 'J', 'H', 'K', 'G', 'I' };
    char preOrder[] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'J', 'K', 'I' };
    int size = sizeof(inOrder) / sizeof(inOrder[0]);

    map<char, int> valueToIndexMap;
    createMapping(inOrder, size, valueToIndexMap);

    int preIndex = 0;
    Node* root = constructTreeFromPreAndInorderTraversal(valueToIndexMap, preOrder, inOrder, preIndex, 0, size - 1, size);

    // Output the constructed tree (inorder should match the original inorder)
    cout << "Inorder traversal of constructed tree: ";
    printInorder(root);
    return 0;
}
