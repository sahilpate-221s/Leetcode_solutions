class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>umap;

        int n = nums1.size();
        int m = nums2.size();

        if(n < m)
        {
            swap(nums1, nums2);
        }

        for(auto x: nums2)
        {
            umap[x]++;
        }

        vector<int>answer;

        for(auto x:nums1)
        {
            if(umap.find(x) != umap.end())
            {
                answer.push_back(x);
                umap.erase(x);
            }
        }
        return answer;

        
    }
};