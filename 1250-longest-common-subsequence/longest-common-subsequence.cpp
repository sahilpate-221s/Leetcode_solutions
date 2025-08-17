class Solution {
public:
    int helper(int i, int j,string& text1, string& text2, vector<vector<int>>& dp)
    {
        //base case
        if(i==text1.size() || j==text2.size())return 0;

        if(dp[i][j] != -1)return dp[i][j];

        int val = 0;

        if(text1[i] == text2[j])
        {
            val = 1 + helper(i+1,j+1,text1,text2,dp);
        }
        else
        {
            val= max(helper(i+1,j,text1,text2,dp), helper(i,j+1,text1,text2,dp));
        }

        return dp[i][j] = val;
    }
    int longestCommonSubsequence(string text1, string text2) {
        
        int n= text1.size();
        int m= text2.size();

        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));

        return helper(0,0,text1,text2,dp);

        
    }
};