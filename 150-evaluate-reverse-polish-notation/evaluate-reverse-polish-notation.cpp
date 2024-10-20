class Solution {
public:
    int result = 0;

    string solve(vector<string>str,string op)
    {
        int b = stoi(str[0]);
        int a = stoi(str[1]);
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
        else
        {
            val = 0;
        }
        result = val;
        return to_string(val);
    }


    int evalRPN(vector<string>& s) {
        stack<string>st;
        int n = s.size();
        if(n<2)
        {
            return stoi(s[0]);
        }

        // int result = 0;
        for(int i=0;i<n;i++)
        {
            vector<string>vec;
            if(s[i]=="-" || s[i]=="+" || s[i]=="*" || s[i]=="/")
            {
                for(int j=0;j<2;j++)
                {
                   vec.push_back(st.top());
                    st.pop();
                }
                string op = s[i];
                string val = solve(vec,op);
                st.push(val);
            }
            else
            {
                st.push(s[i]);
            }
        }
        
        return result;

        
    }
};