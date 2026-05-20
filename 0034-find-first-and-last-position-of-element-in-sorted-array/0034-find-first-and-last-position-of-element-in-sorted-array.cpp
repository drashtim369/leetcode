class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        if (n == 0) return {-1, -1};
        int low = 0, high = n - 1;
        int LB = n, UB = n;
        // Upper Bound (first > target)
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] > target) {
                UB = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        low = 0; high = n - 1;
        // Lower Bound (first >= target)
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] >= target) {
                LB = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        // Validation
        if (LB == n || nums[LB] != target)
            return {-1, -1};

        return {LB, UB - 1};
    }
};