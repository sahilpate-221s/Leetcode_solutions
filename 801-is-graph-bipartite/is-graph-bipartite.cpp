class Solution {
public:
    bool dfs(int u, vector<vector<int>>& graph, vector<int>& color, int c) {
        color[u] = c;
        for (auto v : graph[u]) {
            if (color[v] == color[u])
                return false;
            if (color[v] == -1) {
                int nc = 1 - c;
                if (dfs(v, graph, color, nc) == false)
                    return false;
            }
        }

        return true;
    }

    bool bfs(int u, vector<vector<int>>& graph, vector<int>& color, int c)
    {
        queue<int>pq;
        pq.push(u);
        color[u] = c;

        while(!pq.empty())
        {
            int node = pq.front();
            pq.pop();

            for(auto &v:graph[node])
            {
                if(color[v] == color[node])return false;
                if(color[v] == -1)
                {
                    
                    color[v] = 1-color[node];
                    pq.push(v);
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<int> color(V, -1);

        for (int i = 0; i < V; i++) {
            if (color[i] == -1) {
                if (bfs(i, graph, color, 1) == false)
                    return false;
            }
        }
        return true;
    }
};