class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size();

        vector<int>LIS(n,1);
        vector<int>LDS(n,1);

        //calculate LIS
        for(int i=0;i<n;i++)
        {
            for(int j= i-1;j>=0;j--)
            {
                if(nums[i] > nums[j])
                {
                    LIS[i] = max(LIS[i],LIS[j]+1);
                }
            }
        }
        //calculate LDS
        for(int i=n-1;i>=0;i--)
        {
            for(int j=i+1;j<n;j++)
            {
                if(nums[i] > nums[j])
                {
                    LDS[i] = max(LDS[i],LDS[j]+1);
                }
            }
        }
        
        int minRemovals = n;
        for(int i=0;i<n;i++)
        {
            // treat each elemtn as peak and find the min removal
            if(LIS[i] > 1&& LDS[i]>1)
                 minRemovals = min(minRemovals, n-LIS[i] - LDS[i]+1);
        }

        return minRemovals;
    }
};