class Solution {
public:
    int helper(int index, vector<int>&nums,int prev,vector<vector<int>>& dp)
    {
        if(index == nums.size())
        {
            return 0;
        }
        if(prev != -1 &&  dp[index][prev] != -1)return  dp[index][prev];

        int   noTake = helper(index+1,nums,prev,dp);
        int take = 0;
        if(prev == -1 || nums[index] > nums[prev])
        {
            take = 1 + helper(index+1,nums,index,dp);
        }
        if(prev != -1)
            dp[index][prev] = max(take,noTake);

        return max(take,noTake);
        
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        // vector<vector<int>>dp(n,vector<int>(n,1));
        // return helper(0,nums,-1,dp);

        vector<int>dp(n,1);

        //tabulation code 

        int maxLIS = 1;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(nums[j] < nums[i])
                {
                    dp[i] = max(dp[i],dp[j]+1);
                }
                maxLIS = max(maxLIS,dp[i]);
            }
        }
        return  maxLIS;
    }
};