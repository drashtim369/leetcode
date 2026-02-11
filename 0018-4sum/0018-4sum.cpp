class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i++) {
            if (i > 0 && nums[i] == nums[i-1]) continue;
            for (int j = i+1; j < n; j++) {
                if (j > i+1 && nums[j] == nums[j-1]) continue;
                int k = j+1, m = n-1;
                long long target2 = (long long) target - nums[i] - nums[j]; 
                while (k < m) {
                    long long sum = (long long) nums[k] + nums[m];
                    if (sum < target2) {
                        k++;
                    } else if (sum > target2) {
                        m--;
                    } else {
                        res.push_back({nums[i], nums[j], nums[k], nums[m]});
                        k++;
                        m--;
                        while (k < m && nums[k] == nums[k-1]) k++;
                        while (k < m && nums[m] == nums[m+1]) m--;
                    }
                }
            }
        }
        return res;
    }
};