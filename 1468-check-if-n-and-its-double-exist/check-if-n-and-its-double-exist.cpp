class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_set<int>umap(arr.begin(),arr.end());
        int zero = 0;
        for(auto it: arr)
        {
            if(it==0)zero++;
        }
        if(zero > 1)return true;

        for(int i=0;i<arr.size();i++)
        {
            int val = arr[i]*2;
            if(val==0)continue;
            if(umap.find(val) != umap.end())return true;
        }
        return false;
        
    }
};