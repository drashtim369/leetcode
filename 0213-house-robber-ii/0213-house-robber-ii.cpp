class Solution {
public:
    int helper(int start, int end, vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n);
        dp[start] = nums[start];
        dp[start+1] = max(nums[start], nums[start+1]);
        for (int i = start + 2; i <= end; i++) {
            dp[i] = max(dp[i-2] + nums[i], dp[i-1]);
        }
        return dp[end];
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        if (n == 2) return max(nums[0], nums[1]);
        int case1 = helper(0, n-2, nums);
        int case2 = helper(1, n-1, nums);
        return max(case1, case2);
    }
};