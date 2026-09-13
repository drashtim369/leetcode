class Solution {
public:
    int minimumTotal(vector<vector<int>>& arr) {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        for (int i = 0; i < n; i++) {
            dp[n-1][i] = arr[n-1][i];
        }
        for (int i = n-2; i >= 0; i--) {
            for (int j = 0; j <= i; j++) {
                dp[i][j] = arr[i][j] + min(dp[i+1][j], dp[i+1][j+1]);
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }
        return dp[0][0];
    }
};