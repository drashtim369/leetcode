class Solution {
public:
    int findNthDigit(int n) {
        long long digits = 1;      // digits per number (1, 2, 3...)
        long long count = 9;       // how many numbers in this block
        long long start = 1;       // starting number (1, 10, 100...)

        // STEP 1: Find the correct block
        while (n > digits * count) {
            n -= digits * count;   // skip this entire block
            digits++;              // move to next digit length
            count *= 10;           // 9 -> 90 -> 900...
            start *= 10;           // 1 -> 10 -> 100...
        }

        // STEP 2: Find the actual number
        int number = start + (n - 1) / digits;

        // STEP 3: Find the digit inside that number
        string s = to_string(number);
        return s[(n - 1) % digits] - '0';
    }
};