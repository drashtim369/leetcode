class Solution {
public:
    int atMost(vector<int>&s, int k) {
        unordered_map<int, int> mpp;
        int left = 0, n = s.size(), cnt = 0;
        for (int right = 0; right < n; right++) {
            mpp[s[right]]++;
            while (mpp.size() > k) {
                mpp[s[left]]--;
                if (mpp[s[left]] == 0) mpp.erase(s[left]);
                left++;
            }
            cnt += right - left + 1;
        }
        return cnt;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMost(nums, k) - atMost(nums, k - 1);
    }
};