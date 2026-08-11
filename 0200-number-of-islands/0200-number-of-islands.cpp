class Solution {
public:
    void dfs(int row, int col, vector<vector<char>>& edges, vector<vector<bool>>& vis) {
        int n = edges.size(), m = edges[0].size();
        if (row < 0 || col < 0 || row > n - 1|| col > m - 1 || vis[row][col] == true || edges[row][col] == '0') return;
        vis[row][col] = true;
        dfs(row + 1, col, edges, vis);
        dfs(row - 1, col, edges, vis);
        dfs(row, col + 1, edges, vis);
        dfs(row, col - 1, edges, vis);
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[i][j] && grid[i][j] == '1') {
                    cnt++;
                    dfs(i, j, grid, vis);
                }
            }
        }
        return cnt;
    }
};