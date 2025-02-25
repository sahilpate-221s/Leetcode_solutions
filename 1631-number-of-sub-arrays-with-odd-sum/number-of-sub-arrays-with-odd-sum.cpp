class Solution {
public:
    int numOfSubarrays(vector<int>& nums) {
        int n = nums.size();
        int MOD = 1e9 + 7;

        vector<int> prefix(n + 1, 0);
        int evenCount = 1;
        int oddCount = 0;

        int ans = 0;

        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + nums[i];
            if (prefix[i + 1] % 2 == 1) {
                ans = (ans + evenCount) % MOD;
                oddCount++;

            } else {
                ans = (ans + oddCount) % MOD;
                evenCount++;
            }
        }
        return ans % MOD;
    }
};