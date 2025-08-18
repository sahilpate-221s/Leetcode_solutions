class Solution {
public:
    int trap(vector<int>& nums) {
        int n = nums.size();

        int left = 0;
        int right = n-1;

        int leftMax = 0;
        int rightMax = 0;
        int ans = 0;

        while(left < right)
        {
            if(nums[left] > leftMax)
            {
                leftMax = max(leftMax, nums[left]);
            }
            if(nums[right] > rightMax)
            {
                rightMax = max(rightMax, nums[right]);
            }


            if(leftMax < rightMax)
            {
                ans = ans + leftMax - nums[left];
                left++;
            }
            else
            {
                ans = ans+rightMax - nums[right];
                right--;
            }
        }
        return ans;


        
    }
};