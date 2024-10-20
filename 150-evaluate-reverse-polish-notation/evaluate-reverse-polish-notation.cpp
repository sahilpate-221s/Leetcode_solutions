class Solution {
public:
    int solve(int a, int b, string op)
    {
        int val = 0;
        if(op=="-")
        {
            val = a-b;
        }
        else if(op=="+")
        {
            val = a+b;
        }
        else if(op=="*")
        {
            val = a*b;
        }
        else if(op=="/")
        {
            val = a/b;
        }
        

        return val;
    }
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(string &token: tokens)
        {
            if(token=="+" || token=="-" || token=="*" || token=="/")
            {
                int b = st.top();
                st.pop();

                int a = st.top();
                st.pop();

                int result = solve(a,b,token);
                st.push(result);
            }
            else
            {
                st.push(stoi(token));
            }
        }
        return st.top();
        
    }
};