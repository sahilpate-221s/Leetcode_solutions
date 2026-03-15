class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int lastIdx = 0;
        for(int i=1;i<n;i++)
        {
            if(nums[i] == nums[lastIdx])
            {
                continue;
            }
            else
            {
                lastIdx++;
                swap(nums[lastIdx], nums[i]);
            }
        }
        return lastIdx + 1;
    }
};