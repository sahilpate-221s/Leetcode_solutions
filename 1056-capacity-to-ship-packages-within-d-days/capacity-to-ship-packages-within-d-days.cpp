class Solution {
public:
    bool isPossible(vector<int>& nums, int mid, int maxdays) {
        int load = 0;
        int days = 1;

        for (int i = 0; i < nums.size(); i++) {

            if (load+ nums[i] <= mid)
            {
                load=load+nums[i];
            }
            else
            {

                days++;
                load = nums[i];
            }
        }

        return days <= maxdays;
    }
    int shipWithinDays(vector<int>& weights, int days) {

        int left = *max_element(weights.begin(), weights.end());
        int right = accumulate(weights.begin(), weights.end(), 0);

        while (left <= right) {
            long long mid = (left + right) / 2;

            if (isPossible(weights, mid, days)) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};