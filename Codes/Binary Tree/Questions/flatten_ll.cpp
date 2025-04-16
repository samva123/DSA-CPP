///////////////JAVA/////////////







// import java.util.Stack;

// class TreeNode {
//     int val;
//     TreeNode left, right;
//     TreeNode(int x) { val = x; }
// }

// class Solution {
//     TreeNode prev = null;

//     public void flattenRecursive(TreeNode root) {
//         if (root == null) return;
//         flattenRecursive(root.right);
//         flattenRecursive(root.left);
//         root.right = prev;
//         root.left = null;
//         prev = root;
//     }

//     public void flattenIterative(TreeNode root) {
//         if (root == null) return;

//         Stack<TreeNode> st = new Stack<>();
//         st.push(root);

//         while (!st.isEmpty()) {
//             TreeNode cur = st.pop();
//             if (cur.right != null) st.push(cur.right);
//             if (cur.left != null) st.push(cur.left);
//             if (!st.isEmpty()) cur.right = st.peek();
//             cur.left = null;
//         }
//     }

//     public void flattenMorris(TreeNode root) {
//         TreeNode curr = root;
//         while (curr != null) {
//             if (curr.left != null) {
//                 TreeNode pre = curr.left;
//                 while (pre.right != null) {
//                     pre = pre.right;
//                 }
//                 pre.right = curr.right;
//                 curr.right = curr.left;
//                 curr.left = null;
//             }
//             curr = curr.right;
//         }
//     }
// }

// public class Main {
//     static void printPreorder(TreeNode root) {
//         if (root == null) return;
//         System.out.print(root.val + " ");
//         printPreorder(root.left);
//         printPreorder(root.right);
//     }

//     static void printFlattenTree(TreeNode root) {
//         if (root == null) return;
//         System.out.print(root.val + " ");
//         printFlattenTree(root.right);
//     }

//     static TreeNode buildSampleTree() {
//         TreeNode root = new TreeNode(1);
//         root.left = new TreeNode(2);
//         root.right = new TreeNode(3);
//         root.left.left = new TreeNode(4);
//         root.left.right = new TreeNode(5);
//         root.left.right.right = new TreeNode(6);
//         root.right.left = new TreeNode(8);
//         root.right.right = new TreeNode(7);
//         return root;
//     }

//     public static void main(String[] args) {
//         Solution sol = new Solution();

//         TreeNode root1 = buildSampleTree();
//         System.out.print("Original Preorder: ");
//         printPreorder(root1);
//         System.out.println();

//         sol.flattenRecursive(root1);
//         System.out.print("Flatten Recursive: ");
//         printFlattenTree(root1);
//         System.out.println();

//         TreeNode root2 = buildSampleTree();
//         sol.flattenIterative(root2);
//         System.out.print("Flatten Iterative: ");
//         printFlattenTree(root2);
//         System.out.println();

//         TreeNode root3 = buildSampleTree();
//         sol.flattenMorris(root3);
//         System.out.print("Flatten Morris: ");
//         printFlattenTree(root3);
//         System.out.println();
//     }
// }
