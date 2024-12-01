class Solution {
public:
    int n;
    int LIS(int index , vector<vector<int>>& nums, int prev,vector<vector<int>>& dp)
    {
        //base case
        if(index == n)return  0;
        if(dp[index][prev+1] != -1)return dp[index][prev+1];

        int noTake = LIS(index+1,nums,prev,dp);
        int take = 0;
        if(prev == -1 || nums[index][0] > nums[prev][1])
        {
            take =1+ LIS(index+1, nums,index,dp);
        }

        return dp[index][prev+1] =  max(take,noTake);
    }


    int findLongestChain(vector<vector<int>>& pairs) {
        n = pairs.size();
        sort(begin(pairs),end(pairs));

        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));

        return LIS(0,pairs,-1,dp);
    }
};