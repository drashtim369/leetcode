import java.util.*;

class Solution {
    static int n;
    static char[][] board;
    List<List<String>> list = new ArrayList<>();

    void nQueens(int c) {
        if (c == n) {
            list.add(construct()); // ✅ convert board → List<String>
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
        for (int r = row, c = col; r >= 0 && c >= 0; r--, c--) {
            if (board[r][c] == 'Q') return false;
        }
        for (int r = row, c = col; r < n && c >= 0; r++, c--) {
            if (board[r][c] == 'Q') return false;
        }
        return true;
    }

    // 🔥 convert board → List<String>
    List<String> construct() {
        List<String> res = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            res.add(new String(board[i]));
        }
        return res;
    }
    public List<List<String>> solveNQueens(int nn) {
        n = nn; 
        board = new char[n][n];
        for (int i = 0; i < n; i++) {
            Arrays.fill(board[i], '.');
        }
        nQueens(0);
        return list;
    }
}