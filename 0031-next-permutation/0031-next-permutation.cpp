class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int pivot, pivotVal, mn = INT_MAX;
    for (int i = nums.size()-2; i >= 0; i--) {
        if (nums[i] < nums[i+1]) {
            pivot = i;
            pivotVal = nums[i];
            break;
        }
    }
    int idx = -1;
    for (int i = nums.size() - 1; i > pivot; i--) {
        if (nums[i] > pivotVal && nums[i] < mn) {
            mn = nums[i];
            idx = i;
        }
    }
    swap(nums[pivot], nums[idx]);
    reverse(nums.begin() + pivot + 1, nums.begin() + nums.size());
    }
};