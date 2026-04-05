class Solution {
public:
    int trap(vector<int>& height) {
        if (height.size() == 0) return 0;
        vector<int> leftMax(height.size());
        vector<int> rightMax(height.size());
        int maxSoFar = 0;
        for (int i = 0; i < height.size(); i++) {
            maxSoFar = max(maxSoFar, height[i]);
            leftMax[i] = maxSoFar;
        }
        maxSoFar = 0;
        for (int i = height.size() - 1; i >= 0; i--) {
            maxSoFar = max(maxSoFar, height[i]);
            rightMax[i] = maxSoFar;
        }
        int trap = 0;
        for (int i = 0; i < height.size(); i++) {
            trap += (min(leftMax[i], rightMax[i]) - height[i]);
        }
        return trap;
    }
};