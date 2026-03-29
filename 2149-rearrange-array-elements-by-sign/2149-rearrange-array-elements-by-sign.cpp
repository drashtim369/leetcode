class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> res(nums.size());
        int posIdx = 0, negIdx = 1; 
        for (int i : nums) {
            if (i > 0) {
                res[posIdx] = i;
                posIdx+=2;
            } else {
                res[negIdx] = i;
                negIdx+=2;
            }
        }
        return res;
    }
};