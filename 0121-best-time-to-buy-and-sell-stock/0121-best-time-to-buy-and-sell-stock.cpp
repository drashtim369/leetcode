class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0, mxProf = 0, mn = INT_MAX;
        for (int i = 0; i < prices.size(); i++) {
            if (prices[i] < mn) mn = prices[i];
            profit = prices[i] - mn;
            mxProf = max(mxProf, profit);
        }
        return mxProf;
    }
};