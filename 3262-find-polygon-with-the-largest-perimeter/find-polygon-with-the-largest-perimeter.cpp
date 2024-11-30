class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        sort(begin(nums),end(nums));

        long long maxSum = -1;
        long long sum = nums[0]+nums[1];
        for(int i=2;i<nums.size();i++)
        {
            if(nums[i] >= sum)
            {
                sum+=nums[i];
                continue;
            }
            sum+=nums[i];
            maxSum = sum;
        }
        return maxSum;
        
    }
};