class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.size(), x = 0;
        if (n == k) return "0";
        string res = ""; stack<char> st;
        for (int i = 0; i < n; i++) {
            char ch = num[i];
            while (!st.empty() && (ch < st.top()) && k > 0) {
                st.pop();
                k--;
            }
            st.push(ch);
        }
        while (!st.empty() && k > 0) {
            st.pop();
            k--;
        }
        while (!st.empty()) {
            res += st.top();
            st.pop();
        }
        reverse(res.begin(), res.end());
        int i = 0;
        while (i < res.size() && res[i] == '0') i++;
        res = res.substr(i);

        return res.empty() ? "0" : res;
    }
};