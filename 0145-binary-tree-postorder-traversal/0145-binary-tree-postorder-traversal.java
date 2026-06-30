/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public List<Integer> postorderTraversal(TreeNode root) {
        // List<Integer> ans = new ArrayList<>();
        // if (root == null) return ans;
        // ans.addAll(postorderTraversal(root.left));
        // ans.addAll(postorderTraversal(root.right));
        // ans.add(root.val);
        // return ans;
        List<Integer> ans = new ArrayList<>();
        Stack<TreeNode> s1 = new Stack<>();
        Stack<TreeNode> s2 = new Stack<>();
        if (root == null) return ans;
        s1.push(root);
        while (!s1.isEmpty()) {
            root = s1.pop();
            s2.push(root);
            if (root.left != null) s1.push(root.left);
            if (root.right != null) s1.push(root.right);
        }
        while (!s2.isEmpty()) {
            ans.add(s2.pop().val);
        }
        return ans;
    }
}