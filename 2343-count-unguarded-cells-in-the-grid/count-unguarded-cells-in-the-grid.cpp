class Solution {
public:
    void unguarded(int i, int j, vector<vector<int>>& grid, int m, int n) {
        // for all 4 directions
        // fir right
        for (int x = i + 1; x < m; x++) {
            if (grid[x][j] == 1 || grid[x][j] == 2)
                break;
            grid[x][j] = 3;
        }
        // for left
        for (int x = i - 1; x >= 0; x--) {
            if (grid[x][j] == 1 || grid[x][j] == 2)
                break;
            grid[x][j] = 3;
        }
        // for up
        for (int y = j - 1; y >= 0; y--) {
            if (grid[i][y] == 1 || grid[i][y] == 2)
                break;
            grid[i][y] = 3;
        }
        // for right side
        for (int y = j + 1; y < n; y++) {
            if (grid[i][y] == 1 || grid[i][y] == 2)
                break;
            grid[i][y] = 3;
        }
    }
    int countUnguarded(int m, int n, vector<vector<int>>& guards,
                       vector<vector<int>>& walls) {
        vector<vector<int>> grid(m, vector<int>(n, 0));
        for (auto& vec : guards) {
            int u = vec[0];
            int v = vec[1];
            grid[u][v] = 1;
        }

        for (auto& vec : walls) {
            int u = vec[0];
            int v = vec[1];
            grid[u][v] = 2;
        }

        for (auto& it : guards) {
            int u = it[0];
            int v = it[1];

            unguarded(u, v, grid, m, n);
        }

        // final check to find the unguarded cells
        int count = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0)
                    count++;
            }
        }
        return count;
    }
};