class Solution {
public:
    int n;
    vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
    int dfs(int i, int j, vector<vector<int>>& grid, int uniqueId) {
        grid[i][j] = uniqueId;
        int count = 1;

        for (auto& dir : directions) {
            int nRow = i + dir[0];
            int nCol = j + dir[1];

            if (nRow >= 0 && nRow < n && nCol >= 0 && nCol < n &&
                grid[nRow][nCol] ==1) {
                count += dfs(nRow, nCol, grid, uniqueId);
            }
        }

        return count;
    }
    int largestIsland(vector<vector<int>>& grid) {
        n = grid.size();
        unordered_map<int, int> islands;
        int uniqueId = 2;
        int size = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    int val = dfs(i, j, grid, uniqueId);
                    islands[uniqueId] = val;
                    size = max(size, val);
                    uniqueId++;
                }
            }
        }

        if (size == n*n) {
            return size;
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                unordered_set<int> index;
                int newSize = 1;
                if (grid[i][j] == 0) {
                    for (auto& dir : directions) {
                        int nRow = i + dir[0];
                        int nCol = j + dir[1];

                        if (nRow >= 0 && nRow < n && nCol >= 0 && nCol < n &&
                            grid[nRow][nCol] > 0) {
                            index.insert(grid[nRow][nCol]);
                        }
                    }

                    for (auto& it : index) {
                        newSize += islands[it];
                    }
                    size = max(size, newSize);
                }
            }
        }
        return size;
    }
};