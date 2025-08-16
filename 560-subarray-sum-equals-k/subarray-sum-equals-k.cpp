class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        
        int n= nums.size();
        unordered_map<int,int>umap;

        int count =0;
        int sum  =0;
        umap[0] = 1;
        for(int i=0;i<n;i++){
            sum+= nums[i];
            int rem =  sum-k;
            if(umap.find(rem) != umap.end())
            {
                count+= umap[rem];
            }
             umap[sum]++;
        }
        return count;
    }
    
};