class Solution {
public:
    int solve(int i, int j, int m,int n, vector<vector<int>>& nums, vector<vector<int>>& dp)
    {
        //base case
        if(i==m-1 && j == n-1)return 1;

        if(i < 0 || i >= m || j < 0 || j>= n || nums[i][j] == 1)return 0;

        if(dp[i][j] != -1)return dp[i][j];

        int right = solve(i+1, j, m, n, nums, dp);
        int left = solve(i, j+1, m,n,nums,dp);

        return dp[i][j] = right + left;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& nums) {

        int n = nums.size();
        int m = nums[0].size();

        if(nums[0][0] == 1 || nums[n-1][m-1] == 1)return 0;

        vector<vector<int>>dp(n+1, vector<int>(m+1, -1));

        return solve(0,0,n,m,nums,dp);
        
    }
};