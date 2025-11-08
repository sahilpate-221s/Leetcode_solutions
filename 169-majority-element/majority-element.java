class Solution {
    public int majorityElement(int[] nums) {
        int n = nums.length;

        int count = 1;

        int last = nums[0];

        for (int i = 1; i < n; i++) {
            if (count == 0) {
                last = nums[i];
            }

            
            if (nums[i] == last)
                count++;
            else {
                count--;
            }
        }
        return last;

    }
}