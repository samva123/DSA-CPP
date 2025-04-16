void printLeftBoundary(Node *root, vector<int> &res)
{
    if (root == NULL || (root->left == NULL && root->right == NULL))
        return;
    res.push_back(root->data);
    if (root->left)
        printLeftBoundary(root->left, res);
    else
        printLeftBoundary(root->right, res);
}

void printRightBoundary(Node *root, vector<int> &res)
{
    if (root == NULL || (root->left == NULL && root->right == NULL))
        return;
    if (root->right)
        printRightBoundary(root->right, res);
    else
        printRightBoundary(root->left, res);
    res.push_back(root->data);
}

void printLeafBoundary(Node *root, vector<int> &res)
{
    if (root == NULL)
        return;
    if (root->left == NULL && root->right == NULL)
    {
        res.push_back(root->data);
        return;
    }
    printLeafBoundary(root->left, res);
    printLeafBoundary(root->right, res);
}

vector<int> boundaryTraversal(Node *root)
{
    vector<int> res;
    if (root == NULL)
        return res;
    res.push_back(root->data);
    printLeftBoundary(root->left, res);
    printLeafBoundary(root, res);
    printRightBoundary(root->right, res);
    return res;
}
