class Solution {
public:
    void dfs(unordered_map<int,vector<int>>& adj, int source , vector<bool>& visited)
    {
        // if(visited[source]==true)return ;
        visited[source]=true;

        for(auto &node: adj[source])
        {
            if(!visited[node])
            {
                dfs(adj,node,visited);
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        unordered_map<int,vector<int>> adj;
        for(int i=0;i<rooms.size();i++)
        {
            for(int j=0;j<rooms[i].size();j++)
            {
                adj[i].push_back(rooms[i][j]);
            }
        }

        vector<bool> visited(n,false);

        dfs(adj,0,visited);
        for(int i=0;i<n;i++)
        {
            if(visited[i]==false)return false;
        }
        return true;
    }
};