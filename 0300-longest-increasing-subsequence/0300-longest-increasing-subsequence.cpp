class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size(), mx = 0;
        vector<int> length(n, 1);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {
                    if (length[i] < length[j] + 1) {
                        length[i] = length[j] + 1;
                    }
                }
            }
            mx = max(mx, length[i]);
        }
        return mx;
    }
};
