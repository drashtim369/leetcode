class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int pivotIdx = -1; // Removed pivotVal since we must use index references
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i-1] < nums[i]) {
                pivotIdx = (i-1);
            }
        }
        if (pivotIdx == -1) { // Checked index instead of value
            return reverse(nums.begin(), nums.end());
        }
        
        // Find the smallest element larger than the pivot, ONLY to the right of pivotIdx
        int successorIdx = pivotIdx + 1;
        for (int i = pivotIdx + 1; i < nums.size(); i++) {
            if (nums[i] > nums[pivotIdx] && nums[i] <= nums[successorIdx]) {
                successorIdx = i;
            }
        }
        
        swap(nums[pivotIdx], nums[successorIdx]); // Swapped by reference inside the vector
        reverse(nums.begin() + pivotIdx + 1, nums.end()); // Reversed starting from pivotIdx + 1
        
    }
};
