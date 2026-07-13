class Solution {
public:
    int maxRect(vector<int>& height) {
        int n = height.size();
        stack<int> st;
        vector<int> left(n,-1);
        vector<int> right(n,n);
        for (int i = 0; i < n; i++) {
            int curr = height[i];
            while (!st.empty() && height[st.top()] >= curr) {
                st.pop();
            }
            if (!st.empty()) {
                left[i] = st.top();
            }
            st.push(i);
        }
        while (!st.empty()) st.pop();
        for (int i = n - 1; i >= 0; i--) {
            int curr = height[i];
            while (!st.empty() && height[st.top()] >= curr) {
                st.pop();
            }
            if (!st.empty()) {
                right[i] = st.top();
            }
            st.push(i);
        }
        int mx = 0;
        for (int i = 0; i < left.size(); i++) {
            int width = right[i] - left[i] - 1;
            int area = width * height[i];
            mx = max(mx, area);
        }
        return mx;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int ans = 0;
        vector<int> height(m, 0);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == '1') {
                    height[j]++;
                } else {
                    height[j] = 0;
                }
            }
            ans = max(ans, maxRect(height));
        }
        return ans;
    }
};