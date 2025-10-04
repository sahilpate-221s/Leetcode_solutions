class Solution {
public:

    bool helper(vector<int>& nums, int idx, int target, vector<vector<int>>& dp)
    {
        //base case
        if(target==0)return true;
        if(idx==0)return nums[idx] == target;


        if(dp[idx][target] != -1)return dp[idx][target];

        bool noTake = helper(nums, idx-1, target, dp);
        bool take = false;

        if(nums[idx] <= target)
        {
            take = helper(nums, idx-1, target-nums[idx], dp);
        }

        return dp[idx][target] = noTake || take;
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();

        int sum = accumulate(nums.begin(),nums.end(),0);

        if(sum % 2 != 0)return false;

        int target = sum/2;

        vector<vector<int>>dp(n+1, vector<int>(sum+1,-1));

        return helper(nums, n-1,target,dp);
        
    }
};