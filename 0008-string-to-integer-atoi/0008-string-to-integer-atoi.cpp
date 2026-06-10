class Solution {
public:
    int myAtoi(string s) {
        long long ans = 0;
        int sign = 1;
        int i = 0;
        while (i < s.size() && s[i] == ' ')
            i++;
        if (i < s.size() && s[i] == '-') {
            sign = -1;
            i++;
        }
        else if (i < s.size() && s[i] == '+') {
            i++;
        }
        while (i < s.size()) {
            if (s[i] < '0' || s[i] > '9')
                break;
            int digit = s[i] - '0';
            if (ans > INT_MAX / 10 ||
                (ans == INT_MAX / 10 && digit > 7)) {
                return sign == 1 ? INT_MAX : INT_MIN;
            }
            ans = ans * 10 + digit;
            i++;
        }
        return sign * ans;
    }
};