class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k<=1)
            return 0;
        int start = 0;
        int end = 0;
        int prod = 1;
        int count=0;
        while(end<nums.size()){
            prod = prod*nums[end];

            while(prod>= k){
                prod = prod/nums[start++];
            }
            count = count+(end-start+1);
            end++;
        }

        return count;
        
    }
};