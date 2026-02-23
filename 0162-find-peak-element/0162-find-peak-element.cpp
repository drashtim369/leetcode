class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size(), low = 0, high = n - 1, peak;
        if (n == 0 || n == 1) return 0;
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] <= nums[mid+1]) {
                low = mid + 1;
            } else {
                high = mid;
            }
        } 
        return low;
    }
};