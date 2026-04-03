class Solution {
public:
    int maxDepth(string s) {
        int depth = 0, mxdepth = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(' && depth == 0) {
                depth = 1;
            } else if (s[i] == '(') {
                depth++;
            } else if (s[i] == ')') {
                depth--;
            }
            mxdepth = max(mxdepth, depth);
        }
        return mxdepth;
    }
};