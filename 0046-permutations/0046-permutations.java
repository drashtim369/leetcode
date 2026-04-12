class Solution {
    void bt(int[] nums, boolean[] used List<Integer> curr, List<List<Integer>> res) {
        if (curr.size() == nums.length) {
            res.add(new ArrayList<>(curr));
            return;
        }
        for (int num : nums) {
            if (used[i] == true) continue;
            used[i] = true;
            curr.add(num);
            bt(nums, used, curr, res);
            curr.remove(curr.size() - 1);
            used[i] = false;
        }
    }
    public List<List<Integer>> permute(int[] nums) {
        List<List<Integer>> res = new ArrayList<>();
        bt(nums, boolean[], used new ArrayList<>(), res);
        return res;
    }
}