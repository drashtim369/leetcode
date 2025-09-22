class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int sum = (n * (n + 1)) / 2;
        int missum = 0;
        for (auto i = 0; i < nums.size(); i++) {
            missum += nums[i];
        }
        cout << sum << " " << missum << endl;
        return sum - missum;
    }
};