class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int size = nums.size();
        int sum = 0;

        int maxSum = INT_MIN;
        for(int idx= 0;idx<size;idx++)
        {
            sum+= nums[idx];

            maxSum = max(maxSum, sum);
            if(sum < 0)sum = 0;
        }
        return maxSum;
        
    }
};