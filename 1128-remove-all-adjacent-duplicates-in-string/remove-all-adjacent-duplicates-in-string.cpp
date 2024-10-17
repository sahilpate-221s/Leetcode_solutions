class Solution {
public:
    string removeDuplicates(string s) {
        string st;
        for(int i=0;i<s.length();i++)
        {
            if(!st.empty() and st.back()==s[i])
            {
                st.pop_back();
            }
            else
            {
                st.push_back(s[i]);
            }

        }
        // string ans = "";
        // while(!st.empty())
        // {
        //     ans+=st.top();
        //     st.pop();
        // }
        // reverse(ans.begin(),ans.end());

        // return ans;

        return st;
        
    }
};