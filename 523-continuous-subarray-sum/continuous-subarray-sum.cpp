class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {

        int n = nums.size();
        unordered_map<int, int> umap;

        umap[0] = -1;
        int sum = 0;

        for (int i = 0; i < n; i++) {
            sum += nums[i];
            int rem = sum % k;

            if (rem < 0)
                rem += k;
            else if (umap.find(rem) != umap.end()) {
                if (i - umap[rem] > 1)
                    return true;
            } else {
                umap[rem] = i;
            }
        }
        return false;
    }
};