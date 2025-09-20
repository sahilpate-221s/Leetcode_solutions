class Solution {
public:
    bool isValid(string s) {
        stack<char>st;

        for(int i=0;i<s.length();i++)
        {
            char ch = s[i];
            if(st.empty() || ch == '(' || ch=='{' || ch=='[' )
                st.push(ch);
            else if(!st.empty() && ((ch==')' && st.top() == '(') 
            || (ch=='}' &&st.top() == '{' ) 
            || (ch==']' && st.top() == '[')))
            {
                st.pop();
            }
            else
                return false;
        }
        return st.size() == 0 ? true : false;
        
    }
};