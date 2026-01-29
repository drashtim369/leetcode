class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;

        long long sum = 0;
        int orig = x;

        while (x != 0) {
            sum = sum * 10 + (x % 10);
            x /= 10;
        }

        return sum == orig;
    }
};
