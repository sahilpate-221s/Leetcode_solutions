class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int>umap;
        long long sum  = 0;
        long long maxi = INT_MIN;

        int i=0,j=i;
        while(j<n)
        {
            //curr element ko umap me insert
            umap[nums[j]]++;
            //sum the value
            sum+=nums[j];

            while(umap[nums[j]] > 1 || j-i+1 > k)
            {
                // window size se jyada ho gya 
                sum-=nums[i];
                umap[nums[i]]--;
                if(umap[nums[i]] == 0)umap.erase(nums[i]);
                i++;
            }

            //check if the window size is equal to k 
            if(j-i+1 == k)
            {
                maxi = max(maxi,sum);
            }
            j++;
        }

        return (maxi == INT_MIN) ? 0: maxi;
        
    }
};