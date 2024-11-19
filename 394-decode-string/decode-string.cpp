class Solution {
public:
    string decodeString(string s) {
        int n= s.length();
        stack<int> product;
        stack<string>st;

        string result = "";

        for(int i=0;i<n;i++)
        {
            if(isdigit(s[i]))
            {
                string mul = "";
                while(i<n && isdigit(s[i]))
                {
                    mul+=s[i];
                    i++;
                }
                int multi = stoi(mul);
                product.push(multi);
                i--;
            }
            else if(s[i]=='[')
            {
                st.push("[");
            }
            else if(isalpha(s[i]))
            {
               if(!st.empty() && st.top() != "[")
               {
                    string top = st.top();  // agar open bracket ke andar multiple characters hai
                    st.pop();
                    top+=s[i];
                    st.push(top);
               }
               else
               {
                st.push(string(1,s[i]));  //single character ke liye
               }
            }
            else if(s[i] == ']')
            {
                string temp = "";
                while(!st.empty() && st.top()!= "[")
                {
                    temp+=st.top();
                    st.pop();
                }
                st.pop();
                int p = product.top();
                product.pop();

                string ans = "";
                for(int j=0;j<p;j++)
                {
                    ans+=temp;
                }

                //add the temp to previous string
                if(!st.empty() && st.top() != "[")
                {
                    string a = st.top();
                    st.pop();
                    a = a+ans;
                    st.push(a);
                }
                else
                {
                    st.push(ans);
                }
            }

        }

        while(!st.empty())
        {
            result = st.top()+result;
            st.pop();   
        }
        return result;
        
    }
};