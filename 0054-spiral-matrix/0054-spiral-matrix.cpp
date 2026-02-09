class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int left = 0, top = 0, right = matrix[0].size() - 1, bottom = matrix.size() - 1;
        vector<int> res;
        while (left <= right && top <= bottom) {
            for (int col = left; col <= right; col++) {
                res.emplace_back(matrix[top][col]);
            }
            top++;
            for (int row = top; row <= bottom; row++) {
                res.emplace_back(matrix[row][right]);
            } 
            right--;
            if (top <= bottom) {
                for (int col = right; col >= left; col--) {
                    res.emplace_back(matrix[bottom][col]);
                }
                bottom--;
            }
            if (left <= right) {
                for (int row = bottom; row >= top; row--) {
                    res.emplace_back(matrix[row][left]);
                }
                left++;
            }
        }
        return res;
    }
};