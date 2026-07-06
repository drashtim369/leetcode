class Solution {
public:
    string reverseWords(string s) {
        int i = 0; 
        vector<string> res;
        while (i < s.size()) {
            while (s[i] == ' ') i++;
            if (i >= s.size()) break;
            string ans;
            while (i < s.size() && s[i] != ' ') {
                ans+=s[i];
                i++;
            }
            res.push_back(ans);
        }
        string answer;
        for (int i = res.size()-1; i >= 0; i--) {
            answer += res[i];
            if (i > 0) {
                answer+=" ";
            }
        }
        return answer;
    }
};