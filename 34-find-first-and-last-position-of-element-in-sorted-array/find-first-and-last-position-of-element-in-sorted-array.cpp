class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int size = nums.size();

        int first = -1;
        int last = -1;

        int left = 0;
        int right = size - 1;

        // finding the first position of target
        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target) {
                first = mid;
                right = mid - 1;
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        // finding second one
        left = 0;
        right = size - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target) {
                last = mid;
                left = mid+1;
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return {first, last};
    }
};