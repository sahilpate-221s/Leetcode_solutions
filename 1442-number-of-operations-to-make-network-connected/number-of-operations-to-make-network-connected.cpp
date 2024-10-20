class Solution {
public:
    void dfs(unordered_map<int,vector<int>>& adj, int u, vector<bool>& visited)
    {
        
        visited[u]=true;
        for(int &v : adj[u])
        {
            if(!visited[v])
            {
                dfs(adj,v,visited);
            }
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        
        if(connections.size() < n-1)return -1;
      // Build the adjacency list from the connections
        unordered_map<int, vector<int>> adj;
        for (auto &conn : connections)
        {
            int u = conn[0];
            int v = conn[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<bool> visited(n,0);
        int count=0;
        for(int i=0;i<n;i++)
        {
            if(!visited[i])
            {
                dfs(adj,i,visited);
                count++;
            }
        }
        return count-1;
    }
};