class Solution {
public:
    int atMost(vector<int>& nums, int k) {
        unordered_map<int, int> mpp;
        int left = 0, ans = 0, x = 0, n = nums.size();
        for (int right = 0; right < nums.size(); right++) {
            mpp[nums[right]]++;
            while (mpp.size() > k) {
                mpp[nums[left]]--;
                if (mpp[nums[left]] == 0) mpp.erase(nums[left]);
                left++;
            }
            ans += right - left + 1;
        }
        return ans;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMost(nums, k) - atMost(nums, k -1);
    }
};