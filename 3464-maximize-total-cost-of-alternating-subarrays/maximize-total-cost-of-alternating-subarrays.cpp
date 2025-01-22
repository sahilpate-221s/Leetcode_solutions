class Solution {
public:
    long long helper(int index, vector<int>& nums, int multiplier, vector<vector<long long>>& dp) {
        // Base case: End of the array
        if (index == nums.size()) return 0;

        // Map multiplier (-1 or 1) to valid dp indices (0 for -1, 1 for 1)
        int multiplierIndex = (multiplier == -1) ? 0 : 1;

        // If already computed, return stored value
        if (dp[index][multiplierIndex] != -1) return dp[index][multiplierIndex];

        // Option 1: Start a new subarray with multiplier = -1
        long long newSubarray = helper(index + 1, nums, -1, dp) + nums[index];

        // Option 2: Continue with the existing subarray
        long long oldSubarray = helper(index + 1, nums, -multiplier, dp) + nums[index] * multiplier;

        // Store the result in dp table and return the maximum
        return dp[index][multiplierIndex] = max(newSubarray, oldSubarray);
    }

    long long maximumTotalCost(vector<int>& nums) {
        int n = nums.size();
        // Create dp array with 2 columns (0 for -1 multiplier, 1 for +1 multiplier)
        vector<vector<long long>> dp(n + 1, vector<long long>(2, -1));

        // Start recursion with multiplier = 1
        return helper(0, nums, 1, dp);
    }
};
