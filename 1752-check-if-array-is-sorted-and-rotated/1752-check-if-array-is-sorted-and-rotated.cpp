class Solution {
public:
    bool check(vector<int>& nums) {
        int cnt = 0;
        if (nums[nums.size() - 1] > nums[0]) cnt++;
        for (int i = 0; i < nums.size()-1; i++) {
            if (nums[i] > nums[i+1]) cnt++;
        }
        cout << cnt;
        if (cnt == 1 || cnt == 0) return true;
        else return false;
    }
};