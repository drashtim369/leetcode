class Solution {
public:
    string largestOddNumber(string num) {
        int largestOdd = -1, oddIdx = 0, cntOdd = 0; string res = "";
        for (int i = num.size()-1; i >= 0; i--) {
            if (num[i] % 2 != 0) {
                cntOdd++;
                oddIdx = i;
                break;
            }
        }
        res += num.substr(0,oddIdx+1);
        if (cntOdd == 0)  return "";
        else return res;
    }
};