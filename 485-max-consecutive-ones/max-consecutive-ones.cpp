class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int size = nums.size();

        int count = 0;
        int i = 0;
        int j = 0;

        while (j < size) {
            if (nums[j] == 1) {
                j++;
            } else {
                count = max(count, j - i);
                j++;
                i = j;
            }
        }

        count = max(count, j - i);
        return count;
    }
};