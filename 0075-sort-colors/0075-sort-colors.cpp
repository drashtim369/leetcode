class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size(), cnt0 = 0, cnt1 = 0, cnt2 = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) cnt0++;
            else if (nums[i] == 1) cnt1++;
            else cnt2++;
        }
        cout << cnt0 << ' ' << cnt1 << ' ' << cnt2 << endl;;
        nums.clear();
        for (int i = 0; i < cnt0; i++) nums.emplace_back(0);
        for (int i = 0; i < cnt1; i++) nums.emplace_back(1);
        for (int i = 0; i < cnt2; i++) nums.emplace_back(2);
        for (int i = 0; i < nums.size(); i++) cout << nums[i] << " ";
    }
};