class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
    vector<int> res;
    int candidateOne = 0, candidateTwo = 0, cnt1 = 0, cnt2 = 0;
    for (int i = 0; i < nums.size(); i++) {
        if (cnt1 == 0) {
            candidateOne = nums[i];
            cnt1 = 1;
        } else if (cnt2 == 0 && nums[i] != candidateOne) {
            candidateTwo = nums[i];
            cnt2 = 1;
        } else if (nums[i] == candidateOne) {
            cnt1++;
        } else if (nums[i] == candidateTwo) {
            cnt2++;
        } else {
            cnt1--;
            cnt2--;
        }
    }
    int cnt3 = 0, cnt4 = 0;
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] == candidateOne) {
            cnt3++;
        } else if (nums[i] == candidateTwo) {
            cnt4++;
        } else {
            continue;
        }
    }
    if (cnt3 > (nums.size())/3) res.emplace_back(candidateOne);
    if (cnt4 > (nums.size())/3) res.emplace_back(candidateTwo);
    return res;
    }
};