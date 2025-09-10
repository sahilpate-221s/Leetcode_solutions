class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int size = nums.size();
        int maxi = INT_MIN;
        int product = 1;

        for(int i=0;i<size;i++)
        {
            product *= nums[i];
            maxi = max(maxi, product);
            if(product == 0)product = 1;
        }
        product = 1;

         for(int i=size-1;i>=0;i--)
        {
            product =product *  nums[i];
            maxi = max(maxi, product);
            if(product == 0)product = 1;
        }

        return maxi;
        
    }
};