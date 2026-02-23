class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int min_speed = 1, mx_speed = INT_MIN, ans = 0;
        for (auto it : piles) if (it > mx_speed) mx_speed = it;
        while (min_speed <= mx_speed) {
            int mid_speed = min_speed + (mx_speed - min_speed) / 2;
            long long sum = 0;
            for (auto it : piles) {
                sum += (it + mid_speed - 1) / mid_speed; // this is just to get ceil values.
            }
            if (sum <= h) {
                mx_speed = mid_speed - 1;
            } else {
                min_speed = mid_speed + 1; 
            }
        }
        return min_speed;
    }
};