class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());

        int maxi = 0;
        for (int num : s) {
            // only start counting if it's the start of a sequence
            if (!s.count(num - 1)) {
                int curr = num;
                int streak = 1;

                while (s.count(curr + 1)) {
                    curr++;
                    streak++;
                }
                maxi = max(maxi, streak);
            }
        }
        return maxi;
    }
};
