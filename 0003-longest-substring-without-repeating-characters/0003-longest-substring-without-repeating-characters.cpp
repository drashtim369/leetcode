class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mpp;
        int ans = 0,left = 0;
        for (int right = 0; right < s.size(); right++) {
            mpp[s[right]]++;
            while (mpp[s[right]] > 1) {
                mpp[s[left]]--;
                left++;
            }
            ans=max(ans,right-left+1);
        }
        return ans;
    }
};