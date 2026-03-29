class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mpp;
        vector<int> res;
        for (int i = 0; i < nums.size(); i++) {
            int c = target - nums[i];
            
            if (mpp.find(c) != mpp.end()) {
                res.push_back(mpp[c]);
                res.push_back(i);
            } else {
                mpp[nums[i]] = i;
            }
        }
        return res;
    }
};