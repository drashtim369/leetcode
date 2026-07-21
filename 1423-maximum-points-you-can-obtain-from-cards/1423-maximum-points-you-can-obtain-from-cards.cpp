class Solution {
public:
    int maxScore(vector<int>& arr, int k) {
        int n = arr.size();
        if (n == k) return accumulate(arr.begin(), arr.end(), 0);
        int rem = n - k, x = 0, mn = INT_MAX, sum = 0, left = 0;
        for (int right = 0; right < n; right++) {
            sum+=arr[right];
            x++;
            if (x > rem) {
                sum -= arr[left];
                left++;
                x--;
            }
            if (x == rem) {
                mn = min(mn, sum);
            }
        }
        return accumulate(arr.begin(), arr.end(), 0) - mn;
    }
};