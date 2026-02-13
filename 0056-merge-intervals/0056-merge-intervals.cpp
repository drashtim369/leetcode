class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& arr) {
        if (arr.size() == 1) return arr;
        sort(arr.begin(), arr.end());
        vector<vector<int>> res;
        int n = arr.size();
        for (int i = 0; i < n; i++) {
            if (res.empty() || arr[i][0] > res.back()[1]) {
                res.push_back(arr[i]);
            } else {
                res.back()[1] = max(res.back()[1], arr[i][1]);
            }
        }
        return res;
    }
};