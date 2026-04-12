class Solution {
    void bt(int[] nums, List<Integer> curr, List<List<Integer>> res) {
        if (curr.size() == nums.length) {
            res.add(new ArrayList<>(curr));
            return;
        }
        for (int num : nums) {
            if (curr.contains(num)) continue;
            curr.add(num);
            bt(nums, curr, res);
            curr.remove(curr.size() - 1);
        }
    }
    public List<List<Integer>> permute(int[] nums) {
        List<List<Integer>> res = new ArrayList<>();
        bt(nums, new ArrayList<>(), res);
        return res;
    }
}