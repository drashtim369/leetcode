class Solution {
public:
    string reverseWords(string s) {
        string result = "";
        vector<string> res;
        int n = s.size(), i = 0;
        while (i < n) {
            while (i < n && s[i] == ' ') {
                i++;
            }
            if (i >= n) break;
            string temp = "";
            while (i < n && s[i] != ' ') {
                temp += s[i];
                i++;
            }
            res.push_back(temp);
        }
        reverse(res.begin(), res.end());
        for (int i = 0; i < res.size(); i++) {
            result += res[i];
            if (i < res.size()-1) {
                result+=' ';
            }
        }
        return result;
    }
};