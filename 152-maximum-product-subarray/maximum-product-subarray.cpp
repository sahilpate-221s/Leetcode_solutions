class Solution {
public:
    int maxProduct(vector<int>& nums) {

        int n = nums.size();
        int product = 1;
        int maxi = INT_MIN;

        // find product from the left side ;
        for (auto it : nums) {
            product *= it;
            maxi = max(maxi, product);
            if (product == 0) {
                product = 1;
            }
        }
        cout << "Product = " << product;
        product = 1;

        for (int i = n - 1; i >= 0; i--) {
            product *= nums[i];
            maxi = max(maxi, product);
            if (product == 0) {
                product = 1;
            }
        }

        return maxi;
    }
};