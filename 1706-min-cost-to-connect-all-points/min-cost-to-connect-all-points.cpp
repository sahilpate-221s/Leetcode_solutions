class Solution {
public:
    typedef pair<int,int> P;
    int minCostConnectPoints(vector<vector<int>>& points) {
        unordered_map<int,vector<P>>adj;
        //making adjacency list
        for(int i=0;i<points.size();i++)
        {
            for(int j=i+1;j<points.size();j++)
            {
                int wt = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                adj[i].push_back({j,wt});
                adj[j].push_back({i,wt});
            }
        }

        int V = points.size();
        priority_queue<P,vector<P>, greater<P>> pq;
        vector<bool>inMST(V,false);
        int sum = 0;

        pq.push({0,0});
        while(!pq.empty())
        {
                auto p = pq.top();
                pq.pop();


                int wt = p.first;
                int node = p.second;

                if(inMST[node])continue;

                inMST[node]=true;
                sum+=wt;

                for(auto &temp: adj[node])
                {
                    int neighbour = temp.first;
                    int N_wt = temp.second;

                    if(inMST[neighbour] == false)
                    {
                        pq.push({N_wt,neighbour});
                    }
                }
        }
        return sum;


    }
};