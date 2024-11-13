class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        sort(begin(nums), end(nums));

        long long ans = 0;
        for (int i = 0; i < n; i++) {
            int idx =
                lower_bound(begin(nums) + i + 1, end(nums), lower - nums[i]) -
                begin(
                    nums); // gives the first elemtn not less than lower-nums[i]
            int x = idx - 1 - i;
            idx = upper_bound(begin(nums) + i + 1, end(nums), upper - nums[i]) -
                  begin(nums); // gives the first elemtn greater than
                               // (upper-nums[i])
            int y = idx - i - 1;

            ans += y - x;
        }
        return ans;
    }
};