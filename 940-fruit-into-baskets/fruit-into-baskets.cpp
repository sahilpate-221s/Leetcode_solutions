class Solution {
public:
    int totalFruit(vector<int>& nums) {
        
        int n= nums.size();
        unordered_map<int,int>umap;

        int j= 0;
        int maxLength = 0;

        for(int i=0;i<n;i++)
        {
            umap[nums[i]]++;
            while(umap.size() > 2)
            {
                umap[nums[j]]--;
                if(umap[nums[j]] == 0)
                    umap.erase(nums[j]);

                j++;
            }
            maxLength = max(maxLength, i-j+1);
        }
        return maxLength;
    }
};