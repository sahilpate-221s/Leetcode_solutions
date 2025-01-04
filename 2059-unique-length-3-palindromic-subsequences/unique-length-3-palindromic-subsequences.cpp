class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n= s.length();
        vector<int> startIndex(26,-1);
        vector<int>endIndex(26,-1);

        for(int i=0;i<n;i++)
        {
            if(startIndex[s[i]-'a'] == -1)
            {
                startIndex[s[i]-'a'] = i;
            }
            endIndex[s[i]-'a']=i;
        }

        int count = 0;
        cout<<startIndex[0];
        cout<<endIndex[0];
        
        for(int i=0;i<26;i++)
        {
            int start = startIndex[i];
            int end = endIndex[i];

            if(end > start+1)
            {
                unordered_set<char> umap;
                for(int j=start+1;j<end;j++)
                {
                    umap.insert(s[j]);
                }
                count+= umap.size();
            }
        }

        return count;
    }
};