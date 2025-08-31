class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<pair<int, int>, int>> pq;

        vector<vector<int>> visited(n + 1, vector<int>(m + 1, -1));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    pq.push({{i, j}, 0});
                    visited[i][j] = 2;
                }
                else visited[i][j] = 0;
            }
        }

        int maxi = 0;
        vector<vector<int>> direction = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        while (!pq.empty()) {
            int i = pq.front().first.first;
            int j = pq.front().first.second;
            int t = pq.front().second;
            maxi = max(maxi, t);
            pq.pop();

            for (auto dir : direction) {
                int ni = i + dir[0];
                int nj = j + dir[1];

                if (ni >= 0 && ni < n && nj >= 0 && nj < m &&
                    visited[ni][nj] == 0 && grid[ni][nj] == 1) {
                    pq.push({{ni, nj}, t + 1});
                    visited[ni][nj] = 2;
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (visited[i][j] != 2 && grid[i][j] == 1)
                    return -1;
            }
        }

        return maxi;
    }
};