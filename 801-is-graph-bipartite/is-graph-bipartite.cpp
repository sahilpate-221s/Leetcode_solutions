class Solution {
public:
    bool CheckBipartiteBFS(vector<vector<int>>& adj, int curr,vector<int>& color,int currColor)
    {
        queue<int>q;
        q.push(curr);
        color[curr]=currColor;

        while(!q.empty())
        {
            int u = q.front();
            q.pop();

            for(int &v:adj[u])
            {
                if(color[v]==color[u])
                    return false;
                else if(color[v]==-1)
                {
                    color[v] = 1-color[u];
                    q.push(v);
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        //using BFS
        int n = graph.size();
        vector<int>color(n,-1); //no one is colored
        // red ->1
        // green -> 0

        for(int i=0;i<n;i++)
        {
            if(color[i]==-1)
            {
                if(CheckBipartiteBFS(graph,i,color,1)==false)
                {
                    return false;
                }
            }
        }
        return true;
        
    }
};