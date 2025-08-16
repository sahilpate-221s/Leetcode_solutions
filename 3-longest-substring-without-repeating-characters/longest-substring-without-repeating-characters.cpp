class Solution {
public:
    int lengthOfLongestSubstring(string nums) {
        int n= nums.length();
        unordered_map<char,int>umap;
        int maxi = 0;
        int j = 0;

        for(int i=0;i<n;i++)
        {
            while(umap.find(nums[i]) != umap.end())
            {
                umap[nums[j]]--;
                if(umap[nums[j]] == 0)
                {
                    umap.erase(nums[j]);
                }
                j++;
            }
            umap[nums[i]]++;
            maxi = max(maxi, i-j+1);
        }
        return maxi;
    }
};