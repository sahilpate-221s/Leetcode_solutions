class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int,int> umap;
        for(auto &num: nums)
        {
            umap[num]++;
        }
        int result = 0;
        for(auto &it: umap)
        {
            int freq = it.second;
            if(freq == 1)return -1;
            result += ceil((double)freq/3);
        }
        return result;
        
    }
};