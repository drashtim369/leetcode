class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
    unordered_set<int> st(nums.begin(), nums.end());
    if (nums.size() == 0) return 0;
    int mx = 1, len = 0, start;
    int j = 0;
    for (auto it : st) {
        if (st.find(it-1) == st.end()) {
            start = it;
            int cnt = 1;
            while (st.find(start + 1) != st.end()) {
                start = start + 1;
                cnt++;
                mx = max(cnt, mx);
            }
        } 
    }
    return mx;
    }
};