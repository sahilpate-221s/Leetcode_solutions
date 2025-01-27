class Solution {
public:
    bool dfs(unordered_map<int, vector<int>>& adj,int src,int dest,vector<bool>& visited)
    {
        visited[src]=true;
        if(src==dest)return true;

        bool isReachable = false;
        for(auto &v:adj[src])
        {
            if(!visited[v])
            {
                isReachable = isReachable || dfs(adj,v,dest,visited);
            }
        }
        return isReachable;
    }
    vector<bool> checkIfPrerequisite(int numCourses,
                                     vector<vector<int>>& prerequisites,
                                     vector<vector<int>>& queries) {

        unordered_map<int, vector<int>> adj;
        for (auto& edges : prerequisites) {
            int u = edges[0];
            int v = edges[1];

            adj[u].push_back(v);
        }

        int Q = queries.size();
        vector<bool>result(Q);

        // dfs marenge
        for(int i=0;i<Q;i++)
        {
            //visited array bana
            vector<bool> visited(numCourses,false);
            int u = queries[i][0];
            int v = queries[i][1];
            result[i] = dfs(adj,u,v,visited);
        }
        return result;
    }
};