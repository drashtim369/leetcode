class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> left(n, -1); 
        vector<int> right(n, n); 
        stack<int> st;
        for (int i = 0; i < n; i++) {
            int curr = heights[i];
            while (!st.empty() && heights[st.top()] >= curr) {
                st.pop();
            }
            if (!st.empty()) {
                left[i] = st.top();
            }
            st.push(i);
        }
        stack<int> st1;
        for (int i = n - 1; i >= 0; i--) {
            int curr = heights[i];
            while (!st1.empty() && heights[st1.top()] >= curr) {
                st1.pop();
            }
            if (!st1.empty()) {
                right[i] = st1.top();
            }
            st1.push(i);
        }
        int mx = INT_MIN;
        for (int i = 0; i < left.size(); i++) {
            int width = right[i] - left[i] - 1;
            int area = heights[i] * width;
            mx = max(mx, area);
        }
        return mx;
    }
};