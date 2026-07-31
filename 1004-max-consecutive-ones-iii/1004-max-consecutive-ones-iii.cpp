class Solution {
public:
    int longestOnes(vector<int>& s, int k) {
        unordered_map<int, int> mpp;
        int ans = 0, left = 0, zero = 0, n = s.size();
        for (int right = 0; right < n; right++) {
            mpp[s[right]]++;
            if (s[right] == 0) zero++;
            while (zero > k) {
                mpp[s[left]]--;
                if (s[left] == 0) zero--;
                left++;
            }
            ans=max(ans,right-left+1);
        }
        return ans;
    }
};