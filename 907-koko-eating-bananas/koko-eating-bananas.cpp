class Solution {
public:
    bool isPossible(vector<int>& nums, int time, int hour) {
        long long  totalhours = 0;

        for (int i = 0; i < nums.size(); i++) {
            totalhours += nums[i] / time;
            if (nums[i] % time != 0) {
                totalhours++;
            }
        }
        return totalhours <= hour;
    }

    int minEatingSpeed(vector<int>& piles, int h) {

        int maxi = *max_element(piles.begin(), piles.end());

        int left = 1;
        int right = maxi;
        while (left <= right) {
            long long mid = (left + right) / 2;

            if (isPossible(piles, mid, h)) {

                right = mid-1;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};