class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() == 0) return 0;  // Edge case

        sort(nums.begin(), nums.end());  // Sort the array

        int count = 1, maxCount = 1;

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1]) {
                continue;  // Skip duplicates
            }
            if (nums[i] == nums[i - 1] + 1) {
                count++;  // Continue the streak
            } else {
                count = 1;  // Reset count if streak breaks
            }
            maxCount = max(maxCount, count);
        }

        return maxCount;
    }
};
