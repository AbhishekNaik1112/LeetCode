class Solution {
private:
    int dfs(vector<vector<int>>& grid, int i, int j) {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() ||
            grid[i][j] == 0) { // OoB and 0 gold
            return 0;
        }

        int originalValue = grid[i][j];
        grid[i][j] = 0; // marking cel

        // go all dirs
        int up = dfs(grid, i - 1, j);
        int down = dfs(grid, i + 1, j);
        int left = dfs(grid, i, j - 1);
        int right = dfs(grid, i, j + 1);

        // change to original value
        grid[i][j] = originalValue;

        // return maxgold
        return originalValue + max({up, down, left, right});
    }

public:
    int getMaximumGold(vector<vector<int>>& grid) {
        int maxGold = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] > 0) { // if cell has gold use rec to find
                    maxGold = max(maxGold, dfs(grid, i, j));
                }
            }
        }
        return maxGold;
    }
};
