// class Result {
//   public static boolean solve(Node root, long lowerBound, long upperBound) {
//     if (root == null) {
//       return true;
//     }

//     boolean cond1 = root.data > lowerBound;
//     boolean cond2 = root.data < upperBound;

//     boolean leftAns = solve(root.left, lowerBound, root.data);
//     boolean rightAns = solve(root.right, root.data, upperBound);

//     return cond1 && cond2 && leftAns && rightAns;
//   }

//   static int isBinarySearchTree(Node root) {
//     long lowerBound = Long.MIN_VALUE;
//     long upperBound = Long.MAX_VALUE;

//     boolean ans = solve(root, lowerBound, upperBound);
//     return ans ? 1 : 0;
//   }
// }
// // 