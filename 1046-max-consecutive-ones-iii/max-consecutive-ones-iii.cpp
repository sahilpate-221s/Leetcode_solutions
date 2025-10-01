class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {

        int n = nums.size();

        int j = 0;
        int temp = 0;
        int maxi = 0;

        for (int i = 0; i < n; i++) {
            if (nums[i] == 0)
                temp++;
            while (temp > k) {
                if (nums[j] == 0) {
                    temp--;
                }
                j++;
            }

            maxi = max(maxi, i - j + 1);
        }

        return maxi;
    }
};