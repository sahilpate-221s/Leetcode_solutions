class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> umap;

        int n = s.length();
        int m= t.length();

        if(n != m)return false;

        for(int i=0;i<n;i++)
        {
            umap[s[i]]++;
        }

        for(auto it: t)
        {
            umap[it]--;

        }

        for (auto it : umap) {
            if (it.second != 0) return false;  // <-- check frequencies
        }

        
        return true;
    }
};