class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {

        //patience sorting
        int n = nums.size();
        vector<int>sorted;

        for(int i=0;i<n;i++)
        {
            auto it = lower_bound(begin(sorted),end(sorted),nums[i]); // justgreater than or equal to nums[i];

            if(it == end(sorted))
            {
                sorted.push_back(nums[i]);
            }
            else
            {
                *it = nums[i];
            }
        }
        return sorted.size();
        
        
    }
};