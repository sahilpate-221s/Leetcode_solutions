class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        int n = nums.size();
        bool swapped = false;
        for(int i=0;i<n;i++)
        {
            swapped = false;
            for(int j = 0;j<n-i-1;j++) //in every pass max wala right me chala jata hai to usko nahi check karte
            {

                if(nums[j]<= nums[j+1])
                {
                    continue; // no swap required
                }
                else
                {
                    //nums[j] bada hai nums[j+1]
                    if(__builtin_popcount(nums[j]) == __builtin_popcount(nums[j+1]))
                    {
                        swap(nums[j],nums[j+1]);
                        swapped = true;
                    }
                    else
                    {
                        return false;
                    }
                }
            }

            if(swapped==false)break;
        }

        return true;
        
        
    }
};