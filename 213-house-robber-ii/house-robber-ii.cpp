class Solution {
public:
    int solve(int idx, vector<int>& nums,int end,vector<int>& dp) {
        if (idx < end)return 0;
        if (dp[idx] != -1)
            return dp[idx];

        int noTake = solve(idx - 1, nums,end, dp);
        int take = nums[idx] + solve(idx - 2, nums,end, dp);

        return dp[idx] = max(noTake, take);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0]; 

        vector<int> dp(n + 1, -1);
        vector<int> dp2(n + 1, -1);

        int val1 = solve(n - 1, nums,1 ,dp);
        int val2 = solve(n - 2, nums,0, dp2);
        return max(val1, val2);
    }
};