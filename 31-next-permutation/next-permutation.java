class Solution {
    public void swap(int[] nums, int i, int j) {
    int temp = nums[i];
    nums[i] = nums[j];
    nums[j] = temp;
}

    public void reverse(int[] nums,int l) {
        
        int r = nums.length - 1;

        while (l < r) {
            swap(nums, l,r);
            l++;
            r--;
        }
    }

    public void nextPermutation(int[] nums) {
        int n = nums.length;

        int i = n - 2;

        while (i >= 0 && nums[i] >= nums[i + 1]) {
            i--;
        }

        if (i >= 0) {
            int j = n - 1;
            while (j >= 0 && nums[j] <= nums[i]) {
                j--;
            }
           swap(nums, j, i);
        }

        reverse(nums,i+1);
    }
}