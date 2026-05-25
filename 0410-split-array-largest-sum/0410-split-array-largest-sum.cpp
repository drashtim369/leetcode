class Solution {
public:
    bool canSplit(vector<int>& nums, int k, int mid) {
        int n = 1;
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] + sum <= mid) {
                sum += nums[i];
            } else {
                n++;
                sum = nums[i];
            }
        }
        return n <= k;
    } 
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(),0);
        int ans = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (canSplit(nums, k, mid)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};