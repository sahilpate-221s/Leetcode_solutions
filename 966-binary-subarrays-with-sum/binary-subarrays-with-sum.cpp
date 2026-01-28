class Solution {
public:
    int helper(vector<int>& nums, int goal) {
        int n = nums.size();
        int sum = 0;
        int count = 0;
        int j = 0;

        for (int i = 0; i < n; i++) {
            sum += nums[i];
            while (j <= i && sum > goal) {
                sum -= nums[j];
                j++;
            }

            count += i - j + 1;
        }

        return count;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return helper(nums, goal) - helper(nums, goal-1);
    }
};