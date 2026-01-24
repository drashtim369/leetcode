class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k = k  % nums.size();
        reverse(nums.begin(),nums.begin() + (k-1));
        reverse(nums.begin() + k, nums.end()-1);
        reverse(nums.begin(), nums.end()-1);
    }
};