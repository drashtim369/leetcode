class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> res;
        int c1, c2, cnt1 = 0, cnt2 = 0;
        for (int i = 0; i < nums.size(); i++) {
            int el = nums[i];
            if (el != c2 && cnt1 == 0) {
                c1 = el;
                cnt1++;
            } else if (el != c1 && cnt2 == 0) {
                c2 = el;
                cnt2++;
            } else if (el == c1) {
                cnt1++;
            } else if (el == c2) {
                cnt2++;
            } else {
                cnt1--;
                cnt2--;
            }
        }
        int cnt3 = 0, cnt4 = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == c1) cnt3++;
            if (nums[i] == c2) cnt4++;
        }  
        if (cnt3 > (nums.size() / 3)) res.push_back(c1);
        if (cnt4 > (nums.size() / 3)) res.push_back(c2);
        return res;
    }
};