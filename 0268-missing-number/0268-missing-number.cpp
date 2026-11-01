class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int xr = 0, xr2 = 0;
        for (int i = 0; i < n; i++) {
            xr ^= i;
            xr2 ^= nums[i];
        }
        return xr ^ xr2 ^ n;
    }
};