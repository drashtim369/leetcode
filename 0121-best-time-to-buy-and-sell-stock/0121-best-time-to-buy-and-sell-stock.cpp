class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mn = prices[0], maxprofit = 0, profit = 0;
        for (int i = 0; i < prices.size(); i++) {
            if (prices[i] < mn) {
                mn = prices[i];
            }
            profit = prices[i] - mn;
            maxprofit = max(maxprofit, profit);
        }
        cout << mn << " " << profit << " " << maxprofit << endl; 
        return maxprofit;
    }
};