class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {

        int n = nums.size();
        int ones = 0;
        int zero_count = 0;
        int maxi  = 0;
        int j=0;

        for(int i=0;i<n;i++)
        {
            if(nums[i] == 0)
            {
                zero_count++;
            }

            while(zero_count > k)
            {
                if(nums[j] == 0)
                {
                    zero_count--;
                }
                j++;
            }

            maxi = max(maxi, i-j+1);

            
        }

        return maxi;
        
    }
};