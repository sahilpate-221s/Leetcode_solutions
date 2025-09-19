class Solution {
public:
    int solve(int idx, string& s, int n,vector<int>& dp) {
        if (idx == n)
            return 1;
        if (s[idx] == '0')
            return 0;

        if(dp[idx] != -1)return dp[idx];

        int ith_char = solve(idx + 1, s, n,dp);
        int second_char = 0;

        if (idx + 1 < n) {
            if (s[idx] == '1' || (s[idx] == '2' && s[idx + 1] <= '6')) {
                second_char = solve(idx + 2, s, n,dp);
            }
        }

        return dp[idx] =  ith_char + second_char;
    }
    int numDecodings(string s) {
        int n = s.length();
        vector<int>dp(n+1,-1);

        return solve(0, s, n,dp);
    }
};