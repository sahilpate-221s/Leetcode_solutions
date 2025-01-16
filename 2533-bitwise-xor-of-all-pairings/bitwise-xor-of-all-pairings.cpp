class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {

    int n = nums1.size(); // length of first one
    int m = nums2.size(); //length of second one

    unordered_map<long long ,long long> umap;
    for(auto &it: nums1)
    {
        umap[it]+=m;
    }
    for(auto &it: nums2)
    {
        umap[it]+=n;
    }

    int ans = 0;
    for(auto &it: umap)
    {
        int val = it.second;
        if(val%2==0)
        {
            continue;
        }
        else
        {
            ans = ans ^it.first;
        }
    }
    return ans;


    }
};