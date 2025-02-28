class Solution {
public:
    string lcs(string s,string t)
    {
        int n = s.size();
        int m = t.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        for(int i=0;i<=n;i++)
        {
            dp[i][0]=0;
        }
        for(int i=0;i<=m;i++)
        {
            dp[0][i]=0;
        }

        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(s[i-1]==t[j-1])
                {
                    dp[i][j]= 1+dp[i-1][j-1];
                }
                else 
                {
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }

        int len = dp[n][m];
        string str="";
        int i=n;
        int j = m;
        while(i>0 && j>0)
        {
            if(s[i-1]==t[j-1])
            {
                str+=s[i-1];
                i--,j--;
            }
            else if(dp[i-1][j] > dp[i][j-1])
            {
                str+=s[i-1];
                i--;
            }
            else
            {
                str+=t[j-1];
                j--;
            }
        }

        while(i>0)
        {
            str+=s[i-1];
            i--;
        }
        while(j>0)
        {
            str+=t[j-1];
            j--;
        }

        reverse(str.begin(),str.end());

        return str;
    }
    string shortestCommonSupersequence(string str1, string str2) {
        ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
        
        string ans = lcs(str1,str2);
       
        return ans;
        
    }
};