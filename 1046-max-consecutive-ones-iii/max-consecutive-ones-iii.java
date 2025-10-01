class Solution {
    public int longestOnes(int[] nums, int k) {

        int n = nums.length;
        int j = 0;
        int maxi = 0;
        int temp = 0;

        for(int i=0;i<n;i++)
        {
            if(nums[i] == 0)temp++;
            while(temp > k)
            {
                if(nums[j] == 0)temp--;
                j++;
            }

            maxi = Math.max(maxi, i-j+1);
        }
        return maxi;
        
    }
}