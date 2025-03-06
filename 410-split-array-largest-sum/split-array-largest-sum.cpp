class Solution {
public:
    bool  isPossible(int n,vector<int>& nums,int k, int mid)
    {
        int subarraySize = 1;
        int subarrayValue = 0;
        for(int i=0;i<n;i++)
        {
            if(nums[i] >mid)
            {
                return false;
            }

            if(subarrayValue + nums[i] > mid)
            {
                subarraySize++;
                subarrayValue = nums[i];

                if(subarraySize > k)return false;
            }
            else
            {
                subarrayValue+=nums[i];
            }


        }
        return true;
    }
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();

        if(k>n)return -1;
        int sum = accumulate(nums.begin(),nums.end(),0);
        int left = 0;
        int right = sum;
        int ans = -1;

        while(left <= right)
        {
            int mid = left+(right-left)/2;

            if(isPossible(n,nums,k,mid))
            {
                ans=mid;
                right = mid-1;
            }
            else
            {
                left = mid+1;
            }
        }

        return ans;
        
    }
};