class Solution {
public:
    bool helper(vector<int>& nums, int sum, int index,
                vector<vector<int>>& dp) {
        if (index >= nums.size())
            return false;
        if (sum == 0) {
            return true;
        }

        if (dp[index][sum] != -1)
            return dp[index][sum];

        int noTake = helper(nums, sum, index + 1, dp);
        int take = 0;
        if (nums[index] <= sum) {
            take = helper(nums, sum - nums[index], index + 1, dp);
        }

        return dp[index][sum] = noTake || take;
    }
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2 != 0)
            return false;

        sum = sum / 2;

        vector<vector<int>> dp(nums.size() + 1, vector<int>(sum + 1, -1));

        return helper(nums, sum, 0, dp);
    }
};