class Solution {
public:
    bool isPossible(vector<int>& nums, int mid, int k) {
        int subarry = 1;
        int sum = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > mid)
                return false;

            if (sum + nums[i] > mid) {
                subarry++;
                sum = nums[i];
                // mid represents our current guess for the maximum allowed sum.
                // If splitting requires more than k subarrays, then:
                // mid is too small because we cannot fit all elements into only k subarrays without exceeding mid.
                // So, this configuration is not possible.

                if(subarry > k)return false;
            } else {
                sum += nums[i];
            }
        }
        return true;
    }
    int splitArray(vector<int>& nums, int k) {

        int left = 0;
        int right = accumulate(begin(nums), end(nums), 0);
        int ans = -1;
        while (left <= right) {

            long long mid = (left + right) / 2;

            if (isPossible(nums, mid, k)) {
                ans = mid;
                right = mid - 1;

            } else {
                left = mid + 1;
            }
        }
        return ans;
    }
};