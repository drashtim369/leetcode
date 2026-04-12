class Solution {
    List<String> res = new ArrayList<>();
    String[] map = {
        "",     // 0
        "",     // 1
        "abc",  // 2
        "def",  // 3
        "ghi",  // 4
        "jkl",  // 5
        "mno",  // 6
        "pqrs", // 7
        "tuv",  // 8
        "wxyz"  // 9
    };
    public List<String> letterCombinations(String digits) {
        if (digits.length() == 0) return res;
        bt(digits, 0, "");
        return res;
    }

    void bt(String digits, int idx, String curr) {
        // ✅ base case
        if (curr.length() == digits.length()) {
            res.add(curr);
            return;
        }
        String letters = map[digits.charAt(idx) - '0'];
        for (char ch : letters.toCharArray()) {
            bt(digits, idx + 1, curr + ch);
        }
    }
}