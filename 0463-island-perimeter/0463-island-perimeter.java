class Solution {
    public int islandPerimeter(int[][] grid) {
        int n = grid.length, m = grid[0].length;
        int perimeter = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {

                    // check all 4 sides

                    // top
                    if (i == 0 || grid[i - 1][j] == 0)
                        perimeter++;

                    // bottom
                    if (i == n - 1 || grid[i + 1][j] == 0)
                        perimeter++;

                    // left
                    if (j == 0 || grid[i][j - 1] == 0)
                        perimeter++;

                    // right
                    if (j == m - 1 || grid[i][j + 1] == 0)
                        perimeter++;
                }
            }
        }

        return perimeter;
    }
}