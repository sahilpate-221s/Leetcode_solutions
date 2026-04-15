class Solution {
public:
    int isPossible(vector<int>& nums, int capacity) {
        int days = 1;
        int curr = 0;

        for (auto it : nums) {
            if (it > capacity)
                return INT_MAX;

            if (curr + it <= capacity) {
                curr += it;
            } else {
                curr = it;
                days++;
            }
        }
        return days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int size = weights.size();
        int left = 0;
        int right = accumulate(weights.begin(), weights.end(), 0);

        int ans = -1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (isPossible(weights, mid) <= days) {
                ans = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return ans;
    }
};