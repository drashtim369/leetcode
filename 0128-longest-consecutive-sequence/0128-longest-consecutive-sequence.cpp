class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
    set<int> st(nums.begin(), nums.end());
    for (auto it : st) cout << it << " ";
    int mx = 0, len = 0, start;
    int j = 0;
    for (auto it : st) {
        if (st.find(it-1) == st.end()) {
            start = it;
            len = 0;
            j = 0;
        } 
        if (st.find(start + j) != st.end()) {
            len++;
            j++;
            mx = max(len, mx);
            cout << endl << start << " " << len << " " << mx << endl;
        }
    }
    return mx;
    }
};