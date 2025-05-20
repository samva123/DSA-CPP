class Result {
  static Node buildSearchTree(int t[], int n) {
    if (n == 0) return null;

    Node root = null;

    for (int i = 0; i < n; i++) {
      root = insertIntoBST(root, t[i]);
    }

    return root;
  }

  private static Node insertIntoBST(Node root, int val) {
    if (root == null) {
      return new Node(val);
    }
    if (val < root.data) {
      root.leftChild = insertIntoBST(root.leftChild, val);
    } else {
      root.rightChild = insertIntoBST(root.rightChild, val);
    }
    return root;
  }
}
