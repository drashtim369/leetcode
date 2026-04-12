import java.util.*;

class Solution {
    static char[][] board;
    static int n, cnt = 0;

    void nQueens(int c) {
        if (c == n) {
            cnt++;
            return;
        }
        for (int r = 0; r < n; r++) {
            if (isSafe(r, c)) {
                board[r][c] = 'Q';
                nQueens(c + 1);
                board[r][c] = '.'; 
            }
        }
    }

    boolean isSafe(int row, int col) {
        for (int c = 0; c < col; c++) {
            if (board[row][c] == 'Q') return false;
        }
        for (int r = row - 1, c = col - 1; r >= 0 && c >= 0; r--, c--) {
            if (board[r][c] == 'Q') return false;
        }
        for (int r = row + 1, c = col - 1; r < n && c >= 0; r++, c--) {
            if (board[r][c] == 'Q') return false;
        }
        return true;
    }

    public int totalNQueens(int nn) {
        n = nn;
        cnt = 0; 
        board = new char[n][n];
        for (int i = 0; i < n; i++) {
            Arrays.fill(board[i], '.');
        }
        nQueens(0);
        return cnt;
    }
}