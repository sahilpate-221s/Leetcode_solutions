class Solution {
public:
    int solve(vector<int>& nums, int k) {
        int n = nums.size();

        int j = 0;
        int count = 0;
        int temp = 0;

        for (int i = 0; i < n; i++) {
            if (nums[i] % 2 != 0)
                temp++;

            while (temp > k) {
                if (nums[j] % 2 != 0) {
                    temp--;
                }
                j++;
            }

            count += (j - i + 1);
        }

        return count;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return solve(nums, k-1) - solve(nums, k);
    }
};