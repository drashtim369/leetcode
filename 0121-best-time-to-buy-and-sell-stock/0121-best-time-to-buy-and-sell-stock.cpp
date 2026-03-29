class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int diff = 0, proft = 0, mn = prices[0];
        for (int i = 0; i < prices.size(); i++) {
            mn = min(prices[i], mn);
            diff = prices[i] - mn;
            proft = max(proft, diff);
        }
        return proft;
    }
};