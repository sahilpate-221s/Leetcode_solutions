class Solution {
public:
    int solve(int idx, int prev, vector<int>& nums, vector<vector<int>>& dp) {
        // base case
        if (idx == nums.size()) {

            return 0;
        }

        if (dp[idx][prev + 1] != -1)
            return dp[idx][prev + 1];

        int noTake = solve(idx + 1, prev, nums, dp);
        int take = 0;

        if (prev == -1 || nums[idx] > nums[prev]) {
            take = 1  + solve(idx + 1, idx, nums, dp);
        }

        return dp[idx][prev + 1] = max(noTake, take);
    }
    int lengthOfLIS(vector<int>& nums) {

        int n = nums.size();

        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));

        return solve(0, -1, nums, dp);
    }
};