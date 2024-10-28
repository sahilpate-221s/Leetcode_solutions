class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
    unordered_set<int> umap(nums.begin(),nums.end());
    int maxCount = 0;
    for(auto &num: nums)
    {
        int count = 0;
        long long sq = num;
        while(umap.find(sq) != umap.end())
        {
            count++;
            sq = sq*sq;
            if(sq > INT_MAX)
            {
                break;
            }
        }
        maxCount = max(maxCount, count);
    }
    return maxCount < 2 ? -1 : maxCount;
        
    }
};