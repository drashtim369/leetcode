class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<int,int> mpp;
        int left = 0, ans = 0, n = s.size(), mxFreq = 0;
        for (int right = 0; right < n; right++) {
            mpp[s[right]]++;
            mxFreq=max(mxFreq,mpp[s[right]]);
            while ((right - left + 1) - mxFreq > k) {
                mpp[s[left]]--;
                left++;
            }
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};