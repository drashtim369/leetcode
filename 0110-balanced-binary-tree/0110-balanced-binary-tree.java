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
    public int heightChecker(TreeNode root) {
        if (root == null) return 0;
        int leftCheck = heightChecker(root.left);
        int rightCheck = heightChecker(root.right);
        if (leftCheck == -1 || rightCheck == -1) return -1;
        if (Math.abs(leftCheck-rightCheck) > 1) return -1;
        return 1 + Math.max(leftCheck, rightCheck);
    }
    public boolean isBalanced(TreeNode root) {
        return heightChecker(root) != -1;
    }
}