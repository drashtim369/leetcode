class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int x1 = 0, x2 = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            x1 = x1 ^ nums[i];
            x2 = x2 ^ i;
        }
        return (x1^x2^n);
    }
};