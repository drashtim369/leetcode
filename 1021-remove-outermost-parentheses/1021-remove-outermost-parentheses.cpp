class Solution {
public:
    string removeOuterParentheses(string s) {
        int depth = 0;
        string res = ""; 
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(' && depth == 0) {
                depth = 1; 
            } else if (s[i] == '(') {
                depth++;
                res+='(';
            } else if (s[i] == ')') {
                depth--;
                if (depth > 0) {
                    res+=')';
                }
            } 
        }
        return res;
    }
};