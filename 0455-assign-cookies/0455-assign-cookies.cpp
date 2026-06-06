class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int left = 0, right = 0, maxChild = 0;
        while (left < g.size() && right < s.size()) {
            if (g[left] <= s[right]) {
                right++;
                left++;
                maxChild++;
            } else {
                right++;
            }
        }
        return maxChild;
    }
};