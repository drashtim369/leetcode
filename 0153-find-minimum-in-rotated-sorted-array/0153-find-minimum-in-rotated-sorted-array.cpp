class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size(), low = 0, high = n - 1, mn = INT_MAX;
        while (low < high) {
            if (nums[low] > nums[high]) {
                low++;
            } else {
                high--;
            }
        }
        cout << nums[low];
        return nums[low];
    }
};