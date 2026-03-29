class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> umap;
        umap[0] = -1;
        int max_len = 0;
        int sum = 0;

        for (int i = 0; i < n; i++) {
            sum += nums[i] == 1 ? 1 : -1;

            if (umap.find(sum) != umap.end()) {
                max_len = max(max_len, i - umap[sum]);
            } else
                umap[sum] = i;
        }

        return max_len;
    }
};