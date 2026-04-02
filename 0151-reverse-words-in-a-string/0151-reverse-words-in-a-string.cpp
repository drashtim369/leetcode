class Solution {
public:
    string reverseWords(string s) {
        int i = 0, n = s.size();
        vector<string> res; 
        while (i < n) {
            while (i < n && s[i] == ' ') i++;
            if (i >= n) break; 
            string temp = ""; 
            while (i < n && s[i] != ' ') {
                temp+=s[i];
                i++;
            }
            res.push_back(temp);
        }
        reverse(res.begin(), res.end());
        string result = "";
        for (int j = 0; j < res.size(); j++) {
            if (j > 0) result+=" ";
            result+=res[j];
        }
        return result;
    }
};