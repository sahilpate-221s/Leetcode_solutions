class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int>umap;

        for(int i=0;i<nums.size();i++)
        {
            if(umap.find(nums[i]) != umap.end())return true;
            umap.insert(nums[i]);
        }
        return false;


        
    }
};