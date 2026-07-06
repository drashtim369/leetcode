class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> mpp = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };
        int sum = 0;
        for (int i = 1; i < s.size(); i++) {
            if (mpp[s[i]] <= mpp[s[i-1]]) {
                sum += mpp[s[i-1]];
            } else {
                sum -= mpp[s[i-1]];
            }
        }
        sum += mpp[s.back()];
        return sum;
    }
};