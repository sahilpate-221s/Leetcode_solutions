class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int n = nums.size();
        int neg = lower_bound(nums.begin(), nums.end(), 0)- nums.begin();;
        cout<<neg;
        int pos = nums.end() - upper_bound(nums.begin(), nums.end(), 0);
        
        return max(pos,neg);
    }
};