class Solution {
public:
    int n;
    void dfs(vector<vector<int>>& adj, int u,vector<bool>& visited) {
        visited[u] = true;

        for (int v=0;v<n;v++) {
            if (!visited[v] && adj[u][v]==1) {
                dfs(adj, v, visited);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        n = isConnected.size();
        vector<bool> visited(n, false);
        // unordered_map<int, vector<int>> adj;
        // for (int i = 0; i < n; i++) {
        //     for (int j = 0; j < n; j++) {
        //         if (isConnected[i][j] == 1) {
        //             adj[i].push_back(j);
        //             adj[j].push_back(i);
        //         }
        //     }
        // }
        int count = 0;
        for (int u = 0; u < n; u++) {
            if (!visited[u]) {
                dfs(isConnected, u, visited);
                count++;
            }
        }
        return count;
    }
};