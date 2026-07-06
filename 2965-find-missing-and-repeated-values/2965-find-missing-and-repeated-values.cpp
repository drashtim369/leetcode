class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        vector<int> arr;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                arr.push_back(grid[i][j]);
            }
        }
        long long n = arr.size();
        long long sum = 0, sum2 = 0, sumsq = 0, sumsq2 = 0;
        for (int i = 0; i < n; i++) {
            sum += arr[i];
            sumsq += (long long)arr[i] * arr[i];
        }
        sum2 = (n * (n + 1)) / 2;
        sumsq2 = (n * (n + 1) * (2 * n + 1)) / 6;
        int val1 = sum2 - sum;
        int val2 = sumsq2 - sumsq;
        int val3 = val2 / val1;
        int x = (val1 + val3) / 2;
        int y = val3 - x;
        return {(int)y, (int)x};
    }
};