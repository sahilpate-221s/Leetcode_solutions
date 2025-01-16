class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        unordered_map<int,vector<pair<int,int>>> adj;


        for(auto &vec: flights)
        {
            int u = vec[0];
            int v = vec[1];
            int cost = vec[2];

            adj[u].push_back({v,cost});
        }

        int steps = 0;
        vector<int>distance(n,INT_MAX);

        queue<pair<int,int>>pq;
        pq.push({src,0});
        distance[src]=0;

        while(!pq.empty() && steps <=k)
        {
            int N = pq.size();

            while(N--)
            {
                int u = pq.front().first;
                int d = pq.front().second;

                pq.pop();

                for(pair<int,int> &P: adj[u])
                {
                    int v = P.first;
                    int cost = P.second;

                    if(distance[v] > d+cost)
                    {
                        distance[v]=d+cost;
                        pq.push({v,d+cost});
                    }
                }
            }
            steps++;
        }
        return distance[dst]==INT_MAX ? -1:distance[dst];
    }
};