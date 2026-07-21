class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> need;
        if (t.size() > s.size()) return "";
        for (auto ch : t) {
            need[ch]++;
        }
        int required = t.size(), left = 0, start = 0, minLen = INT_MAX;
        for(int right = 0; right < s.size(); right++){
            if(need[s[right]] > 0)
                required--;
            need[s[right]]--;
            while(required==0){
                if(right-left+1 < minLen){
                    minLen = right-left+1;
                    start = left;
                }
                need[s[left]]++;
                if(need[s[left]] > 0) required++;
                left++;
            }
        }
        if(minLen==INT_MAX)
            return "";
        return s.substr(start,minLen);
    }
};