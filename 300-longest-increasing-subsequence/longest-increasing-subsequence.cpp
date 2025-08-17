class Solution {
public:
    int helper(int idx, vector<int>&nums, int prev, vector<vector<int>>& dp)
    {
        //base case
        if(idx == nums.size())return 0;
        
        if(dp[idx][prev+1] != -1)return dp[idx][prev+1];

        int noTake = helper(idx+1,nums,prev,dp);
        int take = 0;
        if(prev == -1 || nums[idx] > nums[prev])
        {
            take = 1 + helper(idx+1,nums,idx,dp);
        }

        return dp[idx][prev+1] = max(noTake, take);


    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();

        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));

        return helper(0,nums,-1,dp);
        
    }
};