class Solution {
public:
    string clearStars(string s) {
        int n = s.length();

        vector<int> vis(n,0);
       priority_queue<pair<char, int>, vector<pair<char, int>>, greater<pair<char, int>>> pq;

        for(int i=0;i<n;i++)
            {
                if(s[i]=='*')
                {
                    int index = pq.top().second;
                    vis[-index]=1;
                    vis[i]=1;
                    pq.pop();
                }
                else
                {
                    pq.push({s[i],-i});
                }
            }

        string result = "";
        for(int i=0;i<n;i++)
            {
                if(vis[i]==0)
                {
                    result+=s[i];
                }
            }
        return result;
        
    }
};