import java.util.*;

class Solution {
    static int n;
    List<String> list = new ArrayList<>();
    void bt(int open, int close, String ans) {
        // ✅ base case
        if (open == n && close == n) {
            list.add(ans);
            return;
        }
        // add '('
        if (open < n) {
            bt(open + 1, close, ans + "(");
        }
        // add ')'
        if (close < open) {
            bt(open, close + 1, ans + ")");
        }
    }
    public List<String> generateParenthesis(int nn) {
        n = nn;
        bt(0, 0, "");
        return list;
    }
}