class Solution {
public:
    void dfs(int row, int col, vector<vector<char>>& edges) {
        int n = edges.size(), m = edges[0].size();
        if (row < 0 || col < 0 || row > n - 1|| col > m - 1 || edges[row][col] == '0') return;
        edges[row][col] = '0';
        dfs(row + 1, col, edges);
        dfs(row - 1, col, edges);
        dfs(row, col + 1, edges);
        dfs(row, col - 1, edges);
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '1') {
                    cnt++;
                    dfs(i, j, grid);
                }
            }
        }
        return cnt;
    }
};