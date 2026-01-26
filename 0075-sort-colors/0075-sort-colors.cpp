class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size(), mid = 0, low = 0, high = n-1;
        while (mid <= high) {
            if (nums[mid] == 1) {
                mid++;
            } else if (nums[mid] == 2) {
                swap(nums[high], nums[mid]);
                high--;
            } else {
                swap(nums[low], nums[mid]);
                low++;
                mid++;
            }
        }
    }
};