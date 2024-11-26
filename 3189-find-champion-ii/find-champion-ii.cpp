class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int> indegree(n,0);

        for (const auto& edge : edges) {
            int u = edge[0]; // Source node
            int v = edge[1]; // Destination node
            indegree[v]++;
        }

        int deg = 0;
        int count = 0;
        for(int i=0;i<indegree.size();i++)
        {
            if(indegree[i]==0)
            {
                deg = i;
                count++;
            }
        }

        if(count==1)return deg;
        else return -1;
        

        
        
    }
};