class Solution {
public:
    int totalFruit(vector<int>& s) {
        unordered_map<int, int> mpp;
        int ans = 0, left = 0, n = s.size();
        for (int right = 0; right < n; right++) {
            mpp[s[right]]++;
            while (mpp.size() > 2) {
                mpp[s[left]]--;
                if (mpp[s[left]] == 0) mpp.erase(s[left]);
                left++;
            }
            ans=max(ans,right-left+1);
        }
        return ans;
    }
};