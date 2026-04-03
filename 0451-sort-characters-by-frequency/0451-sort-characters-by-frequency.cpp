class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> freq; string ans = "";
        for (char c : s) freq[c]++;
        vector<vector<char>> buckets(s.size() + 1);
        for (auto it : freq) buckets[it.second].push_back(it.first);
        for (int i = s.size(); i >= 0; i--) {
            for (auto c : buckets[i]) {
                ans += string(i, c);
            }
        }
        return ans;
    }
};