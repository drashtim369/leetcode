class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> mpp1, mpp2;
        for (int i = 0; i < s.size(); i++) {
            if (!mpp1.count(s[i])) mpp1[s[i]] = t[i];
            if (!mpp2.count(t[i])) mpp2[t[i]] = s[i];
            if (mpp1.count(s[i]) && mpp1[s[i]] != t[i]) return false; 
            if (mpp2.count(t[i]) && mpp2[t[i]] != s[i]) return false;
        }
        return true;
    }
};