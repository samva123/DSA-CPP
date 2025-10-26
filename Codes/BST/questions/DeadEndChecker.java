import java.util.*;

class TreeNode {
    int data;
    TreeNode left, right;

    TreeNode(int d) {
        data = d;
    }
}

// ✅ Solution 1 — Using HashMap (Visited nodes approach)
class Solution1 {

    private void fun(TreeNode root, HashMap<Integer, Boolean> visited, boolean[] ans) {
        if (root == null) return;

        visited.put(root.data, true);

        if (root.left == null && root.right == null) {
            int xpl = root.data + 1;
            int xml = (root.data - 1 == 0) ? root.data : root.data - 1;

            if (visited.containsKey(xpl) && visited.containsKey(xml)) {
                ans[0] = true;
                return;
            }
        }

        fun(root.left, visited, ans);
        fun(root.right, visited, ans);
    }

    public boolean isDeadEnd(TreeNode root) {
        boolean[] ans = new boolean[1];
        HashMap<Integer, Boolean> visited = new HashMap<>();
        fun(root, visited, ans);
        return ans[0];
    }
}

// ✅ Solution 2 — Using Min & Max range constraints
class Solution2 {

    private boolean isDeadEndUtil(TreeNode root, int min, int max) {
        if (root == null) return false;

        if (root.left == null && root.right == null) {
            return (min == max);
        }

        return isDeadEndUtil(root.left, min, root.data - 1) ||
               isDeadEndUtil(root.right, root.data + 1, max);
    }

    public boolean isDeadEnd(TreeNode root) {
        return isDeadEndUtil(root, 1, Integer.MAX_VALUE);
    }
}

// ✅ Optional: Testing class (You can modify/extend this)
public class DeadEndChecker {
    public static void main(String[] args) {

        /*
           BST Example:
                 8
                / \
               5   11
              / \
             2   7
              \
               3
                \
                 4  <- Dead end here
        */

        TreeNode root = new TreeNode(8);
        root.left = new TreeNode(5);
        root.right = new TreeNode(11);
        root.left.left = new TreeNode(2);
        root.left.right = new TreeNode(7);
        root.left.left.right = new TreeNode(3);
        root.left.left.right.right = new TreeNode(4);

        Solution1 s1 = new Solution1();
        Solution2 s2 = new Solution2();

        System.out.println("Solution 1 (HashMap): " + s1.isDeadEnd(root));
        System.out.println("Solution 2 (Min-Max): " + s2.isDeadEnd(root));
    }
}
