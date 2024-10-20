class Solution {
public:
    vector<int>parent;
    vector<int>rank;
   
    int find(int x)
    {
        if(parent[x]==x)
        {
            return x;
        }
        return parent[x] = find(parent[x]);
    }

     void Union(int x, int y)
    {
        int x_parent = find(x);
        int y_parent = find(y);

        if(rank[x_parent] > rank[y_parent])
        {
            parent[y_parent] = x_parent;
        }
        else if(rank[x_parent] < rank[y_parent])
        {
            parent[x_parent] = y_parent;
        }
        else
        {
            parent[x_parent] = y_parent;
            rank[y_parent]++;
        }
    }


    long long countPairs(int n, vector<vector<int>>& edges) {
        parent.resize(n);
        rank.resize(n,0);

        for(int i=0;i<n;i++)
        {
            parent[i] = i;
        }
        //step2 ->making components
        for(auto &vec: edges)
        {
            int u = vec[0];
            int v = vec[1];
            Union(u,v);

        }

        // step3// map bana do for storing parent/components and number of nodes inside the node
         unordered_map<int,int>umap;
        for(int i=0;i<n;i++)
        {
            int Parent = find(i);
            umap[Parent]++;
        }
        // find result from map by iteratingl
        long long result = 0;
        long long rem = n;
        for(auto &it:umap)
        {
            long long size = it.second;
            result+= (size)*(rem-size);
            rem-=size;
        }

        return result;
    }
};