class Solution {
public:
    int helper(int idx, vector<int>& nums, int target,
               vector<unordered_map<int, int>>& dp) {
        // base case
        int n = nums.size();
        if (idx == n) {
            return target == 0;
        }

        if (dp[idx].count(target))
            return dp[idx][target];
        int pos = 0;
        int neg = 0;

        pos = helper(idx + 1, nums, target - nums[idx], dp);
        neg = helper(idx + 1, nums, target + nums[idx], dp);

        return dp[idx][target] = pos + neg;
    }
    int findTargetSumWays(vector<int>& nums, int target) {

        int n = nums.size();
        vector<unordered_map<int, int>> dp(n);

        return helper(0, nums, target, dp);
    }
};