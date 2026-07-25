class Solution {
    public TreeNode buildTree(int[] inorder, int[] postorder) {
        HashMap<Integer, Integer> mpp = new HashMap<>();
        for (int i = 0; i < inorder.length; i++) {
            mpp.put(inorder[i], i);
        }
        TreeNode root = buildTree(inorder, 0, inorder.length - 1, postorder, 0, postorder.length - 1, mpp);
        return root;
    }
    public TreeNode buildTree(int[] inorder, int inStart, int inEnd, int[] postorder, int postStart, int postEnd, HashMap<Integer, Integer> mpp) {
        if (postStart > postEnd || inStart > inEnd) return null;
        TreeNode root = new TreeNode(postorder[postEnd]);
        int inRoot = mpp.get(root.val);
        int numsleft = inRoot - inStart;
        root.left = buildTree(inorder, inStart, inRoot - 1, postorder, postStart, postStart + numsleft - 1, mpp);
        root.right = buildTree(inorder, inRoot + 1, inEnd, postorder, postStart + numsleft, postEnd - 1, mpp);
        return root;
    }
}