class Solution {
public:
    bool rotateString(string s, string goal) {
        for (int k = 0; k < s.size(); k++) {
            string copy = s;
            reverse(copy.begin(), copy.begin()+k);
            reverse(copy.begin()+k,copy.end());
            reverse(copy.begin(), copy.end());
            if (copy == goal) return true;
        }
        return false;
    }
};