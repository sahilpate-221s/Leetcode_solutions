class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int x= *max_element(nums.begin(),nums.end());
        int ans = 0;
        int len = 0;
        for(int el: nums)
        {
            if(el==x) ans = max(ans,++len);
            else
                len = 0;
        }
        return ans;
        
    }
};