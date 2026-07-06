class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.size() != t.size()) return false;
        vector<int> f1(256,-1);
        vector<int> f2(256,-1);
        for (int i = 0; i < s.size(); i++) {
            char a = s[i], b = t[i];
            if (f1[a] == -1 && f2[b] == -1) {
                f1[a] = b; f2[b] = a;
            } else {
                if (f1[a] != b || f2[b] != a) return false;
            }
        }
        return true;
    }
};