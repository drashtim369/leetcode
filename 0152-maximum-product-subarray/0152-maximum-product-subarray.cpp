class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int mx = nums[0];
        int mn = nums[0];
        int global = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            int x = nums[i];

            if (x < 0) swap(mx, mn);

            mx = max(x, mx * x);
            mn = min(x, mn * x);

            global = max(global, mx);
        }

        return global;
    }
};
