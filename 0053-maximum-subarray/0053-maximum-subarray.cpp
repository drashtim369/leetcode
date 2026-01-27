class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0, mx = INT_MIN;
        for (auto i : nums) {
            if (sum < 0) sum = 0;
            else sum += i;
            mx = max(sum,mx);
        }
        return mx;
    }
};