class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.size() == 0) return{-1,-1};
        int low = 0, n = nums.size(), high = n - 1, LB = n, UB = n;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] > target) {
                UB = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        int lastOcc = UB - 1;
        int low1 = 0,high1 = n-1;
        while (low1 <= high1) {
            int mid = low1 + (high1 - low1) / 2;
            if (nums[mid] >= target) {
                LB = mid;
                high1 = mid - 1;
            } else {
                low1 = mid + 1;
            }
        }
        int firstOcc = LB;
        if (nums[LB] != target || LB == n) return{-1,-1};
        return{firstOcc, lastOcc};
    }
};