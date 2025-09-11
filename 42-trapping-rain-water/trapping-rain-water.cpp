class Solution {
public:
    int trap(vector<int>& nums) {
        int n = nums.size();

        int left = 0;
        int right = n - 1;

        int leftMax = -1;
        int rightMax = -1;
        int water = 0;
        while (left < right) {
           
            leftMax = max(leftMax, nums[left]);
            rightMax = max(rightMax, nums[right]);

            if(leftMax <= rightMax)
            {
                water += leftMax - nums[left];
                left++;
            }
            else
            {
                water += rightMax - nums[right];
                right--;
            }
            
        }
        return water;
    }
};
