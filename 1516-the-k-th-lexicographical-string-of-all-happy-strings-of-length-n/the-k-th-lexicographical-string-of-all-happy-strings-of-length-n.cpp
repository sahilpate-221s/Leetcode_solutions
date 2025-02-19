class Solution {
public:
    vector<string>result;
    void solve(string curr, int n)
    {
        if(curr.length()==n)
        {
            result.push_back(curr);
            return;
        }

        for(char ch = 'a'; ch<='c';ch++)
        {
            if(!curr.empty() && curr.back() == ch) continue;
            curr.push_back(ch);
            solve(curr,n);
            curr.pop_back();
        }
    }
    string getHappyString(int n, int k) {
        string curr = "";
        solve(curr,n);
        return result.size() < k?"" : result[k-1];
        
    }
};