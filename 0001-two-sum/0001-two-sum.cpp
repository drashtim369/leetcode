class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> v;
        unordered_map<int, int> mpp;
        for (int i = 0; i < n; i++) {
            int comp = target - nums[i];
            if (mpp.find(comp) != mpp.end()) {
                v.emplace_back(mpp[comp]);
                v.emplace_back(i);
                break;
            }
            else mpp[nums[i]] = i;
        }
        return v;
    }
};