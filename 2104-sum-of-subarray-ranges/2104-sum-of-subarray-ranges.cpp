class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        vector<int> leftSmallest(n,-1);
        vector<int> leftLargest(n,-1);
        vector<int> rightSmallest(n,n);
        vector<int> rightLargest(n,n);
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[st.top()] >= nums[i]) {
                st.pop();
            }
            if (!st.empty()) {
                leftSmallest[i] = st.top();
            }
            st.push(i);
        }
        while (!st.empty()) st.pop();
        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[st.top()] <= nums[i]) {
                st.pop();
            }
            if (!st.empty()) {
                leftLargest[i] = st.top();
            }
            st.push(i);
        }
        while (!st.empty()) st.pop();
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] > nums[i]) {
                st.pop();
            }
            if (!st.empty()) {
                rightSmallest[i] = st.top();
            }
            st.push(i);
        }
        while (!st.empty()) st.pop();
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] < nums[i]) {
                st.pop();
            }
            if (!st.empty()) {
                rightLargest[i] = st.top();
            }
            st.push(i);
        }
        long long ans = 0; 
        for (int i = 0; i < n; i++) {
            long long maxContribution = 1LL * nums[i] * (i - leftLargest[i]) * (rightLargest[i] - i);
            long long minContribution = 1LL * nums[i] * (i - leftSmallest[i]) * (rightSmallest[i] - i);    
            ans += maxContribution - minContribution;
        }
        return ans;
    }
};