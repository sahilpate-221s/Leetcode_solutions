class Solution {
public:
    int count;
    void dfs(int u,  unordered_map<int,vector<pair<int,int>>> &adj,int parent)
    {
        for(auto &P:adj[u])
        {
            int v= P.first;
            int check = P.second;
            if(v != parent)
            {
                if(check==1)
                {
                    count++;
                }
                dfs(v,adj,u);
            }
        }
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        unordered_map<int,vector<pair<int,int>>>adj;

        for(auto &vec:connections)
        {
            int u = vec[0];
            int v =  vec[1];
            adj[u].push_back({v,1});
            adj[v].push_back({u,0});
        }

        dfs(0,adj,-1);
        return count;

        
    }
};