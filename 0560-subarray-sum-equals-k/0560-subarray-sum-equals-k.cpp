class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mpp; int cnt = 0, sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            if(sum == k){
                cnt++;
            }
            int rem = sum - k;
            if (mpp.count(rem) > 0) {
                cnt += mpp[rem];
            }
            mpp[sum]++;
        }
        return cnt;
    }
};