class Solution {
public:
    bool isAnagram(string s, string t) {
        int n = s.length();
        int m = t.length();

        if(n != m)return false;

        unordered_map<char, int>umap;

        for(auto it: s)
        {
            umap[it]++;
        }

        for(auto it: t)
        {
            umap[it]--;
            if(umap[it] <= 0)umap.erase(it);
        }

        if(umap.size())return false;
        return true;


        
    }
};