#include <iostream>
#include <string>
#include <climits>

class Solution {
public:
    int myAtoi(std::string s) {
        int i = 0, n = s.size(), sign = 1;
        long sum = 0;
        while (i < n && s[i] == ' ') {
            i++;
        }
        if (i < n && s[i] == '-') {
            sign = -1;
            i++;
        } else if (i < n && s[i] == '+') {
            i++;
        }
        while (i < n && s[i] >= '0' && s[i] <= '9') {
            int digit = s[i] - '0'; // Convert character digit to integer
            sum = sum * 10 + digit;
            if (sign == 1 && sum > INT_MAX) return INT_MAX;
            if (sign == -1 && -sum < INT_MIN) return INT_MIN;
            i++;
        }
        return sum * sign;
    }
};