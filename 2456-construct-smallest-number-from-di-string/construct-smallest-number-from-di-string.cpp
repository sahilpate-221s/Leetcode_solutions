class Solution {
public:
    string smallestNumber(string pattern) {
        int n = pattern.length();
        string answer = ""; // n+1 size ki hogi
        stack<char>st;

        int counter = 1;
        for(int i=0;i<=n;i++)
        {
            st.push(counter + '0');
            counter++;

            if(i==n || pattern[i]=='I')
            {
                while(!st.empty())
                {
                    answer+=st.top();
                    st.pop();
                }
            }
        }
        return answer;
        
    }
};