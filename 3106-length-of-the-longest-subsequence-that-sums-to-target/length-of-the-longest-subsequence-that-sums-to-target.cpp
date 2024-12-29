class Solution {
public:
    int helper(int i, vector<int>& nums, int target,vector<vector<int>>& dp) {
        // base case
        if( i>=nums.size())return (target==0)?0:INT_MIN;
        // if(nums[i]==target)return count;

        if(dp[i][target] != -1)return dp[i][target];

        int noTake = 0 + helper(i+1,nums,target,dp);
        int Take = INT_MIN;
        if(nums[i] <=target)
        {
            Take = 1 + helper(i+1,nums,target-nums[i],dp);
        }

        return dp[i][target] =  max(noTake,Take);

    }
    int lengthOfLongestSubsequence(vector<int>& nums, int target) {

            int n = nums.size();
            vector<vector<int>>dp(n+1,vector<int>(target+1,INT_MIN));
            // int result = helper(0, nums, target,dp);

            // return (result < 0)?-1:result;


        //tabulation


        // BASE case 
        for(int i=0;i<=n;i++)
        {
            dp[i][0] = 0;
        }

        // last se shuru karenge 
        for(int i=n-1;i>=0;i--)
        {
            // target ko zero se start karenge
            for(int tg = 0;tg<=target;tg++)
            {
                // no Take 
                int noTake = dp[i+1][tg];
                // take 
                int take = INT_MIN;
                if(nums[i] <=tg)
                {
                    take = 1 + dp[i+1][tg-nums[i]];
                }

                dp[i][tg]= max(take,noTake);
            }
        }

        return (dp[0][target] < 0) ? -1: dp[0][target];
        
            
        
    }
};