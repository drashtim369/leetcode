class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> st;
        int n = nums.size();
        vector<int> ans(n,-1);
       for (int i = n*2 - 1; i >= 0; i--) {
            int el = nums[i % n];
            while (!st.empty() && el >= st.top()) {
                st.pop();
            }
            if (i < n) {
                if (!st.empty()) {
                    ans[i] = st.top();
                }
            }
            st.push(el);
       }

        return ans;
    }
};