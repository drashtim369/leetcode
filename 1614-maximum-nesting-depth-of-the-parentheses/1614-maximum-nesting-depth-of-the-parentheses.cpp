class Solution {
public:
    int maxDepth(string s) {
        int depth = 0, mx = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                depth++;
            } else if (s[i] == ')') {
                depth--;
            }
            mx = max(mx, depth);
            cout << mx << " ";
        }
        return mx;
    }
};