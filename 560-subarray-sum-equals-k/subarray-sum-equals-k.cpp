class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {

        int n  = nums.size();
        int count =0;
        unordered_map<int,int>umap;
        umap[0] = 1;

        int sum = 0;
        for(int i=0;i<n;i++)
        {
            sum+= nums[i];
            int rem = sum-k;

            if(umap.find(rem) != umap.end())
            {
                count+= umap[rem];
            }
            umap[sum]++;
        }
        return count;
        
    }
};