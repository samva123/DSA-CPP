// class Solution {
//     public int rangeSumBST(TreeNode root, int low, int high) {
//         if (root == null) {
//             return 0;
//         }

//         // If value is less than low, skip left subtree
//         if (root.val < low) {
//             return rangeSumBST(root.right, low, high);
//         }

//         // If value is greater than high, skip right subtree
//         if (root.val > high) {
//             return rangeSumBST(root.left, low, high);
//         }

//         // Else value is in range: add it and explore both sides
//         return root.val + 
//                rangeSumBST(root.left, low, high) + 
//                rangeSumBST(root.right, low, high);
//     }
// }




///////////// i wrote a levelorder traversal approach/////////////////////

// class Solution {
//     public int rangeSumBST(TreeNode root, int low, int high) {
//         if (root == null) return 0;

//         int sum = 0;
//         Queue<TreeNode> q = new LinkedList<>();
//         q.add(root);

//         while (!q.isEmpty()) {
//             TreeNode top = q.poll();
//             int val = top.val;

//             if (val >= low && val <= high) {
//                 sum += val;
//             }

//             if (top.left != null && val > low) {
//                 q.add(top.left);
//             }

//             if (top.right != null && val < high) {
//                 q.add(top.right);
//             }
//         }

//         return sum;
//     }
// }
