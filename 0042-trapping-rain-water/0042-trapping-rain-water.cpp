class Solution {
public:
    int trap(vector<int>& height) {
        // if (height.size() == 0) return 0;
        // vector<int> leftMax(height.size());
        // vector<int> rightMax(height.size());
        // int maxSoFar = 0;
        // for (int i = 0; i < height.size(); i++) {
        //     maxSoFar = max(maxSoFar, height[i]);
        //     leftMax[i] = maxSoFar;
        // }
        // maxSoFar = 0;
        // for (int i = height.size() - 1; i >= 0; i--) {
        //     maxSoFar = max(maxSoFar, height[i]);
        //     rightMax[i] = maxSoFar;
        // }
        // int trap = 0;
        // for (int i = 0; i < height.size(); i++) {
        //     trap += (min(leftMax[i], rightMax[i]) - height[i]);
        // }
        // 2-pointer Solution: 
        int n = height.size();
        int leftMax = 0, rightMax = 0, trap = 0, l = 0, r = n - 1; 
    while (l < r) {
        leftMax = max(leftMax, height[l]);
        rightMax = max(rightMax, height[r]);
        if (leftMax < rightMax) {
            trap += leftMax - height[l];
            l++;
        } else {
            trap += rightMax - height[r];
            r--;
        }
    }
        return trap;
    }
};