class Solution {    
    List<List<Integer>> res = new ArrayList<>();
    void bt(int[] nums, boolean[] used, List<Integer> curr) {
        if (curr.size() == nums.length) {
            res.add(new ArrayList<>(curr));
            return;
        }
        for (int i = 0; i < nums.length; i++) {
            if (used[i]) continue;
            used[i] = true;
            curr.add(nums[i]);
            bt(nums, used, curr, res);

            // 🔙 backtrack
            curr.remove(curr.size() - 1);
            used[i] = false;
        }
    }

    public List<List<Integer>> permute(int[] nums) {
        bt(nums, new boolean[nums.length], new ArrayList<>());
        return res;
    }
}