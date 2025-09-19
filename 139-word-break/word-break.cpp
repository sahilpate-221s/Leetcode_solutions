class Solution {
public:
    set<string> st;
    bool helper(string& s, int idx,vector<int>& dp) {
        int n = s.length();
        if (idx >= n)
            return true;

        if (st.find(s) != st.end())
            return true;

        if(dp[idx] != -1)return dp[idx];

        for (int len = 1; len <= n; len++) {
            string temp = s.substr(idx, len);
            if (st.find(temp) != st.end() && helper(s,idx + len,dp))
                return dp[idx] =  true;
        }
        return dp[idx] = false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {

        for (auto it : wordDict) {
            st.insert(it);
        }

        int n = s.length();
        vector<int>dp(n+1,-1);

        return helper(s, 0,dp);
    }
};