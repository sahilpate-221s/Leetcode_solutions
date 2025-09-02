class Solution {
public:
    bool isPossible(vector<int>& nums, int mid, int m, int k) {
        int continuousDays = 0;
        int bloomdays = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] <= mid) {
                continuousDays++;
            } else {
                continuousDays = 0;
            }

            if (continuousDays == k) {
                bloomdays++;
                continuousDays = 0;
            }
        }
        return bloomdays >= m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {

        int left = 0;
        int right = *max_element(bloomDay.begin(), bloomDay.end());

        int days = -1;

        while (left <= right) {
            long long mid = (left + right) / 2;

            if (isPossible(bloomDay, mid, m, k)) {
                days = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return days;
    }
};