class Solution {
public:
    int gcd(int a, int b) {
        return (b == 0) ? a : gcd(b, a%b); 
    }
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        sort(nums.begin(), nums.end());
        int res = numsDivide[0];
        for (int i = 0; i < numsDivide.size(); i++) {
            res = gcd(numsDivide[i], res);
        }
        int numToDelete;
        for (int i = 0; i < nums.size(); i++) {
            if (res % nums[i] == 0) {
                return i;
            }
        }
        return -1;
    }
};