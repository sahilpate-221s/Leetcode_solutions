class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
        unordered_map<int,int> umap;
        umap[0]=1;
        int sum=0;
        int count=0;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            int rem = sum%k;

            if(rem<0)
            {
                //agar remainder negative hai to usko hum k add kar ke positive me le ayenge aise bhi kar skte hai 
                
                rem+=k;
            }

            if(umap.find(rem) != umap.end())
            {
                count+=umap[rem];
            }
            umap[rem]++;

        }

        return count;
    }
};