class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int mn = INT_MAX, mx = 0;
        for (int i = 0; i < n; i++) {
            if (prices[i] < mn) {
                mn = prices[i];
            }
            int profit = prices[i] - mn;
            mx = max(profit, mx); 
        }
        return mx;
    }
};