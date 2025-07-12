class Solution {
public:
   int solve(int idx, vector<int>& nums, vector<int>& dp) {
        // Base case
        if (idx < 0) return 0;
        if (dp[idx] != -1) return dp[idx];

        // Option 1: Do not rob current house
        int noTake = solve(idx - 1, nums, dp);

        // Option 2: Rob current house and skip previous
        int take = nums[idx] + solve(idx - 2, nums, dp);

        return dp[idx] = max(take, noTake);
    }
    int rob(vector<int>& nums) {
        int n= nums.size();
        vector<int>dp(n+1,-1);
        return solve(n-1, nums, dp);
        
    }
};