class Solution {
public:
    string reverseWords(string s) {
        int i = 0, n = s.size();
        vector<string> res;
        while (i < n) {
            while (s[i] == ' ') i++;
            if (i >= n) break;
            string ans = "";
            while (s[i] != ' ' && i < n) {
                ans += s[i];
                i++;
            }
            res.push_back(ans);
        }
        reverse(res.begin(), res.end());
        string fin = "";
        for (int i = 0; i < res.size(); i++) {
            fin += res[i];
            if (i < res.size() - 1) {
                fin += " ";
            }
        }
        return fin;
    }
};