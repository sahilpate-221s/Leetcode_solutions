class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        unordered_set<char>umap;
        int j = 0;

        int maxi = 0;
        for(int i=0;i<n;i++)
        {
            char ch = s[i];
            while(umap.find(ch) != umap.end())
            {
                umap.erase(s[j]);
                j++;
            }
            maxi = max(maxi, i-j+1);
            umap.insert(s[i]);
        }

        return maxi;
        
    }
};