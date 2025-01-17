class Solution {
public:
    string clearDigits(string s) {
        stack<char>st;
        for(int i=0;i<s.size();i++){
            if(!isdigit(s[i])){
                    st.push(s[i]);
            }
            else{
                st.pop();
            }
        }
string b="";
        while(!st.empty()){
            b.push_back(st.top());
            st.pop();
        }
    reverse(b.begin(),b.end());
    return b;
    }
};