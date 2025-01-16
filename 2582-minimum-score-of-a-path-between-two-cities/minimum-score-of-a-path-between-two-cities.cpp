class Solution {
public:

    void dfs(int u,  vector<bool> &visited,unordered_map<int,vector<pair<int,int>>>&adj,int &result)
    {

        visited[u]=true;
        for(auto &vec:adj[u])
        {
            int v = vec.first;
            int dist = vec.second;

            result = min(result,dist);

            if(!visited[v])
            {
                dfs(v,visited,adj,result);
            }
        }
    }
    int minScore(int n, vector<vector<int>>& roads) {
        
        vector<bool> visited(n,false);
        unordered_map<int,vector<pair<int,int>>>adj;

        for(auto &vec:roads)
        {
            int u = vec[0];
            int v = vec[1];
            int cost = vec[2];

            adj[u].push_back({v,cost});
            adj[v].push_back({u,cost});
        }

        int result = INT_MAX;
        dfs(1,visited,adj,result);

        return result;
    }
};