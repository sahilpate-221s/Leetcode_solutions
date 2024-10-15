class Solution {
public:
    unordered_set<string> umap;
    int n;
    bool solve(int index, string& s,vector<int>& dp)
    {
        if(index >=n)return true;

        if(umap.find(s)!= umap.end())
            return true;

        if(dp[index] != -1)return dp[index];

        for(int l=1;l<=n;l++)
        {
            string temp = s.substr(index,l);
            if(umap.find(temp) != umap.end() && solve(index+l,s,dp))
            {
                return dp[index]= true;
            }
        }
        return dp[index]= false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        n = s.length();
        
        for(string &word: wordDict)
        {
            umap.insert(word);
        }
        vector<int>dp(n,-1);

        return solve(0,s,dp);
        
    }
};