class Solution {
public:
    int mini = 0;
    int solve(int idx, vector<int>& coins, int amount,
              vector<vector<int>>& dp) {
        // base case
        if (idx == 0) {
            return amount % coins[idx] == 0 ? amount / coins[idx] : 1e9;
        }

        if (dp[idx][amount] != -1)
            return dp[idx][amount];

        int noTake = solve(idx - 1, coins, amount, dp);
        int take = 1e9;
        if (coins[idx] <= amount) {
            take = 1 + solve(idx, coins, amount - coins[idx], dp);
        }

        return dp[idx][amount] = min(take, noTake);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();

        vector<vector<int>> dp(n + 1, vector<int>(amount + 1, -1));

        int val = solve(n - 1, coins, amount,dp);

        return val == 1e9 ? -1 : val;
    }
};