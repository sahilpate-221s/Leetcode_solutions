class Solution {
public:
    bool dfs(unordered_map<int,vector<int>>& adj,int source, int dest, vector<bool>& visited)
    {
        if(source == dest)return true;
        if(visited[source]==true)return false;

        visited[source]=true;

        for(auto &node: adj[source])
        {
            if(dfs(adj,node,dest,visited))return true;
        }

        return false;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        unordered_map<int,vector<int>> adj;
        
        for(auto &edg: edges)
        {
            int u = edg[0];
            int v = edg[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool> visited(n,false);
        return dfs(adj,source,destination,visited);
        
    }
};