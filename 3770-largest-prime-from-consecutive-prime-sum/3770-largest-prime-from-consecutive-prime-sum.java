class Solution {
    public int largestPrime(int n) {
        int sum = 0;
        int ans = 0;
        for (int i = 2; sum + i <= n; i++) {
            if (isPrime(i)) {
                sum += i;

                if (isPrime(sum)) {
                    ans = sum;
                }
            }
        }
        return ans;
    }
    boolean isPrime(int num) {
        if (num < 2) return false;
        for (int i = 2; i * i <= num; i++) {
            if (num % i == 0) return false;
        }
        return true;
    }
}