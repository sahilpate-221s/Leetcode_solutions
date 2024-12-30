class Solution {
public:
    char dfs(unordered_map<char,vector<char>>& adj,char ch, vector<int>& visited)
    {
        visited[ch-'a'] = 1;

        char minCh = ch;


        for(auto &v: adj[ch])
        {
            if(visited[v-'a']==0)
            {
                minCh = min(minCh,dfs(adj,v,visited));
            }

        }
        return minCh;
    }
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        int n = s1.length();
        int m = baseStr.length();

        unordered_map<char,vector<char>> adj;
        for(int i=0;i<n;i++)
        {
            int u = s1[i];
            int v = s2[i];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        string result;
        for(int i=0;i<m;i++)
        {
            char ch = baseStr[i];
            vector<int> visited(26,0);

            char minChar = dfs(adj,ch,visited);
            result.push_back(minChar);
        }

        return result;
    }
};