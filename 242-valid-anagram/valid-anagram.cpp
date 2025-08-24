class Solution {
public:
    bool isAnagram(string s, string t) {


        unordered_map<char,int>umap;

        for(auto it:s)
        {
            umap[it]++;
        }

        for(auto it: t)
        {
            umap[it]--;
            if(umap[it] < 0)return false;
        }

        for(auto ch: umap)
        {
            if(ch.second != 0)return false;
        }


        return true;
        
    }
};