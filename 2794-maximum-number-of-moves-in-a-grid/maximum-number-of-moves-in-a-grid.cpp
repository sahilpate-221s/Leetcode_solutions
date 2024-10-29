class Solution {
public:
    int n, m;
    int f(int i, int j, vector<vector<int>>& grid, vector<vector<int>>&dp)
    {
        if (j >= m || i < 0 || i >= n) {
            return 0;
        }
        if(dp[i][j] != -1)return dp[i][j];

        int up = 0, down = 0, straight = 0;

        if (i > 0 && j + 1 < m && grid[i][j] < grid[i - 1][j + 1]) {
            up = 1 + f(i - 1, j + 1, grid,dp);
        }
        if (i + 1 < n && j + 1 < m && grid[i][j] < grid[i + 1][j + 1]) {
            down = 1 + f(i + 1, j + 1, grid,dp);
        }
        if (j + 1 < m && grid[i][j] < grid[i][j + 1]) {
            straight = 1 + f(i, j + 1, grid,dp);
        }

        return dp[i][j] =  max({up, straight, down});
    }

    int maxMoves(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        int val = 0;
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));

        for (int i = 0; i < n; i++) {
            val = max(val, f(i, 0, grid,dp));
        }
        return val;
    }
};
