class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m));
        int sum = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i == 0 && j == 0) {
                    dp[i][j] = grid[i][j];
                } else {
                    int up = 0, left = 0;
                    bool upisfalse = true, leftisfalse = true;
                    if (i > 0) {up = dp[i-1][j]; upisfalse = false;}
                    if (j > 0) {left = dp[i][j-1]; leftisfalse = false;}
                    if (upisfalse) {
                        dp[i][j] = grid[i][j] + left;
                    } else if (leftisfalse) {
                        dp[i][j] = grid[i][j] + up;
                    } else {
                        dp[i][j] = grid[i][j] + min(up,left);
                    }
                }
            }
        }
        for (int i = 0;i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }
        return dp[n-1][m-1];
    }
};