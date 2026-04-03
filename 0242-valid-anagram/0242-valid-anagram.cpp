class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;
        vector<int>freq(128,0); //Create a 128 sized array filled with zeroes -> [0,0,0...0];
        for (int i = 0; i < s.size(); i++) {
            freq[s[i]]++;
            freq[t[i]]--;
        }
        for (int num : freq) {
            if (num != 0) return false;
        }
        return true;
    }
};