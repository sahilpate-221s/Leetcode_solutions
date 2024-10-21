class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& poped) {
        stack<int> st;
        int n = pushed.size();
        int i=0;
        int j = 0;
        
        while(i<n)
        {
            st.push(pushed[i++]);

            while(!st.empty() && st.top() == poped[j])
            {
                st.pop();
                j++;
            }
            
        }
        return  st.empty();
        
    }
};