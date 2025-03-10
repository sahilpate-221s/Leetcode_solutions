class Solution {
public:
    int numberOfSubstrings(string s) {
        int n= s.length();

        unordered_map<int,int>umap;

        int count = 0;
        int j = 0;

        for(int i=0;i<n;i++)
        {
            umap[s[i]-'a']++;

            while(umap[0] > 0 && umap[1] > 0 && umap[2] > 0) 
            {
                count+= n-i;
                umap[s[j]-'a']--;
                j++;
            }
        }
        return count;
    }
};