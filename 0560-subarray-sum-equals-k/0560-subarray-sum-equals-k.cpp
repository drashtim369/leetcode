class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int curr = 0, cnt = 0;
        unordered_map<int, int> mpp;
        mpp[0] = 1;
        for (auto it : nums) {
            curr += it;
            if (mpp.find(curr-k) != mpp.end()) {
                cnt+=mpp[curr-k];
            }
            mpp[curr]++;
        }
        return cnt;
    }
};