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
            vector<vector<int>>dp(n,vector<int>(target+1,-1));
            int result = helper(0, nums, target,dp);

            return (result < 0)?-1:result;

            
        
    }
};