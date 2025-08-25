class Solution {
public:
    bool isValid(string s) {
        ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
        stack<char> st;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='(' || s[i]=='{' || s[i]=='[')
            {
                st.push(s[i]);
            }
            else if(!st.empty() && ((s[i] == ')' && st.top() == '(') || 
                                    (s[i] == '}' && st.top() == '{') || 
                                    (s[i] == ']' && st.top() == '['))) {
                st.pop();
            } 
            else return false;
        }

        return st.empty();
        
        

        
    }
};