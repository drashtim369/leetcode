class Solution {
public:
    int numberOfSubstrings(string s) {
        unordered_map<int, int> mpp;
        int left = 0, ans = 0, n = s.size();
        for (int right = 0; right < n; right++) {
            char ch = s[right];
            mpp[ch]++;
            while (mpp.count('a') && mpp.count('b') && mpp.count('c')) {
                ans += n - right;
                mpp[s[left]]--;
                if (mpp[s[left]] == 0)mpp.erase(s[left]);
                left++;
            }
        }
        return ans;
    }
};