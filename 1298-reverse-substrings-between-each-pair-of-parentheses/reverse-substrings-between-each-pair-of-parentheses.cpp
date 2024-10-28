class Solution {
public:
    string reverseParentheses(string s) {
        stack<int>st;
        for(int i=0;i<s.size();i++)
        {
            char ch = s[i];
            if(ch=='(')
            {
                st.push(i);
            }
            else if(ch==')')
            {
                int index = st.top();
                st.pop();
                reverse(s.begin()+index+1, s.begin()+i);
            }
        }

        string result = "";
        for(auto num: s)
        {
            if(num=='(' || num==')')
            {
                continue;
            }
            else
                result+=num;
        }
        return result;
        
    }
};