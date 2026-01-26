class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int,int> mpp;
        vector<int> v;
        for (int i = 0; i < n; i++) {
            int comp = target - nums[i];
            if (mpp.find(comp) != mpp.end()) {
                v.emplace_back(mpp[comp]);
                v.emplace_back(i);
            }
            mpp[nums[i]]++;
        }
        return v;
    }
};