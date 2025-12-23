class Solution {
public:
    int solve(vector<int>& nums, int idx,vector<int>& dp)
    {
        //base case
        if(idx == 0)
        {
            return nums[0];
        }
        if(idx == 1)
        {
            return max(nums[0], nums[1]);
        }

        if(dp[idx] != -1)
        {
            return dp[idx];
        }

        int noTake = solve(nums, idx-1,dp);
        int Take = INT_MIN;
        if(idx > 1)
        {
            Take = nums[idx] + solve(nums, idx-2,dp);
        }

        return dp[idx] = max(noTake, Take);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();

        vector<int>dp(n,0);
        // return solve(nums, n-1,dp);

        if(n==1)return nums[0];

        dp[0] = nums[0];
        dp[1] = max(nums[0],nums[1]);

        for(int i=2;i<n;i++)
        {
            int noTake = dp[i-1];
            int Take = dp[i-2] + nums[i];

            dp[i] = max(noTake, Take);
        }

        return dp[n-1];
        
    }
};