class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size(), fresh = 0;
        queue<pair<pair<int, int>, int>> q;
        vector<vector<int>> vis; 
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    q.push({{i, j}, 0});
                } else if (grid[i][j] == 1) {
                    fresh++;
                }
            }
        }
        int minutes = 0;
        int row[] = {-1, 0, 1, 0};
        int col[] = {0, 1, 0, -1};
        while (!q.empty()) {
            int x = q.front().first.first;
            int y = q.front().first.second;
            int t = q.front().second;
            minutes = max(minutes, t);
            q.pop();
            for (int i = 0; i < 4; i++) {
                int nr = x + row[i];
                int nc = y + col[i];
                if (nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] == 1) {
                    grid[nr][nc] = 2;
                    fresh--;
                    q.push({{nr, nc}, t+1});
                }
            }
        }
        if (fresh > 0) return -1;
        return minutes;
    }
};