class Solution {
public:
    int solve(vector<int>& nums, int start, int idx,vector<int>& dp) {
        if (idx < start)
            return 0;

        if (idx == start) {
            return nums[idx];
        }

        if(dp[idx] != -1)return dp[idx];

        int noTake = solve(nums, start, idx - 1,dp);
        int Take = nums[idx] + solve(nums, start, idx - 2,dp);

        return dp[idx] =  max(noTake, Take);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();

        if(n==1)return nums[0];
        vector<int>dp(n+1, -1);
        vector<int>dp2(n+1, -1);

        int val1 = solve(nums, 1, n - 1,dp);
        int val2 = solve(nums, 0, n - 2,dp2);

        return max(val1, val2);
    }
};