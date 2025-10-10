class Solution {
public:
    int helper(int i, int j, int m, int n, vector<vector<int>>& grid,
              vector<vector<int>>& dp) {
        // base case
        if (i == m - 1 && j == n - 1)
            return grid[i][j];

        if (i < 0 || i >= m || j < 0 || j >= n)
            return 1e8;

        if (dp[i][j] != -1)
            return dp[i][j];

        int left =grid[i][j] +  helper(i + 1, j, m, n, grid, dp);
        int right = grid[i][j] +  helper(i, j + 1, m, n, grid, dp);

        return dp[i][j] = min(left, right);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));

        return helper(0, 0, m, n, grid, dp);
    }
};