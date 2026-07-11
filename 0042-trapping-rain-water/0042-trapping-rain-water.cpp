class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size(), sum = 0, l = 0, r = n - 1, leftMax = INT_MIN, rightMax = INT_MIN;
        while (l < r) {
            leftMax = max(height[l], leftMax);
            rightMax = max(height[r], rightMax);
            if (leftMax < rightMax) {
                sum += (leftMax - height[l]);
                l++;
            } else {
                sum += (rightMax - height[r]);
                r--;
            }
        }
        return sum;
    }
};