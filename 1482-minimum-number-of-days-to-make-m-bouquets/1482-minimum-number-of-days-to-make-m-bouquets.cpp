class Solution {
public:
    int canMake(vector<int>& bloomDay, int mid, int m, int k) {
        int bouque = 0, consecutive = 0;
        for (int it : bloomDay) {
            if (it <= mid) {
                consecutive++;
                if (consecutive == k) {
                    bouque++;
                    consecutive = 0;
                }
            } else {
                consecutive = 0;
            }
        }
        return bouque;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        if (m > n / k) return -1;
        int low = *min_element(bloomDay.begin(), bloomDay.end()), high = *max_element(bloomDay.begin(), bloomDay.end());
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int req = canMake(bloomDay, mid, m, k);
            if (req < m) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return low;
    }
};