/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    public List<Integer> distanceK(TreeNode root, TreeNode target, int k) {
        HashMap<TreeNode, TreeNode> mpp = new HashMap<>();
        Queue<TreeNode> q = new LinkedList<>();
        q.add(root);
        while (!q.isEmpty()) {
            TreeNode parent = q.poll();
            if (parent.left != null) {
                mpp.put(parent.left, parent);
                q.add(parent.left);
            }
            if (parent.right != null) {
                mpp.put(parent.right, parent);
                q.add(parent.right);
            }
        }
        HashSet<TreeNode> vis = new HashSet<>();
        Queue<TreeNode> que = new LinkedList<>();
        que.add(target); vis.add(target); int dist = 0;
        while (!que.isEmpty()) {
            int size = que.size();
            if (k == dist) break;
            for (int i = 0; i < size; i++) {
                TreeNode node = que.poll();
                if (node.left != null && !vis.contains(node.left)) {
                    vis.add(node.left);
                    que.add(node.left);
                }
                if (node.right != null && !vis.contains(node.right)) {
                    vis.add(node.right);
                    que.add(node.right);
                }
                if (mpp.get(node) != null && !vis.contains(mpp.get(node))) {
                    vis.add(mpp.get(node));
                    que.add(mpp.get(node));
                }
            }
            dist++;
        }
        List<Integer> ls = new ArrayList<>();
        while (!que.isEmpty()) {
            ls.add(que.poll().val);
        }
        return ls;
    }
}