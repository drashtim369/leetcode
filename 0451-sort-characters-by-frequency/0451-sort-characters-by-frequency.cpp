class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> mpp;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            mpp[s[i]]++;
        }
        vector<vector<int>> bucket(s.size()+1);
        for (auto it : mpp) {
            bucket[it.second].push_back(it.first);
        }
        string res = "";
        for (int i = bucket.size() - 1; i >= 0; i--) {
            for (auto c : bucket[i]) {
                res+=string(i,c); 
            }
        }
        
        return res;
    }
};