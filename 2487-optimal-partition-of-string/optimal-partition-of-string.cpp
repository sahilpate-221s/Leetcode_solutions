class Solution {
public:
    int partitionString(string s) {
        vector<int> lastSeen(26,-1);

        int count = 0;
        int currSubStr = 0;

        for(int i=0;i<s.length();i++)
        {
            char ch = s[i];

            if(lastSeen[ch-'a'] >= currSubStr)
            {
                count++;
                currSubStr= i;
            }
            lastSeen[ch-'a']=i; 
        }
        return count+1;
        
    }
};