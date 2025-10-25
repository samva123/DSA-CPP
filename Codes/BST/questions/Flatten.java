class TreeNode {
    int val;
    TreeNode left, right;
    TreeNode(int x) { val = x; }
}

public class Flatten {

    private static void inorder(TreeNode root, TreeNode[] prev) {
        if (root == null) return;

        inorder(root.left, prev);

        prev[0].left = null;
        prev[0].right = root;
        prev[0] = root;

        inorder(root.right, prev);
    }

    public static TreeNode flatten(TreeNode root) {
        TreeNode dummy = new TreeNode(-1);
        TreeNode[] prev = new TreeNode[]{dummy};

        inorder(root, prev);

        prev[0].left = null;
        prev[0].right = null;

        return dummy.right;
    }

    private static void printList(TreeNode root) {
        TreeNode curr = root;
        while (curr != null) {
            System.out.print(curr.val + " -> ");
            curr = curr.right;
        }
        System.out.println("null");
    }

    public static void main(String[] args) {

        TreeNode root = new TreeNode(4);
        root.left = new TreeNode(2);
        root.right = new TreeNode(6);
        root.left.left = new TreeNode(1);
        root.left.right = new TreeNode(3);
        root.right.left = new TreeNode(5);
        root.right.right = new TreeNode(7);

        System.out.println("Flattening tree inorder...");
        //TreeNode flattened = flatten(root);

        printList(flatten(root));
    }
}
