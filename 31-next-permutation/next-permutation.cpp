class Solution {
public:
    void nextPermutation(vector<int>& nums) {

        int n = nums.size();

        int i = n - 2;
        // step1 : finding (ith) element which is smaller than (i+1)
        while (i >= 0 && nums[i] >= nums[i + 1]) {
            i--;
        }

        // finding the successor means finding element  from the last which is
        // greater than (ith element)
        if (i >= 0) {
            int j = n - 1;
            while (nums[j] <= nums[i]) {
                j--;
            }
            swap(nums[j], nums[i]);
        }
        // return the suffix part only not the whole array
        reverse(nums.begin() + i + 1, nums.end());
    }
};