import java.util.*;

class Solution {
    static int n;
    List<String> bt(int open, int close, String ans) {
        List<String> list = new ArrayList<>();
        // ✅ base case
        if (open == n && close == n) {
            list.add(ans);
            return list;
        }
        // add '('
        if (open < n) {
            list.addAll(bt(open + 1, close, ans + "("));
        }
        // add ')'
        if (close < open) {
            list.addAll(bt(open, close + 1, ans + ")"));
        }
        return list;
    }
    public List<String> generateParenthesis(int nn) {
        n = nn;
        return bt(0, 0, "");
    }
}