class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
        unordered_map<int,int>umap;
        umap[0]=-1;
        int sum = 0;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            int rem = sum%k;
            if(rem<0)
            {
                rem+=k;
            }
            if(umap.find(rem) != umap.end())
            {
                if(i - umap[rem] > 1)
                    return true;
            }
            else
            {
                umap[rem]=i;
            }
        }

        return false;
        
        
    }
};