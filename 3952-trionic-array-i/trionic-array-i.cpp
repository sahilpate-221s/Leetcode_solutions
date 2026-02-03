class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return false;

        int p = -1, q = -1;
        int i = 0;

        // 1️⃣ strictly increasing
        for (; i < n - 1; i++) {
            if (nums[i] >= nums[i + 1]) {
                p = i;
                break;
            }
        }

        // first increasing must exist
        if (p <= 0) return false;

        // 2️⃣ strictly decreasing
        for (; i < n - 1; i++) {
            if (nums[i] <= nums[i + 1]) {
                q = i;
                break;
            }
        }

        // decreasing must exist
        if (q == -1 || q == p) return false;

        // 3️⃣ strictly increasing
        for (; i < n - 1; i++) {
            if (nums[i] >= nums[i + 1]) {
                return false;
            }
        }

        return true;
    }
};
