class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int,int>umap;
        for(auto it: arr)
        {
            umap[it]++;
        }

        int maxi = -1;
        for(auto &[val,freq]:umap)
        {
            if(val == freq)
            {
                maxi = max(maxi, val);
            }
        }
        return  maxi;
        
    }
};