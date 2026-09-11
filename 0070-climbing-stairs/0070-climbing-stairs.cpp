class Solution {
public:
    int calc(int n, vector<int>& dp) {
        if (dp[n] != -1) return dp[n];
        return dp[n] = calc(n-1, dp) + calc(n-2, dp);
    }
    int climbStairs(int n) {
        vector<int> dp(n+1, -1);
        dp[0] = 1;
        dp[1] = 1;
        return calc(n, dp);
    }
};