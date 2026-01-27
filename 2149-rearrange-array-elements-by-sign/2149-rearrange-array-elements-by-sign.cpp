class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> arr(nums.size());
        int posIdx = 0, negIdx = 1;
        for (auto x : nums) {
            if (x > 0) {
                arr[posIdx] = x;
                posIdx+=2;
            } else {
                arr[negIdx] = x;
                negIdx+=2;
            }
        }
        return arr;
    }
};