class Solution {
public:
    int MOD  = 1e9+7;
    int helper(int currLen, int low, int high, int zero, int one,
               vector<int>& dp) {
        // base case
        if (currLen > high)
            return 0;

        int curr = (currLen >= low) ? 1 : 0;

        if (dp[currLen] != -1)
            return dp[currLen];

        curr =(curr+ helper(currLen + zero, low, high, zero, one, dp))%MOD;
        curr =(curr+helper(currLen + one, low, high, zero, one, dp))%MOD;

        return dp[currLen] = curr;
    }
    int countGoodStrings(int low, int high, int zero, int one) {
        vector<int> dp(high + 1, -1);

        return helper(0, low, high, zero, one, dp);
    }
};