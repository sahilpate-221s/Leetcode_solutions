class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        long long count = 0;

        for(int i=0;i<nums.size();i++)
        {
            nums[i] = nums[i]-i;
        }

        unordered_map<int,int>umap;
        umap[nums[0]]++;
        for(int j=1;j<nums.size();j++)
        {
            int countofNumj = umap[nums[j]];
            int totalNumBeforeJ = j;

            int badPairs =  totalNumBeforeJ - countofNumj;
            count+=badPairs;


            umap[nums[j]]++;

        }

        return count;
        
    }
};