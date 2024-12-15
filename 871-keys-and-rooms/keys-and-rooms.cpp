class Solution {
public:
    
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        
        vector<bool> visited(n,false);
        queue<int> que;
        que.push(0);

        visited[0]=true;
        while(!que.empty())
        {
            int node = que.front();
            que.pop();
            for(auto &it: rooms[node])
            {
                if(!visited[it])
                {
                    que.push(it);
                    visited[it]=true;
                }
            }
        }

        for(auto x:visited )
        {
            if(x==false)return false;
        }
        return true;
    }
};