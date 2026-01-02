class Solution {
public:
    int f(int i,int j,vector<vector<int>>& arr,vector<vector<int>>& dp)
    {
        int m = arr[0].size();
        if(j<0 || j>=m) return 1e9;
        if(i==0) return arr[i][j];

        if(dp[i][j]!=-1)return dp[i][j];
        int st = arr[i][j]+f(i-1,j,arr,dp);
        int left = arr[i][j] + f(i-1,j-1,arr,dp);
        int right = arr[i][j] + f(i-1,j+1,arr,dp);
        return dp[i][j] = min({st,left,right});
    }


    int minFallingPathSum(vector<vector<int>>& matrix) {
        ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
        int n = matrix.size();
        int m = matrix[0].size();
        // int ans = 1e9;

        // vector<vector<int>>dp(n,vector<int>(m,-1));

        // vector<vector<int>>dp(n,vector<int>(m,0));

        // for(int j=0;j<m;j++)
        // {
        //     ans = min(ans, f(n - 1, j, matrix,dp));
        // }

        //  TABULATION
        // for(int j=0;j<m;j++)
        // {
        //     dp[0][j]=matrix[0][j];
        // }

        // for (int i = 1; i < n; i++) {
        //     for (int j = 0; j < m; j++) {
        //         int st = matrix[i][j] + dp[i-1][j];
        //         int dl = (j > 0) ? matrix[i][j] + dp[i-1][j-1] : 1e9;
        //         int dr = (j < m - 1) ? matrix[i][j] + dp[i-1][j+1] : 1e9;

        //         dp[i][j] = min({st, dl, dr});
        //     }
        // }

        // int ans = 1e9;
        // for (int j = 0; j < m; j++) {
        //     ans = min(ans, dp[n-1][j]);
        // }

        // return ans;


        //SPACE OPTIMISATION
        vector<int> prev(m,0);
        vector<int> curr(m,0);
        for(int j = 0;j<m;j++)
        {
            prev[j]=matrix[0][j];
        }

        for(int i=1;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                int st = matrix[i][j] + prev[j];
                int dl = (j > 0) ? matrix[i][j] +prev[j-1] : 1e9;
                int dr = (j < m - 1) ? matrix[i][j] + prev[j+1] : 1e9;

               curr[j] = min({st, dl, dr});
            }
            prev=curr;
        }
        
        int ans = 1e9;
        for(int j =0;j<m;j++)
        {
            ans=min(ans,prev[j]);
        }
        return ans;
    }
};