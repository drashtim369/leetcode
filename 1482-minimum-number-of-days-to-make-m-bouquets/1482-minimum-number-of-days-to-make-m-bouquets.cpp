class Solution {
public:
    int minDays(vector<int>& arr, int m, int k) {
        if (m > arr.size() / k) return -1;
        int min_day = *min_element(arr.begin(), arr.end());
        int max_day = *max_element(arr.begin(), arr.end());
        while (min_day <= max_day) {
            int mid_day = min_day + (max_day - min_day) / 2;
            int consecutive_days = 0, req_boquets = 0;
            for (auto it: arr) {
                if (it <= mid_day) {
                    consecutive_days++;
                    if (consecutive_days == k) {
                        req_boquets++;
                        consecutive_days = 0;
                    }
                } else {
                    consecutive_days = 0;
                }
            }
            if (req_boquets < m) {
                min_day = mid_day + 1;
            } else {
                max_day = mid_day - 1;
            }
        }
        return min_day;
    }
};