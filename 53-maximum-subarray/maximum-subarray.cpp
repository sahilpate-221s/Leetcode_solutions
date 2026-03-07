class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        int size = nums.size();
        int maxSum = nums[0];
        int sum = 0;
        for (int i = 0; i < size; i++) {
            sum += nums[i];
            maxSum = max(maxSum, sum);

            if (sum < 0)
                sum = 0;
            // A negative running sum will only make future sums worse, so we
            // drop it and start fresh.
        }
        return maxSum;
    }
};