class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        // we have to make adjancy list
        unordered_map<int, vector<pair<int,int>>>adj;
        for(auto & edge: times)
        {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            adj[u].push_back({v,w});
        }

        //first make priority queue
        priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>>pq;
        vector<int>result(n+1,INT_MAX);
        //source to source ke liye 0 time lagega
        result[k]=0;
                //w,node
        pq.push({0,k});
        //pq me check karenge
        while(!pq.empty())
        {
            //pq ke nodes hai 
            int d = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            //adjacent neighbours ke dekhenge
            for(auto &vec: adj[node])
            {
                int adjNode = vec.first;
                int dist = vec.second;

                //check the distance from source to neighbour
                if(d+dist < result[adjNode])
                {
                    result[adjNode] = d+dist;
                    pq.push({d+dist,adjNode});
                }


            }
        }
            int ans = INT_MIN;
            for(int i=1;i<=n;i++)
            {
                ans= max(ans,result[i]);    
            }
            return ans==INT_MAX ? -1:ans;
        
    }
};