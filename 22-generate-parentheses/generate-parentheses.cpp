class Solution {
public:
    set<string>st;
    void helper(int n, string s,int left, int right)
    {
        if(s.length() == 2*n && left == right)
        {
            st.insert(s);
            return;
        }

        if(left < n)
        {
            helper(n,s+'(', left+1, right);
        }
        if(right < left)
        {
            helper(n,s+')',left,right+1);
        }
    }
    vector<string> generateParenthesis(int n) {
        string str;
        helper(n,str,0,0);

        vector<string>answer;

        for(auto it: st)
        {
            answer.push_back(it);
        }

        return answer;
        
    }
};