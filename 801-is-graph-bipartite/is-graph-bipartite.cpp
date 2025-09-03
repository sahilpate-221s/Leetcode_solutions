class Solution {
public:
    bool dfs(int u, vector<vector<int>>& graph,vector<int>& color, int c)
    {
        color[u] = c;
        for(auto v:graph[u])
        {
            if(color[v]== color[u])return false;
            if(color[v] == -1)
            {
                int nc = 1-c;
                if(dfs(v,graph,color,nc) == false)return false;
            }
        }

        return true;

    }
    bool isBipartite(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<int>color(V,-1);

        for(int i=0;i<V;i++)
        {
            if(color[i]==-1)
            {
                if(dfs(i,graph,color,1) == false)return false;
                
            }
        }
        return true;




        
    }
};