class Solution {
public:
    void solve(string s, int i, unordered_set<string>& st,int currCount,int &maxCount)
    {

        //this is called pruning (extra cases ko remove kar dete hai jo result ko affect anhi karenge)
        if(currCount +(s.length()-i) <= maxCount)
        {
            return;
        }
        if(i>=s.length())
        {
            maxCount = max(maxCount,currCount);
            return ;
        }

        for(int j=i;j<s.length();j++)
        {
            string sub = s.substr(i,j-i+1);//o(n)
            if(st.find(sub)==st.end())
            {
                st.insert(sub);//do
                solve(s,j+1,st,currCount+1,maxCount);//explore possiblities
                st.erase(sub);

            }
        }
    }
    int maxUniqueSplit(string s) {
        unordered_set<string>st;
        int currCount = 0;
        int maxCount = 0;
        int i=0;
        solve(s,i,st,currCount,maxCount);
        return maxCount;
    }
};