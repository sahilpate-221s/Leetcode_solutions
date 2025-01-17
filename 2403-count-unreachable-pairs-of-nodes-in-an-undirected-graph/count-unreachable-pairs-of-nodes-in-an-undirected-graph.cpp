class Solution {
public:
    void dfs(int u, vector<bool>& visited, unordered_map<int, vector<int>>& adj,
             long long& size) {
        visited[u] = true;
        size++;
        for (auto& v : adj[u]) {
            if (!visited[v]) {
                dfs(v, visited, adj, size);
            }
        }
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        long long result = 0;
        long long currentSum = n;

        unordered_map<int, vector<int>> adj;
        vector<bool> visited(n, false);

        for (auto& vec : edges) {
            int u = vec[0];
            int v = vec[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                long long size = 0;
                dfs(i, visited, adj, size);
                result += (size) * (currentSum - size);
                currentSum -= size;
            }
        }

        return result;
    }
};