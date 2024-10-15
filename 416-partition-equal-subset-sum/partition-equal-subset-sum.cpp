class Solution {
public:
    bool f(int index,vector<int>& nums,int sum,vector<vector<int>>& dp)
    {
        if(sum==0)
            return true;
        if(index==0) return nums[0]==sum;

        if(dp[index][sum] != -1)return dp[index][sum];

        bool noTake = f(index-1,nums,sum,dp);
        bool take = false;
        if(sum>=nums[index])
        {
            take = f(index-1,nums,sum-nums[index],dp);
        }

        return dp[index][sum] =  take || noTake; 
    }
    bool canPartition(vector<int>& nums) {
        ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);

        int sum = 0;
        for(auto it: nums)
            sum+=it;
        
        int n = nums.size();
        int k=sum/2;

        vector<vector<int>> dp(n,vector<int>(k+1,-1));

        if(sum %2 != 0)
            return false;
        else 
            return f(n-1,nums,k,dp);
        
    }
};