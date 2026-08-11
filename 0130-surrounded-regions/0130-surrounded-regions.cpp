class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size(), m = board[0].size();
        //all 4 boundaries
        for (int i = 0; i < n; i++) {
            dfs(i, 0, board);
            dfs(i, m-1, board);
        }
        for (int i = 0; i < m; i++) {
            dfs(0, i, board);
            dfs(n-1, i, board);
        } 
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == '#') {
                    board[i][j] = 'O';
                } else if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }
        }
    }
    void dfs(int i, int j, vector<vector<char>>& board) {
        int n = board.size(), m = board[0].size();
        if (i < 0 || j < 0 || i > n - 1 || j > m - 1 || board[i][j] != 'O') return;
        board[i][j] = '#';
        dfs(i + 1, j, board);
        dfs(i - 1, j, board);
        dfs(i, j + 1, board);
        dfs(i, j - 1, board);
    }
};