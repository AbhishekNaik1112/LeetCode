class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> totalPaths(m, vector<int>(n, 0));
        totalPaths[m-1][n-1] = 1;
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (i < m - 1) totalPaths[i][j] += totalPaths[i + 1][j];
                if (j < n - 1) totalPaths[i][j] += totalPaths[i][j + 1];
            }
        }

        return totalPaths[0][0];
    }
};
