class Solution {
    public boolean judgeSquareSum(int c) {
        int low = 0, high = (int)Math.sqrt(c);
        while (low <= high) {
            if ((Math.pow(low,2) + Math.pow(high,2)) == c) {
                return true;
            } else if (Math.pow(low,2) + Math.pow(high,2) > c) {
                high--;
            } else {
                low++;
            }
        }
        return false;
    }
}