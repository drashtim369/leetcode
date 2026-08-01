class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int start = image[sr][sc], n = image.size(), m = image[0].size();
        if (start == color) return image;
        queue<pair<int, int>> q;
        q.push({sr,sc});
        vector<int> dr = {-1, 0, 1, 0};
        vector<int> dc = {0, 1, 0, -1};
        while (!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            image[r][c] = color;
            q.pop();
            for (int i = 0; i < 4; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];
                if (nr >= 0 && nr < n && nc >= 0 && nc < m && image[nr][nc] == start) {
                    q.push({nr, nc});
                }
            }
        }
        return image;
    }
};