class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        long sum5 = 0, sum10 = 0, sum20 = 0, i = 0;
        while (i < bills.size()) {
            if (bills[i] == 5) {
                sum5++;
            } else if (bills[i] == 10) {
                if (sum5 >= 1) {
                    sum10++;
                    sum5--;
                } else {
                    return false;
                }
            } else {
                if (sum10 >= 1 && sum5 >= 1) {
                    sum20++;
                    sum10--;
                    sum5--;
                } else if (sum5>=3) {
                    sum20++;
                    sum5-=3;
                } else {
                    return false;
                }
            }
            i++;
        } 
        return true;
    }
};