class Solution {
public:
    int beauty(vector<int>& freq) {
        int mn = INT_MAX, mx = INT_MIN;
        for (int i = 0; i < freq.size(); i++) {
            mx = max(mx, freq[i]);
            if (freq[i] >= 1) {
                mn = min(mn, freq[i]);
            }
        }
        return mx - mn;
    }
    int beautySum(string s) {
        int res = 0;
        for (int i = 0; i < s.size(); i++) {
            vector<int> freq(26,0);
            for (int j = i; j < s.size(); j++) {
                freq[s[j] - 'a']++;
                res += beauty(freq);
            }
        }
        return res;
    }
};