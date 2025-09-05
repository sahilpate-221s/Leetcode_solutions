class Solution {
public:
    int solve(vector<int>& nums, int k)
    {
        int n = nums.size();
        unordered_map<int,int>umap;

        int count = 0;

        int j=0;
        for(int i = 0; i < n; i++) {
        umap[nums[i]]++;
        
        while(umap.size() > k) {
            umap[nums[j]]--;
            if(umap[nums[j]] == 0) {
                umap.erase(nums[j]);
            }
            j++;
        }
        
        // For every valid window [j...i], all subarrays ending at i
        // and starting from j to i are valid
        count += (i - j + 1);
    }
        return count;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return solve(nums,k) - solve(nums,k-1);
    }
};