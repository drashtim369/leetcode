class Solution {
    public String reverseWords(String s) {
        String[] res = s.trim().split("\\s+");
        int i = 0, j = res.length - 1;
        while (i < j) {
            String t = res[i];
            res[i] = res[j];
            res[j] = t;
            i++; j--;
        }
        String result = String.join(" ", res);
        return result;
    }
}