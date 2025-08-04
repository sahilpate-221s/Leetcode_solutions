class Solution {
public:
    bool helper(string& s, string& p, int i, int j, vector<vector<int>>& dp) {
        // base case: both string and pattern are fully matched
        if (i == s.length() && j == p.length())
            return true;

        // pattern exhausted but string is not
        if (j == p.length())
            return false;

        // string exhausted
        if (i == s.length()) {
            while (j < p.length()) {
                if (p[j] != '*') return false;
                j++;
            }
            return true;
        }

        if (dp[i][j] != -1) return dp[i][j];

        bool res;
        if (s[i] == p[j] || p[j] == '?') {
            res = helper(s, p, i + 1, j + 1, dp);
        } else if (p[j] == '*') {
            res = helper(s, p, i + 1, j, dp) || helper(s, p, i, j + 1, dp);
        } else {
            res = false; // ✨ Fix: handle mismatch explicitly
        }

        dp[i][j] = res;
        return res;
    }

    bool isMatch(string s, string p) {
        int n = s.length();
        int m = p.length();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        return helper(s, p, 0, 0, dp);
    }
};
