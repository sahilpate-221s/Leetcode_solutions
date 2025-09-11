class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();

        int left = 0;
        int right = n -1;

        while (left <= right) {
            long long mid = (left + right) / 2;

            if (nums[left] <= nums[mid]) {
                if (nums[right] < nums[mid]) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            } else {
                right = mid;
            }
        }
        return nums[left];
    }
};