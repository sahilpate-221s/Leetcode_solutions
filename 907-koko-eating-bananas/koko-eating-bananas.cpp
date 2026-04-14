class Solution {
public:
    long long isPossible(vector<int>& piles, int capacity) {
        long long time = 0;
        for (auto x : piles) {
            time += x / capacity;
            if (x % capacity != 0) {
                time++;
            }
        }
        return time;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int size = piles.size();
        int left = 1;
        int right = *max_element(piles.begin(), piles.end());
        int ans = -1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (isPossible(piles, mid) <= h) {
                ans = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return ans;
    }
};