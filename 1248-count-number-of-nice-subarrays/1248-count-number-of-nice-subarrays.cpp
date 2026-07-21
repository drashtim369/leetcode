class Solution {
public:
    int atMost(vector<int>& nums, int k) {
        int left = 0, sum = 0, cnt = 0;
        for (int right = 0; right < nums.size(); right++) {
            sum += nums[right];
            while (sum > k) {
                sum -= nums[left];
                left++;
            }
            cnt += right - left + 1;
        }
        return cnt;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        for (int right = 0; right < nums.size(); right++) {
            if (nums[right] % 2 == 0) nums[right] = 0;
            else nums[right] = 1;
        }
        return atMost(nums, k) - atMost(nums, k - 1);
    }
};