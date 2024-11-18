class Solution {
public:
    long long solve(int index, int n, vector<int>& nums, bool flag,
                    vector<vector<long long>>& dp) {
        if (index >= n)
            return 0;
        if (dp[index][flag] != -1)
            return dp[index][flag];

        long long noTake = 0 + solve(index + 1, n, nums, flag, dp);
        long long val = nums[index];
        if (!flag) {
            val = -val;
        }
        long long take = val + solve(index + 1, n, nums, !flag, dp);

        return dp[index][flag] = max(noTake, take);
    }
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();

        // DP table: dp[index][flag] where flag is 0 (subtract) or 1 (add)
        vector<vector<long long>> dp(n + 1, vector<long long>(2, 0));

        // Bottom-up DP processing
        for (int index = n - 1; index >= 0; --index) {
            for (int flag = 0; flag <= 1; ++flag) {
                long long noTake =
                    dp[index + 1][flag]; // Do not take nums[index]
                long long val = nums[index];
                if (flag == 1)
                    val = -val; // Subtract if flag is 0
                long long take =
                    val + dp[index + 1][1 - flag];   // Take nums[index]
                dp[index][flag] = max(take, noTake); // Take maximum
            }
        }

        return dp[0][0]; // Result starts from index 0 with addition
    }
};