class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int min_capacity = *max_element(weights.begin(), weights.end());
        int max_capacity = accumulate(weights.begin(), weights.end(), 0);
        while (min_capacity <= max_capacity) {
            int mid_capacity = min_capacity + (max_capacity - min_capacity) / 2;
            int d = 0, sum = 0;
            for (auto i : weights) {
                sum += i;
                if (sum > mid_capacity) {
                    d++;
                    sum = i;
                }
            }
            
            if (d < days) {
                max_capacity = mid_capacity - 1;
            } else {
                min_capacity = mid_capacity + 1;
            }
        }
        return min_capacity;
    }
};