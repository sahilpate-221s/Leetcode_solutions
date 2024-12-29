class Solution {
public:
    bool dfs(unordered_map<int,vector<int>>& adj,int node, vector<int>& color,int red)
    {
        color[node]=red;

        for(auto &v: adj[node])
        {
            if(color[v]==color[node])return false;

            if(color[v]==-1)
            {
                if(!dfs(adj,v,color,1-red))return false;
            }
        }

        return true;
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        unordered_map<int,vector<int>> adj;

        for(auto it: dislikes)
        {
            int u = it[0];
            int v = it[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> color(n+1,-1);
        int red = 1;

        for(int i=1;i<=n;i++)
        {
            if(color[i]==-1)
            {
                if(dfs(adj,i,color,red) == false)
                {
                    return false;
                }
            }
        }
        return true;
        
    }
};