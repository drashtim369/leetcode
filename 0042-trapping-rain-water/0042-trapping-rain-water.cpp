class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> leftmx(n);
        vector<int> rightmx(n);
        int mx = INT_MIN;
        for (int i = 0; i < n; i++) {
            if (height[i] > mx) {
                mx = height[i];
            }
            leftmx[i] = mx;
        }
        mx = INT_MIN;
        for (int i = n -1; i >= 0; i--) {
            if (height[i] > mx) {
                mx = height[i];
            }
            rightmx[i] = mx;
        }
        int sum = 0;
        for (int i = 0; i < n; i++) {
            int mn = min(leftmx[i], rightmx[i]);
            sum += mn - height[i];
        }
        return sum;
    }
};