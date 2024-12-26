class Solution {
public:
    int f(int index,int target,vector<int>& nums,vector<vector<int>>& dp)
    {
        if(index==0)
        {
            if(target==0 && nums[0]==0)return 2;
            if(target==0 || target==nums[0])return 1;
            return 0;
        }

        if(dp[index][target]!= -1)return dp[index][target];

        int noTake = f(index-1,target,nums,dp);

        int take =0;
        if(nums[index]<=target)
        {
            take = f(index-1,target-nums[index],nums,dp);
        }

        return dp[index][target]= (take+noTake);
    }
    int findTargetSumWays(vector<int>& nums, int target) {

        int n= nums.size();

        int totalSum = 0;
        for(int i=0;i<n;i++)
        {
            totalSum+=nums[i];
        }

        if(totalSum-target < 0)
            return 0;
        if((totalSum-target)%2 ==1)
            return 0;

        int s2 = (totalSum-target)/2;
        vector<vector<int>> dp(n,vector<int>(s2+1,-1));

        return f(n-1,s2,nums,dp);
        
    }
};